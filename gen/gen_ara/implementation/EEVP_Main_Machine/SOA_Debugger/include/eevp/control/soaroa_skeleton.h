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
/// GENERATED FILE NAME               : soaroa_skeleton.h
/// SERVICE INTERFACE NAME            : SoaRoa
/// GENERATED DATE                    : 2025-02-11 11:52:31
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_COM_GEN_SERVICE_INTERFACE_SOAROA_SKELETON_H
#define PARA_COM_GEN_SERVICE_INTERFACE_SOAROA_SKELETON_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_01004}
#include "soaroa_common.h"
#include "para/com/skeleton/skeleton_interface.h"
/// @uptrace{SWS_CM_01005}
namespace eevp
{
namespace control
{
/// @uptrace{SWS_CM_01006}
namespace skeleton
{
class SoaRoaSkeleton;
/// @uptrace{SWS_CM_01009}
namespace events
{
} /// namespace events
/// @uptrace{SWS_CM_01031}
namespace fields
{
/// @uptrace{SWS_CM_00007}
class soaRoaDetectCount
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = std::uint8_t;
    /// @brief Constructor
    explicit soaRoaDetectCount(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRoaDetectCount() = default;
    /// @brief Delete copy constructor
    soaRoaDetectCount(const soaRoaDetectCount& other) = delete;
    /// @brief Delete copy assignment
    soaRoaDetectCount& operator=(const soaRoaDetectCount& other) = delete;
    /// @brief Move constructor
    soaRoaDetectCount(soaRoaDetectCount&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRoaDetectCount& operator=(soaRoaDetectCount&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRoaDetectCountGetter"};
    const std::string kNotifierCallSign = {"soaRoaDetectCountNotifier"};
};
/// @uptrace{SWS_CM_00007}
class soaRoaDetectState
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = eevp::control::SoaRoaDetectState;
    /// @brief Constructor
    explicit soaRoaDetectState(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRoaDetectState() = default;
    /// @brief Delete copy constructor
    soaRoaDetectState(const soaRoaDetectState& other) = delete;
    /// @brief Delete copy assignment
    soaRoaDetectState& operator=(const soaRoaDetectState& other) = delete;
    /// @brief Move constructor
    soaRoaDetectState(soaRoaDetectState&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRoaDetectState& operator=(soaRoaDetectState&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRoaDetectStateGetter"};
    const std::string kNotifierCallSign = {"soaRoaDetectStateNotifier"};
};
/// @uptrace{SWS_CM_00007}
class soaRoaDeviceNormal
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = eevp::control::SoaDeviceIsNormal;
    /// @brief Constructor
    explicit soaRoaDeviceNormal(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRoaDeviceNormal() = default;
    /// @brief Delete copy constructor
    soaRoaDeviceNormal(const soaRoaDeviceNormal& other) = delete;
    /// @brief Delete copy assignment
    soaRoaDeviceNormal& operator=(const soaRoaDeviceNormal& other) = delete;
    /// @brief Move constructor
    soaRoaDeviceNormal(soaRoaDeviceNormal&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRoaDeviceNormal& operator=(soaRoaDeviceNormal&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRoaDeviceNormalGetter"};
    const std::string kNotifierCallSign = {"soaRoaDeviceNormalNotifier"};
};
/// @uptrace{SWS_CM_00007}
class soaRoaMode
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = eevp::control::SoaRoaMode;
    /// @brief Constructor
    explicit soaRoaMode(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRoaMode() = default;
    /// @brief Delete copy constructor
    soaRoaMode(const soaRoaMode& other) = delete;
    /// @brief Delete copy assignment
    soaRoaMode& operator=(const soaRoaMode& other) = delete;
    /// @brief Move constructor
    soaRoaMode(soaRoaMode&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRoaMode& operator=(soaRoaMode&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRoaModeGetter"};
    const std::string kNotifierCallSign = {"soaRoaModeNotifier"};
};
/// @uptrace{SWS_CM_00007}
class soaRoaRunningState
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = eevp::control::SoaRoaRunningState;
    /// @brief Constructor
    explicit soaRoaRunningState(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRoaRunningState() = default;
    /// @brief Delete copy constructor
    soaRoaRunningState(const soaRoaRunningState& other) = delete;
    /// @brief Delete copy assignment
    soaRoaRunningState& operator=(const soaRoaRunningState& other) = delete;
    /// @brief Move constructor
    soaRoaRunningState(soaRoaRunningState&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRoaRunningState& operator=(soaRoaRunningState&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRoaRunningStateGetter"};
    const std::string kNotifierCallSign = {"soaRoaRunningStateNotifier"};
};
/// @uptrace{SWS_CM_00007}
class soaRoaSensorError
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = eevp::control::SoaRoaSensorError;
    /// @brief Constructor
    explicit soaRoaSensorError(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRoaSensorError() = default;
    /// @brief Delete copy constructor
    soaRoaSensorError(const soaRoaSensorError& other) = delete;
    /// @brief Delete copy assignment
    soaRoaSensorError& operator=(const soaRoaSensorError& other) = delete;
    /// @brief Move constructor
    soaRoaSensorError(soaRoaSensorError&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRoaSensorError& operator=(soaRoaSensorError&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRoaSensorErrorGetter"};
    const std::string kNotifierCallSign = {"soaRoaSensorErrorNotifier"};
};
/// @uptrace{SWS_CM_00007}
class soaRoaSwVersion
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = std::uint8_t;
    /// @brief Constructor
    explicit soaRoaSwVersion(para::com::SkeletonInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~soaRoaSwVersion() = default;
    /// @brief Delete copy constructor
    soaRoaSwVersion(const soaRoaSwVersion& other) = delete;
    /// @brief Delete copy assignment
    soaRoaSwVersion& operator=(const soaRoaSwVersion& other) = delete;
    /// @brief Move constructor
    soaRoaSwVersion(soaRoaSwVersion&& other) noexcept : mInterface(other.mInterface)
    {
        RegisterGetHandler(std::move(other.mGetHandler));
    }
    /// @brief Move assignment
    soaRoaSwVersion& operator=(soaRoaSwVersion&& other) noexcept
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
    const std::string kGetterCallSign = {"soaRoaSwVersionGetter"};
    const std::string kNotifierCallSign = {"soaRoaSwVersionNotifier"};
};
} /// namespace fields
/// @uptrace{SWS_CM_00002}
class SoaRoaSkeleton
{
public:
    /// @uptrace{SWS_CM_00191}
    /// @brief Constructor
    /// @uptrace{SWS_CM_00002, SWS_CM_00152}
    SoaRoaSkeleton(ara::core::InstanceSpecifier instanceSpec, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
        : mInterface(std::make_unique<para::com::SkeletonInterface>(instanceSpec, mode))
        , soaRoaDetectCount(mInterface.get())
        , soaRoaDetectState(mInterface.get())
        , soaRoaDeviceNormal(mInterface.get())
        , soaRoaMode(mInterface.get())
        , soaRoaRunningState(mInterface.get())
        , soaRoaSensorError(mInterface.get())
        , soaRoaSwVersion(mInterface.get())
    {
        mInterface->SetMethodCallHandler(kResetRoaDetectInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleResetRoaDetectInfo(data);
        });
        mInterface->SetMethodCallHandler(kSetRoaModeCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleSetRoaMode(data);
        });
        mInterface->SetMethodCallHandler(kStartRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleStartRoa(data);
        });
        mInterface->SetMethodCallHandler(kStopRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleStopRoa(data);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
    }
    /// @brief Destructor
    virtual ~SoaRoaSkeleton() = default;
    /// @brief Delete copy constructor
    /// @uptrace{SWS_CM_00134}
    SoaRoaSkeleton(const SoaRoaSkeleton& other) = delete;
    /// @brief Delete copy assignment
    /// @uptrace{SWS_CM_00134}
    SoaRoaSkeleton& operator=(const SoaRoaSkeleton& other) = delete;
    /// @brief Move constructor
    /// @uptrace{SWS_CM_00135}
    SoaRoaSkeleton(SoaRoaSkeleton&& other) noexcept
        : mInterface(std::move(other.mInterface))
        , soaRoaDetectCount(std::move(other.soaRoaDetectCount))
        , soaRoaDetectState(std::move(other.soaRoaDetectState))
        , soaRoaDeviceNormal(std::move(other.soaRoaDeviceNormal))
        , soaRoaMode(std::move(other.soaRoaMode))
        , soaRoaRunningState(std::move(other.soaRoaRunningState))
        , soaRoaSensorError(std::move(other.soaRoaSensorError))
        , soaRoaSwVersion(std::move(other.soaRoaSwVersion))
    {
        mInterface->SetMethodCallHandler(kResetRoaDetectInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleResetRoaDetectInfo(data);
        });
        mInterface->SetMethodCallHandler(kSetRoaModeCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleSetRoaMode(data);
        });
        mInterface->SetMethodCallHandler(kStartRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleStartRoa(data);
        });
        mInterface->SetMethodCallHandler(kStopRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleStopRoa(data);
        });
        mInterface->SetE2EErrorHandler([this](const ara::com::e2e::E2EErrorDomain& errorCode, ara::com::e2e::DataID dataID, ara::com::e2e::MessageCounter messageCounter) {
            E2EErrorHandler(errorCode, dataID, messageCounter);
        });
        other.mInterface.reset();
    }
    /// @brief Move assignment
    /// @uptrace{SWS_CM_00135}
    SoaRoaSkeleton& operator=(SoaRoaSkeleton&& other) noexcept
    {
        mInterface = std::move(other.mInterface);
        soaRoaDetectCount = std::move(other.soaRoaDetectCount);
        soaRoaDetectState = std::move(other.soaRoaDetectState);
        soaRoaDeviceNormal = std::move(other.soaRoaDeviceNormal);
        soaRoaMode = std::move(other.soaRoaMode);
        soaRoaRunningState = std::move(other.soaRoaRunningState);
        soaRoaSensorError = std::move(other.soaRoaSensorError);
        soaRoaSwVersion = std::move(other.soaRoaSwVersion);
        mInterface->SetMethodCallHandler(kResetRoaDetectInfoCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleResetRoaDetectInfo(data);
        });
        mInterface->SetMethodCallHandler(kSetRoaModeCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleSetRoaMode(data);
        });
        mInterface->SetMethodCallHandler(kStartRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleStartRoa(data);
        });
        mInterface->SetMethodCallHandler(kStopRoaCallSign, [this](const std::vector<std::uint8_t>& data, const para::com::MethodToken /*token*/) {
            HandleStopRoa(data);
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
    /// @brief Field, soaRoaDetectCount
    fields::soaRoaDetectCount soaRoaDetectCount;
    /// @brief Field, soaRoaDetectState
    fields::soaRoaDetectState soaRoaDetectState;
    /// @brief Field, soaRoaDeviceNormal
    fields::soaRoaDeviceNormal soaRoaDeviceNormal;
    /// @brief Field, soaRoaMode
    fields::soaRoaMode soaRoaMode;
    /// @brief Field, soaRoaRunningState
    fields::soaRoaRunningState soaRoaRunningState;
    /// @brief Field, soaRoaSensorError
    fields::soaRoaSensorError soaRoaSensorError;
    /// @brief Field, soaRoaSwVersion
    fields::soaRoaSwVersion soaRoaSwVersion;
    /// @brief Method, ResetRoaDetectInfo
    /// @uptrace{SWS_CM_90434}
    virtual void ResetRoaDetectInfo() = 0;
    /// @brief Method, SetRoaMode
    /// @uptrace{SWS_CM_90434}
    virtual void SetRoaMode(const eevp::control::SoaRoaMode& mode) = 0;
    /// @brief Method, StartRoa
    /// @uptrace{SWS_CM_90434}
    virtual void StartRoa() = 0;
    /// @brief Method, StopRoa
    /// @uptrace{SWS_CM_90434}
    virtual void StopRoa() = 0;
    
private:
    void HandleResetRoaDetectInfo(const std::vector<std::uint8_t>& data)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        ResetRoaDetectInfo();
    }
    void HandleSetRoaMode(const std::vector<std::uint8_t>& data)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        para::serializer::Deserializer deserializer{data};
        eevp::control::SoaRoaMode _mode_;
        deserializer.read(_mode_);
        SetRoaMode(_mode_);
    }
    void HandleStartRoa(const std::vector<std::uint8_t>& data)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        StartRoa();
    }
    void HandleStopRoa(const std::vector<std::uint8_t>& data)
    {
        std::uint8_t retResult{1};
        std::vector<std::uint8_t> retData{};
        StopRoa();
    }
    const std::string kResetRoaDetectInfoCallSign{"ResetRoaDetectInfo"};
    const std::string kSetRoaModeCallSign{"SetRoaMode"};
    const std::string kStartRoaCallSign{"StartRoa"};
    const std::string kStopRoaCallSign{"StopRoa"};
};
} /// namespace skeleton
} /// namespace control
} /// namespace eevp
#endif /// PARA_COM_GEN_SERVICE_INTERFACE_SOAROA_SKELETON_H