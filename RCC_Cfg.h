/*****************************************************************************************/
/************ STM32f103xx RCC Driver                       *******************************/ 
/************ File Name  : RCC_Cfg.h                       *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/

#ifndef RCC_CFG_H  
#define RCC_CFG_H

#define AHB_PRESCALER      SYSCLK_NOT_DIVIDED 
#define APB1_PRESCALER     HCLK_DIVIDED_BY_2
#define APB2_PRESCALER     HCLK_DIVIDED_BY_2
#define ADC_PRESCALER      PCLK2_DIVIDED_BY_2
#define PLL_MUL            PLL_X16  


#define SYS_CLK_SOURCE  PLL

#if(SYS_CLK_SOURCE == PLL)
#define   PLL_SOURCE     HSI
#endif

#endif