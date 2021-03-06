/**
 * Autogenerated by Thrift for RpcMetadata.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "RpcMetadata_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::apache::thrift::ZlibCompressionCodecConfig> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::apache::thrift::ZstdCompressionCodecConfig> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::apache::thrift::CodecConfig> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).zlibConfig_ref()...);
    f(1, static_cast<T&&>(t).zstdConfig_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::CompressionConfig> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).codecConfig_ref()...);
    f(1, static_cast<T&&>(t).compressionSizeLimit_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::NegotiationParameters> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).compressionAlgos_ref()...);
    f(1, static_cast<T&&>(t).useStopTLS_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::InteractionCreate> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).interactionId_ref()...);
    f(1, static_cast<T&&>(t).interactionName_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::InteractionTerminate> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).interactionId_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::RequestRpcMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).protocol_ref()...);
    f(1, static_cast<T&&>(t).name_ref()...);
    f(2, static_cast<T&&>(t).kind_ref()...);
    f(3, static_cast<T&&>(t).seqId_ref()...);
    f(4, static_cast<T&&>(t).clientTimeoutMs_ref()...);
    f(5, static_cast<T&&>(t).queueTimeoutMs_ref()...);
    f(6, static_cast<T&&>(t).priority_ref()...);
    f(7, static_cast<T&&>(t).otherMetadata_ref()...);
    f(8, static_cast<T&&>(t).crc32c_ref()...);
    f(9, static_cast<T&&>(t).loadMetric_ref()...);
    f(10, static_cast<T&&>(t).compression_ref()...);
    f(11, static_cast<T&&>(t).compressionConfig_ref()...);
    f(12, static_cast<T&&>(t).interactionId_ref()...);
    f(13, static_cast<T&&>(t).interactionCreate_ref()...);
    f(14, static_cast<T&&>(t).clientId_ref()...);
    f(15, static_cast<T&&>(t).serviceTraceMeta_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::ErrorClassification> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).kind_ref()...);
    f(1, static_cast<T&&>(t).blame_ref()...);
    f(2, static_cast<T&&>(t).safety_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadResponseMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadDeclaredExceptionMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).errorClassification_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadProxyExceptionMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadProxiedExceptionMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadAppClientExceptionMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadAppServerExceptionMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadAppUnknownExceptionMetdata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).errorClassification_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadExceptionMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).declaredException_ref()...);
    f(1, static_cast<T&&>(t).proxyException_ref()...);
    f(2, static_cast<T&&>(t).DEPRECATED_proxiedException_ref()...);
    f(3, static_cast<T&&>(t).DEPRECATED_appClientException_ref()...);
    f(4, static_cast<T&&>(t).DEPRECATED_appServerException_ref()...);
    f(5, static_cast<T&&>(t).appUnknownException_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadExceptionMetadataBase> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_utf8_ref()...);
    f(1, static_cast<T&&>(t).what_utf8_ref()...);
    f(2, static_cast<T&&>(t).metadata_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::PayloadMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).responseMetadata_ref()...);
    f(1, static_cast<T&&>(t).exceptionMetadata_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::ProxiedPayloadMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::apache::thrift::ResponseRpcMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).protocol_ref()...);
    f(1, static_cast<T&&>(t).seqId_ref()...);
    f(2, static_cast<T&&>(t).otherMetadata_ref()...);
    f(3, static_cast<T&&>(t).load_ref()...);
    f(4, static_cast<T&&>(t).crc32c_ref()...);
    f(5, static_cast<T&&>(t).compression_ref()...);
    f(6, static_cast<T&&>(t).payloadMetadata_ref()...);
    f(7, static_cast<T&&>(t).proxiedPayloadMetadata_ref()...);
    f(8, static_cast<T&&>(t).streamId_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::ResponseRpcError> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_utf8_ref()...);
    f(1, static_cast<T&&>(t).what_utf8_ref()...);
    f(2, static_cast<T&&>(t).category_ref()...);
    f(3, static_cast<T&&>(t).code_ref()...);
    f(4, static_cast<T&&>(t).load_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::StreamRpcError> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).name_utf8_ref()...);
    f(1, static_cast<T&&>(t).what_utf8_ref()...);
    f(2, static_cast<T&&>(t).code_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::StreamPayloadMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).compression_ref()...);
    f(1, static_cast<T&&>(t).otherMetadata_ref()...);
    f(2, static_cast<T&&>(t).payloadMetadata_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::ClientMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).agent_ref()...);
    f(1, static_cast<T&&>(t).hostname_ref()...);
    f(2, static_cast<T&&>(t).otherMetadata_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::RequestSetupMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).opaque_ref()...);
    f(1, static_cast<T&&>(t).interfaceKind_ref()...);
    f(2, static_cast<T&&>(t).minVersion_ref()...);
    f(3, static_cast<T&&>(t).maxVersion_ref()...);
    f(4, static_cast<T&&>(t).dscpToReflect_ref()...);
    f(5, static_cast<T&&>(t).markToReflect_ref()...);
    f(6, static_cast<T&&>(t).clientMetadata_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::SetupResponse> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).version_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::HeadersPayloadContent> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).otherMetadata_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::StreamHeadersPush> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).streamId_ref()...);
    f(1, static_cast<T&&>(t).headersPayloadContent_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::DrainCompletePush> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).drainCompleteCode_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::ServerPushMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).setupResponse_ref()...);
    f(1, static_cast<T&&>(t).streamHeadersPush_ref()...);
    f(2, static_cast<T&&>(t).drainCompletePush_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::ClientPushMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).interactionTerminate_ref()...);
    f(1, static_cast<T&&>(t).streamHeadersPush_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::HeadersPayloadMetadata> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).compression_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
