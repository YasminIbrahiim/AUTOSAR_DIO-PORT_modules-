/*****************************************************************************************/
/************ STM32f103xx AFIO Driver                      *******************************/ 
/************ File Name  : AFIO.c                          *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/

void  AFIO_CAN_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	switch (AFIO_PeriphMapping)
	{
		case CAN_RX_PA11_TX_PA12:
		AFIO->AFIO_MAPR |= 0x00000000 << 13;
		break;
		case CAN_RX_PB8_TX_PB9:
	    AFIO->AFIO_MAPR |= 0x00000002 << 13;
		break;
	    case CAN_RX_PD0_TX_PD1:
		AFIO->AFIO_MAPR |= 0x00000003 << 13;
		break;
	}
}

void  AFIO_JTAG_OR_SWD_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	switch (AFIO_PeriphMapping)
	{
		case JTMS_PA13_JTCK_PA14_JTDI_PA15_JTDO_PB3_NJTRST_PB4: 
		AFIO->AFIO_MAPR |= 0x00000000 << 24;
		break;
		case JTMS_PA13_JTCK_PA14_JTDI_PA15_JTDO_PB3           : 
		AFIO->AFIO_MAPR |= 0x00000001 << 24;
		break;
		case JTMS_PA13_JTCK_PA14                              : 
		AFIO->AFIO_MAPR |= 0x00000002 << 24;
		break;
		case JTAG_DP_Disabled_SW_DP_Disabled                  : 
		AFIO->AFIO_MAPR |= 0x00000004 << 24;
		break;
	}	
}

void  AFIO_TIM4_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == TIM4_CH1_PB6_CH2_PB7_CH3_PB8_CH4_PB9)
	{
		AFIO->AFIO_MAPR |= 0x00000000 << 12;
	}else if(AFIO_PeriphMapping == TIM4_CH1_PD12_CH2_PD13_CH3_PD14_CH4_PD15)
	{
		AFIO->AFIO_MAPR |= 0x00000001 << 12;
	}else
	{
		
	}
}

void  AFIO_TIM3_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	switch (AFIO_PeriphMapping)
	{
		case TIM3_CH1_PA6_CH2_PA7_CH3_PB0_CH4_PB1 :
		AFIO->AFIO_MAPR |= 0x00000000 << 10;
		break;
		case TIM3_CH1_PB4_CH2_PB5_CH3_PB0_CH4_PB1 :
		AFIO->AFIO_MAPR |= 0x00000001 << 10;
		break;
		case TIM3_CH1_PC6_CH2_PC7_CH3_PC8_CH4_PC9 :
		AFIO->AFIO_MAPR |= 0x00000003 << 10;
		break;
	}
}

void  AFIO_TIM2_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	switch (AFIO_PeriphMapping)
	{
		case TIM2_CH1_ETR_PA0_CH2_PA1_CH3_PA2_CH4_PA3   : 
		AFIO->AFIO_MAPR |= 0x00000000 << 8;
		break; 
		case TIM2_CH1_ETR_PA15_CH2_PB3_CH3_PA2_CH4_PA3  :
		AFIO->AFIO_MAPR |= 0x00000001 << 8;
		break;
		case TIM2_CH1_ETR_PA0_CH2_PA1_CH3_PB10_CH4_PB11 : 
		AFIO->AFIO_MAPR |= 0x00000002 << 8;
		break;
	    case TIM2_CH1_ETR_PA15_CH2_PB3_CH3_PB10_CH4_PB11: 
		AFIO->AFIO_MAPR |= 0x00000003 << 8;
		break;
	}
}

void  AFIO_TIM1_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	switch (AFIO_PeriphMapping)
	{
		case TIM1_ETR_PA12_CH1_PA8_CH2_PA9_CH3_PA10_CH4_PA11_BKIN_PB12_CH1N_PB13_CH2N_PB14_CH3N_PB15: 
		AFIO->AFIO_MAPR |= 0x00000000 << 6;	
		break;
		case TIM1_ETR_PA12_CH1_PA8_CH2_PA9_CH3_PA10_CH4_PA11_BKIN_PA6_CH1N_PA7_CH2N_PB0_CH3N_PB1    : 
		AFIO->AFIO_MAPR |= 0x00000001 << 6;	
		break;
		case TIM1_ETR_PE7_CH1_PE9_CH2_PE11_CH3_PE13_CH4_PE14_BKIN_PE15_CH1N_PE8_CH2N_PE10_CH3N_PE12 : 
		AFIO->AFIO_MAPR |= 0x00000003 << 6;		
		break;		
	}
}

void  AFIO_TIM9_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == TIM9_CH1_PA2_CH2_PA3)
	{
		AFIO->AFIO_MAPR2 |= 0x00000000 << 5;
	}else if(AFIO_PeriphMapping == TIM9_CH1_PE5_CH2_PE6)
	{
		AFIO->AFIO_MAPR2 |= 0x00000001 << 5;
	}else
	{
		
	}
}

void  AFIO_TIM10_PinMapping(AFIO_PeriphMappingType  AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == TIM10_CH1_PB8)
	{                         
		AFIO->AFIO_MAPR2 |= 0x00000000 << 6;
	}else if(AFIO_PeriphMapping == TIM10_CH1_PF6)
	{
		AFIO->AFIO_MAPR2 |= 0x00000001 << 6;
	}else
	{
		
	}
}

void  AFIO_TIM11_PinMapping(AFIO_PeriphMappingType  AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == TIM11_CH1_PB9)
	{                         
		AFIO->AFIO_MAPR2 |= 0x00000000 << 7;
	}else if(AFIO_PeriphMapping == TIM11_CH1_PF7)
	{
		AFIO->AFIO_MAPR2 |= 0x00000001 << 7;
	}else
	{
		
	}
}
void  AFIO_TIM13_PinMapping(AFIO_PeriphMappingType  AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == TIM13_CH1_PA6)
	{                         
		AFIO->AFIO_MAPR2 |= 0x00000000 << 8;
	}else if(AFIO_PeriphMapping == TIM13_CH1_PF8)
	{
		AFIO->AFIO_MAPR2 |= 0x00000001 << 8;
	}else
	{
		
	}
}
void  AFIO_TIM14_PinMapping(AFIO_PeriphMappingType  AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == TIM14_CH1_PA7)
	{                         
		AFIO->AFIO_MAPR2 |= 0x00000000 << 9;
	}else if(AFIO_PeriphMapping == TIM14_CH1_PF9)
	{
		AFIO->AFIO_MAPR2 |= 0x00000001 << 9;
	}
	else
	{

	}
}

void  AFIO_USART3_PinMapping(AFIO_PeriphMappingType AFIO_PeriphMapping)
{
	switch (AFIO_PeriphMapping)
	{
		case USART3_TX_PB10_RX_PB11_CK_PB12_CTS_PB13_RTS_PB14:
		AFIO->AFIO_MAPR |= 0x00000000 << 4;
		break;
		case USART3_TX_PC10_RX_PC11_CK_PC12_CTS_PB13_RTS_PB14:
		AFIO->AFIO_MAPR |= 0x00000001 << 4;
		break;
		case USART3_TX_PD8_RX_PD9_CK_PD10_CTS_PD11_RTS_PD12  :
		AFIO->AFIO_MAPR |= 0x00000003 << 4;
		break;
	}
}

void  AFIO_USART2_PinMapping(AFIO_PeriphMappingType AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == USART2_CTS_PA0_RTS_PA1_TX_PA2_RX_PA3_CK_PA4 )
	{	
		AFIO->AFIO_MAPR |= 0x00000000 << 3;
	}else if(AFIO_PeriphMapping == USART2_CTS_PD3_RTS_PD4_TX_PD5_RX_PD6_CK_PD7)
	{
		AFIO->AFIO_MAPR |= 0x00000001 << 3;
	}else
	{
		
	}
}

void  AFIO_USART1_PinMapping(AFIO_PeriphMappingType AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == USART1_TX_PA9_RX_PA10)
	{ 
		AFIO->AFIO_MAPR |= 0x00000000 << 2;
	}else if(AFIO_PeriphMapping == USART1_TX_PB6_RX_PB7)
	{
		AFIO->AFIO_MAPR |= 0x00000001 << 2;
	}
	else
	{
		
	}
}

void  AFIO_I2C1_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == I2C1_SCL_PB6_SDA_PB7)
	{                         
		AFIO->AFIO_MAPR |= 0x00000000 << 1;
	}else if(AFIO_PeriphMapping == I2C1_SCL_PB8_SDA_PB9)
	{
		AFIO->AFIO_MAPR |= 0x00000001 << 1;
	}
	else
	{
		
	}
}

void  AFIO_SPI1_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	if (AFIO_PeriphMapping == SPI1_NSS_PA4_SCK_PA5_MISO_PA6_MOSI_PA7 )
	{                         
		AFIO->AFIO_MAPR |= 0x00000000 << 0;
	}else if(AFIO_PeriphMapping == SPI1_NSS_PA15_SCK_PB3_MISO_PB4_MOSI_PB5)
	{
		AFIO->AFIO_MAPR |= 0x00000001 << 0;
	}
	else
	{
		
	}
}

void  AFIO_ADC1_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	switch(AFIO_PeriphMapping)
	{
		case ADC1_EXTERNAL_TRIGGER_REGULAR_CONVERSION_EXTI11:
		AFIO->AFIO_MAPR |= 0x00000000 << 18;
	    break;
		case ADC1_EXTERNAL_TRIGGER_REGULAR_CONVERSION_TIM8_TRGO:
		AFIO->AFIO_MAPR |= 0x00000001 << 18;
		break;
		case ADC1_EXTERNAL_TRIGGER_INJECTED_CONVERSION_EXTI15: 
		AFIO->AFIO_MAPR |= 0x00000000 << 17;
		break;
		case ADC1_EXTERNAL_TRIGGER_INJECTED_CONVERSION_TIM8_CH4:
		AFIO->AFIO_MAPR |= 0x00000001 << 17;
		break;
	}
}                            

void  AFIO_ADC2_PinMapping(AFIO_PeriphMappingType   AFIO_PeriphMapping)
{
	switch(AFIO_PeriphMapping)
	{
		case ADC2_EXTERNAL_TRIGGER_REGULAR_CONVERSION_EXTI11:
		AFIO->AFIO_MAPR |= 0x00000000 << 20;
	    break;
		case ADC2_EXTERNAL_TRIGGER_REGULAR_CONVERSION_TIM8_TRGO:
		AFIO->AFIO_MAPR |= 0x00000001 << 20;
		break;
		case ADC2_EXTERNAL_TRIGGER_INJECTED_CONVERSION_EXTI15: 
		AFIO->AFIO_MAPR |= 0x00000000 << 19;
		break;
		case ADC2_EXTERNAL_TRIGGER_INJECTED_CONVERSION_TIM8_CH4:
		AFIO->AFIO_MAPR |= 0x00000001 << 19;
		break;
	}
}

void  AFIO_EXTI_PinMapping(EXTI_PinType   EXTI_Pin, EXTI_PortType  EXTI_Port)
{
	if( (EXTI_Pin =< EXTI3) && (EXTI_Pin => EXTI0) )
	{
		AFIO->AFIO_EXTICR1 |= EXTI_Port << (EXTI_Pin*4);
	}else if( (EXTI_Pin =< EXTI7) && (EXTI_Pin => EXTI4) )
	{
		AFIO->AFIO_EXTICR2 |= EXTI_Port << ((EXTI_Pin - 4)*4);
	}else if( (EXTI_Pin =< EXTI11) && (EXTI_Pin => EXTI8) )
	{
		AFIO->AFIO_EXTICR3 |= EXTI_Port << ((EXTI_Pin - 8)*4);
	}else if( (EXTI_Pin =< EXTI12) && (EXTI_Pin => EXTI15) )
	{
		AFIO->AFIO_EXTICR4 |= EXTI_Port << ((EXTI_Pin - 12)*4);
	}else
	{
		
	}
}

void  AFIO_Eventout_PinMapping(Eventout_PinType Eventout_Pin, Eventout_PortType  Eventout_Port)
{
	
	AFIO->AFIO_EVCR |= Eventout_Pin;
	AFIO->AFIO_EVCR |= Eventout_Port << 4;
	// Event output enable
	AFIO->AFIO_EVCR |= 0x00000001 << 7;
}