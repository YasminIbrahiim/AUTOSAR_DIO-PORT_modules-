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
#define PORT_VENDOR_ID      (12U)

/* Port Module ID */
#define PORT_MODULE_ID      (110U)   

/* Port Instance ID */
#define PORT_INSTANCE_ID    (0U)

/* Module Version 1.0.0 */
#define DIO_SW_MAJOR_VERSION              (1U)
#define DIO_SW_MINOR_VERSION              (0U)
#define DIO_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define DIO_AR_RELEASE_MAJOR_VERSION      (4U)
#define DIO_AR_RELEASE_MINOR_VERSION      (4U)
#define DIO_AR_RELEASE_PATCH_VERSION      (0U)

#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Module */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
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

/* the type for the value of a DIO port 
   Dio_PortLevelType inherits the size of the largest port.*/
typedef uint8  Dio_PortLevelType; 


/* These are the possible levels a DIO channel can have (input or output) */
#define STD_LOW    (Dio_LevelType)0x00
#define STD_HIGH   (Dio_LevelType)0x01

/* Type for the definition of a channel group, which consists of several adjoining 
channels within a port. */
typedef struct 
{
	uint32         mask;      /* This element mask which defines the positions of the channel group. */
	uint8          offset;    /* This element shall be the position of the Channel Group on the port, counted from the LSB. */
	Dio_PortType   port;      /* This shall be the port on which the Channel group is defined */
}Dio_ChannelGroupType;

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

/* Description: Service to get the version information of this module. */
void Dio_GetVersionInfo (Std_VersionInfoType* VersionInfo);

/* Description: Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip. */
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);

/* Description: Service to set the value of a given port with required mask. */
void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);


#endif  /* DIO_H */