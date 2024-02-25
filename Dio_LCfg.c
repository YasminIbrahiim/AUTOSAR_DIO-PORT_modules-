/**************************************************************************************************/
/************ STM32f103xx DIO_Driver                                    ***************************/ 
/************ File Name  : Dio_LCfg.c                                  ***************************/ 
/************ Author     : Yasmeen Ibrahim                              ***************************/           
/************ Description:                                              ***************************/
/**************************************************************************************************/

#include "Dio_LCfg.h"

Dio_ChannelCfg arrDio_Channels[NUM_OF_CHANNELS] = 
{
	{PIN0, PORTA},  // Dio_Channel_A0 with id (0U)
	{PIN1, PORTA},  // Dio_Channel_A1 with id (1U)
	{PIN1, PORTE}   // Dio_Channel_E1 with id (2U)
};


