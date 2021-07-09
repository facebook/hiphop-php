/**
 * Autogenerated by Thrift for ../../../../src/thrift/lib/thrift/metadata.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "../../../../src/thrift/lib/thrift/gen-cpp2/metadata_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::apache::thrift::metadata::ThriftStructType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftConstStruct> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).type_ref()...);
    f(1, static_cast<T&&>(t).fields_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftConstValue> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).cv_bool_ref()...);
    f(1, static_cast<T&&>(t).cv_integer_ref()...);
    f(2, static_cast<T&&>(t).cv_double_ref()...);
    f(3, static_cast<T&&>(t).cv_string_ref()...);
    f(4, static_cast<T&&>(t).cv_map_ref()...);
    f(5, static_cast<T&&>(t).cv_list_ref()...);
    f(6, static_cast<T&&>(t).cv_struct_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftConstValuePair> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).value_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftListType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).valueType_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftSetType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).valueType_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftMapType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).keyType_ref()...);
    f(1, static_cast<T&&>(t).valueType_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftEnumType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftUnionType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftTypedefType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
    f(1, static_cast<T&&>(t).underlyingType_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftStreamType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).elemType_ref()...);
    f(1, static_cast<T&&>(t).initialResponseType_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftSinkType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).elemType_ref()...);
    f(1, static_cast<T&&>(t).finalResponseType_ref()...);
    f(2, static_cast<T&&>(t).initialResponseType_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).t_primitive_ref()...);
    f(1, static_cast<T&&>(t).t_list_ref()...);
    f(2, static_cast<T&&>(t).t_set_ref()...);
    f(3, static_cast<T&&>(t).t_map_ref()...);
    f(4, static_cast<T&&>(t).t_enum_ref()...);
    f(5, static_cast<T&&>(t).t_struct_ref()...);
    f(6, static_cast<T&&>(t).t_union_ref()...);
    f(7, static_cast<T&&>(t).t_typedef_ref()...);
    f(8, static_cast<T&&>(t).t_stream_ref()...);
    f(9, static_cast<T&&>(t).t_sink_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftEnum> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
    f(1, static_cast<T&&>(t).elements_ref()...);
    f(2, static_cast<T&&>(t).structured_annotations_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftField> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).id_ref()...);
    f(1, static_cast<T&&>(t).type_ref()...);
    f(2, static_cast<T&&>(t).name_ref()...);
    f(3, static_cast<T&&>(t).is_optional_ref()...);
    f(4, static_cast<T&&>(t).structured_annotations_ref()...);
    f(5, static_cast<T&&>(t).unstructured_annotations_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftStruct> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
    f(1, static_cast<T&&>(t).fields_ref()...);
    f(2, static_cast<T&&>(t).is_union_ref()...);
    f(3, static_cast<T&&>(t).structured_annotations_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftException> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
    f(1, static_cast<T&&>(t).fields_ref()...);
    f(2, static_cast<T&&>(t).structured_annotations_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftFunction> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
    f(1, static_cast<T&&>(t).return_type_ref()...);
    f(2, static_cast<T&&>(t).arguments_ref()...);
    f(3, static_cast<T&&>(t).exceptions_ref()...);
    f(4, static_cast<T&&>(t).is_oneway_ref()...);
    f(5, static_cast<T&&>(t).structured_annotations_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftService> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
    f(1, static_cast<T&&>(t).functions_ref()...);
    f(2, static_cast<T&&>(t).parent_ref()...);
    f(3, static_cast<T&&>(t).structured_annotations_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftModuleContext> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftServiceContext> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).service_info_ref()...);
    f(1, static_cast<T&&>(t).module_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).enums_ref()...);
    f(1, static_cast<T&&>(t).structs_ref()...);
    f(2, static_cast<T&&>(t).exceptions_ref()...);
    f(3, static_cast<T&&>(t).services_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::metadata::ThriftServiceMetadataResponse> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).context_ref()...);
    f(1, static_cast<T&&>(t).metadata_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
