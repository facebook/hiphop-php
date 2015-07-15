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

#ifndef incl_HPHP_COUNTABLE_H_
#define incl_HPHP_COUNTABLE_H_

#include <cstdint>
#include <cstddef>
#include "hphp/util/assertions.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/*
 * The sign bit flags a reference count as static. If a reference count
 * is static, it means we should never increment or decrement it: the
 * object lives across requests and may be accessed by multiple threads.
 * Long lived objects can be static or uncounted; static objects have process
 * lifetime, while uncounted objects are freed using the treadmill.
 * Using 8-bit values generates shorter cmp instructions while still being
 * far enough from 0 to be safe.
 */
constexpr size_t UncountedBitPos = 31;
constexpr int32_t UncountedValue = -128;
constexpr int32_t StaticValue = -127; // implies UncountedValue
constexpr int32_t RefCountMaxRealistic = (1 << 30) - 1;

static_assert((uint32_t)UncountedValue & (1uL << UncountedBitPos),
              "Check UncountedValue and UncountedBitPos");
static_assert((uint32_t)StaticValue & (1uL << UncountedBitPos),
              "Check StaticValue and UncountedBitPos");

/*
 * Check that the refcount is realistic, and not the static flag
 */
inline bool check_refcount_ns(int32_t count) {
  return (uint32_t)count <= (uint32_t)RefCountMaxRealistic;
}

/*
 * Real count values should always be less than or equal to
 * RefCountMaxRealistic, and asserting this will also catch
 * common malloc freed-memory patterns (e.g. 0x5a5a5a5a and smart
 * allocator's 0x6a6a6a6a).
 */
inline bool check_refcount(int32_t count) {
  return count <= StaticValue || check_refcount_ns(count);
}

/*
 * As above, but additionally check for non-zero
 */
inline bool check_refcount_nz(int32_t count) {
  return count <= StaticValue || check_refcount_ns(count - 1);
}

/*
 * As above, but additionally check for greater-than-zero
 */
inline bool check_refcount_ns_nz(int32_t count) {
  return check_refcount_ns(count - 1);
}

/**
 * Ref-counted types have a count field at FAST_REFCOUNT_OFFSET
 * and define counting methods with these macros.
 */
#define IMPLEMENT_COUNTABLE_METHODS_NO_STATIC                           \
  RefCount getCount() const {                                           \
    assert(check_refcount(m_hdr.count));                                \
    return m_hdr.count;                                                 \
  }                                                                     \
                                                                        \
  bool isRefCounted() const {                                           \
    return m_hdr.counted;                                               \
  }                                                                     \
                                                                        \
  bool hasMultipleRefs() const {                                        \
    return m_hdr.mrb;                                                   \
  }                                                                     \
                                                                        \
  bool maybeShared() const {                                            \
    return m_hdr.mrb;                                                   \
  }                                                                     \
                                                                        \
  bool hasExactlyOneRef() const {                                       \
    return !m_hdr.mrb; /* deal with static? */                          \
  }                                                                     \
                                                                        \
  void incRefCount() const {                                            \
    assert(!MemoryManager::sweeping());                                 \
    m_hdr.mrb = true;                                                   \
  }                                                                     \
                                                                        \
  void setRefCount(RefCount count) {                                    \
    assert(count == StaticValue || !MemoryManager::sweeping());         \
    if (count > 1) { m_hdr.mrb = true; }                                \
    else m_hdr.mrb = false;                                             \
  }                                                                     \
                                                                        \
  RefCount decRefCount() const {                                        \
    assert(!MemoryManager::sweeping());                                 \
    return m_hdr.mrb;                                                   \
  }                                                                     \
  ALWAYS_INLINE bool decReleaseCheck() {                                \
    assert(!MemoryManager::sweeping());                                 \
    return !m_hdr.mrb;                                                  \
  }                                                                     \
  ALWAYS_INLINE void decRefAndRelease() {                               \
    if (decReleaseCheck()) release();                                   \
  }

#define IMPLEMENT_COUNTABLE_METHODS             \
  void setStatic() const {                      \
    m_hdr.gcbyte = 0x14; /* 10100 */            \
  }                                             \
  bool isStatic() const {                       \
    return !m_hdr.counted && m_hdr._static;     \
  }                                             \
  void setUncounted() const {                   \
    m_hdr.gcbyte = 0x4; /* 00100 */             \
  }                                             \
  bool isUncounted() const {                    \
    return !m_hdr.counted && !m_hdr._static;    \
  }                                             \
  IMPLEMENT_COUNTABLE_METHODS_NO_STATIC

#define IMPLEMENT_COUNTABLENF_METHODS_NO_STATIC         \
  RefCount getCount() const {                           \
    assert(check_refcount_ns(m_hdr.count));             \
    return m_hdr.count;                                 \
  }                                                     \
                                                        \
  bool isRefCounted() const { return true; }            \
                                                        \
  bool hasMultipleRefs() const {                        \
    return m_hdr.mrb;                                   \
  }                                                     \
                                                        \
  bool hasExactlyOneRef() const {                       \
    return !m_hdr.mrb;                                  \
  }                                                     \
                                                        \
  void incRefCount() const {                            \
    assert(!MemoryManager::sweeping());                 \
    m_hdr.mrb = true;                                   \
  }                                                     \
                                                        \
  RefCount decRefCount() const {                        \
    assert(!MemoryManager::sweeping());                 \
    return m_hdr.mrb;                                   \
  }                                                     \
                                                        \
  void setRefCount(RefCount count) {                    \
    assert(!MemoryManager::sweeping());                 \
    if (count > 1) { m_hdr.mrb = true; }                \
    else m_hdr.mrb = false;                             \
  }                                                     \
                                                        \
  ALWAYS_INLINE bool decRefAndRelease() {               \
    assert(!MemoryManager::sweeping());                 \
    if (!m_hdr.mrb) {                                   \
      release();                                        \
      return true;                                      \
    }                                                   \
    return false;                                       \
  }

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_COUNTABLE_H_
