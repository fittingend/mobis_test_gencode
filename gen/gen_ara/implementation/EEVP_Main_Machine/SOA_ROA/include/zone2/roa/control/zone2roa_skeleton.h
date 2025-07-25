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
/// GENERATED FILE NAME               : zone2roa_skeleton.h
/// SERVICE INTERFACE NAME            : Zone2Roa
/// GENERATED DATE                    : 2025-02-11 11:52:33
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_COM_GEN_SERVICE_INTERFACE_ZONE2ROA_SKELETON_H
#define PARA_COM_GEN_SERVICE_INTERFACE_ZONE2ROA_SKELETON_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_01004}
#include "zone2roa_common.h"
#include "para/com/skeleton/skeleton_interface.h"
/// @uptrace{SWS_CM_01005}
namespace zone2
{
namespace roa
{
namespace control
{
/// @uptrace{SWS_CM_01006}
namespace skeleton
{
class Zone2RoaSkeleton;
/// @uptrace{SWS_CM_01009}
namespace events
{
} /// namespace events
/// @uptrace{SWS_CM_01031}
namespace fields
{
/// @uptrace{SWS_CM_00007}
class zone2RoaSnsrStatus
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = zone2::roa::control::EcmRoaSnsrStatus;
    /// @brief Constructor
    explicit zone2RoaSnsrStatus(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~zone2RoaSnsrStatus() = default;
    /// @brief Delete copy constructor
    zone2RoaSnsrStatus(const zone2RoaSnsrStatus& other) = delete;
    /// @brief Delete copy assignment
    zone2RoaSnsrStatus& operator=(const zone2RoaSnsrStatus& other) = delete;
    /// @brief Move constructor
    zone2RoaSnsrStatus(zone2RoaSnsrStatus&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    zone2RoaSnsrStatus& operator=(zone2RoaSnsrStatus&& other) noexcept
    {
        mInterface = other.mInterface;
        RegisterGetHandler(std::move(other.mGetHandler));
        return *this;
    }
    /// @brief Register callback for getter method
    /// @uptrace{SWS_CM_00114}
    ara::core::Result<void> RegisterGetHandler(std::function<ara::core::Future<FieldType>()> getHandler)
    {
        ara::core::Result<void> result{};
        if (getHandler != nullptr)
        {
            mGetHandler = std::move(getHandler);
            mInterface->SetMethodCallHandler(kGetterCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
                HandleGet(token);
            });
        }
        return result;
    }
    /// @brief Send notification with value to subscribing service consumers
    /// @uptrace{SWS_CM_90437}
    ara::core::Result<void> Update(const FieldType& value)
    {
        para::serializer::Serializer serializer{};
        serializer.write(value);
        auto payload = serializer.ensure();
        return mInterface->SendEvent(kNotifierCallSign, payload);
    }
    
private:
    void HandleGet(const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        auto future = mGetHandler();
        auto result = future.GetResult();
        if (result.HasValue())
        {
            FieldType value = result.Value();
            para::serializer::Serializer serializer{};
            serializer.write(value);
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
        mInterface->ReturnMethod(kGetterCallSign, retResult, retData, token);
    }
    para::com::SkeletonInterface* mInterface;
    std::function<ara::core::Future<FieldType>()> mGetHandler{nullptr};
    const std::string kGetterCallSign = {"zone2RoaSnsrStatusGetter"};
    const std::string kNotifierCallSign = {"zone2RoaSnsrStatusNotifier"};
};
} /// namespace fields
/// @uptrace{SWS_CM_00002}
class Zone2RoaSkeleton
{
public:
    /// @uptrace{SWS_CM_00191}
    /// @brief Constructor
    /// @uptrace{SWS_CM_00002, SWS_CM_00152}
    Zone2RoaSkeleton(ara::core::InstanceSpecifier instanceSpec, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
        : mInterface(std::make_unique<para::com::SkeletonInterface>(instanceSpec, mode))
        , zone2RoaSnsrStatus(mInterface.get())
    {
        mInterface->SetMethodCallHandler(kcontrolRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandlecontrolRoa(data);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
    }
    /// @brief Destructor
    virtual ~Zone2RoaSkeleton() = default;
    /// @brief Delete copy constructor
    /// @uptrace{SWS_CM_00134}
    Zone2RoaSkeleton(const Zone2RoaSkeleton& other) = delete;
    /// @brief Delete copy assignment
    /// @uptrace{SWS_CM_00134}
    Zone2RoaSkeleton& operator=(const Zone2RoaSkeleton& other) = delete;
    /// @brief Move constructor
    /// @uptrace{SWS_CM_00135}
    Zone2RoaSkeleton(Zone2RoaSkeleton&& other) noexcept
        : mInterface(std::move(other.mInterface))
        , zone2RoaSnsrStatus(std::move(other.zone2RoaSnsrStatus))
    {
        mInterface->SetMethodCallHandler(kcontrolRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandlecontrolRoa(data);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
        other.mInterface.reset();
    }
    /// @brief Move assignment
    /// @uptrace{SWS_CM_00135}
    Zone2RoaSkeleton& operator=(Zone2RoaSkeleton&& other) noexcept
    {
        mInterface = std::move(other.mInterface);
        zone2RoaSnsrStatus = std::move(other.zone2RoaSnsrStatus);
        mInterface->SetMethodCallHandler(kcontrolRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandlecontrolRoa(data);
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
    /// @brief Field, zone2RoaSnsrStatus
    fields::zone2RoaSnsrStatus zone2RoaSnsrStatus;
    /// @brief Method, controlRoa
    /// @uptrace{SWS_CM_90434}
    virtual void controlRoa(const std::uint8_t& snsrRunReq) = 0;
    
private:
    void HandlecontrolRoa(const std::vector<std::uint8_t>& data)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        para::serializer::Deserializer deserializer{data};
        std::uint8_t _snsrRunReq_;
        deserializer.read(_snsrRunReq_);
        controlRoa(_snsrRunReq_);
    }
    const std::string kcontrolRoaCallSign{"controlRoa"};
};
} /// namespace skeleton
} /// namespace control
} /// namespace roa
} /// namespace zone2
#endif /// PARA_COM_GEN_SERVICE_INTERFACE_ZONE2ROA_SKELETON_H