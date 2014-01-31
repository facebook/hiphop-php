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

#ifndef incl_HPHP_INI_SETTING_H_
#define incl_HPHP_INI_SETTING_H_

#include "hphp/runtime/base/complex-types.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

class Extension;

class IniSetting {
public:
  static const Extension* CORE;
  enum ScannerMode {
    NormalScanner,
    RawScanner,
  };

  enum ParserCallbackType {
    ParserSection,
    ParserEntry,
    ParserPopEntry,
  };

  enum Mode {
    PHP_INI_NONE   = 0,
    // These 3 match zend
    PHP_INI_USER   = (1u << 0),
    PHP_INI_PERDIR = (1u << 1),
    PHP_INI_SYSTEM = (1u << 2),

    PHP_INI_ONLY   = (1u << 3),
    PHP_INI_ALL    = (1u << 4),
  };

  typedef void (*PFN_PARSER_CALLBACK)(String *arg1, String *arg2, String *arg3,
                                      int callback_type, void *arg);

  typedef std::function<bool(const String& value, void*p)> UpdateCallback;
  typedef std::function<String(void* p)> GetCallback;

public:
  static Variant FromString(const String& ini, const String& filename,
                            bool process_sections, int scanner_mode);

  static bool Get(const String& name, String &value);
  static bool Set(const String& name, const String& value);
  static bool SetUser(const String& name, const String& value);
  static Array GetAll(const String& extension, bool details);

  static void Bind(const Extension* extension, const Mode mode,
                   const char *name, const char *value,
                   UpdateCallback updateCallback, GetCallback getCallback,
                   void *p = nullptr);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name,
                   UpdateCallback updateCallback, GetCallback getCallback,
                   void *p = nullptr);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name,
                   std::string *p);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name, const char *value,
                   std::string *p);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name,
                   String *p);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name, const char *value,
                   String *p);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name,
                   bool *p);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name, const char *value,
                   bool *p);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name,
                   int64_t *p);
  static void Bind(const Extension* extension, const Mode mode,
                   const char *name, const char *value,
                   int64_t *p);
  static void Unbind(const char *name);

  static void SetGlobalDefault(const char *name, const char *value);

};

int64_t convert_bytes_to_long(const String& value);

#define ini_on_update_fail HPHP::IniSetting::UpdateCallback()
bool ini_on_update_bool(const String& value, void *p);
bool ini_on_update_long(const String& value, void *p);
bool ini_on_update_non_negative(const String& value, void *p);
bool ini_on_update_real(const String& value, void *p);
bool ini_on_update_stdstring(const String& value, void *p);
bool ini_on_update_string(const String& value, void *p);

String ini_get_bool(void *p);
String ini_get_bool_as_int(void *p);
String ini_get_long(void *p);
String ini_get_real(void *p);
String ini_get_string(void *p);
String ini_get_stdstring(void *p);
String ini_get_static_string_1(void *p);

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_INI_SETTING_H_
