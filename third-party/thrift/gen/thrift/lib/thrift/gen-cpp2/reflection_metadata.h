/**
 * Autogenerated by Thrift for ../../../../src/thrift/lib/thrift/reflection.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_metadata_h.h>
#include "../../../../src/thrift/lib/thrift/gen-cpp2/reflection_types.h"


namespace apache {
namespace thrift {
namespace detail {
namespace md {

template <>
class EnumMetadata<::apache::thrift::reflection::Type>
    : private EmptyMetadata {
 public:
  using EmptyMetadata::gen;
};
template <>
class StructMetadata<::apache::thrift::reflection::StructField>
    : private EmptyMetadata {
 public:
  using EmptyMetadata::gen;
};
template <>
class StructMetadata<::apache::thrift::reflection::DataType>
    : private EmptyMetadata {
 public:
  using EmptyMetadata::gen;
};
template <>
class StructMetadata<::apache::thrift::reflection::Schema>
    : private EmptyMetadata {
 public:
  using EmptyMetadata::gen;
};
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
