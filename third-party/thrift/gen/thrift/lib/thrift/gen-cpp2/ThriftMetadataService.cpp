/**
 * Autogenerated by Thrift for metadata.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftMetadataService.h"
#include "ThriftMetadataService.tcc"
#include "metadata_metadata.h"
#include <thrift/lib/cpp2/gen/service_cpp.h>

namespace apache { namespace thrift { namespace metadata {
std::unique_ptr<apache::thrift::AsyncProcessor> ThriftMetadataServiceSvIf::getProcessor() {
  return std::make_unique<ThriftMetadataServiceAsyncProcessor>(this);
}

ThriftMetadataServiceSvIf::CreateMethodMetadataResult ThriftMetadataServiceSvIf::createMethodMetadata() {
  return ::apache::thrift::detail::ap::createMethodMetadataMap<ThriftMetadataServiceAsyncProcessor>();
}


void ThriftMetadataServiceSvIf::getThriftServiceMetadata(::apache::thrift::metadata::ThriftServiceMetadataResponse& /*_return*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("getThriftServiceMetadata");
}

folly::SemiFuture<std::unique_ptr<::apache::thrift::metadata::ThriftServiceMetadataResponse>> ThriftMetadataServiceSvIf::semifuture_getThriftServiceMetadata() {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_getThriftServiceMetadata.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  auto ret = std::make_unique<::apache::thrift::metadata::ThriftServiceMetadataResponse>();
  getThriftServiceMetadata(*ret);
  return folly::makeSemiFuture(std::move(ret));
}

folly::Future<std::unique_ptr<::apache::thrift::metadata::ThriftServiceMetadataResponse>> ThriftMetadataServiceSvIf::future_getThriftServiceMetadata() {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_getThriftServiceMetadata.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_getThriftServiceMetadata(), getInternalKeepAlive());
}

void ThriftMetadataServiceSvIf::async_tm_getThriftServiceMetadata(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr<::apache::thrift::metadata::ThriftServiceMetadataResponse>>> callback) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we set that up
  // for all cases.
  apache::thrift::detail::si::async_tm_prep(this, callback.get());
  auto invocationType = __fbthrift_invocation_getThriftServiceMetadata.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
        __fbthrift_invocation_getThriftServiceMetadata.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_getThriftServiceMetadata();
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_getThriftServiceMetadata();
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        ::apache::thrift::metadata::ThriftServiceMetadataResponse _return;
        getThriftServiceMetadata(_return);
        callback->result(_return);
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

void ThriftMetadataServiceSvNull::getThriftServiceMetadata(::apache::thrift::metadata::ThriftServiceMetadataResponse& /*_return*/) {}



const char* ThriftMetadataServiceAsyncProcessor::getServiceName() {
  return "ThriftMetadataService";
}

void ThriftMetadataServiceAsyncProcessor::getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  ::apache::thrift::detail::md::ServiceMetadata<ThriftMetadataServiceSvIf>::gen(*response.metadata_ref(), *response.context_ref());
}

void ThriftMetadataServiceAsyncProcessor::processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), protType, context, eb, tm);
}

void ThriftMetadataServiceAsyncProcessor::processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), methodMetadata, protType, context, eb, tm);
}

const ThriftMetadataServiceAsyncProcessor::ProcessMap& ThriftMetadataServiceAsyncProcessor::getOwnProcessMap() {
  return kOwnProcessMap_;
}

const ThriftMetadataServiceAsyncProcessor::ProcessMap ThriftMetadataServiceAsyncProcessor::kOwnProcessMap_ {
  {"getThriftServiceMetadata", {&ThriftMetadataServiceAsyncProcessor::setUpAndProcess_getThriftServiceMetadata<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>, &ThriftMetadataServiceAsyncProcessor::setUpAndProcess_getThriftServiceMetadata<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
};

}}} // apache::thrift::metadata
