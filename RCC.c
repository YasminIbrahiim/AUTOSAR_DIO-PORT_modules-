/*****************************************************************************************/
/************ STM32f103xx RCC Driver                       *******************************/ 
/************ File Name  : RCC.c                           *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/

#define  "PlatformTypes.h"
#define  "Std_Types.h" 
#include "RCC.h"
#include "RCC_Regs.h"
#include "RCC_Cfg.h"

/* 
@Service Name       : RCC_ClockInit
@Service ID [hex]   : 0x00
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : None
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : This function is used to initilize the clock for AHB , APB1 ,and APB2. */
void RCC_ClockInit(void)
{
	#if (SYS_CLK_SOURCE == HSI) 
		RCC->RCC_CR |= 0x00000001 ; 
		while(~(RCC->RCC_CR & (0x00000001 << 1)) )
		{
			/* HSI Oscilaltor is not ready */
		}	
	#elif (SYS_CLK_SOURCE == HSE)
		RCC->RCC_CR |= 0x00000001 << 16;
	    while(~(RCC->RCC_CR & (0x00000001 << 17)) )
		{
			/* HSE Oscilaltor is not ready */
		}
	#elif (SYS_CLK_SOURCE == PLL)
		#if (PLL_SOURCE == HSE_CLK_NOT_DIVIDED)
			RCC->RCC_CR |= 0x00000001 << 16;
	        while(~(RCC->RCC_CR & (0x00000001 << 17)) )
		    {
		    	/* HSE Oscilaltor is not ready */
		    }
			RCC->RCC_CFGR &= ~(0x00000001 << 17);
			RCC->RCC_CFGR |= 0x00000001 << 16;
		#elif (PLL_SOURCE == HSE_CLK_DIVIDED_BY_2)
			RCC->RCC_CR |= 0x00000001 << 16;
			while(~(RCC->RCC_CR & (0x00000001 << 17)) )
			{
				/* HSE Oscilaltor is not ready */
			}
			RCC->RCC_CFGR |= 0x00000001  << 17;
			RCC->RCC_CFGR |= 0x00000001  << 16;
		#elif (PLL_SOURCE == HSI_CLK_DIVIDED_BY_2)	
			RCC->RCC_CR |= 0x00000001 ; 
			while(~(RCC->RCC_CR & (0x00000001 << 1)) )
			{
				/* HSI Oscilaltor is not ready */
			}
			RCC->RCC_CFGR &= ~(0x00000001 << 16);  // set HSI as PLL source */
		#endif
		RCC->RCC_CFGR |= PLL_MUL  << 18;  
		/* PLL ON */
		RCC->RCC_CR |= 0x00000001 << 24;
		while(~(RCC->RCC_CR & (0x00000001 << 25)) )
		{
			/* PLL is not ready */
		}
	#endif
	RCC->RCC_CFGR |= AHB_PRESCALER  << 4;
	RCC->RCC_CFGR |= APB1_PRESCALER << 8;
	RCC->RCC_CFGR |= APB2_PRESCALER << 11;
	RCC->RCC_CFGR |= ADC_PRESCALER  << 8;
}

/* 
@Service Name       : RCC_AHB_peripheral_Set_clock
@Service ID [hex]   : 0x01
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (Peripheral) defines the peripheral
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : This function is used to set the clock for AHB peripherals. */
void RCC_AHB_peripheral_Set_clock(PeripheralType  Peripheral)
{
	RCC->RCC_AHBENR  |= 0x00000001 << Peripheral;
}

/* 
@Service Name       : RCC_APB1_peripheral_Set_clock
@Service ID [hex]   : 0x02
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (Peripheral) defines the peripheral
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : This function is used to set the clock for ABP1 peripherals. */
void RCC_APB1_peripheral_Set_clock(PeripheralType  Peripheral)
{
	RCC->RCC_APB1ENR |= 0x00000001 << Peripheral;
}

/* 
@Service Name       : RCC_APB2_peripheral_Set_clock
@Service ID [hex]   : 0x03
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (Peripheral) defines the peripheral
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : This function is used to set the clock for ABP2 peripherals. */
void RCC_APB2_peripheral_Set_clock(PeripheralType  Peripheral)
{
	RCC->RCC_APB2ENR |= 0x00000001 << Peripheral;
}

/* 
@Service Name       : RCC_APB1_peripheral_Reset_clock
@Service ID [hex]   : 0x04
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (Peripheral) defines the peripheral
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : This function is used to reset the clock for ABP1 peripherals. */
void RCC_APB1_peripheral_Reset_clock(PeripheralType  Peripheral)
{
	RCC->RCC_APB1RSTR |= 0x00000001 << Peripheral;
}

/* 
@Service Name       : RCC_APB2_peripheral_Reset_clock
@Service ID [hex]   : 0x05
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (Peripheral) defines the peripheral
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : This function is used to reset the clock for ABP2 peripherals. */
void RCC_APB2_peripheral_Reset_clock(PeripheralType  Peripheral)
{
	RCC->RCC_APB2RSTR |= 0x00000001 << Peripheral;
}