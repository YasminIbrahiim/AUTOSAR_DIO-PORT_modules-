/*****************************************************************************************/
/************ STM32f103xx AFIO Driver                      *******************************/ 
/************ File Name  : AFIO.h                          *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/

#ifndef  AFIO_H 
#define  AFIO_H

typedef  uint32  AFIO_PeriphMappingType;
typedef  uitn32  EXTI_PinType;
typedef  uint32  EXTI_PortType;
typedef  uint32  Eventout_PinType;
typedef  uint32  Eventout_PortType;

/* CAN AFIO  
The CAN signals can be mapped on PortA, PortB or PortD. For portD,
remapping is not possible in devices delivered in 36-, 48- and 64-pin packages.*/
#define  CAN_RX_PA11_TX_PA12    ((AFIO_PeriphMappingType)0)
#define  CAN_RX_PB8_TX_PB9      ((AFIO_PeriphMappingType)1)
#define  CAN_RX_PD0_TX_PD1      ((AFIO_PeriphMappingType)2)

/* JTAG or SWD AFIO */
#define  JTMS_PA13_JTCK_PA14_JTDI_PA15_JTDO_PB3_NJTRST_PB4  ((AFIO_PeriphMappingType)3) 
#define  JTMS_PA13_JTCK_PA14_JTDI_PA15_JTDO_PB3             ((AFIO_PeriphMappingType)4)
#define  JTMS_PA13_JTCK_PA14                                ((AFIO_PeriphMappingType)5)
#define  JTAG_DP_Disabled_SW_DP_Disabled                    ((AFIO_PeriphMappingType)6)

/* TIM4_AFIO */
#define TIM4_CH1_PB6_CH2_PB7_CH3_PB8_CH4_PB9      ((AFIO_PeriphMappingType)7)
#define TIM4_CH1_PD12_CH2_PD13_CH3_PD14_CH4_PD15  ((AFIO_PeriphMappingType)8)  /* Remap available only for 100-pin and for 144-pin package. */

/* TIM3 AFIO */
#define TIM3_CH1_PA6_CH2_PA7_CH3_PB0_CH4_PB1      ((AFIO_PeriphMappingType)9)  
#define TIM3_CH1_PB4_CH2_PB5_CH3_PB0_CH4_PB1      ((AFIO_PeriphMappingType)10)
#define TIM3_CH1_PC6_CH2_PC7_CH3_PC8_CH4_PC9      ((AFIO_PeriphMappingType)11)  /* Remap available only for 64-pin, 100-pin and 144-pin packages */

/* TIM2 AFIO */
#define TIM2_CH1_ETR_PA0_CH2_PA1_CH3_PA2_CH4_PA3     ((AFIO_PeriphMappingType)12)
#define TIM2_CH1_ETR_PA15_CH2_PB3_CH3_PA2_CH4_PA3    ((AFIO_PeriphMappingType)13)
#define TIM2_CH1_ETR_PA0_CH2_PA1_CH3_PB10_CH4_PB11   ((AFIO_PeriphMappingType)14)
#define TIM2_CH1_ETR_PA15_CH2_PB3_CH3_PB10_CH4_PB11  ((AFIO_PeriphMappingType)15)

/* TIM1 AFIO  
TIM_CH1 and TIM_ETR share the same pin but cannot be used at the same time 
(which is why we have this notation: TIM2_CH1_ETR) */
#define TIM1_ETR_PA12_CH1_PA8_CH2_PA9_CH3_PA10_CH4_PA11_BKIN_PB12_CH1N_PB13_CH2N_PB14_CH3N_PB15  ((AFIO_PeriphMappingType)16) 
#define TIM1_ETR_PA12_CH1_PA8_CH2_PA9_CH3_PA10_CH4_PA11_BKIN_PA6_CH1N_PA7_CH2N_PB0_CH3N_PB1      ((AFIO_PeriphMappingType)17)
#define TIM1_ETR_PE7_CH1_PE9_CH2_PE11_CH3_PE13_CH4_PE14_BKIN_PE15_CH1N_PE8_CH2N_PE10_CH3N_PE12   ((AFIO_PeriphMappingType)18)

/* TIM9 AFIO */
#define TIM9_CH1_PA2_CH2_PA3  ((AFIO_PeriphMappingType)19)
#define TIM9_CH1_PE5_CH2_PE6  ((AFIO_PeriphMappingType)20)

/* TIM10 AFIO */
#define TIM10_CH1_PB8   ((AFIO_PeriphMappingType)21)
#define TIM10_CH1_PF6   ((AFIO_PeriphMappingType)22)

/* TIM11 AFIO */
#define TIM11_CH1_PB9   ((AFIO_PeriphMappingType)23)
#define TIM11_CH1_PF7   ((AFIO_PeriphMappingType)24)

/* TIM13 AFIO */
#define TIM13_CH1_PA6   ((AFIO_PeriphMappingType)25)
#define TIM13_CH1_PF8   ((AFIO_PeriphMappingType)26)

/* TIM14 AFIO */
#define TIM14_CH1_PA7   ((AFIO_PeriphMappingType)27)
#define TIM14_CH1_PF9   ((AFIO_PeriphMappingType)28)

/* USART3 AFIO */
#define USART3_TX_PB10_RX_PB11_CK_PB12_CTS_PB13_RTS_PB14  ((AFIO_PeriphMappingType)29)
#define USART3_TX_PC10_RX_PC11_CK_PC12_CTS_PB13_RTS_PB14  ((AFIO_PeriphMappingType)30)   /* Remap available only for 64-pin, 100-pin and 144-pin packages */
#define USART3_TX_PD8_RX_PD9_CK_PD10_CTS_PD11_RTS_PD12    ((AFIO_PeriphMappingType)31)   /* Remap available only for 100-pin and 144-pin packages. */

/* USART2 AFIO */
#define USART2_CTS_PA0_RTS_PA1_TX_PA2_RX_PA3_CK_PA4  ((AFIO_PeriphMappingType)32)
#define USART2_CTS_PD3_RTS_PD4_TX_PD5_RX_PD6_CK_PD7  ((AFIO_PeriphMappingType)33)    /* Remap available only for 100-pin and 144-pin packages */

/* USART1 AFIO */
#define USART1_TX_PA9_RX_PA10   ((AFIO_PeriphMappingType)34)
#define USART1_TX_PB6_RX_PB7    ((AFIO_PeriphMappingType)35)

/* I2C1 AFIO */
#define I2C1_SCL_PB6_SDA_PB7    ((AFIO_PeriphMappingType)36)
#define I2C1_SCL_PB8_SDA_PB9    ((AFIO_PeriphMappingType)37)

/* SPI1 AFIO */
#define SPI1_NSS_PA4_SCK_PA5_MISO_PA6_MOSI_PA7     ((AFIO_PeriphMappingType)38)
#define SPI1_NSS_PA15_SCK_PB3_MISO_PB4_MOSI_PB5    ((AFIO_PeriphMappingType)39)

/* ADC1 external trigger injected conversion alternate function remapping */
#define ADC1_EXTERNAL_TRIGGER_INJECTED_CONVERSION_EXTI15   ((AFIO_PeriphMappingType)40)
#define ADC1_EXTERNAL_TRIGGER_INJECTED_CONVERSION_TIM8_CH4 ((AFIO_PeriphMappingType)41)

/* ADC1 external trigger regular conversion alternate function remapping */
#define ADC1_EXTERNAL_TRIGGER_REGULAR_CONVERSION_EXTI11      ((AFIO_PeriphMappingType)42)
#define ADC1_EXTERNAL_TRIGGER_REGULAR_CONVERSION_TIM8_TRGO   ((AFIO_PeriphMappingType)43)

/* ADC2 external trigger injected conversion alternate function remapping */
#define ADC2_EXTERNAL_TRIGGER_INJECTED_CONVERSION_EXTI15   ((AFIO_PeriphMappingType)44)
#define ADC2_EXTERNAL_TRIGGER_INJECTED_CONVERSION_TIM8_CH4 ((AFIO_PeriphMappingType)45)

/* ADC2 external trigger regular conversion alternate function remapping */
#define ADC2_EXTERNAL_TRIGGER_REGULAR_CONVERSION_EXTI11      ((AFIO_PeriphMappingType)46)
#define ADC2_EXTERNAL_TRIGGER_REGULAR_CONVERSION_TIM8_TRGO   ((AFIO_PeriphMappingType)47)

#define EXTI0    ((EXTI_PinType)0)
#define EXTI1    ((EXTI_PinType)1)
#define EXTI2    ((EXTI_PinType)2)
#define EXTI3    ((EXTI_PinType)3)
#define EXTI4    ((EXTI_PinType)4)
#define EXTI5    ((EXTI_PinType)5)
#define EXTI6    ((EXTI_PinType)6)
#define EXTI7    ((EXTI_PinType)7)
#define EXTI8    ((EXTI_PinType)8)
#define EXTI9    ((EXTI_PinType)9)
#define EXTI10   ((EXTI_PinType)10)
#define EXTI11   ((EXTI_PinType)11)
#define EXTI12   ((EXTI_PinType)12)
#define EXTI13   ((EXTI_PinType)13)
#define EXTI14   ((EXTI_PinType)14)
#define EXTI15   ((EXTI_PinType)15)

#define EXTI_PORTA  ((EXTI_PortType)0)
#define EXTI_PORTB  ((EXTI_PortType)1)
#define EXTI_PORTC  ((EXTI_PortType)2)
#define EXTI_PORTD  ((EXTI_PortType)3)
#define EXTI_PORTE  ((EXTI_PortType)4)
#define EXTI_PORTF  ((EXTI_PortType)5)
#define EXTI_PORTG  ((EXTI_PortType)6)

#define EVENTOUT_PIN0    ((Eventout_PinType)0)
#define EVENTOUT_PIN1    ((Eventout_PinType)1)
#define EVENTOUT_PIN2    ((Eventout_PinType)2)
#define EVENTOUT_PIN3    ((Eventout_PinType)3)
#define EVENTOUT_PIN4    ((Eventout_PinType)4)
#define EVENTOUT_PIN5    ((Eventout_PinType)5)
#define EVENTOUT_PIN6    ((Eventout_PinType)6)
#define EVENTOUT_PIN7    ((Eventout_PinType)7)
#define EVENTOUT_PIN8    ((Eventout_PinType)8)
#define EVENTOUT_PIN9    ((Eventout_PinType)9)
#define EVENTOUT_PIN10   ((Eventout_PinType)10)
#define EVENTOUT_PIN11   ((Eventout_PinType)11)
#define EVENTOUT_PIN12   ((Eventout_PinType)12)
#define EVENTOUT_PIN13   ((Eventout_PinType)13)
#define EVENTOUT_PIN14   ((Eventout_PinType)14)
#define EVENTOUT_PIN15   ((Eventout_PinType)15)

#define EVENTOUT_PORTA  ((Eventout_PortType)0)
#define EVENTOUT_PORTB  ((Eventout_PortType)1)
#define EVENTOUT_PORTC  ((Eventout_PortType)2)
#define EVENTOUT_PORTD  ((Eventout_PortType)3)
#define EVENTOUT_PORTE  ((Eventout_PortType)4)

void  AFIO_CAN_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_JTAG_OR_SWD_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_TIM4_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_TIM3_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_TIM2_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_TIM1_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_TIM9_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_TIM10_PinMapping(AFIO_PeriphMappingType  AFIO_PeriphMapping);
void  AFIO_TIM11_PinMapping(AFIO_PeriphMappingType  AFIO_PeriphMapping);
void  AFIO_TIM13_PinMapping(AFIO_PeriphMappingType  AFIO_PeriphMapping);
void  AFIO_TIM14_PinMapping(AFIO_PeriphMappingType  AFIO_PeriphMapping);
void  AFIO_USART3_PinMapping(AFIO_PeriphMappingType AFIO_PeriphMapping);
void  AFIO_USART2_PinMapping(AFIO_PeriphMappingType AFIO_PeriphMapping);
void  AFIO_USART1_PinMapping(AFIO_PeriphMappingType AFIO_PeriphMapping);
void  AFIO_I2C1_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_SPI1_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_ADC1_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);
void  AFIO_ADC2_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping);

void  AFIO_EXTI_PinMapping(EXTI_PinType EXTI_Pin, EXTI_PortType  EXTI_Port);
void  AFIO_Eventout_PinMapping(Eventout_PinType Eventout_Pin, Eventout_PortType  Eventout_Port);
#endif /* AFIO_H */