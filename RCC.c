/*****************************************************************************************/
/************ STM32f103xx RCC Driver                       *******************************/ 
/************ File Name  : RCC.c                           *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/

#include "RCC.h"
#include "RCC_Regs.h"

void RCC_ClockInit(void)
{
	
}
void RCC_AHB_peripheral_Set_clock(PeripheralType  Peripheral)
{
	RCC->RCC_AHBENR  |= 1 << Peripheral;
}
void RCC_APB1_peripheral_Set_clock(PeripheralType  Peripheral)
{
	RCC->RCC_APB1ENR |= 1 << Peripheral;
}
void RCC_APB2_peripheral_Set_clock(PeripheralType  Peripheral)
{
	RCC->RCC_APB2ENR |= 1 << Peripheral;
}
void RCC_APB1_peripheral_Reset_clock(PeripheralType  Peripheral)
{
	RCC->RCC_APB1RSTR |= 1 << Peripheral;
}
void RCC_APB2_peripheral_Reset_clock(PeripheralType  Peripheral)
{
	RCC->RCC_APB2RSTR |= 1 << Peripheral;
}