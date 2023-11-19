/**************************************************************************************************/
/************ STM32f103xx DIO_Driver                                    ***************************/ 
/************ File Name  : Dio_Cfg.h                                    ***************************/ 
/************ Author     : Yasmeen Ibrahim                              ***************************/           
/************ Description:                                              ***************************/
/**************************************************************************************************/

/* Module Version 1.0.0 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION      (4U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION      (0U)

/* Switches the development error detection and notification on or off.
   true : detection and notification is enabled.
   false: detection and notification is disabled. */
#define DioDevErrorDetect     true 

/* Adds / removes the service Dio_FlipChannel() from the code. */
#define DioFlipChannelApi     true 

/* Adds / removes the service Dio_MaskedWritePort() from the code */
#define DioMaskedWritePortApi true

/* Adds / removes the service Dio_ GetVersionInfo() from the code. */
#define DioVersionInfoApi     true 


/* Numeric identifier of the DIO port. Not all MCU ports may be used for DIO, thus 
there may be "gaps" in the list of all IDs. */
typedef uint32 DioPortId;
#define DIO_PORTA_ID   ((DioPortId)0) 
#define DIO_PORTB_ID   ((DioPortId)1)
#define DIO_PORTF_ID   ((DioPortId)2)
#define DIO_PORTG_ID   ((DioPortId)3)

/* Channel Id of the DIO channel. This value will be assigned to the 
symbolic names. */
typedef uint32 DioChannelId;
#define DIO_CHANNEL_0    ((DioChannelId)0)
#define DIO_CHANNEL_1    ((DioChannelId)1)
#define DIO_CHANNEL_2    ((DioChannelId)2)
#define DIO_CHANNEL_3    ((DioChannelId)3)
#define DIO_CHANNEL_4    ((DioChannelId)4)

/* The DIO channel group is identified in DIO API by a pointer to a data structure 
(of type Dio_ChannelGroupType). That data structure contains the channel 
group information.
This parameter contains the code fragment that has to be inserted in the API call 
of the calling module to get the address of the variable in memory which holds 
the channel group information. Example values are "&MyDioGroup1" or "&MyDio
GroupArray[0]" */

typedef char[10]  DioChannelGroupIdentification;

 
