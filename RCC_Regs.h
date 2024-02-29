/**********************************************************************************************/
/************ STM32f103xx RCC registers                         *******************************/ 
/************ File Name  : RCC_Regs.h                           *******************************/ 
/************ Author     : Yasmeen Ibrahim                      *******************************/           
/************ Description:                                      *******************************/
/**********************************************************************************************/

#ifndef RCC_REGS_H
#define RCC_REGS_H

typedef struct
{
	uint32  RCC_CR      ;
	uint32  RCC_CFGR    ;
	uint32  RCC_CIR     ;
	uint32  RCC_APB2RSTR;
	uint32  RCC_APB1RSTR;
	uitn32  RCC_AHBENR  ;
	uint32  RCC_APB2ENR ;
	uint32  RCC_APB1ENR ;
	uint32  RCC_BDCR    ;
	uint32  RCC_CSR     ;
}RCC_Regs;

#define  RCC          ((volatile RCC_Regs*)0x40021000)


#endif  /* RCC_REGS_H */


