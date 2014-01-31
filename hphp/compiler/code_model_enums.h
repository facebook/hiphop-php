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
// This file is @generated by tools/code-model/GenerateEnums.sh

#ifndef incl_HPHP_CODE_MODEL_ENUMS_H_
#define incl_HPHP_CODE_MODEL_ENUMS_H_

namespace HPHP {
  /** The kinds of operations that IBinaryOpExpressions can perform. */
  enum CodeModelBinaryOperator {
    PHP_AND_ASSIGN = 1,
    PHP_AND = 2,
    PHP_ARRAY_ELEMENT = 3,
    PHP_ARRAY_PAIR = 4,
    PHP_ASSIGNMENT = 5,
    PHP_BOOLEAN_AND = 6,
    PHP_BOOLEAN_OR = 7,
    PHP_CONCAT_ASSIGN = 8,
    PHP_CONCAT = 9,
    PHP_CONDITIONAL = 10,
    PHP_DIVIDE_ASSIGN = 11,
    PHP_DIVIDE = 12,
    PHP_INSTANCEOF = 13,
    PHP_IS_EQUAL = 14,
    PHP_IS_GREATER = 15,
    PHP_IS_GREATER_OR_EQUAL = 16,
    PHP_IS_IDENTICAL = 17,
    PHP_IS_NOT_IDENTICAL = 18,
    PHP_IS_NOT_EQUAL = 19,
    PHP_IS_SMALLER = 20,
    PHP_IS_SMALLER_OR_EQUAL = 21,
    PHP_LOGICAL_AND = 22,
    PHP_LOGICAL_OR = 23,
    PHP_LOGICAL_XOR = 24,
    PHP_MINUS_ASSIGN = 25,
    PHP_MINUS = 26,
    PHP_MODULUS_ASSIGN = 27,
    PHP_MODULUS = 28,
    PHP_MULTIPLY_ASSIGN = 29,
    PHP_MULTIPLY = 30,
    PHP_OR_ASSIGN = 31,
    PHP_OR = 32,
    PHP_PLUS_ASSIGN = 33,
    PHP_PLUS = 34,
    PHP_SHIFT_LEFT_ASSIGN = 35,
    PHP_SHIFT_LEFT = 36,
    PHP_SHIFT_RIGHT_ASSIGN = 37,
    PHP_SHIFT_RIGHT = 38,
    PHP_XOR_ASSIGN = 39,
    PHP_XOR = 40,
  };

  /** The kinds of operations that IUnaryOpExpressions can perform. */
  enum CodeModelUnaryOperator {
    PHP_ARRAY_CAST_OP = 1,
    PHP_ARRAY_APPEND_POINT_OP = 2,
    PHP_AWAIT_OP = 3,
    PHP_BOOL_CAST_OP = 4,
    PHP_BITWISE_NOT_OP = 5,
    PHP_CLONE_OP = 6,
    PHP_DYNAMIC_VARIABLE_OP = 7,
    PHP_ERROR_CONTROL_OP = 8,
    PHP_FLOAT_CAST_OP = 9,
    PHP_INCLUDE_OP = 10,
    PHP_INCLUDE_ONCE_OP = 11,
    PHP_INT_CAST_OP = 12,
    PHP_MINUS_OP = 13,
    PHP_NOT_OP = 14,
    PHP_OBJECT_CAST_OP = 15,
    PHP_PLUS_OP = 16,
    PHP_POST_DECREMENT_OP = 17,
    PHP_POST_INCREMENT_OP = 18,
    PHP_PRE_DECREMENT_OP = 19,
    PHP_PRE_INCREMENT_OP = 20,
    PHP_PRINT_OP = 21,
    PHP_REFERENCE_OP = 22,
    PHP_REQUIRE_OP = 23,
    PHP_REQUIRE_ONCE_OP = 24,
    PHP_STRING_CAST_OP = 25,
    PHP_UNSET_CAST_OP = 26,
  };

  /** Enumerates the kinds of trait require statements. */
  enum CodeModelRequireKind {
    PHP_EXTENDS = 1,
    PHP_IMPLEMENTS = 2,
  };

  /** Enumerates the kinds of type declaration statements. */
  enum CodeModelTypeKind {
    PHP_CLASS = 1,
    PHP_INTERFACE = 2,
    PHP_TRAIT = 3,
  };

  /** The sort order to use when grouping query results */
  enum CodeModelOrder {
    PHP_NOT_SPECIFIED = 1,
    PHP_ASCENDING = 2,
    PHP_DESCENDING = 3,
  };

}
#endif // incl_HPHP_CODE_MODEL_ENUMS_H_
