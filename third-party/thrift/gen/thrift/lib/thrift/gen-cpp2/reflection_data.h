/**
 * Autogenerated by Thrift for ../../../../src/thrift/lib/thrift/reflection.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "../../../../src/thrift/lib/thrift/gen-cpp2/reflection_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::apache::thrift::reflection::Type> {
  using type = ::apache::thrift::reflection::Type;
  static constexpr const std::size_t size = 16;
  static const std::array<type, size> values;
  static const std::array<folly::StringPiece, size> names;
};

template <> struct TStructDataStorage<::apache::thrift::reflection::StructField> {
  static constexpr const std::size_t fields_size = 5;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;
};

template <> struct TStructDataStorage<::apache::thrift::reflection::DataType> {
  static constexpr const std::size_t fields_size = 5;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;
};

template <> struct TStructDataStorage<::apache::thrift::reflection::Schema> {
  static constexpr const std::size_t fields_size = 2;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;
};

}} // apache::thrift
