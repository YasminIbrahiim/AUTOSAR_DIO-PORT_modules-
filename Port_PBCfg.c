/*****************************************************************************************/
/************ STM32f103xx PortConfiguration                *******************************/ 
/************ File Name  : Port_Cfg.c                      *******************************/ 
/************ Author     : Yasmeen Ibrahim                 *******************************/           
/************ Description:                                 *******************************/
/*****************************************************************************************/
#include "Port_PBCfg.h"

const Port_ConfigType Port_Config_Global; 
Port_Config_Global.arrPort_PinConfig[PortNumberOfPortPins] = 
{
  /* PortPinId  , PortPinMode       , Input_PinType , Output_PinType    , OutputMaxSpeed    , PortPinDirection, PortPinDirectionChangeable, 
     PortPinInitialMode , PortPinLevelValue , PortPinModeChangeable , Port_PinAFIOPeriph, Port_PinAFIOPeriphChangeable                        */
	 
    { PORTA_PIN0    , PORT_PIN_MODE_DIO , INPUT_PULLUP_PULLDOWN , INPUT_PIN_NONE     , INPUT_NONE 
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },	
    { PORTA_PIN1    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN2    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN3    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN4    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN5    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN6    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN7    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN8    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN9    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN10   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN11   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN12   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN13   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN14   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTA_PIN15   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	
	
	{ PORTB_PIN0   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN1   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN2   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN3   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN4   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN5   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN6   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN7   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN8   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN9   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN10  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN11  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN12  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN13  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN14  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTB_PIN15  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	
	{ PORTC_PIN0   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN1   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN2   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN3   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN4   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN5   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN6   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN7   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN8   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN9   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN10  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN11  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN12  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN13  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN14  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTC_PIN15  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	
	
	{ PORTD_PIN0   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN1   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN2   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN3   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN4   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN5   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN6   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN7   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN8   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN9   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN10  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN11  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN12  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN13  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN14  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	{ PORTD_PIN15  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO  },
	
	
	{ PORTE_PIN0    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN1    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN2    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN3    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN4    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN5    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN6    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN7    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN8    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN9    , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN10   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ 
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN11   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN12   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN13   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN14   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	{ PORTE_PIN15   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT  , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False       , DIO , DIO  },
	
	
    { PORTF_PIN0   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN1   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN2   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN3   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN4   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN5   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN6   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN7   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN8   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN9   , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN10  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN11  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN12  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN13  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN14  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO },
	{ PORTF_PIN15  , PORT_PIN_MODE_DIO , OUTPUT_PIN_NONE       , OUTPUT_PUSH_PULL   , OUTPUT_MAX_SPEED_10MHZ
	, PORT_PIN_OUT , False             , PORT_PIN_MODE_DIO     , PORT_PIN_LEVEL_LOW , False        , DIO , DIO }
}                                                                                                                                               