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
/// GENERATED FILE NAME               : impl_type_soaseatmotordirection.h
/// IMPLEMENTATION DATA TYPE NAME     : SoaSeatMotorDirection
/// GENERATED DATE                    : 2025-02-11 11:52:37
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// CAUTION!! AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                   
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOASEATMOTORDIRECTION_H
#define PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOASEATMOTORDIRECTION_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @uptrace{SWS_CM_00402}
#include <ara/core/structure.h>
#include "eevp/control/impl_type_soaseatheightdirection.h"
#include "eevp/control/impl_type_soaseatreclinedirection.h"
#include "eevp/control/impl_type_soaseatslidedirection.h"
#include "eevp/control/impl_type_soaseattiltdirection.h"
/// @uptrace{SWS_CM_10375}
namespace eevp
{
namespace control
{
struct SoaSeatMotorDirection
{
    eevp::control::SoaSeatSlideDirection slide;
    eevp::control::SoaSeatReclineDirection recline;
    eevp::control::SoaSeatHeightDirection height;
    eevp::control::SoaSeatTiltDirection tilt;
    PARA_STRUCTURE(SoaSeatMotorDirection, slide, recline, height, tilt);
};
} /// namespace control
} /// namespace eevp
#endif /// PARA_ARA_COM_GEN_CPP_IMPL_TYPE_SOASEATMOTORDIRECTION_H