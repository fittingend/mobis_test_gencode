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
/// GENERATED FILE NAME               : zone3rcurtain_proxy.h
/// SERVICE INTERFACE NAME            : Zone3Rcurtain
/// GENERATED DATE                    : 2025-02-11 11:52:33
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_COM_GEN_SERVICE_INTERFACE_ZONE3RCURTAIN_PROXY_H
#define PARA_COM_GEN_SERVICE_INTERFACE_ZONE3RCURTAIN_PROXY_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_01004}
#include "zone3rcurtain_common.h"
#include "para/com/proxy/proxy_interface.h"
/// @uptrace{SWS_CM_01005}
namespace zone3
{
namespace rcurtain
{
namespace control
{
/// @uptrace{SWS_CM_01007}
namespace proxy
{
/// @uptrace{SWS_CM_01009}
namespace events
{
} /// namespace events
/// @uptrace{SWS_CM_01031}
namespace fields
{
/// @uptrace{SWS_CM_00008}
class zone3RcurtainStatus
{
public:
    /// @brief Type alias for type of field value
    /// @uptrace{SWS_CM_00162, SWS_CM_90437}
    using FieldType = zone3::rcurtain::control::EcuRcurtainStatus;
    /// @brief Constructor
    explicit zone3RcurtainStatus(para::com::ProxyInterface* interface) : mInterface(interface)
    {
        mInterface->SetMethodReturnHandler(kGetterCallSign, [](std::uint8_t result, const std::vector<std::uint8_t>& data, void* userData) {
            HandleMethodReturn(result, data, userData);
        });
    }
    /// @brief Destructor
    virtual ~zone3RcurtainStatus() = default;
    /// @brief Delete copy constructor
    zone3RcurtainStatus(const zone3RcurtainStatus& other) = delete;
    /// @brief Delete copy assignment
    zone3RcurtainStatus& operator=(const zone3RcurtainStatus& other) = delete;
    /// @brief Move constructor
    zone3RcurtainStatus(zone3RcurtainStatus&& other) noexcept : mInterface(other.mInterface)
    {
        mMaxSampleCount = other.mMaxSampleCount;
        mEventReceiveHandler = other.mEventReceiveHandler;
        mSubscriptionStateChangeHandler = other.mSubscriptionStateChangeHandler;
        mInterface->SetEventReceiveHandler(kNotifierCallSign, mEventReceiveHandler);
        mInterface->SetSubscriptionStateChangeHandler(kNotifierCallSign, mSubscriptionStateChangeHandler);
        mInterface->SetMethodReturnHandler(kGetterCallSign, [](std::uint8_t result, const std::vector<std::uint8_t>& data, void* userData) {
            HandleMethodReturn(result, data, userData);
        });
    }
    /// @brief Move assignment
    zone3RcurtainStatus& operator=(zone3RcurtainStatus&& other) noexcept
    {
        mInterface = other.mInterface;
        mMaxSampleCount = other.mMaxSampleCount;
        mEventReceiveHandler = other.mEventReceiveHandler;
        mSubscriptionStateChangeHandler = other.mSubscriptionStateChangeHandler;
        mInterface->SetEventReceiveHandler(kNotifierCallSign, mEventReceiveHandler);
        mInterface->SetSubscriptionStateChangeHandler(kNotifierCallSign, mSubscriptionStateChangeHandler);
        mInterface->SetMethodReturnHandler(kGetterCallSign, [](std::uint8_t result, const std::vector<std::uint8_t>& data, void* userData) {
            HandleMethodReturn(result, data, userData);
        });
        return *this;
    }
    /// @brief Requests getter method to Communication Management
    /// @uptrace{SWS_CM_00112}
    ara::core::Future<FieldType> Get()
    {
        std::vector<std::uint8_t> data{};
        auto* promise = new ara::core::Promise<FieldType>();
        auto future = promise->get_future();
        mInterface->CallMethod(kGetterCallSign, data, promise);
        return future;
    }
    /// @brief Requests "Subscribe" message to Communication Management
    /// @uptrace{SWS_CM_00141}
    ara::core::Result<void> Subscribe(size_t maxSampleCount)
    {
        if (mInterface->GetSubscriptionState(kNotifierCallSign) == ara::com::SubscriptionState::kSubscribed)
        {
            if ((maxSampleCount != 0) && (maxSampleCount != mMaxSampleCount))
            {
                return ara::core::Result<void>(ara::com::ComErrc::kMaxSampleCountNotRealizable);
            }
        }
        mMaxSampleCount = maxSampleCount;
        return mInterface->SubscribeEvent(kNotifierCallSign, mMaxSampleCount);
    }
    /// @brief Requests "StopSubscribe" message to Communication Management
    /// @uptrace{SWS_CM_00151}
    void Unsubscribe()
    {
        mInterface->UnsubscribeEvent(kNotifierCallSign);
    }
    /// @brief Return state for current subscription
    /// @uptrace{SWS_CM_00316}
    ara::com::SubscriptionState GetSubscriptionState() const
    {
        return mInterface->GetSubscriptionState(kNotifierCallSign);
    }
    /// @brief Register callback to catch changes of subscription state
    /// @uptrace{SWS_CM_00333}
    ara::core::Result<void> SetSubscriptionStateChangeHandler(ara::com::SubscriptionStateChangeHandler handler)
    {
        mSubscriptionStateChangeHandler = std::move(handler);
        return mInterface->SetSubscriptionStateChangeHandler(kNotifierCallSign, mSubscriptionStateChangeHandler);
    }
    /// @brief Unset bound callback by SetSubscriptionStateChangeHandler
    /// @uptrace{SWS_CM_00334}
    void UnsetSubscriptionStateChangeHandler()
    {
        mSubscriptionStateChangeHandler = nullptr;
        mInterface->UnsetSubscriptionStateChangeHandler(kNotifierCallSign);
    }
    /// @brief Get received notification value from cache
    /// @uptrace{SWS_CM_00701}
    template<typename F>
    ara::core::Result<size_t> GetNewSamples(F&& f, size_t maxNumberOfSamples = std::numeric_limits<size_t>::max())
    {
        auto samples = mInterface->GetNewSamples(kNotifierCallSign, maxNumberOfSamples);
        for (const auto& sample : samples)
        {
            para::serializer::Deserializer deserializer{sample};
            FieldType value;
            deserializer.read(value);
            f(ara::com::make_sample_ptr<const FieldType>(value));
        }
        return samples.size();
    }
    /// @brief Register callback to catch that notification value is received
    /// @uptrace{SWS_CM_00181}
    ara::core::Result<void> SetReceiveHandler(ara::com::EventReceiveHandler handler)
    {
        mEventReceiveHandler = std::move(handler);
        return mInterface->SetEventReceiveHandler(kNotifierCallSign, mEventReceiveHandler);
    }
    /// @brief Unset bound callback by SetReceiveHandler
    /// @uptrace{SWS_CM_00183}
    ara::core::Result<void> UnsetReceiveHandler()
    {
        mEventReceiveHandler = nullptr;
        return mInterface->UnsetEventReceiveHandler(kNotifierCallSign);
    }
    /// @brief Returns the count of free notification cache
    /// @uptrace{SWS_CM_00705}
    ara::core::Result<size_t> GetFreeSampleCount() const noexcept
    {
        auto ret = mInterface->GetFreeSampleCount(kNotifierCallSign);
        if (ret < 0)
        {
            return ara::core::Result<size_t>(ara::core::CoreErrc::kInvalidArgument);
        }
        return ret;
    }
    
private:
    static void HandleMethodReturn(std::uint8_t result, const std::vector<std::uint8_t>& data, void* userData)
    {
        auto* promise = static_cast<ara::core::Promise<FieldType>*>(userData);
        if (result == 0)
        {
            para::serializer::Deserializer deserializer{data};
            FieldType value;
            deserializer.read(value);
            promise->set_value(value);
        }
        else
        {
            promise->SetError(ara::core::CoreErrc::kInvalidArgument);
        }
        delete promise;
    }
    size_t mMaxSampleCount{0};
    ara::com::EventReceiveHandler mEventReceiveHandler{nullptr};
    ara::com::SubscriptionStateChangeHandler mSubscriptionStateChangeHandler{nullptr};
    para::com::ProxyInterface* mInterface;
    const std::string kGetterCallSign = {"zone3RcurtainStatusGetter"};
    const std::string kNotifierCallSign = {"zone3RcurtainStatusNotifier"};
};
} /// namespace fields
/// @uptrace{SWS_CM_01015}
namespace methods
{
/// @uptrace{SWS_CM_00006}
class controlRcurtain
{
public:
    /// @brief Constructor
    explicit controlRcurtain(para::com::ProxyInterface* interface) : mInterface(interface)
    {
    }
    /// @brief Destructor
    virtual ~controlRcurtain() = default;
    /// @brief
    controlRcurtain(const controlRcurtain& other) = delete;
    controlRcurtain& operator=(const controlRcurtain& other) = delete;
    /// @brief Move constructor
    controlRcurtain(controlRcurtain&& other) noexcept : mInterface(other.mInterface)
    {
    }
    /// @brief Move assignment
    controlRcurtain& operator=(controlRcurtain&& other) noexcept
    {
        mInterface = other.mInterface;
        return *this;
    }
    /// @brief Function call operator
    /// @uptrace{SWS_CM_90435}
    void operator()(const std::uint8_t& motorPos)
    {
        para::serializer::Serializer __serializer__{};
        __serializer__.write(motorPos);
        auto __data__ = __serializer__.ensure();
        mInterface->CallMethodNoReturn(kCallSign, __data__);
    }
    
private:
    para::com::ProxyInterface* mInterface;
    const std::string kCallSign{"controlRcurtain"};
};
} /// namespace methods
/// @uptrace{SWS_CM_00004}
class Zone3RcurtainProxy
{
public: 
    /// @uptrace{SWS_CM_00312}
    class HandleType
    {
    public:
        HandleType() = default;
        HandleType(ara::core::InstanceSpecifier instanceSpecifier, para::com::ServiceHandle service)
            : mInstanceSpecifier(std::move(instanceSpecifier)), mServiceHandle(service)
        {
        }
        ~HandleType() = default;
        /// @uptrace{SWS_CM_00317}
        HandleType(const HandleType& other) = default;
        HandleType& operator=(const HandleType& other) = default;
        /// @uptrace{SWS_CM_00318}
        HandleType(HandleType&& other) = default;
        HandleType& operator=(HandleType&& other) = default;
        /// @brief Return instance specifier
        ara::core::InstanceSpecifier GetInstanceSpecifier()
        {
            return mInstanceSpecifier;
        }
        /// @brief Return handle for bound service
        para::com::ServiceHandle GetServiceHandle()
        {
            return mServiceHandle;
        }
        /// @brief Is equal to operator
        inline bool operator==(const HandleType& other) const
        {
            return mInstanceSpecifier == other.mInstanceSpecifier && mServiceHandle == other.mServiceHandle;
        }
        /// @brief Less than operator
        inline bool operator<(const HandleType& other) const
        {
            return mServiceHandle.version < other.mServiceHandle.version;
        }
        
    private:
        ara::core::InstanceSpecifier mInstanceSpecifier{"undefined"};
        para::com::ServiceHandle mServiceHandle;
    };
    /// @brief Requests "FindService" message to Communication Management with callback
    /// @uptrace{SWS_CM_00623}
    static ara::core::Result<ara::com::FindServiceHandle> StartFindService(ara::com::FindServiceHandler<Zone3RcurtainProxy::HandleType> handler, ara::core::InstanceSpecifier instanceSpec)
    {
        ara::com::FindServiceHandle findHandle = para::com::ProxyInterface::GetFindServiceHandle(instanceSpec);
        auto findCallback = [&, handler, findHandle, instanceSpec](std::vector<para::com::ServiceHandle> services) {
            ara::com::ServiceHandleContainer<Zone3RcurtainProxy::HandleType> handleContainer;
            for (auto& service : services)
            {
                handleContainer.emplace_back(instanceSpec, service);
            }
            handler(handleContainer, findHandle);
        };
        return para::com::ProxyInterface::StartFindService(instanceSpec, findCallback);
    }
    /// @brief Send "FindService" message to Communication Management at once
    /// @uptrace{SWS_CM_00622}
    static ara::core::Result<ara::com::ServiceHandleContainer<Zone3RcurtainProxy::HandleType>> FindService(ara::core::InstanceSpecifier instanceSpec)
    {
        auto result = para::com::ProxyInterface::FindService(instanceSpec);
        if (!result.HasValue())
        {
            return ara::core::Result<ara::com::ServiceHandleContainer<Zone3RcurtainProxy::HandleType>>::FromError(result.Error());
        }
        ara::com::ServiceHandleContainer<Zone3RcurtainProxy::HandleType> handleContainer;
        const auto& services = result.Value();
        for (auto& service : services)
        {
            handleContainer.emplace_back(instanceSpec, service);
        }
        return handleContainer;
    }
    /// @brief Constructor
    /// @note This function shall be called after processing of FindService/StartFindService was completed
    /// @uptrace{SWS_CM_00004, SWS_CM_00131}
    explicit Zone3RcurtainProxy(HandleType& handle)
        : mHandle(handle)
        , mInterface(std::make_unique<para::com::ProxyInterface>(handle.GetInstanceSpecifier(), handle.GetServiceHandle()))
        , zone3RcurtainStatus(mInterface.get())
        , controlRcurtain(mInterface.get())
    {
    }
    /// @brief Destructor
    /// @uptrace{SWS_CM_10446}
    ~Zone3RcurtainProxy() = default;
    /// @brief Delete copy constructor
    /// @uptrace{SWS_CM_00136}
    Zone3RcurtainProxy(Zone3RcurtainProxy& other) = delete;
    /// @brief Delete copy assignment
    /// @uptrace{SWS_CM_00136}
    Zone3RcurtainProxy& operator=(const Zone3RcurtainProxy& other) = delete;
    /// @brief Move constructor
    /// @uptrace{SWS_CM_00137}
    Zone3RcurtainProxy(Zone3RcurtainProxy&& other) noexcept
        : mHandle(std::move(other.mHandle))
        , mInterface(std::move(other.mInterface))
        , zone3RcurtainStatus(std::move(other.zone3RcurtainStatus))
        , controlRcurtain(std::move(other.controlRcurtain))
    {
        mInterface->StopFindService();
        other.mInterface.reset();
    }
    /// @brief Move assignment
    /// @uptrace{SWS_CM_00137}
    Zone3RcurtainProxy& operator=(Zone3RcurtainProxy&& other) noexcept
    {
        mHandle = std::move(other.mHandle);
        mInterface = std::move(other.mInterface);
        mInterface->StopFindService();
        zone3RcurtainStatus = std::move(other.zone3RcurtainStatus);
        controlRcurtain = std::move(other.controlRcurtain);
        other.mInterface.reset();
        return *this;
    }
    /// @brief Stop the running StartFindService
    /// @uptrace{SWS_CM_00125}
    void StopFindService(ara::com::FindServiceHandle /*handle*/)
    {
        mInterface->StopFindService();
    }
    /// @brief Return handle that is connected with service provider currently
    /// @uptrace{SWS_CM_10383}
    HandleType GetHandle() const
    {
        return mHandle;
    }
    
private:
    HandleType mHandle;
    std::unique_ptr<para::com::ProxyInterface> mInterface;
    
public:
    /// @brief - field, zone3RcurtainStatus
    fields::zone3RcurtainStatus zone3RcurtainStatus;
    /// @brief - method, controlRcurtain
    methods::controlRcurtain controlRcurtain;
};
} /// namespace proxy
} /// namespace control
} /// namespace rcurtain
} /// namespace zone3
#endif /// PARA_COM_GEN_SERVICE_INTERFACE_ZONE3RCURTAIN_PROXY_H