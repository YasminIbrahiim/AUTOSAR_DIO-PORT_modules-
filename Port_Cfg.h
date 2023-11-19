/******************************************************************************************************/
/************ STM32f103xx PortConfiguration                             *******************************/ 
/************ File Name  : Port_Cfg.h                                   *******************************/ 
/************ Author     : Yasmeen Ibrahim                              *******************************/           
/************ Description:                                              *******************************/
/******************************************************************************************************/

/* Module Version 1.0.0 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION      (4U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION      (0U)

/* The number of specified PortPins */
#define PortNumberOfPortPins     ((uint8)32)

/* Switches the development error detection and notification on or off.
   true : detection and notification is enabled.
   false: detection and notification is disabled. */
#define PortDevErrorDetect        False

/* Pre-processor switch to enable / disable the use of the function Port_SetPinDirection().
   true : Enabled - Function Port_SetPinDirection() is available. 
   false: Disabled -Function Port_SetPinDirection() is not available. */
#define PortSetPinDirectionApi    True

/* Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
   true : Enabled - Function Port_SetPinMode() is available. 
   false: Disabled - Function Port_SetPinMode() is not available */
#define PortSetPinModeApi         True 

/* Pre-processor switch to enable / disable the API to read out the modules version information. 
   true : Version info API enabled. 
   false: Version info API disabled.      */
#define PortVersionInfoApi        True  