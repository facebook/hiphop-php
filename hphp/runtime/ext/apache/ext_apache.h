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

#ifndef incl_HPHP_EXT_APACHE_H_
#define incl_HPHP_EXT_APACHE_H_

#include "hphp/runtime/base/base-includes.h"
#include "hphp/util/health-monitor-types.h"

namespace HPHP {

class ApacheExtension : public Extension {
 public:
  ApacheExtension();
  virtual ~ApacheExtension();
  virtual void moduleInit();
  virtual void moduleLoad(const IniSetting::Map& ini, Hdf config);
  static bool Enable;

  static void UpdateHealthLevel(HealthLevel newStatus) {
    m_healthLevel = newStatus;
  }

  static HealthLevel GetHealthLevel() {
    return m_healthLevel;
  }

 private:
  static HealthLevel m_healthLevel;
};

}

#endif // incl_HPHP_EXT_APACHE_H_
