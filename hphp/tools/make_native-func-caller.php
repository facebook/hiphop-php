<?php
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


/**
 * Generate the ABI wrapper functions for HPHP::Native::NativeFuncCaller
 *
 * The NativeFuncCaller class relies on specifics of the amd64 and ARMv8 ABIs
 * to reshuffle the order of certain arguments and reduce the number of
 * possible combinations (by a lot).
 *
 * If you don't understand how NativeFuncCaller works, don't use this script.
 * If you do, then adjust NUM_GP_ARGS/NUM_SIMD_ARGS as needed and pipe the
 * output of this script to runtime/vm/native-func-caller.h
 *
 * I solemnly swear that I am up to no good.
 */
define('NUM_GP_ARGS', 32); // Must match kMaxBuiltinArgs
define('NUM_SIMD_ARGS', 8); // Must match CPU's ABI definition for SIMD usage

$fp = STDOUT;

fwrite($fp, "// @"."generated by hphp/tools/make_native-func-caller.php\n\n");

fwrite($fp, "static_assert(kMaxBuiltinArgs == " . NUM_GP_ARGS.
            ",\"Regenerate native-func-caller.h for updated ".
            "kMaxBuiltinArgs\");\n\n");

fwrite($fp, "static_assert(kNumSIMDRegs == " . NUM_SIMD_ARGS.
            ",\"Regenerate native-func-caller.h for updated ".
            "kNumSIMDRegs\");\n\n");

$callerArgs = 'BuiltinFunction f, int64_t* GP, int GP_count, '.
              'double* SIMD, int SIMD_count';
foreach(['double'=>'Double','int64_t'=>'Int64','Variant&&'=>'Variant','StaticString'=>'StaticString','String'=>'String','Array'=>'Array','TypedValue'=>'TV'] as $ret => $name) {
  fwrite($fp, "${ret} callFunc{$name}Impl({$callerArgs}) {\n");
  fwrite($fp, "  switch (GP_count) {\n");
  $gpargs = [];
  for($gp = 0; $gp <= NUM_GP_ARGS; ++$gp) {
    fwrite($fp, "    case ${gp}:\n");
    fwrite($fp, "      switch (SIMD_count) {\n");
    $simdargs = [];
    for($simd = 0; $simd <= NUM_SIMD_ARGS; ++$simd) {
      $argsD = implode(',', array_merge($simdargs, $gpargs));
      $argsC = [];
      for ($i = 0; $i < $simd; ++$i) {
        $argsC[] = "SIMD[$i]";
      }
      for ($i = 0; $i < $gp; ++$i) {
        $argsC[] = "GP[$i]";
      }
      $argsC = implode(',', $argsC);
      fwrite($fp, "        case ${simd}:\n");
      fwrite($fp, "          return ((${ret} (*)(${argsD}))f)(${argsC});\n");
      $simdargs[] = 'double';
    }
    fwrite($fp, "        default: not_reached();\n");
    fwrite($fp, "      }\n");
    $gpargs[] = 'int64_t';
  }
  fwrite($fp, "    default: not_reached();\n");
  fwrite($fp, "  }\n");
  fwrite($fp, "}\n\n");
}
