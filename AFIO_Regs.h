/*****************************************************************************************/
/************ STM32f103xx AFIO Driver                      *******************************/ 
/************ File Name  : AFIO_Regs.h                     *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/

#ifndef AFIO_REGS_H
#define AFIO_REGS_H

typedef struct 
{
	uint32  AFIO_EVCR;
	uint32  AFIO_MAPR;
	uint32  AFIO_EXTICR1;
	uint32  AFIO_EXTICR2;
	uint32  AFIO_EXTICR3;
	uint32  AFIO_EXTICR4;
	uint32  AFIO_MAPR2;
}AFIO_REG;

#define  AFIO         ((volatile AFIO_REG*)0x40021000)

#endif