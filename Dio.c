/**********************************************************************************************/
/************ STM32f446_NUCLEO DIO_Driver                                **********************/ 
/************ File Name  : Dio.c                                         **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/

#include "Dio.h"

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
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	
	
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
	versioninfo->vendorID         = DIO_VENDOR_ID;
	versioninfo->moduleID         = DIO_MODULE_ID;
	versioninfo->sw_major_version = DIO_SW_MAJOR_VERSION;
	versioninfo->sw_minor_version = DIO_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = DIO_SW_PATCH_VERSION;	
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
	
}


