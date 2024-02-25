/**************************************************************************************************/
/************ STM32f103xx DIO_Driver                                    ***************************/ 
/************ File Name  : Dio.h                                        ***************************/ 
/************ Author     : Yasmeen Ibrahim                              ***************************/           
/************ Description:                                              ***************************/
/**************************************************************************************************/

#ifndef  DIO_H   
#define  DIO_H

/* ID for the Vendor company 
   example: ID = 12          */ 
#define DIO_VENDOR_ID      (12U)

/* Dio Module ID */
#define DIO_MODULE_ID      (110U)   

/* Dio Instance ID */
#define DIO_INSTANCE_ID    (0U)

/* Module Version 1.0.0 */
#define DIO_SW_MAJOR_VERSION              (1U)
#define DIO_SW_MINOR_VERSION              (0U)
#define DIO_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define DIO_AR_RELEASE_MAJOR_VERSION      (4U)
#define DIO_AR_RELEASE_MINOR_VERSION      (4U)
#define DIO_AR_RELEASE_PATCH_VERSION      (0U)

#include "Std_Types.h"

/* AUTOSAR checking between Std_Types and Dio Module */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "PlatformTypes.h"

/* AUTOSAR checking between Platform_Types and Dio Module */
#if ((PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Platform_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

#include "Dio_LCfg.h"
/* AUTOSAR Version checking between Dio_Lcfg.c and Dio.h files */
#if ((DIO_LCFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_LCFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_LCFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Lcfg.c does not match the expected version"
#endif
/* Software Version checking between Dio_Lcfg.c and Dio.h files */
#if ((DIO_LCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_LCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_LCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of Dio_Lcfg.c does not match the expected version"
#endif

/***************************** Development Error Types for DIO module *****************************/
/* Invalid channel requested  */
#define   DIO_E_PARAM_INVALID_CHANNEL_ID   0x0A
/* Invalid port requested     */         
#define   DIO_E_PARAM_INVALID_PORT_ID      0x14
/* Invalid channel group requested  */
#define   DIO_E_PARAM_INVALID_GROUP        0x1F
/* API service called with a NULL pointer */
#define   DIO_E_PARAM_POINTER              0x20

typedef uint32 Dio_ChannelType; /*  Numeric ID of a DIO channel */
typedef uint8  Dio_PortType   ; /*  Numeric ID of a DIO port    */
typedef uint8  Dio_LevelType  ; /*  DIO channel level           */
typedef uint8  Dio_PinType    ; /*  Numeric ID of a DIO pin     */

/* the type for the value of a DIO port 
   Dio_PortLevelType inherits the size of the largest port.*/
typedef uint32  Dio_PortLevelType; 

/* Type for the definition of a channel group, which consists of several adjoining 
channels within a port. */
typedef struct 
{
	uint32          mask;      /* This element mask which defines the positions of the channel group. */
	uint8          offset;    /* This element shall be the position of the Channel Group on the port, counted from the LSB. */
	Dio_PortType   port;      /* This shall be the port on which the Channel group is defined */
}Dio_ChannelGroupType;

typedef struct 
{
	uint32         pin;
	Dio_PortType   port;        
}Dio_ChannelCfg;

#define PIN0   ((Dio_PinType)0)      
#define PIN1   ((Dio_PinType)1)
#define PIN2   ((Dio_PinType)2)
#define PIN3   ((Dio_PinType)3)
#define PIN4   ((Dio_PinType)4)
#define PIN5   ((Dio_PinType)5)
#define PIN6   ((Dio_PinType)6)
#define PIN7   ((Dio_PinType)7)
#define PIN8   ((Dio_PinType)8)
#define PIN9   ((Dio_PinType)9)
#define PIN10  ((Dio_PinType)10)
#define PIN11  ((Dio_PinType)11)
#define PIN12  ((Dio_PinType)12)
#define PIN13  ((Dio_PinType)13)
#define PIN14  ((Dio_PinType)14)
#define PIN15  ((Dio_PinType)15)

#define PORTA  ((Dio_PortType)0)
#define PORTB  ((Dio_PortType)1)
#define PORTC  ((Dio_PortType)2)
#define PORTD  ((Dio_PortType)3)
#define PORTE  ((Dio_PortType)4)
#define PORTF  ((Dio_PortType)5)
#define PORTG  ((Dio_PortType)6)

/************************************************  Function definitions *******************************************************/ 
/* Description: Returns the value of the specified DIO channel. */
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);

/* Description: Service to set a level of a channel.  */
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Description: Returns the level of all channels of that port */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId );

/* Description: Service to set a value of the port */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);

/* Description: This Service reads a subset of the adjoining bits of a port. */
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);

/* Description: Service to set a subset of the adjoining bits of a port to a specified level. */
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

#if DioVersionInfoApi == STD_ON 
/* Description: Service to get the version information of this module. */
void Dio_GetVersionInfo (Std_VersionInfoType* VersionInfo);
#endif 

#if DioFlipChannelApi == STD_ON
/* Description: Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip. */
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);
#endif

#if DioMaskedWritePortApi == STD_ON 
/* Description: Service to set the value of a given port with required mask. */
void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);
#endif

#endif  /* DIO_H */