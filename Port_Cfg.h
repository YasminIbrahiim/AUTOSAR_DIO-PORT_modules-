/******************************************************************************************************/
/************ STM32f103xx PortConfiguration                             *******************************/ 
/************ File Name  : Port_Cfg.h                                   *******************************/ 
/************ Author     : Yasmeen Ibrahim                              *******************************/           
/************ Description:                                              *******************************/
/******************************************************************************************************/

#ifndef  PORT_CFG_H
#define  PORT_CFG_H

/* Module Version 1.0.0 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION      (4U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION      (0U)

/* The number of specified PortPins */
#define PortNumberOfPortPins     ((uint8)3)

/* Switches the development error detection and notification on or off.
   STD_ON : detection and notification is enabled.
   STD_OFF: detection and notification is disabled. */
#define PortDevErrorDetect        STD_OFF

/* Pre-processor switch to enable / disable the use of the function Port_SetPinDirection().
   STD_ON : Enabled - Function Port_SetPinDirection() is available. 
   STD_OFF: Disabled -Function Port_SetPinDirection() is not available. */
#define PortSetPinDirectionApi    STD_OFF

/* Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
   STD_ON : Enabled - Function Port_SetPinMode() is available. 
   STD_OFF: Disabled - Function Port_SetPinMode() is not available */
#define PortSetPinModeApi         STD_OFF 

/* Pre-processor switch to enable / disable the API to read out the modules version information. 
   STD_ON : Version info API enabled. 
   STD_OFF: Version info API disabled.      */
#define PortVersionInfoApi        STD_ON  

/* Pre-processor switch to enable / disable the API to read out the modules version information. 
   STD_ON : Version info API enabled. 
   STD_OFF: Version info API disabled.      */
#define Port_RefreshPortDirection  STD_OFF

#endif  