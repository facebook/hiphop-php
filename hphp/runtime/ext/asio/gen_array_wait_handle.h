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

#ifndef incl_HPHP_EXT_ASIO_GEN_ARRAY_WAIT_HANDLE_H_
#define incl_HPHP_EXT_ASIO_GEN_ARRAY_WAIT_HANDLE_H_

#include "hphp/runtime/base/base-includes.h"
#include "hphp/runtime/ext/asio/blockable_wait_handle.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
// class GenArrayWaitHandle

/**
 * A wait handle that waits for an array of wait handles. The wait handle
 * finishes once all wait handles in the array are finished. The result value
 * preserves structure (order and keys) of the original array. If one of the
 * wait handles failed, the exception is propagated by failure.
 */
class c_GenArrayWaitHandle final : public c_BlockableWaitHandle {
 public:
  DECLARE_CLASS_NO_SWEEP(GenArrayWaitHandle)

  explicit c_GenArrayWaitHandle(Class* cls = c_GenArrayWaitHandle::classof())
    : c_BlockableWaitHandle(cls)
  {}
  ~c_GenArrayWaitHandle() {}

  static void ti_setoncreatecallback(const Variant& callback);
  static Object ti_create(const Array& dependencies);

 public:
  void onUnblocked();
  String getName();
  c_WaitableWaitHandle* getChild();
  void enterContextImpl(context_idx_t ctx_idx);

 private:
  void setState(uint8_t state) { setKindState(Kind::GenArray, state); }
  void initialize(const Object& exception, const Array& deps,
                  ssize_t iter_pos, c_WaitableWaitHandle* child);

 private:
  Object m_exception;
  Array m_deps;       // invariant: always kPackedKind or kMixedKind
  ssize_t m_iterPos;
};

inline c_GenArrayWaitHandle* c_WaitHandle::asGenArray() {
  assert(getKind() == Kind::GenArray);
  return static_cast<c_GenArrayWaitHandle*>(this);
}

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_ASIO_GEN_ARRAY_WAIT_HANDLE_H_
