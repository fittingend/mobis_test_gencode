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
/// GENERATED FILE NAME               : otamonitoring_skeleton.h
/// SERVICE INTERFACE NAME            : OtaMonitoring
/// GENERATED DATE                    : 2025-02-11 11:52:30
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_COM_GEN_SERVICE_INTERFACE_OTAMONITORING_SKELETON_H
#define PARA_COM_GEN_SERVICE_INTERFACE_OTAMONITORING_SKELETON_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_01004}
#include "otamonitoring_common.h"
#include "para/com/skeleton/skeleton_interface.h"
/// @uptrace{SWS_CM_01005}
namespace eevp
{
namespace ota
{
namespace monitoring
{
namespace service
{
/// @uptrace{SWS_CM_01006}
namespace skeleton
{
class OtaMonitoringSkeleton;
/// @uptrace{SWS_CM_01009}
namespace events
{
/// @uptrace{SWS_CM_00003}
class notifyServiceEvent
{
public:
    /// @brief Type alias for type of event data
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using SampleType = eevp::ota::monitoring::type::RequestServiceInfo;
    /// @brief Constructor
    explicit notifyServiceEvent(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~notifyServiceEvent() = default;
    /// @brief Delete copy constructor
    notifyServiceEvent(const notifyServiceEvent& other) = delete;
    /// @brief Delete copy assignment
    notifyServiceEvent& operator=(const notifyServiceEvent& other) = delete;
    /// @brief Move constructor
    notifyServiceEvent(notifyServiceEvent&& other) noexcept : mInterface(other.mInterface)
    {
    }
    /// @brief Move assignment
    notifyServiceEvent& operator=(notifyServiceEvent&& other) noexcept
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
    const std::string kCallSign = {"notifyServiceEvent"};
};
/// @uptrace{SWS_CM_00003}
class notifyUpdatableService
{
public:
    /// @brief Type alias for type of event data
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using SampleType = eevp::ota::monitoring::type::UpdatableServiceInfo;
    /// @brief Constructor
    explicit notifyUpdatableService(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~notifyUpdatableService() = default;
    /// @brief Delete copy constructor
    notifyUpdatableService(const notifyUpdatableService& other) = delete;
    /// @brief Delete copy assignment
    notifyUpdatableService& operator=(const notifyUpdatableService& other) = delete;
    /// @brief Move constructor
    notifyUpdatableService(notifyUpdatableService&& other) noexcept : mInterface(other.mInterface)
    {
    }
    /// @brief Move assignment
    notifyUpdatableService& operator=(notifyUpdatableService&& other) noexcept
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
    const std::string kCallSign = {"notifyUpdatableService"};
};
/// @uptrace{SWS_CM_00003}
class resetUcmCompleted
{
public:
    /// @brief Type alias for type of event data
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using SampleType = bool;
    /// @brief Constructor
    explicit resetUcmCompleted(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~resetUcmCompleted() = default;
    /// @brief Delete copy constructor
    resetUcmCompleted(const resetUcmCompleted& other) = delete;
    /// @brief Delete copy assignment
    resetUcmCompleted& operator=(const resetUcmCompleted& other) = delete;
    /// @brief Move constructor
    resetUcmCompleted(resetUcmCompleted&& other) noexcept : mInterface(other.mInterface)
    {
    }
    /// @brief Move assignment
    resetUcmCompleted& operator=(resetUcmCompleted&& other) noexcept
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
    const std::string kCallSign = {"resetUcmCompleted"};
};
} /// namespace events
/// @uptrace{SWS_CM_01031}
namespace fields
{
} /// namespace fields
/// @uptrace{SWS_CM_00002}
class OtaMonitoringSkeleton
{
public:
    /// @uptrace{SWS_CM_00191}
    struct requestServiceInstallOutput
    {
        bool returnValue;
    };
    struct requestServiceUpdateOutput
    {
        bool returnValue;
    };
    struct requestVersionInfoOutput
    {
        eevp::ota::monitoring::type::RequestServiceInfoMap requestServiceInfoMap;
        bool returnValue;
    };
    struct resetUcmTestOutput
    {
    };
    /// @brief Constructor
    /// @uptrace{SWS_CM_00002, SWS_CM_00152}
    OtaMonitoringSkeleton(ara::core::InstanceSpecifier instanceSpec, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
        : mInterface(std::make_unique<para::com::SkeletonInterface>(instanceSpec, mode))
        , notifyServiceEvent(mInterface.get())
        , notifyUpdatableService(mInterface.get())
        , resetUcmCompleted(mInterface.get())
    {
        mInterface->SetMethodCallHandler(krequestServiceInstallCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestServiceInstall(data, token);
        });
        mInterface->SetMethodCallHandler(krequestServiceUpdateCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestServiceUpdate(data, token);
        });
        mInterface->SetMethodCallHandler(krequestVersionInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestVersionInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kresetUcmTestCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleresetUcmTest(data, token);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
    }
    /// @brief Destructor
    virtual ~OtaMonitoringSkeleton() = default;
    /// @brief Delete copy constructor
    /// @uptrace{SWS_CM_00134}
    OtaMonitoringSkeleton(const OtaMonitoringSkeleton& other) = delete;
    /// @brief Delete copy assignment
    /// @uptrace{SWS_CM_00134}
    OtaMonitoringSkeleton& operator=(const OtaMonitoringSkeleton& other) = delete;
    /// @brief Move constructor
    /// @uptrace{SWS_CM_00135}
    OtaMonitoringSkeleton(OtaMonitoringSkeleton&& other) noexcept
        : mInterface(std::move(other.mInterface))
        , notifyServiceEvent(std::move(other.notifyServiceEvent))
        , notifyUpdatableService(std::move(other.notifyUpdatableService))
        , resetUcmCompleted(std::move(other.resetUcmCompleted))
    {
        mInterface->SetMethodCallHandler(krequestServiceInstallCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestServiceInstall(data, token);
        });
        mInterface->SetMethodCallHandler(krequestServiceUpdateCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestServiceUpdate(data, token);
        });
        mInterface->SetMethodCallHandler(krequestVersionInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestVersionInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kresetUcmTestCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleresetUcmTest(data, token);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
        other.mInterface.reset();
    }
    /// @brief Move assignment
    /// @uptrace{SWS_CM_00135}
    OtaMonitoringSkeleton& operator=(OtaMonitoringSkeleton&& other) noexcept
    {
        mInterface = std::move(other.mInterface);
        notifyServiceEvent = std::move(other.notifyServiceEvent);
        notifyUpdatableService = std::move(other.notifyUpdatableService);
        resetUcmCompleted = std::move(other.resetUcmCompleted);
        mInterface->SetMethodCallHandler(krequestServiceInstallCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestServiceInstall(data, token);
        });
        mInterface->SetMethodCallHandler(krequestServiceUpdateCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestServiceUpdate(data, token);
        });
        mInterface->SetMethodCallHandler(krequestVersionInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandlerequestVersionInfo(data, token);
        });
        mInterface->SetMethodCallHandler(kresetUcmTestCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleresetUcmTest(data, token);
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
    /// @brief Event, notifyServiceEvent
    events::notifyServiceEvent notifyServiceEvent;
    /// @brief Event, notifyUpdatableService
    events::notifyUpdatableService notifyUpdatableService;
    /// @brief Event, resetUcmCompleted
    events::resetUcmCompleted resetUcmCompleted;
    /// @brief Method, requestServiceInstall
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<requestServiceInstallOutput> requestServiceInstall(const eevp::type::String& serviceName) = 0;
    /// @brief Method, requestServiceUpdate
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<requestServiceUpdateOutput> requestServiceUpdate(const eevp::type::String& serviceName) = 0;
    /// @brief Method, requestVersionInfo
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<requestVersionInfoOutput> requestVersionInfo() = 0;
    /// @brief Method, resetUcmTest
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<resetUcmTestOutput> resetUcmTest() = 0;
    
private:
    void HandlerequestServiceInstall(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        para::serializer::Deserializer deserializer{data};
        eevp::type::String _serviceName_;
        deserializer.read(_serviceName_);
        auto future = requestServiceInstall(_serviceName_);
        auto result = future.GetResult();
        if (result.HasValue())
        {
            requestServiceInstallOutput output = result.Value();
            para::serializer::Serializer serializer{};
            serializer.write(output.returnValue);
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
        mInterface->ReturnMethod(krequestServiceInstallCallSign, retResult, retData, token);
    }
    void HandlerequestServiceUpdate(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        para::serializer::Deserializer deserializer{data};
        eevp::type::String _serviceName_;
        deserializer.read(_serviceName_);
        auto future = requestServiceUpdate(_serviceName_);
        auto result = future.GetResult();
        if (result.HasValue())
        {
            requestServiceUpdateOutput output = result.Value();
            para::serializer::Serializer serializer{};
            serializer.write(output.returnValue);
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
        mInterface->ReturnMethod(krequestServiceUpdateCallSign, retResult, retData, token);
    }
    void HandlerequestVersionInfo(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        auto future = requestVersionInfo();
        auto result = future.GetResult();
        if (result.HasValue())
        {
            requestVersionInfoOutput output = result.Value();
            para::serializer::Serializer serializer{};
            serializer.write(output.requestServiceInfoMap);
            serializer.write(output.returnValue);
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
        mInterface->ReturnMethod(krequestVersionInfoCallSign, retResult, retData, token);
    }
    void HandleresetUcmTest(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        auto future = resetUcmTest();
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
        mInterface->ReturnMethod(kresetUcmTestCallSign, retResult, retData, token);
    }
    const std::string krequestServiceInstallCallSign{"requestServiceInstall"};
    const std::string krequestServiceUpdateCallSign{"requestServiceUpdate"};
    const std::string krequestVersionInfoCallSign{"requestVersionInfo"};
    const std::string kresetUcmTestCallSign{"resetUcmTest"};
};
} /// namespace skeleton
} /// namespace service
} /// namespace monitoring
} /// namespace ota
} /// namespace eevp
#endif /// PARA_COM_GEN_SERVICE_INTERFACE_OTAMONITORING_SKELETON_H