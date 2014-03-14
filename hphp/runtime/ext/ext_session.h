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

#ifndef incl_HPHP_EXT_SESSION_H_
#define incl_HPHP_EXT_SESSION_H_

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include "hphp/runtime/base/base-includes.h"
#include <vector>
#include "hphp/runtime/base/request-local.h"
#include "hphp/runtime/base/request-event-handler.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

extern const int64_t k_PHP_SESSION_DISABLED;
extern const int64_t k_PHP_SESSION_NONE;
extern const int64_t k_PHP_SESSION_ACTIVE;

int64_t f_session_status();
void f_session_set_cookie_params(int64_t lifetime, const String& path = null_string, const String& domain = null_string, const Variant& secure = uninit_null(), const Variant& httponly = uninit_null());
Array f_session_get_cookie_params();
String f_session_name(const String& newname = null_string);
Variant f_session_module_name(const String& newname = null_string);
bool f_session_set_save_handler(const Object& sessionhandler, bool register_shutdown = true);
String f_session_save_path(const String& newname = null_string);
String f_session_id(const String& newid = null_string);
bool f_session_regenerate_id(bool delete_old_session = false);
String f_session_cache_limiter(const String& new_cache_limiter = null_string);
int64_t f_session_cache_expire(const String& new_cache_expire = null_string);
Variant f_session_encode();
bool f_session_decode(const String& data);
bool f_session_start();
bool f_session_destroy();
Variant f_session_unset();
void f_session_write_close();
void f_session_commit();
bool f_session_register(int _argc, const Variant& var_names, const Array& _argv = null_array);
bool f_session_unregister(const String& varname);
bool f_session_is_registered(const String& varname);

///////////////////////////////////////////////////////////////////////////////
// SessionModule

/**
 * Session modules are implemeted by extending this class and
 * implementing its virtual methods, usually registering by
 * name as a by-product of the constructor.
 *
 * open() is called on session_init() (or request startup is autostart)
 * read()/write() should load and save serialized session data, respectively
 * destroy() should remove the session from the underlying storage media
 * gc() should look for an clean up expired sessions
 * close() is called on session_destroy() (or request end)
 */
class SessionModule {
public:
  enum {
    md5,
    sha1,
  };

public:
  explicit SessionModule(const char *name) : m_name(name) {
    RegisteredModules.push_back(this);
  }
  virtual ~SessionModule() {}

  const char *getName() const { return m_name; }

  virtual bool open(const char *save_path, const char *session_name) = 0;
  virtual bool close() = 0;
  virtual bool read(const char *key, String &value) = 0;
  virtual bool write(const char *key, const String& value) = 0;
  virtual bool destroy(const char *key) = 0;
  virtual bool gc(int maxlifetime, int *nrdels) = 0;
  virtual String create_sid();

public:
  static SessionModule *Find(const char *name) {
    for (unsigned int i = 0; i < RegisteredModules.size(); i++) {
      SessionModule *mod = RegisteredModules[i];
      if (mod && strcasecmp(name, mod->m_name) == 0) {
        return mod;
      }
    }
    return nullptr;
  }

private:
  static std::vector<SessionModule*> RegisteredModules;

  const char *m_name;
};

///////////////////////////////////////////////////////////////////////////////
// SystemlibSessionModule

struct SystemlibSessionInstance final : RequestEventHandler {
  SystemlibSessionInstance() : m_obj(nullptr) { }

  ObjectData *getObject() { return m_obj; }
  void setObject(ObjectData *obj) {
    destroy();
    obj->incRefCount();
    m_obj = obj;
  }

  void destroy() {
    if (!m_obj) return;
    decRefObj(m_obj);
    m_obj = nullptr;
  }

  void requestInit() override { m_obj = nullptr; }
  void requestShutdown() override { destroy(); }

private:
  ObjectData* m_obj;
};

class SystemlibSessionModule : public SessionModule {
public:
  SystemlibSessionModule(const char *mod_name, const char *phpclass_name) :
           SessionModule(mod_name),
           m_classname(phpclass_name) { }

  virtual bool open(const char *save_path, const char *session_name);
  virtual bool close();
  virtual bool read(const char *key, String &value);
  virtual bool write(const char *key, const String& value);
  virtual bool destroy(const char *key);
  virtual bool gc(int maxlifetime, int *nrdels);

private:
  const char *m_classname;
  Class *m_cls;
  static Class *s_SHIClass;
  DECLARE_STATIC_REQUEST_LOCAL(SystemlibSessionInstance, s_obj);

  const Func *m_ctor;
  const Func *m_open, *m_close;
  const Func *m_read, *m_write;
  const Func *m_destroy, *m_gc;

  void lookupClass();
  Func* lookupFunc(Class *cls, StringData *fname);
  ObjectData *getObject();
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_SESSION_H_
