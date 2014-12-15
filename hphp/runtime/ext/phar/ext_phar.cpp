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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "hphp/runtime/base/array-init.h"
#include "hphp/runtime/base/base-includes.h"
#include "hphp/runtime/base/stream-wrapper.h"
#include "hphp/runtime/base/stream-wrapper-registry.h"
#include "hphp/runtime/base/mem-file.h"
#include "hphp/runtime/base/directory.h"
#include "hphp/runtime/base/execution-context.h"
#include "hphp/runtime/vm/vm-regs.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
// phar:// stream wrapper

static const StaticString
  s_openPhar("openPhar"),
  s_stat("stat"),
  s_size("size"),
  s_mtime("mtime"),
  s_atime("atime"),
  s_ctime("ctime"),
  s_mode("mode"),
  s_opendir("opendir");

static class PharStreamWrapper : public Stream::Wrapper {
 public:
  virtual File* open(const String& filename, const String& mode,
                     int options, const Variant& context) {
    static const char cz[] = "phar://";
    if (strncmp(filename.data(), cz, sizeof(cz) - 1)) {
      return nullptr;
    }

    static Func* f = SystemLib::s_PharClass->lookupMethod(s_openPhar.get());

    Variant ret;
    g_context->invokeFunc(
      ret.asTypedValue(),
      f,
      make_packed_array(filename),
      nullptr,
      SystemLib::s_PharClass
    );
    String contents = ret.toString();

    MemFile* file = newres<MemFile>(contents.data(), contents.size());
    return file;
  }

  virtual int access(const String& path, int mode) {
    Variant ret = callStat(path);
    if (ret.isBoolean()) {
      assert(!ret.toBoolean());
      return -1;
    }
    return 0;
  }

  virtual int stat(const String& path, struct stat* buf) {
    Variant ret = callStat(path);
    if (ret.isBoolean()) {
      assert(!ret.toBoolean());
      return -1;
    }
    const Array& stat = ret.toArray();
    buf->st_size = stat[s_size].asInt64Val();
    buf->st_atime = stat[s_atime].asInt64Val();
    buf->st_mtime = stat[s_mtime].asInt64Val();
    buf->st_ctime = stat[s_ctime].asInt64Val();
    buf->st_mode = stat[s_mode].asInt64Val();
    return 0;
  }

  virtual int lstat(const String& path, struct stat* buf) {
    return stat(path, buf);
  }

  virtual Directory* opendir(const String& path) {
    static Func* f = SystemLib::s_PharClass->lookupMethod(s_opendir.get());
    Variant ret;
    g_context->invokeFunc(
      ret.asTypedValue(),
      f,
      make_packed_array(path),
      nullptr,
      SystemLib::s_PharClass
    );
    Array files = ret.toArray();
    if (files.empty()) {
      raise_warning("No such file or directory");
      return nullptr;
    }
    return newres<ArrayDirectory>(files);
  }

 private:
  Variant callStat(const String& path) {
    static Func* f = SystemLib::s_PharClass->lookupMethod(s_stat.get());
    Variant ret;
    g_context->invokeFunc(
      ret.asTypedValue(),
      f,
      make_packed_array(path),
      nullptr,
      SystemLib::s_PharClass
    );
    return ret;
  }

} s_phar_stream_wrapper;

static String HHVM_STATIC_METHOD(Phar, running, bool retphar = true) {
  //We need to walk up a stack frame and retrieve the value of __FILE__
  //and then pass that onto the php impl
  //FIXME: Why do I need this?
  bool useJit = ThreadInfo::s_threadInfo->m_reqInjectionData.getJit();
  RuntimeOption::EvalJit = useJit;
  CallerFrame cf;
  const ActRec* ar = cf.actRecForArgs();
  const std::string filepath =
    ar->m_func->unit()->filepath()->toCppString();
  constexpr auto kPharScheme = "phar://";
  constexpr auto kPharExt = ".phar";
  if(filepath.length() > std::strlen(kPharScheme)) {
    if(filepath.compare(0, std::strlen(kPharScheme), kPharScheme) == 0) {
      std::size_t pharExtPos = filepath.find(kPharExt);
      if(pharExtPos != std::string::npos) {
        const std::string pharpath =
          filepath.substr(0, pharExtPos + std::strlen(kPharExt));
        if(retphar) {
          return pharpath;
        }
        else {
          return pharpath.substr(std::strlen(kPharScheme));
        }
      }
    }
  }
  return "";
}

class pharExtension : public Extension {
 public:
  pharExtension() : Extension("phar") {}
  virtual void moduleInit() {
    s_phar_stream_wrapper.registerAs("phar");
  }

  virtual void moduleLoad(const IniSetting::Map& Ini, Hdf config) {
    HHVM_STATIC_ME(Phar, running);
  }
} s_phar_extension;

///////////////////////////////////////////////////////////////////////////////
}
