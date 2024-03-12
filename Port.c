/*******************************************************************************************************/
/************ STM32f103xx Port_Driver                                ***********************************/ 
/************ File Name  : Port.c                                    ***********************************/ 
/************ Author     : Yasmeen Ibrahim                           ***********************************/           
/************ Description:                                           ***********************************/
/*******************************************************************************************************/
#include "Port.h"
#include "Port_Regs.h"
#include "RCC.h"
#include "AFIO.h"

#if (DioDevErrorDetect == STD_ON) 
#include "Det.h"

/* AUTOSAR Version checking between Det and Port Module */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION  != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION  != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

Port_ConfigType  PortConfigPtr = NULL_Ptr;

#define PORT_MASK_ID   0x000000F0
#define PIN_MASK_ID    0x0000000F

#define PORTA          0x00000000
#define PORTB          0x00000010
#define PORTC          0x00000020
#define PORTD          0x00000030
#define PORTE          0x00000040
#define PORTF          0x00000050
#define PORTG          0x00000060

/*
@Service Name       : Port_Init
@Service ID [hex]   : 0x00
@Sync/Async         : Synchronous
@Reentrancy         : Non Reentrant
@Parameters (in)    : (ConfigPtr) Pointer to configuration set.
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None 
@Description        : Initializes the Port Driver module      */
void Port_Init (const Port_ConfigType* ConfigPtr)
{
	uint32      PortTypeLOC ;
	uint32      PinTypeLOC  ;
	PortConfigPtr = ConfigPtr;
	GPIOx_REG*  GPIO_BaseAddress = NULL_Ptr;   
	for(uint8 u8Counter = 0 ;u8Counter < PortNumberOfPortPins ; u8Counter++ )
	{
		PortTypeLOC = (PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinId & PORT_MASK_ID) >> 4 ;
		PinTypeLOC  = PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinId & PIN_MASK_ID  ;
		switch(PortTypeLOC)
		{
			case PORTA:
			GPIO_BaseAddress = GPIOA;
			RCC_APB2_peripheral_Set_clock(GPIOA_APB2_PERIPHERAL);
			break;
			case PORTB:
			GPIO_BaseAddress = GPIOB;
			RCC_APB2_peripheral_Set_clock(GPIOB_APB2_PERIPHERAL);
			break;
			case PORTC:
			GPIO_BaseAddress = GPIOC;
			RCC_APB2_peripheral_Set_clock(GPIOC_APB2_PERIPHERAL);
			break;
			case PORTD:
			GPIO_BaseAddress = GPIOD;
			RCC_APB2_peripheral_Set_clock(GPIOD_APB2_PERIPHERAL);
			break;
			case PORTE:
			GPIO_BaseAddress = GPIOE;
			RCC_APB2_peripheral_Set_clock(GPIOE_APB2_PERIPHERAL);
			break;
			case PORTF:
			GPIO_BaseAddress = GPIOF;
			RCC_APB2_peripheral_Set_clock(GPIOF_APB2_PERIPHERAL);
			break;
			case PORTG:
			RCC_APB2_peripheral_Set_clock(GPIOG_APB2_PERIPHERAL);
			GPIO_BaseAddress = GPIOG;
			break;
		}
		if((PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_IN)
		{
			/*  In input mode CNFy:
			    00: Analog mode
			    01: Floating input (reset state)
			    10: Input with pull-up / pull-down
			    11: Reserved               */		
			GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[u8Counter].Input_PinType) << (2 + (PinTypeLOC * 4));
		}else if((PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_OUT)
		{
			/* In output mode CNFy:
			   00: General purpose output push-pull
			   01: General purpose output Open-drain
			   10: Alternate function output Push-pull
			   11: Alternate function output Open-drain */
			GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[u8Counter].Output_PinType) << (2 + (PinTypeLOC * 4));
			GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;
		}
		else
		{
			/* do nothing */
		}
		
		if((PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinMode) != PORT_PIN_MODE_DIO)
		{
			RCC_APB2_peripheral_Set_clock(AFIO_APB2_PERIPHERAL);
		}
		switch((PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinMode))
		{
			case  PORT_PIN_MODE_ADC: 
			/* enable ADC clock */
			/* AFIO pin mapping */
				if((PortConfigPtr->Port_PinAFIOPeriph) == ADC1)
				{
					RCC_APB2_peripheral_Set_clock(ADC1_APB2_PERIPHERAL);
				}else if((PortConfigPtr->Port_PinAFIOPeriph) == ADC2)
				{
					RCC_APB2_peripheral_Set_clock(ADC2_APB2_PERIPHERAL); 
				}else if((PortConfigPtr->Port_PinAFIOPeriph) == ADC3)
				{
					RCC_APB2_peripheral_Set_clock(ADC3_APB2_PERIPHERAL);
				}
			break;
			case  PORT_PIN_MODE_CAN:
				RCC_APB1_peripheral_Set_clock(CAN_APB1_PERIPHERAL);
			break;		
			case  PORT_PIN_MODE_DIO:
				/* do nothing */
			break;
			// Set general purpose timer clock */
			case PORT_PIN_MODE_DIO_GPT: 
				switch(PortConfigPtr->Port_PinAFIOPeriph)
				{	 
					case TIM2 : 
					RCC_APB1_peripheral_Reset_clock(TIM2_APB1_PERIPHERAL);
					break;
					case TIM3 : 
					RCC_APB1_peripheral_Reset_clock(TIM3_APB1_PERIPHERAL);
					break;
					case TIM4 : 
					RCC_APB1_peripheral_Reset_clock(TIM4_APB1_PERIPHERAL);
					break;
					case TIM5 :
					RCC_APB1_peripheral_Reset_clock(TIM5_APB1_PERIPHERAL);
					break;
					case TIM9 : 
					RCC_APB2_peripheral_Reset_clock(TIM9_APB2_PERIPHERAL);
					break;
					case TIM10: 
					RCC_APB2_peripheral_Reset_clock(TIM10_APB2_PERIPHERAL);
					break;
					case TIM11: 
					RCC_APB2_peripheral_Reset_clock(TIM11_APB2_PERIPHERAL);
					break;
					case TIM12: 
					RCC_APB1_peripheral_Reset_clock(TIM12_APB1_PERIPHERAL);
					break;
					case TIM13: 
					RCC_APB1_peripheral_Reset_clock(TIM13_APB1_PERIPHERAL);
					break;
					case TIM14: 
					RCC_APB1_peripheral_Reset_clock(TIM14_APB1_PERIPHERAL);
					break;	
				}
			break;
			case  PORT_PIN_MODE_DIO_WDG:
				RCC_APB1_peripheral_Reset_clock(WWDG_APB1_PERIPHERAL);
			break;
			case  PORT_PIN_MODE_ICU: 
				switch(PortConfigPtr->Port_PinAFIOPeriph)
				{	
					case TIM1 : 
					RCC_APB2_peripheral_Reset_clock(TIM1_APB2_PERIPHERAL);
					break; 
					case TIM2 : 
					RCC_APB1_peripheral_Reset_clock(TIM2_APB1_PERIPHERAL);
					break;
					case TIM3 : 
					RCC_APB1_peripheral_Reset_clock(TIM3_APB1_PERIPHERAL);
					break;
					case TIM4 : 
					RCC_APB1_peripheral_Reset_clock(TIM4_APB1_PERIPHERAL);
					break;
					case TIM5 :
					RCC_APB1_peripheral_Reset_clock(TIM5_APB1_PERIPHERAL);
					break;
					case TIM6 : 
					RCC_APB1_peripheral_Reset_clock(TIM6_APB1_PERIPHERAL);
					break;
					case TIM7 : 
					RCC_APB1_peripheral_Reset_clock(TIM7_APB1_PERIPHERAL);
					break;
					case TIM8 : 
					RCC_APB2_peripheral_Reset_clock(TIM8_APB2_PERIPHERAL);
					break;
					case TIM9 : 
					RCC_APB2_peripheral_Reset_clock(TIM9_APB2_PERIPHERAL);
					break;
					case TIM10: 
					RCC_APB2_peripheral_Reset_clock(TIM10_APB2_PERIPHERAL);
					break;
					case TIM11: 
					RCC_APB2_peripheral_Reset_clock(TIM11_APB2_PERIPHERAL);
					break;
					case TIM12: 
					RCC_APB1_peripheral_Reset_clock(TIM12_APB1_PERIPHERAL);
					break;
					case TIM13: 
					RCC_APB1_peripheral_Reset_clock(TIM13_APB1_PERIPHERAL);
					break;
					case TIM14: 
					RCC_APB1_peripheral_Reset_clock(TIM14_APB1_PERIPHERAL);
					break;	
				}
			break;	
			case  PORT_PIN_MODE_MEM: 
				 
				if(PortConfigPtr->Port_PinAFIOPeriph == FSMC) 
				{
					RCC_AHB1_peripheral_Reset_clock(FSMC_AHB_PERIPHERAL );
				}                                        
			break;
			case  PORT_PIN_MODE_PWM:
				switch(PortConfigPtr->Port_PinAFIOPeriph)
				{	
					case TIM1 : 
					RCC_APB2_peripheral_Reset_clock(TIM1_APB2_PERIPHERAL);
					break; 
					case TIM2 : 
					RCC_APB1_peripheral_Reset_clock(TIM2_APB1_PERIPHERAL);
					break;
					case TIM3 : 
					RCC_APB1_peripheral_Reset_clock(TIM3_APB1_PERIPHERAL);
					break;
					case TIM4 : 
					RCC_APB1_peripheral_Reset_clock(TIM4_APB1_PERIPHERAL);
					break;
					case TIM5 : 
					RCC_APB1_peripheral_Reset_clock(TIM5_APB1_PERIPHERAL);
					break;
					case TIM6 : 
					RCC_APB1_peripheral_Reset_clock(TIM6_APB1_PERIPHERAL);
					break;
					case TIM7 : 
					RCC_APB1_peripheral_Reset_clock(TIM7_APB1_PERIPHERAL);
					break;
					case TIM8 : 
					RCC_APB2_peripheral_Reset_clock(TIM8_APB2_PERIPHERAL);
					break;
					case TIM9 : 
					RCC_APB2_peripheral_Reset_clock(TIM9_APB2_PERIPHERAL);
					break;
					case TIM10: 
					RCC_APB2_peripheral_Reset_clock(TIM10_APB2_PERIPHERAL);
					break;
					case TIM11: 
					RCC_APB2_peripheral_Reset_clock(TIM11_APB2_PERIPHERAL);
					break;
					case TIM12: 
					RCC_APB1_peripheral_Reset_clock(TIM12_APB1_PERIPHERAL);
					break;
					case TIM13: 
					RCC_APB1_peripheral_Reset_clock(TIM13_APB1_PERIPHERAL);
					break;
					case TIM14: 
					RCC_APB1_peripheral_Reset_clock(TIM14_APB1_PERIPHERAL);
					break;	
				}	
			break;
			case  PORT_PIN_MODE_SPI:
				if((PortConfigPtr->Port_PinAFIOPeriph) == SPI1)
				{
					RCC_APB2_peripheral_Set_clock(SPI1_APB2_PERIPHERAL);
				}else if((PortConfigPtr->Port_PinAFIOPeriph) == SPI2)
				{
					RCC_APB1_peripheral_Set_clock(SPI2_APB1_PERIPHERAL); 
				}
				else if((PortConfigPtr->Port_PinAFIOPeriph) == SPI3)
				{
					RCC_APB1_peripheral_Set_clock(SPI3_APB1_PERIPHERAL);
				}
			break;
			case  PORT_PIN_MODE_I2C:
				if((PortConfigPtr->Port_PinAFIOPeriph) == I2C1)
				{
					RCC_APB1_peripheral_Set_clock(I2C1_APB2_PERIPHERAL);
				}else if((PortConfigPtr->Port_PinAFIOPeriph) == I2C2)
				{
					RCC_APB1_peripheral_Set_clock(I2C2_APB1_PERIPHERAL); 
				}
			break;
			case  PORT_PIN_MODE_USART:
				switch
				{
					case USART1:
					RCC_APB2_peripheral_Set_clock(USART1_APB2_PERIPHERAL);
					break;
					case USART2:
					RCC_APB1_peripheral_Set_clock(USART2_APB1_PERIPHERAL);
					break;
					case USART3:
					RCC_APB1_peripheral_Set_clock(USART3_APB1_PERIPHERAL);
					break;
					case USART4:
					RCC_APB1_peripheral_Set_clock(USART4_APB1_PERIPHERAL);
					break;
					case USART5: 
					RCC_APB1_peripheral_Set_clock(USART5_APB1_PERIPHERAL);
					break;
				}
			break;	
			case PORT_PIN_MODE_DAC:
				RCC_APB1_peripheral_Set_clock(DAC_APB1_PERIPHERAL);
			break;
			case PORT_PIN_MODE_SDIO:
				RCC_AHB_peripheral_Set_clock(SDIO_AHB_PERIPHERAL);
			break
			case PORT_PIN_MODE_USB:
				RCC_APB1_peripheral_Set_clock(USB_APB1_PERIPHERAL);
			break;
			case PORT_PIN_MODE_EXTI:
			AFIO_EXTI_PinMapping(PinTypeLOC, PortTypeLOC);
			break;
			case PORT_PIN_MODE_EVENTOUT:
			AFIO_Eventout_PinMapping(PinTypeLOC, PortTypeLOC);
			break;
		}
		
	}
}   
   
/* 
@Service Name       : Port_SetPinDirection
@Service ID [hex]   : 0x01
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (Pin) Port Pin ID number
                      (Direction) Port Pin Direction
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : Sets the port pin direction                */
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction)
{
	PortTypeLOC = (Pin & PORT_MASK_ID) >> 4;
	PinTypeLOC  = Pin & PIN_MASK_ID  ;
	GPIOx_REG*  GPIO_BaseAddress = NULL_Ptr;
	switch(PortTypeLOC)
	{
		case PORTA:
		GPIO_BaseAddress = GPIOA;
		RCC_APB2_peripheral_Set_clock(GPIOA_APB2_PERIPHERAL);
		break;
		case PORTB:
		GPIO_BaseAddress = GPIOB;
		RCC_APB2_peripheral_Set_clock(GPIOB_APB2_PERIPHERAL);
		break;
		case PORTC:
		GPIO_BaseAddress = GPIOC;
		RCC_APB2_peripheral_Set_clock(GPIOC_APB2_PERIPHERAL);
		break;
		case PORTD:
		GPIO_BaseAddress = GPIOD;
		RCC_APB2_peripheral_Set_clock(GPIOD_APB2_PERIPHERAL);
		break;
		case PORTE:
		GPIO_BaseAddress = GPIOE;
		RCC_APB2_peripheral_Set_clock(GPIOE_APB2_PERIPHERAL);
		break;
		case PORTF:
		GPIO_BaseAddress = GPIOF;
		RCC_APB2_peripheral_Set_clock(GPIOF_APB2_PERIPHERAL);
		break;
		case PORTG:
		RCC_APB2_peripheral_Set_clock(GPIOG_APB2_PERIPHERAL);
		GPIO_BaseAddress = GPIOG;
		break;
	}
	if(Direction == PORT_PIN_IN)
	{
		/*  In input mode CNFy:
		    00: Analog mode
		    01: Floating input (reset state)
		    10: Input with pull-up / pull-down
		    11: Reserved               */		
		GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[Pin].Input_PinType) << (2 + (PinTypeLOC * 4));
	}else if(Direction == PORT_PIN_OUT)
	{
		/* In output mode CNFy:
		   00: General purpose output push-pull
		   01: General purpose output Open-drain
		   10: Alternate function output Push-pull
		   11: Alternate function output Open-drain */
		GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[Pin].Output_PinType) << (2 + (PinTypeLOC * 4));
		GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[Pin].OutputMaxSpeed) << (PinTypeLOC * 4) ;
	}
	else
	{
		/* do nothing */
	}
}

/* 
@Service Name       : Port_RefreshPortDirection
@Service ID [hex]   : 0x02
@Sync/Async         : Synchronous
@Reentrancy         : Non Reentrant
@Parameters (in)    : None
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : Refreshes port direction.                   */
void Port_RefreshPortDirection (void)
{
	uint32      PortTypeLOC ;
	uint32      PinTypeLOC  ;
	GPIOx_REG*  GPIO_BaseAddress = NULL_Ptr;
	for(uint8 u8Counter = 0 ;u8Counter < PortNumberOfPortPins ; u8Counter++ )
	{
		PortTypeLOC = (PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinId & PORT_MASK_ID) >> 4 ;
		PinTypeLOC  = PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinId & PIN_MASK_ID  ;
		switch(PortTypeLOC)
		{
			case PORTA:
			GPIO_BaseAddress = GPIOA;
			RCC_APB2_peripheral_Set_clock(GPIOA_APB2_PERIPHERAL);
			break;
			case PORTB:
			GPIO_BaseAddress = GPIOB;
			RCC_APB2_peripheral_Set_clock(GPIOB_APB2_PERIPHERAL);
			break;
			case PORTC:
			GPIO_BaseAddress = GPIOC;
			RCC_APB2_peripheral_Set_clock(GPIOC_APB2_PERIPHERAL);
			break;
			case PORTD:
			GPIO_BaseAddress = GPIOD;
			RCC_APB2_peripheral_Set_clock(GPIOD_APB2_PERIPHERAL);
			break;
			case PORTE:
			GPIO_BaseAddress = GPIOE;
			RCC_APB2_peripheral_Set_clock(GPIOE_APB2_PERIPHERAL);
			break;
			case PORTF:
			GPIO_BaseAddress = GPIOF;
			RCC_APB2_peripheral_Set_clock(GPIOF_APB2_PERIPHERAL);
			break;
			case PORTG:
			RCC_APB2_peripheral_Set_clock(GPIOG_APB2_PERIPHERAL);
			GPIO_BaseAddress = GPIOG;
			break;
		}
		if((PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirectionChangeable ) == PORT_PIN_IN)
		{
			/*  In input mode CNFy:
			    00: Analog mode
			    01: Floating input (reset state)
			    10: Input with pull-up / pull-down
			    11: Reserved               */		
			GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[u8Counter].Input_PinType) << (2 + (PinTypeLOC * 4));
		}else if((PortConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirectionChangeable ) == PORT_PIN_OUT)
		{
			/* In output mode CNFy:
			   00: General purpose output push-pull
			   01: General purpose output Open-drain
			   10: Alternate function output Push-pull
			   11: Alternate function output Open-drain */
			GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[u8Counter].Output_PinType) << (2 + (PinTypeLOC * 4));
			GPIO_BaseAddress->GPIOx_CRL |= (PortConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;
		}
		else
		{
			/* do nothing */
		}	
	}
}

/* 
@Service Name       : Port_GetVersionInfo
@Service ID [hex]   : 0x03
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : None
@Parameters (inout) : None
@Parameters (out)   : (versioninfo) Pointer to where to store the version information of this module.
@Return value       : None
@Description        : Returns the version information of this module       */
void Port_GetVersionInfo (Std_VersionInfoType* versioninfo)
{
	versioninfo->vendorID         = PORT_VENDOR_ID;
	versioninfo->moduleID         = PORT_MODULE_ID;
	versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
	versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;
}                

/* 
@Service Name       : Port_SetPinMode
@Service ID [hex]   : 0x04
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (Pin) Port Pin ID number
                      (Mode) New Port Pin mode to be set on port pin.
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : Sets the port pin mode                          */
void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode)
{
	PortTypeLOC = (Pin & PORT_MASK_ID ) >> 4;
	PinTypeLOC  = Pin & PIN_MASK_ID  ;
	GPIOx_REG*  GPIO_BaseAddress = NULL_Ptr;
	/* enable GPIO driver clock */
	/* enable AFIO */
	switch(PortTypeLOC)
	{
		case PORTA:
		GPIO_BaseAddress = GPIOA;
		RCC_APB2_peripheral_Set_clock(GPIOA_APB2_PERIPHERAL);
		break;
		case PORTB:
		GPIO_BaseAddress = GPIOB;
		RCC_APB2_peripheral_Set_clock(GPIOB_APB2_PERIPHERAL);
		break;
		case PORTC:
		GPIO_BaseAddress = GPIOC;
		RCC_APB2_peripheral_Set_clock(GPIOC_APB2_PERIPHERAL);
		break;
		case PORTD:
		GPIO_BaseAddress = GPIOD;
		RCC_APB2_peripheral_Set_clock(GPIOD_APB2_PERIPHERAL);
		break;
		case PORTE:
		GPIO_BaseAddress = GPIOE;
		RCC_APB2_peripheral_Set_clock(GPIOE_APB2_PERIPHERAL);
		break;
		case PORTF:
		GPIO_BaseAddress = GPIOF;
		RCC_APB2_peripheral_Set_clock(GPIOF_APB2_PERIPHERAL);
		break;
		case PORTG:
		RCC_APB2_peripheral_Set_clock(GPIOG_APB2_PERIPHERAL);
		GPIO_BaseAddress = GPIOG;
		break;
	}
	if(Mode != PORT_PIN_MODE_DIO)
	{
		RCC_APB2_peripheral_Set_clock(AFIO_APB2_PERIPHERAL);
	}
	switch(Mode)
	{
		case  PORT_PIN_MODE_ADC: 
		/* enable ADC clock */
		/* AFIO pin mapping */
			if((PortConfigPtr->Port_PinAFIOPeriphChangeable) == ADC1)
			{
				RCC_APB2_peripheral_Set_clock(ADC1_APB2_PERIPHERAL);
				
			}else if((PortConfigPtr->Port_PinAFIOPeriphChangeable) == ADC2)
			{
				RCC_APB2_peripheral_Set_clock(ADC2_APB2_PERIPHERAL); 
			}else if((PortConfigPtr->Port_PinAFIOPeriphChangeable) == ADC3)
			{
				RCC_APB2_peripheral_Set_clock(ADC3_APB2_PERIPHERAL);
			}
		break;
		case  PORT_PIN_MODE_CAN:
			RCC_APB1_peripheral_Set_clock(CAN_APB1_PERIPHERAL);
		break;		
		case  PORT_PIN_MODE_DIO:
			/* do nothing */
		break;
		// Set general purpose timer clock */
		case PORT_PIN_MODE_DIO_GPT: 
			switch(PortConfigPtr->Port_PinAFIOPeriphChangeable)
			{	 
				case TIM2 : 
				RCC_APB1_peripheral_Reset_clock(TIM2_APB1_PERIPHERAL);
				break;
				case TIM3 : 
				RCC_APB1_peripheral_Reset_clock(TIM3_APB1_PERIPHERAL);
				break;
				case TIM4 : 
				RCC_APB1_peripheral_Reset_clock(TIM4_APB1_PERIPHERAL);
				break;
				case TIM5 :
				RCC_APB1_peripheral_Reset_clock(TIM5_APB1_PERIPHERAL);
				break;
				case TIM9 : 
				RCC_APB2_peripheral_Reset_clock(TIM9_APB2_PERIPHERAL);
				break;
				case TIM10: 
				RCC_APB2_peripheral_Reset_clock(TIM10_APB2_PERIPHERAL);
				break;
				case TIM11: 
				RCC_APB2_peripheral_Reset_clock(TIM11_APB2_PERIPHERAL);
				break;
				case TIM12: 
				RCC_APB1_peripheral_Reset_clock(TIM12_APB1_PERIPHERAL);
				break;
				case TIM13: 
				RCC_APB1_peripheral_Reset_clock(TIM13_APB1_PERIPHERAL);
				break;
				case TIM14: 
				RCC_APB1_peripheral_Reset_clock(TIM14_APB1_PERIPHERAL);
				break;	
			}
		break;
		case  PORT_PIN_MODE_DIO_WDG:
			RCC_APB1_peripheral_Reset_clock(WWDG_APB1_PERIPHERAL);
		break;
		case  PORT_PIN_MODE_ICU: 
			switch(PortConfigPtr->Port_PinAFIOPeriphChangeable)
			{	
				case TIM1 : 
				RCC_APB2_peripheral_Reset_clock(TIM1_APB2_PERIPHERAL);
				break; 
				case TIM2 : 
				RCC_APB1_peripheral_Reset_clock(TIM2_APB1_PERIPHERAL);
				break;
				case TIM3 : 
				RCC_APB1_peripheral_Reset_clock(TIM3_APB1_PERIPHERAL);
				break;
				case TIM4 : 
				RCC_APB1_peripheral_Reset_clock(TIM4_APB1_PERIPHERAL);
				break;
				case TIM5 :
				RCC_APB1_peripheral_Reset_clock(TIM5_APB1_PERIPHERAL);
				break;
				case TIM6 : 
				RCC_APB1_peripheral_Reset_clock(TIM6_APB1_PERIPHERAL);
				break;
				case TIM7 : 
				RCC_APB1_peripheral_Reset_clock(TIM7_APB1_PERIPHERAL);
				break;
				case TIM8 : 
				RCC_APB2_peripheral_Reset_clock(TIM8_APB2_PERIPHERAL);
				break;
				case TIM9 : 
				RCC_APB2_peripheral_Reset_clock(TIM9_APB2_PERIPHERAL);
				break;
				case TIM10: 
				RCC_APB2_peripheral_Reset_clock(TIM10_APB2_PERIPHERAL);
				break;
				case TIM11: 
				RCC_APB2_peripheral_Reset_clock(TIM11_APB2_PERIPHERAL);
				break;
				case TIM12: 
				RCC_APB1_peripheral_Reset_clock(TIM12_APB1_PERIPHERAL);
				break;
				case TIM13: 
				RCC_APB1_peripheral_Reset_clock(TIM13_APB1_PERIPHERAL);
				break;
				case TIM14: 
				RCC_APB1_peripheral_Reset_clock(TIM14_APB1_PERIPHERAL);
				break;	
			}
		break;	
		case  PORT_PIN_MODE_MEM: 
			if(PortConfigPtr->Port_PinAFIOPeriphChangeable == FSMC )
			{  
				RCC_AHB1_peripheral_Reset_clock(FSMC_AHB_PERIPHERAL );
			}                                            
		break;
		case  PORT_PIN_MODE_PWM:
			switch(PortConfigPtr->Port_PinAFIOPeriphChangeable)
			{	
				case TIM1 : 
				RCC_APB2_peripheral_Reset_clock(TIM1_APB2_PERIPHERAL);
				break; 
				case TIM2 : 
				RCC_APB1_peripheral_Reset_clock(TIM2_APB1_PERIPHERAL);
				break;
				case TIM3 : 
				RCC_APB1_peripheral_Reset_clock(TIM3_APB1_PERIPHERAL);
				break;
				case TIM4 : 
				RCC_APB1_peripheral_Reset_clock(TIM4_APB1_PERIPHERAL);
				break;
				case TIM5 : 
				RCC_APB1_peripheral_Reset_clock(TIM5_APB1_PERIPHERAL);
				break;
				case TIM6 : 
				RCC_APB1_peripheral_Reset_clock(TIM6_APB1_PERIPHERAL);
				break;
				case TIM7 : 
				RCC_APB1_peripheral_Reset_clock(TIM7_APB1_PERIPHERAL);
				break;
				case TIM8 : 
				RCC_APB2_peripheral_Reset_clock(TIM8_APB2_PERIPHERAL);
				break;
				case TIM9 : 
				RCC_APB2_peripheral_Reset_clock(TIM9_APB2_PERIPHERAL);
				break;
				case TIM10: 
				RCC_APB2_peripheral_Reset_clock(TIM10_APB2_PERIPHERAL);
				break;
				case TIM11: 
				RCC_APB2_peripheral_Reset_clock(TIM11_APB2_PERIPHERAL);
				break;
				case TIM12: 
				RCC_APB1_peripheral_Reset_clock(TIM12_APB1_PERIPHERAL);
				break;
				case TIM13: 
				RCC_APB1_peripheral_Reset_clock(TIM13_APB1_PERIPHERAL);
				break;
				case TIM14: 
				RCC_APB1_peripheral_Reset_clock(TIM14_APB1_PERIPHERAL);
				break;	
			}	
		break;
		case  PORT_PIN_MODE_SPI:
			if((PortConfigPtr->Port_PinAFIOPeriphChangeable) == SPI1)
			{
				RCC_APB2_peripheral_Set_clock(SPI1_APB2_PERIPHERAL);
			}else if((PortConfigPtr->Port_PinAFIOPeriphChangeable) == SPI2)
			{
				RCC_APB1_peripheral_Set_clock(SPI2_APB1_PERIPHERAL); 
			}
			else if((PortConfigPtr->Port_PinAFIOPeriphChangeable) == SPI3)
			{
				RCC_APB1_peripheral_Set_clock(SPI3_APB1_PERIPHERAL);
			}
		break;
		case  PORT_PIN_MODE_I2C:
			if((PortConfigPtr->Port_PinAFIOPeriphChangeable) == I2C1)
			{
				RCC_APB1_peripheral_Set_clock(I2C1_APB2_PERIPHERAL);
			}else if((PortConfigPtr->Port_PinAFIOPeriphChangeable) == I2C2)
			{
				RCC_APB1_peripheral_Set_clock(I2C2_APB1_PERIPHERAL); 
			}
		break;
		case  PORT_PIN_MODE_USART:
			switch
			{
				case USART1:
				RCC_APB2_peripheral_Set_clock(USART1_APB2_PERIPHERAL);
				break;
				case USART2:
				RCC_APB1_peripheral_Set_clock(USART2_APB1_PERIPHERAL);
				break;
				case USART3:
				RCC_APB1_peripheral_Set_clock(USART3_APB1_PERIPHERAL);
				break;
				case USART4:
				RCC_APB1_peripheral_Set_clock(USART4_APB1_PERIPHERAL);
				break;
				case USART5: 
				RCC_APB1_peripheral_Set_clock(USART5_APB1_PERIPHERAL);
				break;
			}
		break;	
		case PORT_PIN_MODE_DAC:
			RCC_APB1_peripheral_Set_clock(DAC_APB1_PERIPHERAL);
		break;
		case PORT_PIN_MODE_SDIO:
			RCC_AHB_peripheral_Set_clock(SDIO_AHB_PERIPHERAL);
		break
		case PORT_PIN_MODE_USB:
			RCC_APB1_peripheral_Set_clock(USB_APB1_PERIPHERAL);
		break;
		case PORT_PIN_MODE_EXTI:
			AFIO_EXTI_PinMapping(PinTypeLOC, PortTypeLOC);
		break;
		case PORT_PIN_MODE_EVENTOUT:
			AFIO_Eventout_PinMapping(PinTypeLOC, PortTypeLOC);
		break;
	}
}