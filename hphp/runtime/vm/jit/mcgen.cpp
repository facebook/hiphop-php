/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
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

#include "hphp/runtime/vm/jit/mcgen.h"

#include "hphp/runtime/vm/jit/mcgen-prologue.h"
#include "hphp/runtime/vm/jit/mcgen-translate.h"

#include "hphp/runtime/vm/jit/debugger.h"
#include "hphp/runtime/vm/jit/func-prologue.h"
#include "hphp/runtime/vm/jit/prof-data.h"
#include "hphp/runtime/vm/jit/tc.h"
#include "hphp/runtime/vm/jit/trans-db.h"
#include "hphp/runtime/vm/jit/unique-stubs.h"
#include "hphp/runtime/vm/jit/unwind-itanium.h"
#include "hphp/runtime/vm/jit/vtune-jit.h"
#include "hphp/runtime/vm/jit/write-lease.h"

#include "hphp/runtime/vm/debug/debug.h"

#include "hphp/util/timer.h"
#include "hphp/util/trace.h"

TRACE_SET_MOD(mcg);

namespace HPHP { namespace jit {

TransEnv::~TransEnv() {}

namespace mcgen {

struct TCBufferCache {
  TCBufferCache() : m_buffer((TCA)::malloc(localTCSize())) {}
  ~TCBufferCache() { ::free(m_buffer); }

  TCA buf() { return m_buffer; }

private:
  TCA m_buffer;
};

namespace {

IMPLEMENT_THREAD_LOCAL(TCBufferCache, tl_tcBuffer);
bool __thread tl_useLocal{false};

int64_t s_startTime;
bool s_inited{false};

////////////////////////////////////////////////////////////////////////////////
}

bool isLocalTCEnabled() { return tl_useLocal; }

size_t localTCSize() {
  return
    RuntimeOption::EvalThreadTCMainBufferSize +
    RuntimeOption::EvalThreadTCColdBufferSize +
    RuntimeOption::EvalThreadTCFrozenBufferSize +
    RuntimeOption::EvalThreadTCDataBufferSize;
}

TCA cachedLocalTCBuffer() {
  assertx(RuntimeOption::EvalEnableOptTCBuffer);
  return tl_tcBuffer->buf();
}

#ifndef NDEBUG
ReadThreadLocalTC::ReadThreadLocalTC(const tc::ThreadTCBuffer& buf)
  : m_buf(buf)
{
  mprotect(m_buf.start(), localTCSize(), PROT_READ);
}
ReadThreadLocalTC::~ReadThreadLocalTC() {
  mprotect(m_buf.start(), localTCSize(), PROT_NONE);
}
UseThreadLocalTC::UseThreadLocalTC(tc::ThreadTCBuffer& buf) : m_buf(buf) {
  assertx(!tl_useLocal);
  tl_useLocal = true;
  mprotect(m_buf.start(), localTCSize(), PROT_READ | PROT_WRITE);
}
UseThreadLocalTC::~UseThreadLocalTC() {
  tl_useLocal = false;
  mprotect(m_buf.start(), localTCSize(), PROT_NONE);
}
#endif

void processInit() {
  TRACE(1, "mcgen startup\n");

  g_unwind_rds.bind();

  Debug::initDebugInfo();
  tc::processInit();

  if (Trace::moduleEnabledRelease(Trace::printir) &&
      !RuntimeOption::EvalJit) {
    Trace::traceRelease("TRACE=printir is set but the jit isn't on. "
                        "Did you mean to run with -vEval.Jit=1?\n");
  }

  s_startTime = HPHP::Timer::GetCurrentTimeMicros();
  initInstrInfo();

  s_inited = true;
}

bool initialized() { return s_inited; }

int64_t jitInitTime() { return s_startTime; }

bool dumpTCAnnotation(const Func& func, TransKind transKind) {
  return RuntimeOption::EvalDumpTCAnnotationsForAllTrans ||
    (transKind == TransKind::Optimize && (func.attrs() & AttrHot));
}

}}}
