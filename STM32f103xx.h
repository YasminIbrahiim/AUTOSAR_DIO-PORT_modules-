/**********************************************************************************************/
/************ STM32f103xx Device header file                    *******************************/ 
/************ File Name  : STM32f103xx.h                        *******************************/ 
/************ Author     : Yasmeen Ibrahim                      *******************************/           
/************ Description:                                      *******************************/
/**********************************************************************************************/

#ifndef   STM32F103XX_H
#define   STM32F103XX_H

#include "Std_Types.h"


/************************  DIO Module Registers ***************************/

/* General Purpose Input/Output Registers */
typedef struct
{
	uint32 GPIOx_CRL;
	uint32 GPIOx_CRH;
	uint32 GPIOx_ODR;
	uint32 GPIOx_BSRR;
	uint32 GPIOx_BRR;
	uint32 GPIOx_LCKR;
}GPIOx_REG;

#define  GPIOA        *((volatile GPIOx_REG*)0x40010800)
#define  GPIOB        *((volatile GPIOx_REG*)0x40010C00)
#define  GPIOC        *((volatile GPIOx_REG*)0x40011000)
#define  GPIOD        *((volatile GPIOx_REG*)0x40011400)
#define  GPIOE        *((volatile GPIOx_REG*)0x40011800)
#define  GPIOF        *((volatile GPIOx_REG*)0x40011C00)
#define  GPIOG        *((volatile GPIOx_REG*)0x40012000)
#define  AFIO         *((volatile GPIOx_REG*)0x40010000)

/*     Alternative Function Registers */
#define   AFIO_EVCR          *((volatile uint32*)AFIO_BASE_ADDRESS + 0x00)
#define   AFIO_MAPR          *((volatile uint32*)AFIO_BASE_ADDRESS + 0x04)
#define   AFIO_EXTICR1       *((volatile uint32*)AFIO_BASE_ADDRESS + 0x08)
#define   AFIO_EXTICR2       *((volatile uint32*)AFIO_BASE_ADDRESS + 0x0C)
#define   AFIO_EXTICR3       *((volatile uint32*)AFIO_BASE_ADDRESS + 0x10)
#define   AFIO_EXTICR4       *((volatile uint32*)AFIO_BASE_ADDRESS + 0x14)

#endif  /* STM32F103XX_H */  
