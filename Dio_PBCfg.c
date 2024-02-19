/**************************************************************************************************/
/************ STM32f103xx DIO_Driver                                    ***************************/ 
/************ File Name  : Dio_PBCfg.c                                  ***************************/ 
/************ Author     : Yasmeen Ibrahim                              ***************************/           
/************ Description:                                              ***************************/
/**************************************************************************************************/

/* Module Version 1.0.0 */
#define DIO_PBCFG_SW_MAJOR_VERSION              (1U)
#define DIO_PBCFG_SW_MINOR_VERSION              (0U)
#define DIO_PBCFG_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define DIO_PBCFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define DIO_PBCFG_AR_RELEASE_MINOR_VERSION      (4U)
#define DIO_PBCFG_AR_RELEASE_PATCH_VERSION      (0U)

#include "Dio.h"
/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif
/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_PBCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_PBCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

#include "Dio_Cfg.h"
/* AUTOSAR Version checking between Dio_PBcfg.c and Dio_Cfg.h files */
#if ((DIO_PBCFG_AR_RELEASE_MAJOR_VERSION != DIO_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_MINOR_VERSION != DIO_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_PATCH_VERSION != DIO_CFG_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif
/* Software Version checking between Dio_PBcfg.c and Dio_Cfg.h files */
#if ((DIO_PBCFG_SW_MAJOR_VERSION != DIO_CFG_SW_MAJOR_VERSION)\
 ||  (DIO_PBCFG_SW_MINOR_VERSION != DIO_CFG_SW_MINOR_VERSION)\
 ||  (DIO_PBCFG_SW_PATCH_VERSION != DIO_CFG_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif


const Dio_ChannelCfg arrDio_Channels[NUM_OF_CHANNELS] = 
{
	{PIN0, PORTA},  // Dio_Channel_A0 with id (0U)
	{PIN1, PORTA},  // Dio_Channel_A1 with id (1U)
	{PIN1, PORTE}   // Dio_Channel_E1 with id (2U)
};


