/*****************************************************************************************/
/************ STM32f103xx PortConfiguration                *******************************/ 
/************ File Name  : Port_Cfg.c                       *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/
#include "Port_PBCfg.h"

const Port_ConfigType Port_Config_Global; 
Port_Config_Global.arrPort_PinConfig[PortNumberOfPortPins] = 
{
  /* PortPinId  , PortPinMode       , Input_PinType , Output_PinType    , OutputMaxSpeed    , PortPinDirection, 
     PortPinDirectionChangeable, PortPinInitialMode , PortPinLevelValue , PortPinModeChangeable */
	 
    { PORTA_PIN0   , PORT_PIN_MODE_DIO , INPUT_PULLUP_PULLDOWN , INPUT_PIN_NONE     , INPUT_NONE 
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False         },
	
    { PORTA_PIN1   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False         },
	
    { PORTE_PIN1   , PORT_PIN_MODE_DIO , INPUT_PULLUP_PULLDOWN , INPUT_PIN_NONE     , INPUT_NONE             
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False         }
}                                                                                                                                               