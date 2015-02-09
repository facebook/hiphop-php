/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2014 Facebook, Inc. (http://www.facebook.com)     |
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

#include "hphp/compiler/expression/dynamic_function_call.h"
#include "hphp/compiler/analysis/code_error.h"
#include "hphp/compiler/expression/expression_list.h"
#include "hphp/compiler/expression/scalar_expression.h"
#include "hphp/compiler/expression/simple_function_call.h"
#include "hphp/compiler/analysis/function_scope.h"
#include "hphp/compiler/analysis/class_scope.h"
#include "hphp/compiler/option.h"
#include "hphp/compiler/analysis/variable_table.h"

using namespace HPHP;

///////////////////////////////////////////////////////////////////////////////
// constructors/destructors

DynamicFunctionCall::DynamicFunctionCall
(EXPRESSION_CONSTRUCTOR_PARAMETERS,
 ExpressionPtr name, ExpressionListPtr params, ExpressionPtr cls)
  : FunctionCall(EXPRESSION_CONSTRUCTOR_PARAMETER_VALUES(DynamicFunctionCall),
                 name, "", false, params, cls) {
}

ExpressionPtr DynamicFunctionCall::clone() {
  DynamicFunctionCallPtr exp(new DynamicFunctionCall(*this));
  FunctionCall::deepCopy(exp);
  return exp;
}

///////////////////////////////////////////////////////////////////////////////
// parser functions

///////////////////////////////////////////////////////////////////////////////
// static analysis functions

void DynamicFunctionCall::analyzeProgram(AnalysisResultPtr ar) {
  FunctionCall::analyzeProgram(ar);
  if (ar->getPhase() >= AnalysisResult::AnalyzeAll) {
    if (!m_className.empty()) {
      resolveClass();
    }
    if (m_params) {
      m_params->markParams(canInvokeFewArgs());
    }

    if (!m_class && m_className.empty()) {
      FunctionScopePtr fs = getFunctionScope();
      VariableTablePtr vt = fs->getVariables();
      vt->setAttribute(VariableTable::ContainsDynamicFunctionCall);
    }
  }
}

ExpressionPtr DynamicFunctionCall::preOptimize(AnalysisResultConstPtr ar) {
  if (ExpressionPtr rep = FunctionCall::preOptimize(ar)) return rep;
  return ExpressionPtr();
}

///////////////////////////////////////////////////////////////////////////////

void DynamicFunctionCall::outputCodeModel(CodeGenerator &cg) {
  if (m_class || !m_className.empty()) {
    cg.printObjectHeader("ClassMethodCallExpression", 4);
    StaticClassName::outputCodeModel(cg);
    cg.printPropertyHeader("methodExpression");
  } else {
    cg.printObjectHeader("SimpleFunctionCallExpression", 3);
    cg.printPropertyHeader("functionExpression");
  }
  m_nameExp->outputCodeModel(cg);
  cg.printPropertyHeader("arguments");
  cg.printExpressionVector(m_params);
  cg.printPropertyHeader("sourceLocation");
  cg.printLocation(m_nameExp->getLocation());
  cg.printObjectFooter();
}

///////////////////////////////////////////////////////////////////////////////
// code generation functions
void DynamicFunctionCall::outputPHP(CodeGenerator &cg, AnalysisResultPtr ar) {
  if (m_class || !m_className.empty()) {
    StaticClassName::outputPHP(cg, ar);
    cg_printf("::");
    m_nameExp->outputPHP(cg, ar);
  } else {
    const char *prefix = Option::IdPrefix.c_str();
    if (cg.getOutput() == CodeGenerator::TrimmedPHP &&
        cg.usingStream(CodeGenerator::PrimaryStream) &&
        !m_nameExp->is(Expression::KindOfScalarExpression)) {
      cg_printf("${%sdynamic_load($%stmp = (", prefix, prefix);
      m_nameExp->outputPHP(cg, ar);
      cg_printf("), '%stmp'", prefix);
      cg_printf(")}");
    } else {
      m_nameExp->outputPHP(cg, ar);
    }
  }

  cg_printf("(");
  if (m_params) m_params->outputPHP(cg, ar);
  cg_printf(")");
}
