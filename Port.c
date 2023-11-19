/**********************************************************************************************************/
/************ STM32f103xx Port_Driver                                **************************************/ 
/************ File Name  : Port.c                                    **************************************/ 
/************ Author     : Yasmeen Ibrahim                           **************************************/           
/************ Description:                                           **************************************/
/**********************************************************************************************************/

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