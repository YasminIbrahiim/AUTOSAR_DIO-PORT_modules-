/*****************************************************************************************/
/************ STM32f103xx RCC Driver                       *******************************/ 
/************ File Name  : RCC.h                           *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/

#ifndef RCC_H
#define RCC_H

typedef uint32 ClockSourceType; /* This type is used to define the available clock sources */
typedef uint32 PeripheralType;  /* This type is used to define the peripherals that are located on each bus*/

/* Three different clock sources can be used to drive the system clock (SYSCLK) */
#define HSI     ((ClockSourceType)0)
#define HSE     ((ClockSourceType)1)
#define PLL     ((ClockSourceType)2) 

/* APB1_Peripherals */
#define TIM2_APB1_PERIPHERAL   ((PeripheralType)0)        
#define TIM3_APB1_PERIPHERAL   ((PeripheralType)1)
#define TIM4_APB1_PERIPHERAL   ((PeripheralType)2)
#define TIM5_APB1_PERIPHERAL   ((PeripheralType)3)
#define TIM6_APB1_PERIPHERAL   ((PeripheralType)4)
#define TIM7_APB1_PERIPHERAL   ((PeripheralType)5)
#define TIM12_APB1_PERIPHERAL  ((PeripheralType)6)
#define TIM13_APB1_PERIPHERAL  ((PeripheralType)7)
#define TIM14_APB1_PERIPHERAL  ((PeripheralType)8)
#define WWDG_APB1_PERIPHERAL   ((PeripheralType)11)
#define SPI2_APB1_PERIPHERAL   ((PeripheralType)14)
#define SPI3_APB1_PERIPHERAL   ((PeripheralType)15)
#define USART2_APB1_PERIPHERAL ((PeripheralType)17)
#define USART3_APB1_PERIPHERAL ((PeripheralType)18)
#define USART4_APB1_PERIPHERAL ((PeripheralType)19)
#define USART5_APB1_PERIPHERAL ((PeripheralType)20)
#define I2C1_APB1_PERIPHERAL   ((PeripheralType)21)
#define I2C2_APB1_PERIPHERAL   ((PeripheralType)22)
#define USB_APB1_PERIPHERAL    ((PeripheralType)23)
#define CAN_APB1_PERIPHERAL    ((PeripheralType)25)
#define BKP_APB1_PERIPHERAL    ((PeripheralType)27)
#define PWR_APB1_PERIPHERAL    ((PeripheralType)28)
#define DAC_APB1_PERIPHERAL    ((PeripheralType)29)

/* APB2_Peripherals */
#define AFIO_APB2_PERIPHERAL    ((PeripheralType)0)
#define GPIOA_APB2_PERIPHERAL   ((PeripheralType)2)
#define GPIOB_APB2_PERIPHERAL   ((PeripheralType)3)
#define GPIOC_APB2_PERIPHERAL   ((PeripheralType)4)
#define GPIOD_APB2_PERIPHERAL   ((PeripheralType)5)
#define GPIOE_APB2_PERIPHERAL   ((PeripheralType)6)
#define GPIOF_APB2_PERIPHERAL   ((PeripheralType)7)
#define GPIOG_APB2_PERIPHERAL   ((PeripheralType)8)
#define ADC1_APB2_PERIPHERAL    ((PeripheralType)9)
#define ADC2_APB2_PERIPHERAL    ((PeripheralType)10)
#define TIM1_APB2_PERIPHERAL    ((PeripheralType)11)
#define SPI1_APB2_PERIPHERAL    ((PeripheralType)12)
#define TIM8_APB2_PERIPHERAL    ((PeripheralType)13)
#define USART1_APB2_PERIPHERAL  ((PeripheralType)14)
#define ADC3_APB2_PERIPHERAL    ((PeripheralType)15)
#define TIM9_APB2_PERIPHERAL    ((PeripheralType)19)
#define TIM10_APB2_PERIPHERAL   ((PeripheralType)20)
#define TIM11_APB2_PERIPHERAL   ((PeripheralType)21)

/* AHB_Peripherals */
#define DMA1_AHB_PERIPHERAL     ((PeripheralType)0)
#define DMA2_AHB_PERIPHERAL     ((PeripheralType)1)
#define SRAM_AHB_PERIPHERAL     ((PeripheralType)2)
#define FLITF_AHB_PERIPHERAL    ((PeripheralType)4)
#define CRC_AHB_PERIPHERAL      ((PeripheralType)6)
#define FSMC_AHB_PERIPHERAL     ((PeripheralType)8)
#define SDIO_AHB_PERIPHERAL     ((PeripheralType)10)

/* HCLK devisior */
#define HCLK_NOT_DIVIDED        ((uint32)0)
#define HCLK_DIVIDED_BY_2       ((uint32)4)
#define HCLK_DIVIDED_BY_4       ((uint32)5)
#define HCLK_DIVIDED_BY_8       ((uint32)6)
#define HCLK_DIVIDED_BY_16      ((uint32)7)

/*AHB Prescaler*/
#define SYSCLK_NOT_DIVIDED      ((uint32)0)
#define SYSCLK_DIVIDED_BY_2     ((uint32)8)
#define SYSCLK_DIVIDED_BY_4     ((uint32)9)
#define SYSCLK_DIVIDED_BY_8     ((uint32)10)
#define SYSCLK_DIVIDED_BY_16    ((uint32)11)
#define SYSCLK_DIVIDED_BY_64    ((uint32)12)
#define SYSCLK_DIVIDED_BY_128   ((uint32)13)
#define SYSCLK_DIVIDED_BY_256   ((uint32)14)
#define SYSCLK_DIVIDED_BY_512   ((uint32)15)

/* PLL Multiplication factor*/
#define PLL_X2   ((uint32)0)
#define PLL_X3   ((uint32)1)
#define PLL_X4   ((uint32)2)
#define PLL_X5   ((uint32)3)
#define PLL_X6   ((uint32)4)
#define PLL_X7   ((uint32)5)
#define PLL_X8   ((uint32)6)
#define PLL_X9   ((uint32)7)
#define PLL_X10  ((uint32)8)
#define PLL_X11  ((uint32)9)
#define PLL_X12  ((uint32)10)
#define PLL_X13  ((uint32)11)
#define PLL_X14  ((uint32)12)
#define PLL_X15  ((uint32)13)
#define PLL_X16  ((uint32)14)

/* used to define ADC prescaler */
#define PCLK2_DIVIDED_BY_2   ((uint32)0)
#define PCLK2_DIVIDED_BY_4   ((uint32)1)
#define PCLK2_DIVIDED_BY_6   ((uint32)2)
#define PCLK2_DIVIDED_BY_8   ((uint32)3)


/* PLL sources */
#define  HSE_CLK_NOT_DIVIDED    ((uint32)0)
#define  HSE_CLK_DIVIDED_BY_2   ((uint32)1)
#define  HSI_CLK_DIVIDED_BY_2   ((uint32)2)

/* Description: This function is used to initilize the clock for AHB , APB1 ,and APB2. */
void RCC_ClockInit(void);

/* Description: This function is used to set the clock for AHB peripherals. */
void RCC_AHB_peripheral_Set_clock(PeripheralType  Peripheral);

/*Description: This function is used to set the clock for APB1 peripherals. */
void RCC_APB1_peripheral_Set_clock(PeripheralType  Peripheral);

/*Description: This function is used to set the clock for APB2 peripherals. */
void RCC_APB2_peripheral_Set_clock(PeripheralType  Peripheral);

/*Description: This function is used to reset the clock for APB1 peripherals. */
void RCC_APB1_peripheral_Reset_clock(PeripheralType  Peripheral);

/*Description: This function is used to reset the clock for APB2 peripherals. */
void RCC_APB2_peripheral_Reset_clock(PeripheralType  Peripheral);

#endif  /* RCC_H */

