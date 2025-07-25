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
/// GENERATED FILE NAME               : impl_type_soadmsstatus.h
/// IMPLEMENTATION DATA TYPE NAME     : SoaDmsStatus
/// GENERATED DATE                    : 2025-06-13 16:12:50
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOADMSSTATUS_H
#define PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOADMSSTATUS_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_00402}
#include <ara/core/structure.h>

#include "eevp/control/impl_type_soadmsdriverinside.h"
/// @uptrace{SWS_CM_10375}
namespace eevp
{
namespace control
{
struct SoaDmsStatus
{
    bool powerOn;
    eevp::control::SoaDmsDriverInside driverInside;
    PARA_STRUCTURE(SoaDmsStatus, powerOn, driverInside);
};
} /// namespace control
} /// namespace eevp
#endif /// PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOADMSSTATUS_H