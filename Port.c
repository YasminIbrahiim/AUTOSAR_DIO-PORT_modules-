/*******************************************************************************************************/
/************ STM32f103xx Port_Driver                                ***********************************/ 
/************ File Name  : Port.c                                    ***********************************/ 
/************ Author     : Yasmeen Ibrahim                           ***********************************/           
/************ Description:                                           ***********************************/
/*******************************************************************************************************/
#include "Port.h"
#include "Port_Regs.h"


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
	uint32  PortTypeLOC = ConfigPtr->arrPort_PinConfig[u8Counter].PortPinId & PORT_MASK_ID ;
	uint32  PinTypeLOC  = ConfigPtr->arrPort_PinConfig[u8Counter].PortPinId & PIN_MASK_ID  ;
	for(uint8 u8Counter = 0 ;u8Counter < PortNumberOfPortPins ; u8Counter++ )
	{
		switch(PortTypeLOC)
		{
			case PORTA:
			if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_IN)
			{
				/* In input mode CNFy:
				    00: Analog mode
				    01: Floating input (reset state)
				    10: Input with pull-up / pull-down
				    11: Reserved               */		
				GPIOA->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuInput_PinType) << (2 + (PinTypeLOC * 4));
			}else if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_OUT)
			{
				/* In output mode CNFy:
				   00: General purpose output push-pull
				   01: General purpose output Open-drain
				   10: Alternate function output Push-pull
				   11: Alternate function output Open-drain */
				GPIOA->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuOutput_PinType) << (2 + (PinTypeLOC * 4));
			}
			else
			{
				/* do nothing */
			}	
				GPIOA->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;
			break;
			
			case PORTB:
			if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_IN)
			{
           	
				GPIOB->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuInput_PinType) << (2 + (PinTypeLOC * 4));
			}else if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_OUT)
			{

				GPIOB->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuOutput_PinType) << (2 + (PinTypeLOC * 4));
			}
			else
			{
				/* do nothing */
			}	
				GPIOB->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;
			break;
			
			case PORTC:
			if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_IN)
			{	
				GPIOC->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuInput_PinType) << (2 + (PinTypeLOC * 4));
			}else if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_OUT)
			{
				GPIOC->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuOutput_PinType) << (2 + (PinTypeLOC * 4));
			}
			else
			{
				/* do nothing */
			}	
				GPIOC->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;
			break;
			
			case PORTD:
			if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_IN)
			{		
				GPIOD->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuInput_PinType) << (2 + (PinTypeLOC * 4));
			}else if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_OUT)
			{
				GPIOD->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuOutput_PinType) << (2 + (PinTypeLOC * 4));
			}
			else
			{
				/* do nothing */
			}	
				GPIOA->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;
			break;
			
			case PORTE:
			if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_IN)
			{	
				GPIOE->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuInput_PinType) << (2 + (PinTypeLOC * 4));
			}else if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_OUT)
			{
				GPIOE->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuOutput_PinType) << (2 + (PinTypeLOC * 4));
			}
			else
			{
				/* do nothing */
			}	
				GPIOE->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;			
			break;
			
			case PORTF:
			if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_IN)
			{		
				GPIOF->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuInput_PinType) << (2 + (PinTypeLOC * 4));
			}else if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_OUT)
			{
				GPIOF->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuOutput_PinType) << (2 + (PinTypeLOC * 4));
			}
			else
			{
				/* do nothing */
			}	
				GPIOF->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;
			break;
			
			case PORTG:
			if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_IN)
			{
				GPIOG->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuInput_PinType) << (2 + (PinTypeLOC * 4));
			}else if((ConfigPtr->arrPort_PinConfig[u8Counter].PortPinDirection ) == PORT_PIN_OUT)
			{
				GPIOG->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].enuOutput_PinType) << (2 + (PinTypeLOC * 4));
			}
			else
			{
				/* do nothing */
			}	
				GPIOG->GPIOx_CRL |= (ConfigPtr->arrPort_PinConfig[u8Counter].OutputMaxSpeed) << (PinTypeLOC * 4) ;
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
	
	
}