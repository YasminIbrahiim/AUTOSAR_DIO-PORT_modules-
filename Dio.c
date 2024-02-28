/**********************************************************************************************/
/************ STM32f103xx DIO_Driver                                     **********************/ 
/************ File Name  : Dio.c                                         **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"

#if (DioDevErrorDetect == STD_ON) 
#include "Det.h"

/* AUTOSAR Version checking between Det and Dio Module */
#if ((DET_AR_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION  != DIO_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION  != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

/* 
@Service Name       : Dio_ReadChannel
@Service ID [hex]   : 0x00
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (ChannelId) ID of DIO channel
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : (Dio_Level_Type)
					  STD_HIGH: The physical level of the corresponding Pin is STD_HIGH
					  STD_LOW : The physical level of the corresponding Pin is STD_LOW
@Description        : Returns the value of the specified DIO channel. */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType    Dio_ChannelLevelLOC = STD_LOW;
	GPIOx_REG*       GPIO_BaseAddress = NULL_Ptr; 
	switch(arrDio_Channels[ChannelId].port)
	{
		case PORTA:
		GPIO_BaseAddress = GPIOA;
		break;
		case PORTB:
		GPIO_BaseAddress = GPIOB;
		break;
		case PORTC:
		GPIO_BaseAddress = GPIOC;
		break;
		case PORTD:
		GPIO_BaseAddress = GPIOD;
		break;
		case PORTE:
		GPIO_BaseAddress = GPIOE;
		break;
		case PORTG:
		GPIO_BaseAddress = GPIOF;
		break;
	}
	if ( ((GPIO_BaseAddress->GPIOx_IDR) >> (arrDio_Channels[ChannelId].pin)) & 1 )
	{
		Dio_ChannelLevelLOC = STD_HIGH; 
	}else
	{
		Dio_ChannelLevelLOC = STD_LOW ; 
	}	
	return Dio_ChannelLevelLOC;
}

/* 
@Service Name       : Dio_WriteChannel
@Service ID [hex]   : 0x01
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (ChannelId) ID of DIO channel 
                      (Level) Value to be written
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : Service to set a level of a channel.  */
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	GPIOx_REG*  GPIO_BaseAddress = NULL_Ptr;
	switch(arrDio_Channels[ChannelId].port)
	{
		case PORTA:
		GPIO_BaseAddress = GPIOA;
		break;
		case PORTB:
		GPIO_BaseAddress = GPIOB;
		break;
		case PORTC:
		GPIO_BaseAddress = GPIOC;
		break;
		case PORTD:
		GPIO_BaseAddress = GPIOD;
		break;
		case PORTE:
		GPIO_BaseAddress = GPIOE;
		break;
		case PORTG:
		GPIO_BaseAddress = GPIOF;
		break;		
	}
	if(Level == STD_HIGH )
	{
		GPIO_BaseAddress->GPIOx_ODR |=  (1 << (arrDio_Channels[ChannelId].pin));
	}
	else if (Level == STD_LOW)
	{
		GPIO_BaseAddress->GPIOx_ODR |= ~(1 << (arrDio_Channels[ChannelId].pin));
	}
	else
	{
		/*Do nothing */                                              
	}
}

/* 
@Service Name        : Dio_ReadPort
@Service ID [hex]    : 0x02
@Sync/Async          : Synchronous
@Reentrancy          : Reentrant
@Parameters (in)     : (PortId) ID of DIO Port
@Parameters (inout)  : None
@Parameters (out)    : None
@Return value        : (Dio_PortLevelType) Level of all channels of that port
@Description         : Returns the level of all channels of that port */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId )
{
	Dio_PortLevelType Dio_PortLevel_LOC = 0;
	switch(PortId)
	{
	case PORTA:
	Dio_PortLevel_LOC = (GPIOA->GPIOx_IDR); 
	break;
	case PORTB:
	Dio_PortLevel_LOC = (GPIOB->GPIOx_IDR);
	break;
	case PORTC:
	Dio_PortLevel_LOC = (GPIOC->GPIOx_IDR); 
	break;
	case PORTD:
	Dio_PortLevel_LOC = (GPIOD->GPIOx_IDR);
	break;
	case PORTE:
	Dio_PortLevel_LOC = (GPIOE->GPIOx_IDR);
	break;
	case PORTF:
	Dio_PortLevel_LOC = (GPIOF->GPIOx_IDR);
	break;
	case PORTG:
	Dio_PortLevel_LOC = (GPIOG->GPIOx_IDR);
	break;
	}
	return Dio_PortLevel_LOC;
}

/* 
@Service Name       : Dio_WritePort
@Service ID [hex]   : 0x03
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (PortId) ID of DIO Port
					  (Level)  Value to be written
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None
@Description        : Service to set a value of the port */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
	switch(PortId)
	{
	case PORTA: 
	GPIOA->GPIOx_ODR = Level;
	break;
	case PORTB:
	GPIOB->GPIOx_ODR = Level;
	break;
	case PORTC:
	GPIOC->GPIOx_ODR = Level;
	break;
	case PORTD:
	GPIOD->GPIOx_ODR = Level;
	break;
	case PORTE:
	GPIOE->GPIOx_ODR = Level;
	break;
	case PORTF:
	GPIOF->GPIOx_ODR = Level;
	break;
	case PORTG:
	GPIOG->GPIOx_ODR = Level;
	break;
	}
}

/* 
@Service Name       : Dio_ReadChannelGroup
@Service ID [hex]   : 0x04
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (ChannelGroupIdPtr) Pointer to ChannelGroup
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : (Dio_PortLevelType Level) of a subset of the adjoining bits of a port
@Description        : This Service reads a subset of the adjoining bits of a port. */
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	Dio_PortLevelType DIO_ReadChannelLevel_LOC = 0;
	switch(ChannelGroupIdPtr->port)
	{
	case PORTA: 
	DIO_ReadChannelLevel_LOC = (GPIOA->GPIOx_IDR) & ((ChannelGroupIdPtr->mask)<<(ChannelGroupIdPtr->offset));
	break;
	case PORTB:
	DIO_ReadChannelLevel_LOC = (GPIOB->GPIOx_IDR) & ((ChannelGroupIdPtr->mask)<<(ChannelGroupIdPtr->offset));
	break;
	case PORTC:
	DIO_ReadChannelLevel_LOC = (GPIOC->GPIOx_IDR) & ((ChannelGroupIdPtr->mask)<<(ChannelGroupIdPtr->offset));
	break;
	case PORTD:
	DIO_ReadChannelLevel_LOC = (GPIOD->GPIOx_IDR) & ((ChannelGroupIdPtr->mask)<<(ChannelGroupIdPtr->offset));
	break;
	case PORTE:
	DIO_ReadChannelLevel_LOC = (GPIOE->GPIOx_IDR) & ((ChannelGroupIdPtr->mask)<<(ChannelGroupIdPtr->offset));
	break;
	case PORTF:
	DIO_ReadChannelLevel_LOC = (GPIOF->GPIOx_IDR) & ((ChannelGroupIdPtr->mask)<<(ChannelGroupIdPtr->offset));
	break;
	case PORTG:
	DIO_ReadChannelLevel_LOC = (GPIOG->GPIOx_IDR) & ((ChannelGroupIdPtr->mask)<<(ChannelGroupIdPtr->offset));
	break;
	}
	return DIO_ReadChannelLevel_LOC;
}

/*
@Service Name       : Dio_WriteChannelGroup
@Service ID [hex]   : 0x05
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : (ChannelGroupIdPtr) Pointer to ChannelGroup 
					  (Level)             Value to be written
@Parameters (inout) : None
@Parameters (out)   : None
@Return value       : None 
@Description        : Service to set a subset of the adjoining bits of a port to a specified level. */
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
	switch(ChannelGroupIdPtr->port)
	{
		case PORTA:
		(GPIOA->GPIOx_ODR) |= Level&((ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset));
		break;
		case PORTB:
		(GPIOB->GPIOx_ODR) |= Level&((ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset));
		break;
		case PORTC:
		(GPIOC->GPIOx_ODR) |= Level&((ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset));
		break;
		case PORTD:
		(GPIOD->GPIOx_ODR) |= Level&((ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset));
		break;
		case PORTE:
		(GPIOE->GPIOx_ODR) |= Level&((ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset));
		break;
		case PORTF:
		(GPIOF->GPIOx_ODR) |= Level&((ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset));
		break;
		case PORTG:
		(GPIOG->GPIOx_ODR) |= Level&((ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset));
		break;
	}
}

/* 
@Service Name       : Dio_GetVersionInfo
@Service ID [hex]   : 0x12
@Sync/Async         : Synchronous
@Reentrancy         : Reentrant
@Parameters (in)    : None
@Parameters (inout) : None
@Parameters (out)   : (VersionInfo) Pointer to where to store the version information of this module.
@Return value       : None
@Description        : Service to get the version information of this module. */
void Dio_GetVersionInfo (Std_VersionInfoType* VersionInfo)
{
	VersionInfo->vendorID         = DIO_VENDOR_ID;
	VersionInfo->moduleID         = DIO_MODULE_ID;
	VersionInfo->sw_major_version = DIO_SW_MAJOR_VERSION;
	VersionInfo->sw_minor_version = DIO_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = DIO_SW_PATCH_VERSION;	
}

/* 
@Service Name        : Dio_FlipChannel
@Service ID [hex]    : 0x11
@Sync/Async          : Synchronous
@Reentrancy          : Reentrant
@Parameters (in)     : (ChannelId) ID of DIO channel
@Parameters (inout)  : None
@Parameters (out)    : None
@Return value        : (Dio_LevelType)
					   STD_HIGH: The physical level of the corresponding Pin is STD_HIGH.
					   STD_LOW:  The physical level of the corresponding Pin is STD_LOW.
@Description         : Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip. */
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)
{
	Dio_LevelType Dio_ChannelLevelLOC = STD_LOW;
	
	switch(arrDio_Channels[ChannelId].port)
	{
		case PORTA:
		GPIO_BaseAddress = GPIOA;
		break;
		case PORTB:
		GPIO_BaseAddress = GPIOB;
		break;
		case PORTC:
		GPIO_BaseAddress = GPIOC;
		break;
		case PORTD:
		GPIO_BaseAddress = GPIOD;
		break;
		case PORTE:
		GPIO_BaseAddress = GPIOE;
		break;
		case PORTG:
		GPIO_BaseAddress = GPIOF;
		break;		
	}
	GPIO_BaseAddress->GPIOx_ODR ^= 1 << (arrDio_Channels[ChannelId].pin);   
	if ( ((GPIO_BaseAddress->GPIOx_IDR) >> (arrDio_Channels[ChannelId].pin)) & 1 )
	{
		Dio_ChannelLevelLOC = STD_HIGH; 
	}else
	{
		Dio_ChannelLevelLOC = STD_LOW ; 
	}
	return Dio_ChannelLevelLOC;
}

/*
@Service Name        : Dio_MaskedWritePort
@Service ID [hex]    : 0x13
@Sync/Async          : Synchronous
@Reentrancy          : Reentrant
@Parameters (in)     : (PortId)  ID of DIO Port Level Value to be written
					   (Mask)    Channels to be masked in the port
@Parameters  (inout) : None
@Parameters  (out)   : None
@Return value        : None 
@Description         : Service to set the value of a given port with required mask. */
void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
	switch(PortId)
	{
		case PORTA:
		GPIOA->GPIOx_ODR |= (Level & Mask);
		break;
		case PORTB:
		GPIOB->GPIOx_ODR |= (Level & Mask);
		break;
		case PORTC:
		GPIOC->GPIOx_ODR |= (Level & Mask);
		break;
		case PORTD:
		GPIOD->GPIOx_ODR |= (Level & Mask);
		break;
		case PORTE:
		GPIOE->GPIOx_ODR |= (Level & Mask);
		break;
		case PORTF:
		GPIOF->GPIOx_ODR |= (Level & Mask);
		break;
		case PORTG:
		GPIOG->GPIOx_ODR |= (Level & Mask);
		break;
	}
}


