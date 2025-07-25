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
/// GENERATED FILE NAME               : impl_type_soawipermode.h
/// IMPLEMENTATION DATA TYPE NAME     : SoaWiperMode
/// GENERATED DATE                    : 2025-02-11 11:52:37
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOAWIPERMODE_H
#define PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOAWIPERMODE_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_00402}
#include <cstdint>
/// @uptrace{SWS_CM_10375}
namespace eevp
{
namespace control
{
enum class SoaWiperMode : std::uint8_t
{
    kOFF = 0U,
    kINT1 = 1U,
    kINT2 = 2U,
    kINT3 = 3U,
    kON = 4U
};
} /// namespace control
} /// namespace eevp
#endif /// PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOAWIPERMODE_H