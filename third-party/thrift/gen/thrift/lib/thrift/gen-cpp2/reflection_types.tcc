/**
 * Autogenerated by Thrift for /home/fbthrift/thrift/lib/thrift/reflection.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/lib/thrift/gen-cpp2/reflection_types.h"

#include <thrift/lib/cpp2/gen/module_types_tcc.h>

namespace apache { namespace thrift { namespace reflection {

}}} // apache::thrift::reflection
namespace std {

} // std


namespace apache {
namespace thrift {
namespace detail {

template <>
struct TccStructTraits<::apache::thrift::reflection::StructField> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};
template <>
struct TccStructTraits<::apache::thrift::reflection::DataType> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};
template <>
struct TccStructTraits<::apache::thrift::reflection::Schema> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift { namespace reflection {

template <class Protocol_>
void StructField::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_BOOL))) {
    goto _loop;
  }
_readField_isRequired:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, bool>::readWithContext(*iprot, this->isRequired, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.isRequired = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_I64))) {
    goto _loop;
  }
_readField_type:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::readWithContext(*iprot, this->type, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.type = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          3,
          apache::thrift::protocol::T_STRING))) {
    goto _loop;
  }
_readField_name:
  {
    
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::read(*iprot, this->name);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.name = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          3,
          4,
          apache::thrift::protocol::T_MAP))) {
    goto _loop;
  }
_readField_annotations:
  {
    _readState.beforeSubobject(iprot);
    
    this->annotations = std::unordered_map<::std::string, ::std::string>();
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::unordered_map<::std::string, ::std::string>>::read(*iprot, this->annotations);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.annotations = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          4,
          5,
          apache::thrift::protocol::T_I16))) {
    goto _loop;
  }
_readField_order:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int16_t>::readWithContext(*iprot, this->order, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.order = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          5,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

_loop:
  _readState.afterAdvanceFailure(iprot);
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<StructField>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_BOOL))) {
        goto _readField_isRequired;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I64))) {
        goto _readField_type;
      } else {
        goto _skip;
      }
    }
    case 3:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRING))) {
        goto _readField_name;
      } else {
        goto _skip;
      }
    }
    case 4:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_MAP))) {
        goto _readField_annotations;
      } else {
        goto _skip;
      }
    }
    case 5:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I16))) {
        goto _readField_order;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t StructField::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("StructField");
  xfer += prot_->serializedFieldSize("isRequired", apache::thrift::protocol::T_BOOL, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, bool>::serializedSize<false>(*prot_, this->isRequired);
  xfer += prot_->serializedFieldSize("type", apache::thrift::protocol::T_I64, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::serializedSize<false>(*prot_, this->type);
  xfer += prot_->serializedFieldSize("name", apache::thrift::protocol::T_STRING, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::serializedSize<false>(*prot_, this->name);
  if (this->annotations_ref().has_value()) {
    xfer += prot_->serializedFieldSize("annotations", apache::thrift::protocol::T_MAP, 4);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::unordered_map<::std::string, ::std::string>>::serializedSize<false>(*prot_, this->annotations);
  }
  xfer += prot_->serializedFieldSize("order", apache::thrift::protocol::T_I16, 5);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int16_t>::serializedSize<false>(*prot_, this->order);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t StructField::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("StructField");
  xfer += prot_->serializedFieldSize("isRequired", apache::thrift::protocol::T_BOOL, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, bool>::serializedSize<false>(*prot_, this->isRequired);
  xfer += prot_->serializedFieldSize("type", apache::thrift::protocol::T_I64, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::serializedSize<false>(*prot_, this->type);
  xfer += prot_->serializedFieldSize("name", apache::thrift::protocol::T_STRING, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::serializedSize<false>(*prot_, this->name);
  if (this->annotations_ref().has_value()) {
    xfer += prot_->serializedFieldSize("annotations", apache::thrift::protocol::T_MAP, 4);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::unordered_map<::std::string, ::std::string>>::serializedSize<false>(*prot_, this->annotations);
  }
  xfer += prot_->serializedFieldSize("order", apache::thrift::protocol::T_I16, 5);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int16_t>::serializedSize<false>(*prot_, this->order);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t StructField::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("StructField");
  xfer += prot_->writeFieldBegin("isRequired", apache::thrift::protocol::T_BOOL, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, bool>::write(*prot_, this->isRequired);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("type", apache::thrift::protocol::T_I64, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::write(*prot_, this->type);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::write(*prot_, this->name);
  xfer += prot_->writeFieldEnd();
  if (this->annotations_ref().has_value()) {
    xfer += prot_->writeFieldBegin("annotations", apache::thrift::protocol::T_MAP, 4);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::unordered_map<::std::string, ::std::string>>::write(*prot_, this->annotations);
    xfer += prot_->writeFieldEnd();
  }
  xfer += prot_->writeFieldBegin("order", apache::thrift::protocol::T_I16, 5);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int16_t>::write(*prot_, this->order);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void StructField::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t StructField::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t StructField::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t StructField::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void StructField::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t StructField::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t StructField::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t StructField::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::reflection
namespace apache { namespace thrift { namespace reflection {

template <class Protocol_>
void DataType::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_STRING))) {
    goto _loop;
  }
_readField_name:
  {
    
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::read(*iprot, this->name);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.name = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_MAP))) {
    goto _loop;
  }
_readField_fields:
  {
    _readState.beforeSubobject(iprot);
    
    this->fields = std::unordered_map<int16_t,  ::apache::thrift::reflection::StructField>();
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::unordered_map<int16_t,  ::apache::thrift::reflection::StructField>>::read(*iprot, this->fields);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.fields = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          3,
          apache::thrift::protocol::T_I64))) {
    goto _loop;
  }
_readField_mapKeyType:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::readWithContext(*iprot, this->mapKeyType, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.mapKeyType = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          3,
          4,
          apache::thrift::protocol::T_I64))) {
    goto _loop;
  }
_readField_valueType:
  {
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::readWithContext(*iprot, this->valueType, _readState);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.valueType = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          4,
          5,
          apache::thrift::protocol::T_MAP))) {
    goto _loop;
  }
_readField_enumValues:
  {
    _readState.beforeSubobject(iprot);
    
    this->enumValues = std::unordered_map<::std::string, int32_t>();
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, std::unordered_map<::std::string, int32_t>>::read(*iprot, this->enumValues);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.enumValues = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          5,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

_loop:
  _readState.afterAdvanceFailure(iprot);
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<DataType>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRING))) {
        goto _readField_name;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_MAP))) {
        goto _readField_fields;
      } else {
        goto _skip;
      }
    }
    case 3:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I64))) {
        goto _readField_mapKeyType;
      } else {
        goto _skip;
      }
    }
    case 4:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I64))) {
        goto _readField_valueType;
      } else {
        goto _skip;
      }
    }
    case 5:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_MAP))) {
        goto _readField_enumValues;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t DataType::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("DataType");
  xfer += prot_->serializedFieldSize("name", apache::thrift::protocol::T_STRING, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::serializedSize<false>(*prot_, this->name);
  if (this->fields_ref().has_value()) {
    xfer += prot_->serializedFieldSize("fields", apache::thrift::protocol::T_MAP, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::unordered_map<int16_t,  ::apache::thrift::reflection::StructField>>::serializedSize<false>(*prot_, this->fields);
  }
  if (this->mapKeyType_ref().has_value()) {
    xfer += prot_->serializedFieldSize("mapKeyType", apache::thrift::protocol::T_I64, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::serializedSize<false>(*prot_, this->mapKeyType);
  }
  if (this->valueType_ref().has_value()) {
    xfer += prot_->serializedFieldSize("valueType", apache::thrift::protocol::T_I64, 4);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::serializedSize<false>(*prot_, this->valueType);
  }
  if (this->enumValues_ref().has_value()) {
    xfer += prot_->serializedFieldSize("enumValues", apache::thrift::protocol::T_MAP, 5);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, std::unordered_map<::std::string, int32_t>>::serializedSize<false>(*prot_, this->enumValues);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t DataType::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("DataType");
  xfer += prot_->serializedFieldSize("name", apache::thrift::protocol::T_STRING, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::serializedSize<false>(*prot_, this->name);
  if (this->fields_ref().has_value()) {
    xfer += prot_->serializedFieldSize("fields", apache::thrift::protocol::T_MAP, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::unordered_map<int16_t,  ::apache::thrift::reflection::StructField>>::serializedSize<false>(*prot_, this->fields);
  }
  if (this->mapKeyType_ref().has_value()) {
    xfer += prot_->serializedFieldSize("mapKeyType", apache::thrift::protocol::T_I64, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::serializedSize<false>(*prot_, this->mapKeyType);
  }
  if (this->valueType_ref().has_value()) {
    xfer += prot_->serializedFieldSize("valueType", apache::thrift::protocol::T_I64, 4);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::serializedSize<false>(*prot_, this->valueType);
  }
  if (this->enumValues_ref().has_value()) {
    xfer += prot_->serializedFieldSize("enumValues", apache::thrift::protocol::T_MAP, 5);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, std::unordered_map<::std::string, int32_t>>::serializedSize<false>(*prot_, this->enumValues);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t DataType::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("DataType");
  xfer += prot_->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::string, ::std::string>::write(*prot_, this->name);
  xfer += prot_->writeFieldEnd();
  if (this->fields_ref().has_value()) {
    xfer += prot_->writeFieldBegin("fields", apache::thrift::protocol::T_MAP, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::unordered_map<int16_t,  ::apache::thrift::reflection::StructField>>::write(*prot_, this->fields);
    xfer += prot_->writeFieldEnd();
  }
  if (this->mapKeyType_ref().has_value()) {
    xfer += prot_->writeFieldBegin("mapKeyType", apache::thrift::protocol::T_I64, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::write(*prot_, this->mapKeyType);
    xfer += prot_->writeFieldEnd();
  }
  if (this->valueType_ref().has_value()) {
    xfer += prot_->writeFieldBegin("valueType", apache::thrift::protocol::T_I64, 4);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::integral, int64_t>::write(*prot_, this->valueType);
    xfer += prot_->writeFieldEnd();
  }
  if (this->enumValues_ref().has_value()) {
    xfer += prot_->writeFieldBegin("enumValues", apache::thrift::protocol::T_MAP, 5);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, std::unordered_map<::std::string, int32_t>>::write(*prot_, this->enumValues);
    xfer += prot_->writeFieldEnd();
  }
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void DataType::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t DataType::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t DataType::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t DataType::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void DataType::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t DataType::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t DataType::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t DataType::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::reflection
namespace apache { namespace thrift { namespace reflection {

template <class Protocol_>
void Schema::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_MAP))) {
    goto _loop;
  }
_readField_dataTypes:
  {
    _readState.beforeSubobject(iprot);
    
    this->dataTypes = std::unordered_map<int64_t,  ::apache::thrift::reflection::DataType>();
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::unordered_map<int64_t,  ::apache::thrift::reflection::DataType>>::read(*iprot, this->dataTypes);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.dataTypes = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_MAP))) {
    goto _loop;
  }
_readField_names:
  {
    _readState.beforeSubobject(iprot);
    
    this->names = std::unordered_map<::std::string, int64_t>();
    ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, std::unordered_map<::std::string, int64_t>>::read(*iprot, this->names);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    this->__isset.names = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    _readState.afterSubobject(iprot);
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

_loop:
  _readState.afterAdvanceFailure(iprot);
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<Schema>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_MAP))) {
        goto _readField_dataTypes;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_MAP))) {
        goto _readField_names;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t Schema::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Schema");
  xfer += prot_->serializedFieldSize("dataTypes", apache::thrift::protocol::T_MAP, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::unordered_map<int64_t,  ::apache::thrift::reflection::DataType>>::serializedSize<false>(*prot_, this->dataTypes);
  xfer += prot_->serializedFieldSize("names", apache::thrift::protocol::T_MAP, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, std::unordered_map<::std::string, int64_t>>::serializedSize<false>(*prot_, this->names);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Schema::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Schema");
  xfer += prot_->serializedFieldSize("dataTypes", apache::thrift::protocol::T_MAP, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::unordered_map<int64_t,  ::apache::thrift::reflection::DataType>>::serializedSize<false>(*prot_, this->dataTypes);
  xfer += prot_->serializedFieldSize("names", apache::thrift::protocol::T_MAP, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, std::unordered_map<::std::string, int64_t>>::serializedSize<false>(*prot_, this->names);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Schema::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("Schema");
  xfer += prot_->writeFieldBegin("dataTypes", apache::thrift::protocol::T_MAP, 1);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::unordered_map<int64_t,  ::apache::thrift::reflection::DataType>>::write(*prot_, this->dataTypes);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("names", apache::thrift::protocol::T_MAP, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::integral>, std::unordered_map<::std::string, int64_t>>::write(*prot_, this->names);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void Schema::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t Schema::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t Schema::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t Schema::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void Schema::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t Schema::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t Schema::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t Schema::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::reflection
