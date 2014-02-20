/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2014 Facebook, Inc. (http://www.facebook.com)     |
   | Copyright (c) 1997-2010 The PHP Group                                |
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

#ifndef incl_HPHP_EXT_MISC_H_
#define incl_HPHP_EXT_MISC_H_

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include "hphp/runtime/base/base-includes.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

int64_t f_connection_aborted();
int64_t f_connection_status();
int64_t f_connection_timeout();
Variant f_constant(const String& name);
bool f_define(const String& name, CVarRef value, bool case_insensitive = false);
bool f_defined(const String& name, bool autoload = true);
Variant f_die(CVarRef status = null_variant);
Variant f_exit(CVarRef status = null_variant);
void f___halt_compiler();
int64_t f_ignore_user_abort(bool setting = false);
Variant f_pack(int _argc, const String& format, CArrRef _argv = null_array);
int64_t f_sleep(int seconds);
void f_usleep(int micro_seconds);
Variant f_time_nanosleep(int seconds, int nanoseconds);
bool f_time_sleep_until(double timestamp);
String f_uniqid(const String& prefix = null_string, bool more_entropy = false);
Variant f_unpack(const String& format, const String& data);
Array f_sys_getloadavg();
Array f_token_get_all(const String& source);
String f_token_name(int64_t token);
String f_hphp_to_string(CVarRef v);
extern const double k_INF;
extern const double k_NAN;
extern const bool k_PHP_DEBUG;
extern const int64_t k_PHP_MAXPATHLEN;

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_MISC_H_
