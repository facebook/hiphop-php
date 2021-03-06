/**
 * Autogenerated by Thrift for frozen.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>


#include "folly/sorted_vector_types.h"

namespace apache {
namespace thrift {
namespace tag {
struct layoutId;
struct offset;
struct size;
struct bits;
struct fields;
struct typeName;
struct fileVersion;
struct relaxTypeChecks;
struct layouts;
struct rootLayout;
} // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_layoutId
#define APACHE_THRIFT_ACCESSOR_layoutId
APACHE_THRIFT_DEFINE_ACCESSOR(layoutId);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_offset
#define APACHE_THRIFT_ACCESSOR_offset
APACHE_THRIFT_DEFINE_ACCESSOR(offset);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_size
#define APACHE_THRIFT_ACCESSOR_size
APACHE_THRIFT_DEFINE_ACCESSOR(size);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_bits
#define APACHE_THRIFT_ACCESSOR_bits
APACHE_THRIFT_DEFINE_ACCESSOR(bits);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_fields
#define APACHE_THRIFT_ACCESSOR_fields
APACHE_THRIFT_DEFINE_ACCESSOR(fields);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_typeName
#define APACHE_THRIFT_ACCESSOR_typeName
APACHE_THRIFT_DEFINE_ACCESSOR(typeName);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_fileVersion
#define APACHE_THRIFT_ACCESSOR_fileVersion
APACHE_THRIFT_DEFINE_ACCESSOR(fileVersion);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_relaxTypeChecks
#define APACHE_THRIFT_ACCESSOR_relaxTypeChecks
APACHE_THRIFT_DEFINE_ACCESSOR(relaxTypeChecks);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_layouts
#define APACHE_THRIFT_ACCESSOR_layouts
APACHE_THRIFT_DEFINE_ACCESSOR(layouts);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_rootLayout
#define APACHE_THRIFT_ACCESSOR_rootLayout
APACHE_THRIFT_DEFINE_ACCESSOR(rootLayout);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums

// END declare_enums
// BEGIN forward_declare
namespace apache { namespace thrift { namespace frozen { namespace schema {
class Field;
class Layout;
class Schema;
}}}} // apache::thrift::frozen::schema
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
namespace apache { namespace thrift { namespace frozen { namespace schema {
#ifndef SWIG
using ::apache::thrift::detail::operator!=;
using ::apache::thrift::detail::operator>;
using ::apache::thrift::detail::operator<=;
using ::apache::thrift::detail::operator>=;
#endif

class Field final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = Field;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Field() :
      layoutId(0),
      offset(static_cast<int16_t>(0)) {
  }
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Field(apache::thrift::FragileConstructor, ::std::int16_t layoutId__arg, ::std::int16_t offset__arg);

  Field(Field&&) = default;

  Field(const Field&) = default;


  Field& operator=(Field&&) = default;

  Field& operator=(const Field&) = default;
  void __clear();
 private:
  ::std::int16_t layoutId;
 private:
  ::std::int16_t offset;

 private:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool layoutId;
    bool offset;
  } __isset = {};

 public:

  bool operator==(const Field&) const;
  bool operator<(const Field&) const;

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> layoutId_ref() const& {
    return {this->layoutId, __isset.layoutId};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> layoutId_ref() const&& {
    return {std::move(this->layoutId), __isset.layoutId};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> layoutId_ref() & {
    return {this->layoutId, __isset.layoutId};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> layoutId_ref() && {
    return {std::move(this->layoutId), __isset.layoutId};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> offset_ref() const& {
    return {this->offset, __isset.offset};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> offset_ref() const&& {
    return {std::move(this->offset), __isset.offset};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> offset_ref() & {
    return {this->offset, __isset.offset};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> offset_ref() && {
    return {std::move(this->offset), __isset.offset};
  }

  ::std::int16_t get_layoutId() const {
    return layoutId;
  }

  [[deprecated("Use `FOO.layoutId_ref() = BAR;` instead of `FOO.set_layoutId(BAR);`")]]
  ::std::int16_t& set_layoutId(::std::int16_t layoutId_) {
    layoutId = layoutId_;
    __isset.layoutId = true;
    return layoutId;
  }

  ::std::int16_t get_offset() const {
    return offset;
  }

  [[deprecated("Use `FOO.offset_ref() = BAR;` instead of `FOO.set_offset(BAR);`")]]
  ::std::int16_t& set_offset(::std::int16_t offset_) {
    offset = offset_;
    __isset.offset = true;
    return offset;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<Field>;
  friend void swap(Field& a, Field& b);
};

template <class Protocol_>
uint32_t Field::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}}}} // apache::thrift::frozen::schema
namespace apache { namespace thrift { namespace frozen { namespace schema {
#ifndef SWIG
using ::apache::thrift::detail::operator!=;
using ::apache::thrift::detail::operator>;
using ::apache::thrift::detail::operator<=;
using ::apache::thrift::detail::operator>=;
#endif

class Layout final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = Layout;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Layout() :
      size(0),
      bits(static_cast<int16_t>(0)) {
  }
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Layout(apache::thrift::FragileConstructor, ::std::int32_t size__arg, ::std::int16_t bits__arg, folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field> fields__arg, ::std::string typeName__arg);

  Layout(Layout&&) noexcept;

  Layout(const Layout& src);


  Layout& operator=(Layout&&) noexcept;
  Layout& operator=(const Layout& src);
  void __clear();
 private:
  ::std::int32_t size;
 private:
  ::std::int16_t bits;
 private:
  folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field> fields;
 private:
  ::std::string typeName;

 private:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool size;
    bool bits;
    bool fields;
    bool typeName;
  } __isset = {};

 public:

  bool operator==(const Layout&) const;
  bool operator<(const Layout&) const;

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> size_ref() const& {
    return {this->size, __isset.size};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> size_ref() const&& {
    return {std::move(this->size), __isset.size};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> size_ref() & {
    return {this->size, __isset.size};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> size_ref() && {
    return {std::move(this->size), __isset.size};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> bits_ref() const& {
    return {this->bits, __isset.bits};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> bits_ref() const&& {
    return {std::move(this->bits), __isset.bits};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> bits_ref() & {
    return {this->bits, __isset.bits};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> bits_ref() && {
    return {std::move(this->bits), __isset.bits};
  }

  template <typename..., typename T = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> fields_ref() const& {
    return {this->fields, __isset.fields};
  }

  template <typename..., typename T = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> fields_ref() const&& {
    return {std::move(this->fields), __isset.fields};
  }

  template <typename..., typename T = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> fields_ref() & {
    return {this->fields, __isset.fields};
  }

  template <typename..., typename T = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> fields_ref() && {
    return {std::move(this->fields), __isset.fields};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> typeName_ref() const& {
    return {this->typeName, __isset.typeName};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> typeName_ref() const&& {
    return {std::move(this->typeName), __isset.typeName};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> typeName_ref() & {
    return {this->typeName, __isset.typeName};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> typeName_ref() && {
    return {std::move(this->typeName), __isset.typeName};
  }

  ::std::int32_t get_size() const {
    return size;
  }

  [[deprecated("Use `FOO.size_ref() = BAR;` instead of `FOO.set_size(BAR);`")]]
  ::std::int32_t& set_size(::std::int32_t size_) {
    size = size_;
    __isset.size = true;
    return size;
  }

  ::std::int16_t get_bits() const {
    return bits;
  }

  [[deprecated("Use `FOO.bits_ref() = BAR;` instead of `FOO.set_bits(BAR);`")]]
  ::std::int16_t& set_bits(::std::int16_t bits_) {
    bits = bits_;
    __isset.bits = true;
    return bits;
  }
  const folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field>& get_fields() const&;
  folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field> get_fields() &&;

  template <typename T_Layout_fields_struct_setter = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field>>
  [[deprecated("Use `FOO.fields_ref() = BAR;` instead of `FOO.set_fields(BAR);`")]]
  folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Field>& set_fields(T_Layout_fields_struct_setter&& fields_) {
    fields = std::forward<T_Layout_fields_struct_setter>(fields_);
    __isset.fields = true;
    return fields;
  }

  const ::std::string& get_typeName() const& {
    return typeName;
  }

  ::std::string get_typeName() && {
    return std::move(typeName);
  }

  template <typename T_Layout_typeName_struct_setter = ::std::string>
  [[deprecated("Use `FOO.typeName_ref() = BAR;` instead of `FOO.set_typeName(BAR);`")]]
  ::std::string& set_typeName(T_Layout_typeName_struct_setter&& typeName_) {
    typeName = std::forward<T_Layout_typeName_struct_setter>(typeName_);
    __isset.typeName = true;
    return typeName;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<Layout>;
  friend void swap(Layout& a, Layout& b);
};

template <class Protocol_>
uint32_t Layout::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}}}} // apache::thrift::frozen::schema
namespace apache { namespace thrift { namespace frozen { namespace schema {
#ifndef SWIG
using ::apache::thrift::detail::operator!=;
using ::apache::thrift::detail::operator>;
using ::apache::thrift::detail::operator<=;
using ::apache::thrift::detail::operator>=;
#endif

class Schema final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = Schema;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Schema() :
      fileVersion(0),
      relaxTypeChecks(0),
      rootLayout(static_cast<int16_t>(0)) {
  }
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Schema(apache::thrift::FragileConstructor, ::std::int32_t fileVersion__arg, bool relaxTypeChecks__arg, folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout> layouts__arg, ::std::int16_t rootLayout__arg);

  Schema(Schema&&) noexcept;

  Schema(const Schema& src);


  Schema& operator=(Schema&&) noexcept;
  Schema& operator=(const Schema& src);
  void __clear();
 private:
  ::std::int32_t fileVersion;
 private:
  bool relaxTypeChecks;
 private:
  folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout> layouts;
 private:
  ::std::int16_t rootLayout;

 private:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool fileVersion;
    bool relaxTypeChecks;
    bool layouts;
    bool rootLayout;
  } __isset = {};

 public:

  bool operator==(const Schema&) const;
  bool operator<(const Schema&) const;

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> fileVersion_ref() const& {
    return {this->fileVersion, __isset.fileVersion};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> fileVersion_ref() const&& {
    return {std::move(this->fileVersion), __isset.fileVersion};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> fileVersion_ref() & {
    return {this->fileVersion, __isset.fileVersion};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> fileVersion_ref() && {
    return {std::move(this->fileVersion), __isset.fileVersion};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> relaxTypeChecks_ref() const& {
    return {this->relaxTypeChecks, __isset.relaxTypeChecks};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> relaxTypeChecks_ref() const&& {
    return {std::move(this->relaxTypeChecks), __isset.relaxTypeChecks};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> relaxTypeChecks_ref() & {
    return {this->relaxTypeChecks, __isset.relaxTypeChecks};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> relaxTypeChecks_ref() && {
    return {std::move(this->relaxTypeChecks), __isset.relaxTypeChecks};
  }

  template <typename..., typename T = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> layouts_ref() const& {
    return {this->layouts, __isset.layouts};
  }

  template <typename..., typename T = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> layouts_ref() const&& {
    return {std::move(this->layouts), __isset.layouts};
  }

  template <typename..., typename T = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> layouts_ref() & {
    return {this->layouts, __isset.layouts};
  }

  template <typename..., typename T = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> layouts_ref() && {
    return {std::move(this->layouts), __isset.layouts};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> rootLayout_ref() const& {
    return {this->rootLayout, __isset.rootLayout};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> rootLayout_ref() const&& {
    return {std::move(this->rootLayout), __isset.rootLayout};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> rootLayout_ref() & {
    return {this->rootLayout, __isset.rootLayout};
  }

  template <typename..., typename T = ::std::int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> rootLayout_ref() && {
    return {std::move(this->rootLayout), __isset.rootLayout};
  }

  ::std::int32_t get_fileVersion() const {
    return fileVersion;
  }

  [[deprecated("Use `FOO.fileVersion_ref() = BAR;` instead of `FOO.set_fileVersion(BAR);`")]]
  ::std::int32_t& set_fileVersion(::std::int32_t fileVersion_) {
    fileVersion = fileVersion_;
    __isset.fileVersion = true;
    return fileVersion;
  }

  bool get_relaxTypeChecks() const {
    return relaxTypeChecks;
  }

  [[deprecated("Use `FOO.relaxTypeChecks_ref() = BAR;` instead of `FOO.set_relaxTypeChecks(BAR);`")]]
  bool& set_relaxTypeChecks(bool relaxTypeChecks_) {
    relaxTypeChecks = relaxTypeChecks_;
    __isset.relaxTypeChecks = true;
    return relaxTypeChecks;
  }
  const folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout>& get_layouts() const&;
  folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout> get_layouts() &&;

  template <typename T_Schema_layouts_struct_setter = folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout>>
  [[deprecated("Use `FOO.layouts_ref() = BAR;` instead of `FOO.set_layouts(BAR);`")]]
  folly::sorted_vector_map<::std::int16_t, ::apache::thrift::frozen::schema::Layout>& set_layouts(T_Schema_layouts_struct_setter&& layouts_) {
    layouts = std::forward<T_Schema_layouts_struct_setter>(layouts_);
    __isset.layouts = true;
    return layouts;
  }

  ::std::int16_t get_rootLayout() const {
    return rootLayout;
  }

  [[deprecated("Use `FOO.rootLayout_ref() = BAR;` instead of `FOO.set_rootLayout(BAR);`")]]
  ::std::int16_t& set_rootLayout(::std::int16_t rootLayout_) {
    rootLayout = rootLayout_;
    __isset.rootLayout = true;
    return rootLayout;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<Schema>;
  friend void swap(Schema& a, Schema& b);
};

template <class Protocol_>
uint32_t Schema::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}}}} // apache::thrift::frozen::schema
THRIFT_IGNORE_ISSET_USE_WARNING_END
