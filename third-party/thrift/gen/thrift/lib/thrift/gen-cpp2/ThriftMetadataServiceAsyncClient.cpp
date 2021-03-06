/**
 * Autogenerated by Thrift for metadata.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "ThriftMetadataServiceAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace apache { namespace thrift { namespace metadata {
typedef apache::thrift::ThriftPresult<false> ThriftMetadataService_getThriftServiceMetadata_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::apache::thrift::metadata::ThriftServiceMetadataResponse*>> ThriftMetadataService_getThriftServiceMetadata_presult;

template <typename Protocol_>
void ThriftMetadataServiceAsyncClient::getThriftServiceMetadataT(Protocol_* prot, const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback) {

  ThriftMetadataService_getThriftServiceMetadata_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "getThriftServiceMetadata",
                ::apache::thrift::FunctionQualifier::Unspecified);
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, rpcOptions, std::move(callback), contextStack, std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), writer, sizer);

}



void ThriftMetadataServiceAsyncClient::getThriftServiceMetadata(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  getThriftServiceMetadata(rpcOptions, std::move(callback));
}

void ThriftMetadataServiceAsyncClient::getThriftServiceMetadata(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto [ctx, header] = getThriftServiceMetadataCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto* contextStack = ctx.get();
  if (callback) {
    callbackContext.ctx = std::move(ctx);
  }
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  getThriftServiceMetadataImpl(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback));
}

void ThriftMetadataServiceAsyncClient::getThriftServiceMetadataImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      getThriftServiceMetadataT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      getThriftServiceMetadataT(&writer, rpcOptions, std::move(header), contextStack, std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> ThriftMetadataServiceAsyncClient::getThriftServiceMetadataCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      getServiceName(),
      "ThriftMetadataService.getThriftServiceMetadata",
      *header);

  return {std::move(ctx), std::move(header)};
}

void ThriftMetadataServiceAsyncClient::sync_getThriftServiceMetadata(::apache::thrift::metadata::ThriftServiceMetadataResponse& _return) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_getThriftServiceMetadata(rpcOptions, _return);
}

void ThriftMetadataServiceAsyncClient::sync_getThriftServiceMetadata(apache::thrift::RpcOptions& rpcOptions, ::apache::thrift::metadata::ThriftServiceMetadataResponse& _return) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto [ctx, header] = getThriftServiceMetadataCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  getThriftServiceMetadataImpl(rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
  callback.waitUntilDone(evb);

  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctx));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      recv_getThriftServiceMetadata(_return, returnState);
  });
}


folly::Future<::apache::thrift::metadata::ThriftServiceMetadataResponse> ThriftMetadataServiceAsyncClient::future_getThriftServiceMetadata() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_getThriftServiceMetadata(rpcOptions);
}

folly::SemiFuture<::apache::thrift::metadata::ThriftServiceMetadataResponse> ThriftMetadataServiceAsyncClient::semifuture_getThriftServiceMetadata() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_getThriftServiceMetadata(rpcOptions);
}

folly::Future<::apache::thrift::metadata::ThriftServiceMetadataResponse> ThriftMetadataServiceAsyncClient::future_getThriftServiceMetadata(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<::apache::thrift::metadata::ThriftServiceMetadataResponse> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::apache::thrift::metadata::ThriftServiceMetadataResponse>>(std::move(promise), recv_wrapped_getThriftServiceMetadata, channel_);
  getThriftServiceMetadata(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<::apache::thrift::metadata::ThriftServiceMetadataResponse> ThriftMetadataServiceAsyncClient::semifuture_getThriftServiceMetadata(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_getThriftServiceMetadata, channel_);
  auto callback = std::move(callbackAndFuture.first);
  getThriftServiceMetadata(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<::apache::thrift::metadata::ThriftServiceMetadataResponse, std::unique_ptr<apache::thrift::transport::THeader>>> ThriftMetadataServiceAsyncClient::header_future_getThriftServiceMetadata(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<::apache::thrift::metadata::ThriftServiceMetadataResponse, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<::apache::thrift::metadata::ThriftServiceMetadataResponse>>(std::move(promise), recv_wrapped_getThriftServiceMetadata, channel_);
  getThriftServiceMetadata(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<std::pair<::apache::thrift::metadata::ThriftServiceMetadataResponse, std::unique_ptr<apache::thrift::transport::THeader>>> ThriftMetadataServiceAsyncClient::header_semifuture_getThriftServiceMetadata(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_getThriftServiceMetadata, channel_);
  auto callback = std::move(callbackAndFuture.first);
  getThriftServiceMetadata(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void ThriftMetadataServiceAsyncClient::getThriftServiceMetadata(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  getThriftServiceMetadata(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper ThriftMetadataServiceAsyncClient::recv_wrapped_getThriftServiceMetadata(::apache::thrift::metadata::ThriftServiceMetadataResponse& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ThriftMetadataService_getThriftServiceMetadata_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void ThriftMetadataServiceAsyncClient::recv_getThriftServiceMetadata(::apache::thrift::metadata::ThriftServiceMetadataResponse& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_getThriftServiceMetadata(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void ThriftMetadataServiceAsyncClient::recv_instance_getThriftServiceMetadata(::apache::thrift::metadata::ThriftServiceMetadataResponse& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_getThriftServiceMetadata(_return, state);
}

folly::exception_wrapper ThriftMetadataServiceAsyncClient::recv_instance_wrapped_getThriftServiceMetadata(::apache::thrift::metadata::ThriftServiceMetadataResponse& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_getThriftServiceMetadata(_return, state);
}


}}} // apache::thrift::metadata
