/**
 * Autogenerated by Thrift for RpcMetadata.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "RpcMetadata_metadata.h"
#include <thrift/lib/cpp2/visitation/visit_union.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitUnion<::apache::thrift::CodecConfig> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::zlibConfig:
      return f(0, *static_cast<T&&>(t).zlibConfig_ref());
    case Union::Type::zstdConfig:
      return f(1, *static_cast<T&&>(t).zstdConfig_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
template <>
struct VisitUnion<::apache::thrift::PayloadExceptionMetadata> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::declaredException:
      return f(0, *static_cast<T&&>(t).declaredException_ref());
    case Union::Type::proxyException:
      return f(1, *static_cast<T&&>(t).proxyException_ref());
    case Union::Type::DEPRECATED_proxiedException:
      return f(2, *static_cast<T&&>(t).DEPRECATED_proxiedException_ref());
    case Union::Type::DEPRECATED_appClientException:
      return f(3, *static_cast<T&&>(t).DEPRECATED_appClientException_ref());
    case Union::Type::DEPRECATED_appServerException:
      return f(4, *static_cast<T&&>(t).DEPRECATED_appServerException_ref());
    case Union::Type::appUnknownException:
      return f(5, *static_cast<T&&>(t).appUnknownException_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
template <>
struct VisitUnion<::apache::thrift::PayloadMetadata> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::responseMetadata:
      return f(0, *static_cast<T&&>(t).responseMetadata_ref());
    case Union::Type::exceptionMetadata:
      return f(1, *static_cast<T&&>(t).exceptionMetadata_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
template <>
struct VisitUnion<::apache::thrift::ServerPushMetadata> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::setupResponse:
      return f(0, *static_cast<T&&>(t).setupResponse_ref());
    case Union::Type::streamHeadersPush:
      return f(1, *static_cast<T&&>(t).streamHeadersPush_ref());
    case Union::Type::drainCompletePush:
      return f(2, *static_cast<T&&>(t).drainCompletePush_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
template <>
struct VisitUnion<::apache::thrift::ClientPushMetadata> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::interactionTerminate:
      return f(0, *static_cast<T&&>(t).interactionTerminate_ref());
    case Union::Type::streamHeadersPush:
      return f(1, *static_cast<T&&>(t).streamHeadersPush_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
