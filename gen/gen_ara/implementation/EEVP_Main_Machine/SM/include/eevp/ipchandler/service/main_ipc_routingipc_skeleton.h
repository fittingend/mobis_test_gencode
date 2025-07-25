///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// Copyright, 2021 PopcornSAR Co., Ltd. All rights reserved.                                              
/// This software is copyright protected and proprietary to PopcornSAR Co., Ltd.                           
/// PopcornSAR Co., Ltd. grants to you only those rights as set out in the license conditions.             
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AUTOSAR VERSION                   : R20-11
/// GENERATED BY                      : PARA, ARA::COM Generator
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GENERATED FILE NAME               : main_ipc_routingipc_skeleton.h
/// SERVICE INTERFACE NAME            : Main_IPC_RoutingIPC
/// GENERATED DATE                    : 2025-02-11 11:52:31
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_COM_GEN_SERVICE_INTERFACE_MAIN_IPC_ROUTINGIPC_SKELETON_H
#define PARA_COM_GEN_SERVICE_INTERFACE_MAIN_IPC_ROUTINGIPC_SKELETON_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_01004}
#include "main_ipc_routingipc_common.h"
#include "para/com/skeleton/skeleton_interface.h"
/// @uptrace{SWS_CM_01005}
namespace eevp
{
namespace ipchandler
{
namespace service
{
/// @uptrace{SWS_CM_01006}
namespace skeleton
{
class Main_IPC_RoutingIPCSkeleton;
/// @uptrace{SWS_CM_01009}
namespace events
{
/// @uptrace{SWS_CM_00003}
class PeriodicSystemInfo
{
public:
    /// @brief Type alias for type of event data
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using SampleType = eevp::ipchandler::type::PowerState;
    /// @brief Constructor
    explicit PeriodicSystemInfo(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~PeriodicSystemInfo() = default;
    /// @brief Delete copy constructor
    PeriodicSystemInfo(const PeriodicSystemInfo& other) = delete;
    /// @brief Delete copy assignment
    PeriodicSystemInfo& operator=(const PeriodicSystemInfo& other) = delete;
    /// @brief Move constructor
    PeriodicSystemInfo(PeriodicSystemInfo&& other) noexcept : mInterface(other.mInterface)
    {
    }
    /// @brief Move assignment
    PeriodicSystemInfo& operator=(PeriodicSystemInfo&& other) noexcept
    {
        mInterface = other.mInterface;
        return *this;
    }
    /// @brief Send event with data to subscribing service consumers
    /// @uptrace{SWS_CM_90437}
    ara::core::Result<void> Send(const SampleType& data)
    {
        para::serializer::Serializer serializer{};
        serializer.write(data);
        auto payload = serializer.ensure();
        return mInterface->SendEvent(kCallSign, payload);
    }
    /// @brief Returns unique pointer about SampleType
    /// @uptrace{SWS_CM_90438}
    ara::core::Result<ara::com::SampleAllocateePtr<SampleType>> Allocate()
    {
        return std::make_unique<SampleType>();
    }
    
private:
    para::com::SkeletonInterface* mInterface;
    const std::string kCallSign = {"PeriodicSystemInfo"};
};
/// @uptrace{SWS_CM_00003}
class SystemControlRequest
{
public:
    /// @brief Type alias for type of event data
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using SampleType = eevp::ipchandler::type::SysCtrlReq;
    /// @brief Constructor
    explicit SystemControlRequest(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~SystemControlRequest() = default;
    /// @brief Delete copy constructor
    SystemControlRequest(const SystemControlRequest& other) = delete;
    /// @brief Delete copy assignment
    SystemControlRequest& operator=(const SystemControlRequest& other) = delete;
    /// @brief Move constructor
    SystemControlRequest(SystemControlRequest&& other) noexcept : mInterface(other.mInterface)
    {
    }
    /// @brief Move assignment
    SystemControlRequest& operator=(SystemControlRequest&& other) noexcept
    {
        mInterface = other.mInterface;
        return *this;
    }
    /// @brief Send event with data to subscribing service consumers
    /// @uptrace{SWS_CM_90437}
    ara::core::Result<void> Send(const SampleType& data)
    {
        para::serializer::Serializer serializer{};
        serializer.write(data);
        auto payload = serializer.ensure();
        return mInterface->SendEvent(kCallSign, payload);
    }
    /// @brief Returns unique pointer about SampleType
    /// @uptrace{SWS_CM_90438}
    ara::core::Result<ara::com::SampleAllocateePtr<SampleType>> Allocate()
    {
        return std::make_unique<SampleType>();
    }
    
private:
    para::com::SkeletonInterface* mInterface;
    const std::string kCallSign = {"SystemControlRequest"};
};
} /// namespace events
/// @uptrace{SWS_CM_01031}
namespace fields
{
} /// namespace fields
/// @uptrace{SWS_CM_00002}
class Main_IPC_RoutingIPCSkeleton
{
public:
    /// @uptrace{SWS_CM_00191}
    struct ASMInfoRequestOutput
    {
    };
    struct GetOneTimeSystemInfoOutput
    {
        eevp::ipchandler::type::OneTimeSysInfo info;
    };
    struct SetAPSystemInfoOutput
    {
    };
    struct SystemControlResponseOutput
    {
    };
    /// @brief Constructor
    /// @uptrace{SWS_CM_00002, SWS_CM_00152}
    Main_IPC_RoutingIPCSkeleton(ara::core::InstanceSpecifier instanceSpec, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
        : mInterface(std::make_unique<para::com::SkeletonInterface>(instanceSpec, mode))
        , PeriodicSystemInfo(mInterface.get())
        , SystemControlRequest(mInterface.get())
    {
        mInterface->SetMethodCallHandler(kASMInfoRequestCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleASMInfoRequest(data, token);
        });
        mInterface->SetMethodCallHandler(kGetOneTimeSystemInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleGetOneTimeSystemInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kSetAPSystemInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleSetAPSystemInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kSystemControlResponseCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleSystemControlResponse(data, token);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
    }
    /// @brief Destructor
    virtual ~Main_IPC_RoutingIPCSkeleton() = default;
    /// @brief Delete copy constructor
    /// @uptrace{SWS_CM_00134}
    Main_IPC_RoutingIPCSkeleton(const Main_IPC_RoutingIPCSkeleton& other) = delete;
    /// @brief Delete copy assignment
    /// @uptrace{SWS_CM_00134}
    Main_IPC_RoutingIPCSkeleton& operator=(const Main_IPC_RoutingIPCSkeleton& other) = delete;
    /// @brief Move constructor
    /// @uptrace{SWS_CM_00135}
    Main_IPC_RoutingIPCSkeleton(Main_IPC_RoutingIPCSkeleton&& other) noexcept
        : mInterface(std::move(other.mInterface))
        , PeriodicSystemInfo(std::move(other.PeriodicSystemInfo))
        , SystemControlRequest(std::move(other.SystemControlRequest))
    {
        mInterface->SetMethodCallHandler(kASMInfoRequestCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleASMInfoRequest(data, token);
        });
        mInterface->SetMethodCallHandler(kGetOneTimeSystemInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleGetOneTimeSystemInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kSetAPSystemInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleSetAPSystemInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kSystemControlResponseCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleSystemControlResponse(data, token);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
        other.mInterface.reset();
    }
    /// @brief Move assignment
    /// @uptrace{SWS_CM_00135}
    Main_IPC_RoutingIPCSkeleton& operator=(Main_IPC_RoutingIPCSkeleton&& other) noexcept
    {
        mInterface = std::move(other.mInterface);
        PeriodicSystemInfo = std::move(other.PeriodicSystemInfo);
        SystemControlRequest = std::move(other.SystemControlRequest);
        mInterface->SetMethodCallHandler(kASMInfoRequestCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleASMInfoRequest(data, token);
        });
        mInterface->SetMethodCallHandler(kGetOneTimeSystemInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleGetOneTimeSystemInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kSetAPSystemInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleSetAPSystemInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kSystemControlResponseCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleSystemControlResponse(data, token);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
        other.mInterface.reset();
        return *this;
    }
    /// @brief Send "OfferService" message to Communication Management
    /// @uptrace{SWS_CM_00101}
    ara::core::Result<void> OfferService()
    {
        return mInterface->OfferService();
    }
    /// @brief Send "StopOfferService" message to Communication Management
    /// @uptrace{SWS_CM_00111}
    void StopOfferService()
    {
        mInterface->StopOfferService();
    }
    /// @brief Allows the implementation providing the service method to trigger the execution of the next service consumer method call at a specific point of time
    ///        if the processing mode is set to kPoll.
    /// @note This function requires that ara::com::MethodCallProcessingMode is configured as kPoll by constructor
    /// @uptrace{SWS_CM_00199}
    ara::core::Future<bool> ProcessNextMethodCall()
    {
        ara::core::Promise<bool> promise{};
        auto ret = mInterface->ProcessNextMethodCall();
        if (ret.HasValue())
        {
            promise.set_value(ret.Value());
        }
        else
        {
            promise.SetError(ret.Error());
        }
        return promise.get_future();
    }
    /// @brief In case the call to E2E_check indicated a failed E2E check of the request message, the server application can get notified via an E2E error handler.
    /// @uptrace{SWS_CM_10470}
    virtual void E2EErrorHandler(const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter)
    {
    }
    
private:
    std::unique_ptr<para::com::SkeletonInterface> mInterface;
    
public:
    /// @brief Event, PeriodicSystemInfo
    events::PeriodicSystemInfo PeriodicSystemInfo;
    /// @brief Event, SystemControlRequest
    events::SystemControlRequest SystemControlRequest;
    /// @brief Method, ASMInfoRequest
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<ASMInfoRequestOutput> ASMInfoRequest() = 0;
    /// @brief Method, GetOneTimeSystemInfo
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<GetOneTimeSystemInfoOutput> GetOneTimeSystemInfo() = 0;
    /// @brief Method, SetAPSystemInfo
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<SetAPSystemInfoOutput> SetAPSystemInfo(const eevp::type::String& apVersion) = 0;
    /// @brief Method, SystemControlResponse
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<SystemControlResponseOutput> SystemControlResponse(const eevp::ipchandler::type::SysCtrlResp& response) = 0;
    
private:
    void HandleASMInfoRequest(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        auto future = ASMInfoRequest();
        auto result = future.GetResult();
        if (result.HasValue())
        {
            retResult = 0;
        }
        else
        {
            ara::core::ErrorDomain::IdType domainId = result.Error().Domain().Id();
            ara::core::ErrorDomain::CodeType errorCode = result.Error().Value();
            para::serializer::Serializer serializer{};
            serializer.write(0, true, 0, domainId);
            serializer.write(0, true, 0, errorCode);
            retData = serializer.ensure();
            retResult = 1;
        }
        mInterface->ReturnMethod(kASMInfoRequestCallSign, retResult, retData, token);
    }
    void HandleGetOneTimeSystemInfo(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        auto future = GetOneTimeSystemInfo();
        auto result = future.GetResult();
        if (result.HasValue())
        {
            GetOneTimeSystemInfoOutput output = result.Value();
            para::serializer::Serializer serializer{};
            serializer.write(output.info);
            retData = serializer.ensure();
            retResult = 0;
        }
        else
        {
            ara::core::ErrorDomain::IdType domainId = result.Error().Domain().Id();
            ara::core::ErrorDomain::CodeType errorCode = result.Error().Value();
            para::serializer::Serializer serializer{};
            serializer.write(0, true, 0, domainId);
            serializer.write(0, true, 0, errorCode);
            retData = serializer.ensure();
            retResult = 1;
        }
        mInterface->ReturnMethod(kGetOneTimeSystemInfoCallSign, retResult, retData, token);
    }
    void HandleSetAPSystemInfo(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        para::serializer::Deserializer deserializer{data};
        eevp::type::String _apVersion_;
        deserializer.read(_apVersion_);
        auto future = SetAPSystemInfo(_apVersion_);
        auto result = future.GetResult();
        if (result.HasValue())
        {
            retResult = 0;
        }
        else
        {
            ara::core::ErrorDomain::IdType domainId = result.Error().Domain().Id();
            ara::core::ErrorDomain::CodeType errorCode = result.Error().Value();
            para::serializer::Serializer serializer{};
            serializer.write(0, true, 0, domainId);
            serializer.write(0, true, 0, errorCode);
            retData = serializer.ensure();
            retResult = 1;
        }
        mInterface->ReturnMethod(kSetAPSystemInfoCallSign, retResult, retData, token);
    }
    void HandleSystemControlResponse(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        para::serializer::Deserializer deserializer{data};
        eevp::ipchandler::type::SysCtrlResp _response_;
        deserializer.read(_response_);
        auto future = SystemControlResponse(_response_);
        auto result = future.GetResult();
        if (result.HasValue())
        {
            retResult = 0;
        }
        else
        {
            ara::core::ErrorDomain::IdType domainId = result.Error().Domain().Id();
            ara::core::ErrorDomain::CodeType errorCode = result.Error().Value();
            para::serializer::Serializer serializer{};
            serializer.write(0, true, 0, domainId);
            serializer.write(0, true, 0, errorCode);
            retData = serializer.ensure();
            retResult = 1;
        }
        mInterface->ReturnMethod(kSystemControlResponseCallSign, retResult, retData, token);
    }
    const std::string kASMInfoRequestCallSign{"ASMInfoRequest"};
    const std::string kGetOneTimeSystemInfoCallSign{"GetOneTimeSystemInfo"};
    const std::string kSetAPSystemInfoCallSign{"SetAPSystemInfo"};
    const std::string kSystemControlResponseCallSign{"SystemControlResponse"};
};
} /// namespace skeleton
} /// namespace service
} /// namespace ipchandler
} /// namespace eevp
#endif /// PARA_COM_GEN_SERVICE_INTERFACE_MAIN_IPC_ROUTINGIPC_SKELETON_H