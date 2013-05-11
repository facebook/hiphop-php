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

#ifndef incl_HPHP_TEST_EXT_MB_H_
#define incl_HPHP_TEST_EXT_MB_H_

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <test/test_cpp_ext.h>

///////////////////////////////////////////////////////////////////////////////

class TestExtMb : public TestCppExt {
 public:
  virtual bool RunTests(const std::string &which);

  bool test_mb_list_encodings();
  bool test_mb_list_encodings_alias_names();
  bool test_mb_list_mime_names();
  bool test_mb_check_encoding();
  bool test_mb_convert_case();
  bool test_mb_convert_encoding();
  bool test_mb_convert_kana();
  bool test_mb_convert_variables();
  bool test_mb_decode_mimeheader();
  bool test_mb_decode_numericentity();
  bool test_mb_detect_encoding();
  bool test_mb_detect_order();
  bool test_mb_encode_mimeheader();
  bool test_mb_encode_numericentity();
  bool test_mb_ereg_match();
  bool test_mb_ereg_replace();
  bool test_mb_ereg_search_getpos();
  bool test_mb_ereg_search_getregs();
  bool test_mb_ereg_search_init();
  bool test_mb_ereg_search_pos();
  bool test_mb_ereg_search_regs();
  bool test_mb_ereg_search_setpos();
  bool test_mb_ereg_search();
  bool test_mb_ereg();
  bool test_mb_eregi_replace();
  bool test_mb_eregi();
  bool test_mb_get_info();
  bool test_mb_http_input();
  bool test_mb_http_output();
  bool test_mb_internal_encoding();
  bool test_mb_language();
  bool test_mb_output_handler();
  bool test_mb_parse_str();
  bool test_mb_preferred_mime_name();
  bool test_mb_regex_encoding();
  bool test_mb_regex_set_options();
  bool test_mb_send_mail();
  bool test_mb_split();
  bool test_mb_strcut();
  bool test_mb_strimwidth();
  bool test_mb_stripos();
  bool test_mb_stristr();
  bool test_mb_strlen();
  bool test_mb_strpos();
  bool test_mb_strrchr();
  bool test_mb_strrichr();
  bool test_mb_strripos();
  bool test_mb_strrpos();
  bool test_mb_strstr();
  bool test_mb_strtolower();
  bool test_mb_strtoupper();
  bool test_mb_strwidth();
  bool test_mb_substitute_character();
  bool test_mb_substr_count();
  bool test_mb_substr();
};

///////////////////////////////////////////////////////////////////////////////

#endif // incl_HPHP_TEST_EXT_MB_H_
