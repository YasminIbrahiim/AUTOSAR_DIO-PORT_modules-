/**************************************************************************************************/
/************ STM32f103xx DIO_Driver                                    ***************************/ 
/************ File Name  : Dio_LCfg.h                                   ***************************/ 
/************ Author     : Yasmeen Ibrahim                              ***************************/           
/************ Description:                                              ***************************/
/**************************************************************************************************/
#ifndef   DIO_CFG_H
#define   DIO_CFG_H

/* Module Version 1.0.0 */
#define DIO_LCFG_SW_MAJOR_VERSION              (1U)
#define DIO_LCFG_SW_MINOR_VERSION              (0U)
#define DIO_LCFG_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define DIO_LCFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define DIO_LCFG_AR_RELEASE_MINOR_VERSION      (4U)
#define DIO_LCFG_AR_RELEASE_PATCH_VERSION      (0U)

#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio_LCFG */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_LCFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_LCFG_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_LCFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif 

#include "PlatformTypes.h"

/* AUTOSAR checking between Platform_Types and Dio_Lcfg */
#if ((PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_LCFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION != DIO_LCFG_AR_RELEASE_MINOR_VERSION)\
 ||  (PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION != DIO_LCFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PlatformTypes.h does not match the expected version"
#endif

 
#endif