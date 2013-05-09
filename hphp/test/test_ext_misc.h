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

#ifndef incl_HPHP_TEST_EXT_MISC_H_
#define incl_HPHP_TEST_EXT_MISC_H_

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <test/test_cpp_ext.h>

///////////////////////////////////////////////////////////////////////////////

class TestExtMisc : public TestCppExt {
 public:
  virtual bool RunTests(const std::string &which);

  bool test_connection_aborted();
  bool test_connection_status();
  bool test_connection_timeout();
  bool test_constant();
  bool test_define();
  bool test_defined();
  bool test_die();
  bool test_exit();
  bool test_eval();
  bool test_get_browser();
  bool test___halt_compiler();
  bool test_highlight_file();
  bool test_show_source();
  bool test_highlight_string();
  bool test_ignore_user_abort();
  bool test_pack();
  bool test_php_check_syntax();
  bool test_php_strip_whitespace();
  bool test_sleep();
  bool test_usleep();
  bool test_time_nanosleep();
  bool test_time_sleep_until();
  bool test_uniqid();
  bool test_unpack();
  bool test_sys_getloadavg();
  bool test_token_get_all();
  bool test_token_name();
};

///////////////////////////////////////////////////////////////////////////////

#endif // incl_HPHP_TEST_EXT_MISC_H_
