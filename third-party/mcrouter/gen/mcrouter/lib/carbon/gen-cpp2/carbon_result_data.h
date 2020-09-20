/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "mcrouter/lib/carbon/gen-cpp2/carbon_result_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::carbon::Result> {
  using type = ::carbon::Result;
  static constexpr const std::size_t size = 34;
  static constexpr const std::array<type, size> values = {{
    type::UNKNOWN,
    type::DELETED,
    type::TOUCHED,
    type::FOUND,
    type::FOUNDSTALE,
    type::NOTFOUND,
    type::NOTFOUNDHOT,
    type::NOTSTORED,
    type::STALESTORED,
    type::OK,
    type::STORED,
    type::EXISTS,
    type::OOO,
    type::TIMEOUT,
    type::CONNECT_TIMEOUT,
    type::CONNECT_ERROR,
    type::BUSY,
    type::RES_TRY_AGAIN,
    type::SHUTDOWN,
    type::TKO,
    type::BAD_COMMAND,
    type::BAD_KEY,
    type::BAD_FLAGS,
    type::BAD_EXPTIME,
    type::BAD_LEASE_ID,
    type::BAD_CAS_ID,
    type::BAD_VALUE,
    type::ABORTED,
    type::CLIENT_ERROR,
    type::LOCAL_ERROR,
    type::REMOTE_ERROR,
    type::WAITING,
    type::DEADLINE_EXCEEDED,
    type::NUM_RESULTS,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "UNKNOWN",
    "DELETED",
    "TOUCHED",
    "FOUND",
    "FOUNDSTALE",
    "NOTFOUND",
    "NOTFOUNDHOT",
    "NOTSTORED",
    "STALESTORED",
    "OK",
    "STORED",
    "EXISTS",
    "OOO",
    "TIMEOUT",
    "CONNECT_TIMEOUT",
    "CONNECT_ERROR",
    "BUSY",
    "RES_TRY_AGAIN",
    "SHUTDOWN",
    "TKO",
    "BAD_COMMAND",
    "BAD_KEY",
    "BAD_FLAGS",
    "BAD_EXPTIME",
    "BAD_LEASE_ID",
    "BAD_CAS_ID",
    "BAD_VALUE",
    "ABORTED",
    "CLIENT_ERROR",
    "LOCAL_ERROR",
    "REMOTE_ERROR",
    "WAITING",
    "DEADLINE_EXCEEDED",
    "NUM_RESULTS",
  }};
};

}} // apache::thrift
