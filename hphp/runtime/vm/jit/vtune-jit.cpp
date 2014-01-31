/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include "hphp/runtime/vm/jit/vtune-jit.h"
#include "hphp/runtime/vm/jit/vtune/jitprofiling.h"

#include <vector>
#include <algorithm>

namespace HPHP { namespace JIT {

// Method ids reported to Vtune JIT API should not be less than 1000 (see
// the comment in iJIT_Method_Load structure definition.) We use 1000 for
// trampolines and larger values for normal functions.
static const int MIN_METHOD_ID = 1000;

void reportTraceletToVtune(const Unit* unit,
                           const Func* func,
                           const TransRec& tr) {
  iJIT_Method_Load methodInfo;
  memset(&methodInfo, 0, sizeof(methodInfo));

  if (!unit) return;

  methodInfo.method_id = tr.src.getFuncId() + MIN_METHOD_ID;

  if (func && func->fullName()) {
    methodInfo.method_name = const_cast<char *>(func->fullName()->data());
  } else {
    methodInfo.method_name = const_cast<char *>("unknown");
  }

  methodInfo.source_file_name = const_cast<char *>(unit->filepath()->data());

  // aStart field of tr.bcmapping may point to stubs range, so we need to
  // explicitly form mappings for main code and stubs

  size_t bcSize = tr.bcMapping.size();
  std::vector<LineNumberInfo> mainLineMap, stubsLineMap;

  for (size_t i = 0; i < bcSize; i++) {
    LineNumberInfo info;

    info.LineNumber = unit->getLineNumber(tr.bcMapping[i].bcStart);

    // Note that main code may be generated in the stubs code range (see
    // emitBlock in code-gen-x64 genCodeImpl()) so we need to explicitly check
    // the aStart value.
    if (tr.bcMapping[i].aStart >= tr.aStart &&
        tr.bcMapping[i].aStart < tr.aStart + tr.aLen) {
      info.Offset = tr.bcMapping[i].aStart - tr.aStart;
      mainLineMap.push_back(info);
    } else if (tr.bcMapping[i].aStart >= tr.astubsStart &&
               tr.bcMapping[i].aStart < tr.astubsStart + tr.astubsLen) {
      info.Offset = tr.bcMapping[i].aStart - tr.astubsStart;
      stubsLineMap.push_back(info);
    }

    info.Offset = tr.bcMapping[i].astubsStart - tr.astubsStart;
    stubsLineMap.push_back(info);
  }

  auto infoComp = [&](const LineNumberInfo& a,
                      const LineNumberInfo& b) -> bool {
    return a.Offset < b.Offset;
  };

  std::sort(mainLineMap.begin(), mainLineMap.end(), infoComp);
  std::sort(stubsLineMap.begin(), stubsLineMap.end(), infoComp);

  // Note that at this moment LineNumberInfo structures contain pairs of lines
  // and code offset for the start of the corresponding code, while JIT API
  // treats the offset as the end of this code (and the start offset is taken
  // from the previous element or is 0); need to shift the elements. Also,
  // attribute the prologue (code before the first byte in the mapping) to the
  // first line.

  auto shiftLineMap = [&](std::vector<LineNumberInfo>& lineMap,
                          unsigned regionSize) {
    if (lineMap.size() > 0) {
      LineNumberInfo tmpInfo;
      tmpInfo.Offset = regionSize;
      tmpInfo.LineNumber = lineMap.back().LineNumber;
      lineMap.push_back(tmpInfo);
      for (size_t i = lineMap.size() - 2; i > 0; i--) {
        lineMap[i].LineNumber = lineMap[i - 1].LineNumber;
      }
    }
  };

  shiftLineMap(mainLineMap, tr.aLen);
  shiftLineMap(stubsLineMap, tr.astubsLen);

  // Report main body

  methodInfo.method_load_address = tr.aStart;
  methodInfo.method_size = tr.aLen;
  methodInfo.line_number_size = mainLineMap.size();
  methodInfo.line_number_table = &mainLineMap[0];

  iJIT_NotifyEvent(iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED, (void *)&methodInfo);

  // Report stubs

  methodInfo.method_load_address = tr.astubsStart;
  methodInfo.method_size = tr.astubsLen;
  methodInfo.line_number_size = stubsLineMap.size();
  methodInfo.line_number_table = &stubsLineMap[0];

  iJIT_NotifyEvent(iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED, (void *)&methodInfo);
}

void reportTrampolineToVtune(void* begin, size_t size)
{
  iJIT_Method_Load methodInfo;
  memset(&methodInfo, 0, sizeof(methodInfo));

  methodInfo.method_id = MIN_METHOD_ID;

  methodInfo.method_name = const_cast<char *>("Trampoline");

  methodInfo.source_file_name = const_cast<char *>("Undefined");

  // Report main body

  methodInfo.method_load_address = begin;
  methodInfo.method_size = size;

  methodInfo.line_number_size = 0;
  methodInfo.line_number_table = 0;

  iJIT_NotifyEvent(iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED, (void *)&methodInfo);
}

}}
