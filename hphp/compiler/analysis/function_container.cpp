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

#include <compiler/analysis/function_container.h>
#include <compiler/analysis/analysis_result.h>
#include <compiler/analysis/function_scope.h>
#include <compiler/analysis/class_scope.h>
#include <compiler/analysis/file_scope.h>
#include <compiler/analysis/code_error.h>
#include <compiler/statement/statement_list.h>
#include <compiler/option.h>
#include <util/util.h>
#include <util/hash.h>

using namespace HPHP;

///////////////////////////////////////////////////////////////////////////////

FunctionContainer::FunctionContainer() {
}

///////////////////////////////////////////////////////////////////////////////
// parser functions

void FunctionContainer::countReturnTypes(
  std::map<std::string, int> &counts,
  const StringToFunctionScopePtrVecMap *redec) {
  for (StringToFunctionScopePtrMap::const_iterator iter =
         m_functions.begin(); iter != m_functions.end(); ++iter) {
    FunctionScopePtr f = iter->second;
    if (f->isLocalRedeclaring()) {
      always_assert(redec);
      BOOST_FOREACH(f, redec->find(iter->first)->second) {
        TypePtr type = f->getReturnType();
        if (type) {
          type->count(counts);
        }
      }
    } else {
      TypePtr type = f->getReturnType();
      if (type) {
        type->count(counts);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
// code generation functions

void FunctionContainer::getFunctionsFlattened(
  const StringToFunctionScopePtrVecMap *redec,
  FunctionScopePtrVec &funcs,
  bool excludePseudoMains /* = false */) const {
  for (StringToFunctionScopePtrMap::const_iterator it = m_functions.begin();
       it != m_functions.end(); ++it) {
    FunctionScopePtr func = it->second;
    if (!excludePseudoMains || !func->inPseudoMain()) {
      if (func->isLocalRedeclaring()) {
        const FunctionScopePtrVec &r = redec->find(it->first)->second;
        funcs.insert(funcs.end(), r.begin(), r.end());
      } else {
        funcs.push_back(func);
      }
    }
  }
}
