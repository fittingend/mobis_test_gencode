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
/// GENERATED FILE NAME               : impl_type_campaignstatetype.h
/// IMPLEMENTATION DATA TYPE NAME     : CampaignStateType
/// GENERATED DATE                    : 2025-02-11 11:52:35
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_ARA_COM_GEN_CPP_IMPL_TYPE_CAMPAIGNSTATETYPE_H
#define PARA_ARA_COM_GEN_CPP_IMPL_TYPE_CAMPAIGNSTATETYPE_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_00402}
#include <cstdint>
/// @uptrace{SWS_CM_10375}
namespace ara
{
namespace ucm
{
enum class CampaignStateType : std::uint8_t
{
    kIdle = 0x00U,
    kSyncing = 0x01U,
    kVehiclePackageTransferring = 0x02U,
    kSoftwarePackageTransferring = 0x03U,
    kProcessing = 0x04U,
    kActivating = 0x05U,
    kVehicleChecking = 0x06U,
    kCancelling = 0x07U
};
} /// namespace ucm
} /// namespace ara
#endif /// PARA_ARA_COM_GEN_CPP_IMPL_TYPE_CAMPAIGNSTATETYPE_H