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
/// GENERATED FILE NAME               : soarcurtain_skeleton.h
/// SERVICE INTERFACE NAME            : SoaRcurtain
/// GENERATED DATE                    : 2024-09-14 22:41:26
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_COM_GEN_SERVICE_INTERFACE_SOARCURTAIN_SKELETON_H
#define PARA_COM_GEN_SERVICE_INTERFACE_SOARCURTAIN_SKELETON_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_01004}
#include "soarcurtain_common.h"
#include "para/com/skeleton/skeleton_interface.h"
/// @uptrace{SWS_CM_01005}
namespace eevp
{
namespace control
{
/// @uptrace{SWS_CM_01006}
namespace skeleton
{
class SoaRcurtainSkeleton;
/// @uptrace{SWS_CM_01009}
namespace events
{
} /// namespace events
/// @uptrace{SWS_CM_01031}
namespace fields
{
/// @uptrace{SWS_CM_00007}
class soaRctnStatus
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = eevp::control::SoaRctnStatus;
    /// @brief Constructor
    explicit soaRctnStatus(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRctnStatus() = default;
    /// @brief Delete copy constructor
    soaRctnStatus(const soaRctnStatus& other) = delete;
    /// @brief Delete copy assignment
    soaRctnStatus& operator=(const soaRctnStatus& other) = delete;
    /// @brief Move constructor
    soaRctnStatus(soaRctnStatus&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRctnStatus& operator=(soaRctnStatus&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRctnStatusGetter"};
    const std::string kNotifierCallSign = {"soaRctnStatusNotifier"};
};
/// @uptrace{SWS_CM_00007}
class soaRctnSwVersion
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = std::uint8_t;
    /// @brief Constructor
    explicit soaRctnSwVersion(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRctnSwVersion() = default;
    /// @brief Delete copy constructor
    soaRctnSwVersion(const soaRctnSwVersion& other) = delete;
    /// @brief Delete copy assignment
    soaRctnSwVersion& operator=(const soaRctnSwVersion& other) = delete;
    /// @brief Move constructor
    soaRctnSwVersion(soaRctnSwVersion&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRctnSwVersion& operator=(soaRctnSwVersion&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRctnSwVersionGetter"};
    const std::string kNotifierCallSign = {"soaRctnSwVersionNotifier"};
};
} /// namespace fields
/// @uptrace{SWS_CM_00002}
class SoaRcurtainSkeleton
{
public:
    /// @uptrace{SWS_CM_00191}
    struct RequestRearCurtainOperationOutput
    {
        eevp::control::SoaErrorState err;
    };
    /// @brief Constructor
    /// @uptrace{SWS_CM_00002, SWS_CM_00152}
    SoaRcurtainSkeleton(ara::core::InstanceSpecifier instanceSpec, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
        : mInterface(std::make_unique<para::com::SkeletonInterface>(instanceSpec, mode))
        , soaRctnStatus(mInterface.get())
        , soaRctnSwVersion(mInterface.get())
    {
        mInterface->SetMethodCallHandler(kRequestRearCurtainOperationCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleRequestRearCurtainOperation(data, token);
        });
        mInterface->SetMethodCallHandler(kRequestRearCurtainPositionCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleRequestRearCurtainPosition(data);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
    }
    /// @brief Destructor
    virtual ~SoaRcurtainSkeleton() = default;
    /// @brief Delete copy constructor
    /// @uptrace{SWS_CM_00134}
    SoaRcurtainSkeleton(const SoaRcurtainSkeleton& other) = delete;
    /// @brief Delete copy assignment
    /// @uptrace{SWS_CM_00134}
    SoaRcurtainSkeleton& operator=(const SoaRcurtainSkeleton& other) = delete;
    /// @brief Move constructor
    /// @uptrace{SWS_CM_00135}
    SoaRcurtainSkeleton(SoaRcurtainSkeleton&& other) noexcept
        : mInterface(std::move(other.mInterface))
        , soaRctnStatus(std::move(other.soaRctnStatus))
        , soaRctnSwVersion(std::move(other.soaRctnSwVersion))
    {
        mInterface->SetMethodCallHandler(kRequestRearCurtainOperationCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleRequestRearCurtainOperation(data, token);
        });
        mInterface->SetMethodCallHandler(kRequestRearCurtainPositionCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleRequestRearCurtainPosition(data);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
        other.mInterface.reset();
    }
    /// @brief Move assignment
    /// @uptrace{SWS_CM_00135}
    SoaRcurtainSkeleton& operator=(SoaRcurtainSkeleton&& other) noexcept
    {
        mInterface = std::move(other.mInterface);
        soaRctnStatus = std::move(other.soaRctnStatus);
        soaRctnSwVersion = std::move(other.soaRctnSwVersion);
        mInterface->SetMethodCallHandler(kRequestRearCurtainOperationCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken token) {
            HandleRequestRearCurtainOperation(data, token);
        });
        mInterface->SetMethodCallHandler(kRequestRearCurtainPositionCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleRequestRearCurtainPosition(data);
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
    /// @brief Field, soaRctnStatus
    fields::soaRctnStatus soaRctnStatus;
    /// @brief Field, soaRctnSwVersion
    fields::soaRctnSwVersion soaRctnSwVersion;
    /// @brief Method, RequestRearCurtainOperation
    /// @uptrace{SWS_CM_00191}
    virtual ara::core::Future<RequestRearCurtainOperationOutput> RequestRearCurtainOperation(const eevp::control::SoaRctnMotorDir& motorDir) = 0;
    /// @brief Method, RequestRearCurtainPosition
    /// @uptrace{SWS_CM_90434}
    virtual void RequestRearCurtainPosition(const std::uint8_t& posPercentage) = 0;
    
private:
    void HandleRequestRearCurtainOperation(const std::vector<std::uint8_t>& data, const para::com::MethodToken token)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        para::serializer::Deserializer deserializer{data};
        eevp::control::SoaRctnMotorDir _motorDir_;
        deserializer.read(_motorDir_);
        auto future = RequestRearCurtainOperation(_motorDir_);
        auto result = future.GetResult();
        if (result.HasValue())
        {
            RequestRearCurtainOperationOutput output = result.Value();
            para::serializer::Serializer serializer{};
            serializer.write(output.err);
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
        mInterface->ReturnMethod(kRequestRearCurtainOperationCallSign, retResult, retData, token);
    }
    void HandleRequestRearCurtainPosition(const std::vector<std::uint8_t>& data)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        para::serializer::Deserializer deserializer{data};
        std::uint8_t _posPercentage_;
        deserializer.read(_posPercentage_);
        RequestRearCurtainPosition(_posPercentage_);
    }
    const std::string kRequestRearCurtainOperationCallSign{"RequestRearCurtainOperation"};
    const std::string kRequestRearCurtainPositionCallSign{"RequestRearCurtainPosition"};
};
} /// namespace skeleton
} /// namespace control
} /// namespace eevp
#endif /// PARA_COM_GEN_SERVICE_INTERFACE_SOARCURTAIN_SKELETON_H