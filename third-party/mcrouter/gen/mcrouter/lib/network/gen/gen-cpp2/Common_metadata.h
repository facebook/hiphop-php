/**
 * Autogenerated by Thrift for ../src/mcrouter/lib/network/gen/Common.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_metadata_h.h>
#include "mcrouter/lib/network/gen/gen-cpp2/Common_types.h"
#include "mcrouter/lib/carbon/gen-cpp2/carbon_metadata.h"
#include "mcrouter/lib/carbon/gen-cpp2/carbon_result_metadata.h"


namespace apache {
namespace thrift {
namespace detail {
namespace md {

template <>
class StructMetadata<::facebook::memcache::thrift::McVersionRequest> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McVersionReply> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McStatsRequest> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McStatsReply> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McShutdownRequest> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McShutdownReply> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McQuitRequest> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McQuitReply> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McExecRequest> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::McExecReply> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::GoAwayAcknowledgement> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::facebook::memcache::thrift::GoAwayRequest> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
