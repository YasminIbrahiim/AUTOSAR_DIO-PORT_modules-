/**********************************************************************************************/
/************ STM32f103xx Dio registers' addresses              *******************************/ 
/************ File Name  : Dio_Regs.h                           *******************************/ 
/************ Author     : Yasmeen Ibrahim                      *******************************/           
/************ Description:                                      *******************************/
/**********************************************************************************************/

#ifndef   DIO_REGS_H
#define   DIO_REGS_H

/************************  DIO Module Registers ***************************/

/* General Purpose Input/Output Registers */
typedef struct
{
	uint32 GPIOx_CRL;
	uint32 GPIOx_CRH;
	uint32 GPIOx_IDR;
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

#endif  /* DIO_REGS_H */  
