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

#ifndef incl_HPHP_EXT_ASIO_H_
#define incl_HPHP_EXT_ASIO_H_

#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/ext/asio/async_function_wait_handle.h"
#include "hphp/runtime/ext/asio/async_generator.h"
#include "hphp/runtime/ext/asio/async_generator_wait_handle.h"
#include "hphp/runtime/ext/asio/await_all_wait_handle.h"
#include "hphp/runtime/ext/asio/condition_wait_handle.h"
#include "hphp/runtime/ext/asio/external_thread_event_wait_handle.h"
#include "hphp/runtime/ext/asio/gen_array_wait_handle.h"
#include "hphp/runtime/ext/asio/gen_map_wait_handle.h"
#include "hphp/runtime/ext/asio/gen_vector_wait_handle.h"
#include "hphp/runtime/ext/asio/reschedule_wait_handle.h"
#include "hphp/runtime/ext/asio/sleep_wait_handle.h"
#include "hphp/runtime/ext/asio/static_wait_handle.h"
#include "hphp/runtime/ext/asio/waitable_wait_handle.h"

namespace HPHP {

Object HHVM_FUNCTION(asio_get_running);

}

#endif // incl_HPHP_EXT_ASIO_H_
