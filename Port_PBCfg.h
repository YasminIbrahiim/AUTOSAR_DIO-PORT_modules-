/*****************************************************************************************/
/************ STM32f103xx PortConfiguration                *******************************/ 
/************ File Name  : Port_PBCfg.h                    *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/

#ifndef  PORT_PBCFG_H
#define  PORT_PBCFG_H

/* Module Version 1.0.0 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION      (4U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION      (0U)

#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port_PBCfg */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_PBCFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_PBCFG_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_PBCFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif 

#include "PlatformTypes.h"

/* AUTOSAR checking between Platform_Types and Port_PBcfg */
#if ((PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_PBCFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION != PORT_PBCFG_AR_RELEASE_MINOR_VERSION)\
 ||  (PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION != PORT_PBCFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PlatformTypes.h does not match the expected version"
#endif



#endif