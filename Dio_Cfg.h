/**************************************************************************************************/
/************ STM32f103xx DIO_Driver                                    ***************************/ 
/************ File Name  : Dio_Cfg.h                                    ***************************/ 
/************ Author     : Yasmeen Ibrahim                              ***************************/           
/************ Description: Stm32f103C8T6 Configuration                  ***************************/
/**************************************************************************************************/

#ifndef   DIO_CFG_H
#define   DIO_CFG_H

/* Module Version 1.0.0 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION      (4U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION      (0U)

/* Switches the development error detection and notification on or off.
   STD_ON : detection and notification is enabled.
   STD_OFF: detection and notification is disabled. */
#define DioDevErrorDetect     STD_OFF 

/* Adds / removes the service Dio_FlipChannel() from the code. */
#define DioFlipChannelApi     STD_ON 

/* Adds / removes the service Dio_MaskedWritePort() from the code */
#define DioMaskedWritePortApi STD_ON

/* Adds / removes the service Dio_ GetVersionInfo() from the code. */
#define DioVersionInfoApi     STD_ON 

/* Numeric identifier of the DIO port. Not all MCU ports may be used for DIO, thus 
there may be "gaps" in the list of all IDs. */
typedef uint32 DioPortId;
#define DIO_PORTA_ID   ((DioPortId)0) 
#define DIO_PORTE_ID   ((DioPortId)4)

#define NUM_OF_CHANNELS  3

/* Channel Id of the DIO channel. This value will be assigned to the 
symbolic names. */
typedef uint32 DioChannelId;
#define DIO_CHANNEL_A0     ((DioChannelId)0x00000000)
#define DIO_CHANNEL_A1     ((DioChannelId)0x00000001)
#define DIO_CAHNNEL_E1     ((DioChannelId)0x00000002)

extern Dio_ChannelCfg arrDio_Channels[NUM_OF_CHANNELS] ;
#endif