/**
 * Autogenerated by Thrift for /home/fbthrift/thrift/lib/thrift/RpcMetadata.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/lib/thrift/gen-cpp2/RpcMetadata_metadata.h"
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
    case Union::Type::proxiedException:
      return f(2, *static_cast<T&&>(t).proxiedException_ref());
    case Union::Type::appClientException:
      return f(3, *static_cast<T&&>(t).appClientException_ref());
    case Union::Type::appServerException:
      return f(4, *static_cast<T&&>(t).appServerException_ref());
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
    case Union::Type::__EMPTY__: ;
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
