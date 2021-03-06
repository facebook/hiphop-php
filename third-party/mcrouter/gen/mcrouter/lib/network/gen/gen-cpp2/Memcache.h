/**
 * Autogenerated by Thrift for MemcacheService.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "mcrouter/lib/network/gen/gen-cpp2/MemcacheAsyncClient.h"
#include "mcrouter/lib/network/gen/gen-cpp2/MemcacheService_types.h"
#include "mcrouter/lib/network/gen/gen-cpp2/Common_types.h"
#include "mcrouter/lib/network/gen/gen-cpp2/Memcache_types.h"
#include "mcrouter/lib/network/gen/MemcacheMessages.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace facebook { namespace memcache { namespace thrift {

class MemcacheSvAsyncIf {
 public:
  virtual ~MemcacheSvAsyncIf() {}
  virtual void async_eb_mcAdd(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McAddReply>> callback, const facebook::memcache::McAddRequest& p_request) = 0;
  virtual void async_eb_mcAppend(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McAppendReply>> callback, const facebook::memcache::McAppendRequest& p_request) = 0;
  virtual void async_eb_mcCas(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McCasReply>> callback, const facebook::memcache::McCasRequest& p_request) = 0;
  virtual void async_eb_mcDecr(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McDecrReply>> callback, const facebook::memcache::McDecrRequest& p_request) = 0;
  virtual void async_eb_mcDelete(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McDeleteReply>> callback, const facebook::memcache::McDeleteRequest& p_request) = 0;
  virtual void async_eb_mcFlushAll(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McFlushAllReply>> callback, const facebook::memcache::McFlushAllRequest& p_request) = 0;
  virtual void async_eb_mcFlushRe(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McFlushReReply>> callback, const facebook::memcache::McFlushReRequest& p_request) = 0;
  virtual void async_eb_mcGat(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McGatReply>> callback, const facebook::memcache::McGatRequest& p_request) = 0;
  virtual void async_eb_mcGats(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McGatsReply>> callback, const facebook::memcache::McGatsRequest& p_request) = 0;
  virtual void async_eb_mcGet(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McGetReply>> callback, const facebook::memcache::McGetRequest& p_request) = 0;
  virtual void async_eb_mcGets(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McGetsReply>> callback, const facebook::memcache::McGetsRequest& p_request) = 0;
  virtual void async_eb_mcIncr(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McIncrReply>> callback, const facebook::memcache::McIncrRequest& p_request) = 0;
  virtual void async_eb_mcLeaseGet(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McLeaseGetReply>> callback, const facebook::memcache::McLeaseGetRequest& p_request) = 0;
  virtual void async_eb_mcLeaseSet(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McLeaseSetReply>> callback, const facebook::memcache::McLeaseSetRequest& p_request) = 0;
  virtual void async_eb_mcMetaget(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McMetagetReply>> callback, const facebook::memcache::McMetagetRequest& p_request) = 0;
  virtual void async_eb_mcPrepend(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McPrependReply>> callback, const facebook::memcache::McPrependRequest& p_request) = 0;
  virtual void async_eb_mcReplace(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McReplaceReply>> callback, const facebook::memcache::McReplaceRequest& p_request) = 0;
  virtual void async_eb_mcSet(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McSetReply>> callback, const facebook::memcache::McSetRequest& p_request) = 0;
  virtual void async_eb_mcTouch(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McTouchReply>> callback, const facebook::memcache::McTouchRequest& p_request) = 0;
  virtual void async_eb_mcVersion(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McVersionReply>> callback, const facebook::memcache::McVersionRequest& p_request) = 0;
};

class MemcacheAsyncProcessor;

class MemcacheSvIf : public MemcacheSvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef MemcacheAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;


  void async_eb_mcAdd(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McAddReply>> callback, const facebook::memcache::McAddRequest& p_request) override;
  void async_eb_mcAppend(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McAppendReply>> callback, const facebook::memcache::McAppendRequest& p_request) override;
  void async_eb_mcCas(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McCasReply>> callback, const facebook::memcache::McCasRequest& p_request) override;
  void async_eb_mcDecr(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McDecrReply>> callback, const facebook::memcache::McDecrRequest& p_request) override;
  void async_eb_mcDelete(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McDeleteReply>> callback, const facebook::memcache::McDeleteRequest& p_request) override;
  void async_eb_mcFlushAll(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McFlushAllReply>> callback, const facebook::memcache::McFlushAllRequest& p_request) override;
  void async_eb_mcFlushRe(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McFlushReReply>> callback, const facebook::memcache::McFlushReRequest& p_request) override;
  void async_eb_mcGat(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McGatReply>> callback, const facebook::memcache::McGatRequest& p_request) override;
  void async_eb_mcGats(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McGatsReply>> callback, const facebook::memcache::McGatsRequest& p_request) override;
  void async_eb_mcGet(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McGetReply>> callback, const facebook::memcache::McGetRequest& p_request) override;
  void async_eb_mcGets(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McGetsReply>> callback, const facebook::memcache::McGetsRequest& p_request) override;
  void async_eb_mcIncr(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McIncrReply>> callback, const facebook::memcache::McIncrRequest& p_request) override;
  void async_eb_mcLeaseGet(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McLeaseGetReply>> callback, const facebook::memcache::McLeaseGetRequest& p_request) override;
  void async_eb_mcLeaseSet(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McLeaseSetReply>> callback, const facebook::memcache::McLeaseSetRequest& p_request) override;
  void async_eb_mcMetaget(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McMetagetReply>> callback, const facebook::memcache::McMetagetRequest& p_request) override;
  void async_eb_mcPrepend(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McPrependReply>> callback, const facebook::memcache::McPrependRequest& p_request) override;
  void async_eb_mcReplace(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McReplaceReply>> callback, const facebook::memcache::McReplaceRequest& p_request) override;
  void async_eb_mcSet(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McSetReply>> callback, const facebook::memcache::McSetRequest& p_request) override;
  void async_eb_mcTouch(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McTouchReply>> callback, const facebook::memcache::McTouchRequest& p_request) override;
  void async_eb_mcVersion(std::unique_ptr<apache::thrift::HandlerCallback<facebook::memcache::McVersionReply>> callback, const facebook::memcache::McVersionRequest& p_request) override;
 private:
};

class MemcacheSvNull : public MemcacheSvIf {
 public:
};

class MemcacheAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  MemcacheSvIf* iface_;
 public:
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessor::ProcessFuncs<MemcacheAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFuncs>;
  static const MemcacheAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const MemcacheAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcAdd(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcAdd(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcAdd(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McAddReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcAdd(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcAppend(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcAppend(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcAppend(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McAppendReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcAppend(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcCas(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcCas(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcCas(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McCasReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcCas(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcDecr(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcDecr(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcDecr(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McDecrReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcDecr(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcDelete(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcDelete(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcDelete(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McDeleteReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcDelete(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcFlushAll(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcFlushAll(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcFlushAll(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McFlushAllReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcFlushAll(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcFlushRe(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcFlushRe(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcFlushRe(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McFlushReReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcFlushRe(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcGat(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcGat(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcGat(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McGatReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcGat(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcGats(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcGats(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcGats(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McGatsReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcGats(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcGet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcGet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcGet(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McGetReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcGet(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcGets(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcGets(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcGets(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McGetsReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcGets(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcIncr(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcIncr(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcIncr(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McIncrReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcIncr(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcLeaseGet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcLeaseGet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcLeaseGet(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McLeaseGetReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcLeaseGet(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcLeaseSet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcLeaseSet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcLeaseSet(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McLeaseSetReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcLeaseSet(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcMetaget(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcMetaget(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcMetaget(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McMetagetReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcMetaget(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcPrepend(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcPrepend(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcPrepend(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McPrependReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcPrepend(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcReplace(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcReplace(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcReplace(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McReplaceReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcReplace(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcSet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcSet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcSet(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McSetReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcSet(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcTouch(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcTouch(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcTouch(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McTouchReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcTouch(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_mcVersion(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_mcVersion(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::LegacySerializedResponse return_mcVersion(int32_t protoSeqId, apache::thrift::ContextStack* ctx, facebook::memcache::McVersionReply const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_mcVersion(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  MemcacheAsyncProcessor(MemcacheSvIf* iface) :
      iface_(iface) {}

  virtual ~MemcacheAsyncProcessor() {}
};

}}} // facebook::memcache::thrift
