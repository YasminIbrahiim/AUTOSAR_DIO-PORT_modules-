/**********************************************************************************************************/
/************ STM32f103xx Port_Driver                                **************************************/ 
/************ File Name  : Port.h                                    **************************************/ 
/************ Author     : Yasmeen Ibrahim                           **************************************/           
/************ Description:                                           **************************************/
/**********************************************************************************************************/
#ifndef  PORT_H
#define  PORT_H

/* ID for the Vendor company 
   example: ID = 12          */ 
#define PORT_VENDOR_ID      (12U)

/* Port Module ID */
#define PORT_MODULE_ID      (120U)   

/* Port Instance ID */
#define PORT_INSTANCE_ID    (0U)

/* Module Version 1.0.0 */
#define PORT_SW_MAJOR_VERSION              (1U)
#define PORT_SW_MINOR_VERSION              (0U)
#define PORT_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define PORT_AR_RELEASE_MAJOR_VERSION      (4U)
#define PORT_AR_RELEASE_MINOR_VERSION      (4U)
#define PORT_AR_RELEASE_PATCH_VERSION      (0U)

#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Module */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif



/**************************************** Macros for error checking ************************************************/
/** If development error detection is enabled the Port Driver module shall check the function parameters 
    in the order in which they are passed and skip further parameter checking if one check fails.                 **/
	
#define PORT_E_PARAM_PIN              0x0A   /* Invalid Port Pin ID requested                                 */
#define PORT_E_DIRECTION_UNCHANGEABLE 0x0B   /* Port Pin not configured as changeable                         */
#define PORT_E_INIT_FAILED            0x0C   /* API Port_Init service called with wrong parameter             */
#define PORT_E_PARAM_INVALID_MODE     0x0D   /* API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE      0x0E   /* API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_UNINIT                 0x0F   /* API service called without module initialization              */
#define PORT_E_PARAM_POINTER          0x10   /* APIs called with a Null Pointer                               */
/*******************************************************************************************************************/

#define NUMBER_OF_PORT_PINS  32

typedef enum
{
	PORT_PIN_LEVEL_HIGH,          /* Port Pin level is High  */
	PORT_PIN_LEVEL_LOW            /* Port Pin level is LOW   */
}PortPinLevelValueType;

typedef
{
	Port_PinType              	    PortPinId;                  /* Pin Id of the port pin. This value will be assigned to the symbolic name derived from
																   the port pin container short name. */
	Port_PinModeType          	    PortPinMode;
	Port_PinDirectionType     	    PortPinDirection;           /* The initial direction of the pin (IN or OUT). If the direction is not changeable, 
															       the value configured here is fixed. 
															       PORT_PIN_IN  Port Pin direction set as input
															       PORT_PIN_OUT Port Pin direction set as output */
	PortPinDirectionChangeableType  PortPinDirectionChangeable; /* Parameter to indicate if the direction is changeable on a port pin during runtime.
																   true: Port Pin direction changeable enabled. 
																   false: Port Pin direction changeable disabled */                      
	PortPinInitialModeType          PortPinInitialMode;         /* Port pin mode from mode list for use with Port_Init() function. */
	PortPinLevelValueType           PortPinLevelValue;          /* PORT_PIN_LEVEL_HIGH Port Pin level is High
																   PORT_PIN_LEVEL_LOW  Port Pin level is LOW     */   
	PortPinModeChangeableType       PortPinModeChangeable;
}Port_PinConfigType;


/* Type of the external data structure containing the initialization data for this module */
typedef struct
{
	Port_PinConfigType arrPort_PinConfig[NUMBER_OF_PORT_PINS];
}Port_ConfigType;

typedef uint32 Port_PinType;       /* Data type for the symbolic name of a port pin */
typedef enum 
{
	PORT_PIN_IN,
	PORT_PIN_OUT 
}Port_PinDirectionType;            /* Possible directions of a port pin */
typedef Boolean  PortPinDirectionChangeableType;
typedef uint32   PortPinInitialModeType;
typedef Boolean  PortPinModeChangeableType;       /* Parameter to indicate if the mode is changeable on a port pin during runtime. 
													True:  Port Pin mode changeable allowed. 
													False: Port Pin mode changeable not permitted. */
typedef enum
{  
	PORT_PIN_MODE_ADC,       /* Port Pin used by ADC   */                                                                 
	PORT_PIN_MODE_CAN,       /* Port Pin used for CAN  */                                                                                     
	PORT_PIN_MODE_DIO,       /* Port Pin configured for DIO  
						  	    It shall be used under control of the DIO driver */                 
	PORT_PIN_MODE_DIO_GPT,   /* Port Pin configured for DIO
							    It shall be used under control of the general purpose timer driver  */               
	PORT_PIN_MODE_DIO_WDG,   /* Port Pin configured for DIO
							    It shall be used under control of the watchdog driver */        
	PORT_PIN_MODE_FLEXRAY,   /* Port Pin used for FlexRay */                                                            
	PORT_PIN_MODE_ICU,       /* Port Pin used by ICU   */
	PORT_PIN_MODE_LIN,       /* Port Pin used for LIN  */
	PORT_PIN_MODE_MEM,       /* Port Pin used for external memory under control of a memory driver */
	PORT_PIN_MODE_PWM,       /* Port Pin used by PWM Range */
	PORT_PIN_MODE_SPI        /* Port Pin used by SPI       */
} Port_PinModeType;

/*******************************************************************************************/
typedef enum
{
	INPUT_FLOATING, 
	INPUT_PULLUP,
	INPUT_PULLDOWN,
	ANALOG,
	OUTPUT_OPEN_DRAIN,
	OUTPUT_PUSH_PULL,
	ALTERNATE_FUNCTION_PUSH_PULL,
	ALTERNATE_FUNCTION_OPEN_DRAIN
}Port_Pin;

/* 
 * Port Pin ID  
 */
#define  PORTA_PIN0          (uint32)0x00000000
#define  PORTA_PIN1          (uint32)0x00000001
#define  PORTA_PIN2          (uint32)0x00000002
#define  PORTA_PIN3          (uint32)0x00000003
#define  PORTA_PIN4          (uint32)0x00000004
#define  PORTA_PIN5          (uint32)0x00000005
#define  PORTA_PIN6          (uint32)0x00000006
#define  PORTA_PIN7          (uint32)0x00000007
#define  PORTA_PIN8          (uint32)0x00000008
#define  PORTA_PIN9          (uint32)0x00000009
#define  PORTA_PIN10         (uint32)0x0000000A
#define  PORTA_PIN11         (uint32)0x0000000B
#define  PORTA_PIN12         (uint32)0x0000000C
#define  PORTA_PIN13         (uint32)0x0000000D
#define  PORTA_PIN14         (uint32)0x0000000E
#define  PORTA_PIN15         (uint32)0x0000000F
#define  PORTA_PIN16         (uint32)0x00000010
#define  PORTA_PIN17         (uint32)0x00000011
#define  PORTA_PIN18         (uint32)0x00000012
#define  PORTA_PIN19         (uint32)0x00000013
#define  PORTA_PIN20         (uint32)0x00000014
#define  PORTA_PIN21         (uint32)0x00000015
#define  PORTA_PIN22         (uint32)0x00000016
#define  PORTA_PIN23         (uint32)0x00000017
#define  PORTA_PIN24         (uint32)0x00000018
#define  PORTA_PIN25         (uint32)0x00000019
#define  PORTA_PIN26         (uint32)0x0000001A
#define  PORTA_PIN27         (uint32)0x0000001B
#define  PORTA_PIN28         (uint32)0x0000001C
#define  PORTA_PIN29         (uint32)0x0000001D
#define  PORTA_PIN30         (uint32)0x0000001E
#define  PORTA_PIN31         (uint32)0x0000001F
                                     
#define  PORTB_PIN0          (uint32)0x00000020
#define  PORTB_PIN1          (uint32)0x00000021
#define  PORTB_PIN2          (uint32)0x00000022
#define  PORTB_PIN3          (uint32)0x00000023
#define  PORTB_PIN4          (uint32)0x00000024
#define  PORTB_PIN5          (uint32)0x00000025
#define  PORTB_PIN6          (uint32)0x00000026
#define  PORTB_PIN7          (uint32)0x00000027
#define  PORTB_PIN8          (uint32)0x00000028
#define  PORTB_PIN9          (uint32)0x00000029
#define  PORTB_PIN10         (uint32)0x0000002A
#define  PORTB_PIN11         (uint32)0x0000002B
#define  PORTB_PIN12         (uint32)0x0000002C
#define  PORTB_PIN13         (uint32)0x0000002D
#define  PORTB_PIN14         (uint32)0x0000002E
#define  PORTB_PIN15         (uint32)0x0000002F
#define  PORTB_PIN16         (uint32)0x00000030
#define  PORTB_PIN17         (uint32)0x00000031
#define  PORTB_PIN18         (uint32)0x00000032
#define  PORTB_PIN19         (uint32)0x00000033
#define  PORTB_PIN20         (uint32)0x00000034
#define  PORTB_PIN21         (uint32)0x00000035
#define  PORTB_PIN22         (uint32)0x00000036
#define  PORTB_PIN23         (uint32)0x00000037
#define  PORTB_PIN24         (uint32)0x00000038
#define  PORTB_PIN25         (uint32)0x00000039
#define  PORTB_PIN26         (uint32)0x0000003A
#define  PORTB_PIN27         (uint32)0x0000003B
#define  PORTB_PIN28         (uint32)0x0000003C
#define  PORTB_PIN29         (uint32)0x0000003D
#define  PORTB_PIN30         (uint32)0x0000003E
#define  PORTB_PIN31         (uint32)0x0000003F

#define  PORTC_PIN0          (uint32)0x00000040
#define  PORTC_PIN1          (uint32)0x00000041
#define  PORTC_PIN2          (uint32)0x00000042
#define  PORTC_PIN3          (uint32)0x00000043
#define  PORTC_PIN4          (uint32)0x00000044
#define  PORTC_PIN5          (uint32)0x00000045
#define  PORTC_PIN6          (uint32)0x00000046
#define  PORTC_PIN7          (uint32)0x00000047
#define  PORTC_PIN8          (uint32)0x00000048
#define  PORTC_PIN9          (uint32)0x00000049
#define  PORTC_PIN10         (uint32)0x0000004A
#define  PORTC_PIN11         (uint32)0x0000004B
#define  PORTC_PIN12         (uint32)0x0000004C
#define  PORTC_PIN13         (uint32)0x0000004D
#define  PORTC_PIN14         (uint32)0x0000004E
#define  PORTC_PIN15         (uint32)0x0000004F
#define  PORTC_PIN16         (uint32)0x00000050
#define  PORTC_PIN17         (uint32)0x00000051
#define  PORTC_PIN18         (uint32)0x00000052
#define  PORTC_PIN19         (uint32)0x00000053
#define  PORTC_PIN20         (uint32)0x00000054
#define  PORTC_PIN21         (uint32)0x00000055
#define  PORTC_PIN22         (uint32)0x00000056
#define  PORTC_PIN23         (uint32)0x00000057
#define  PORTC_PIN24         (uint32)0x00000058
#define  PORTC_PIN25         (uint32)0x00000059
#define  PORTC_PIN26         (uint32)0x0000005A
#define  PORTC_PIN27         (uint32)0x0000005B
#define  PORTC_PIN28         (uint32)0x0000005C
#define  PORTC_PIN29         (uint32)0x0000005D
#define  PORTC_PIN30         (uint32)0x0000005E
#define  PORTC_PIN31         (uint32)0x0000005F

#define  PORTD_PIN0          (uint32)0x00000060
#define  PORTD_PIN1          (uint32)0x00000061
#define  PORTD_PIN2          (uint32)0x00000062
#define  PORTD_PIN3          (uint32)0x00000063
#define  PORTD_PIN4          (uint32)0x00000064
#define  PORTD_PIN5          (uint32)0x00000065
#define  PORTD_PIN6          (uint32)0x00000066
#define  PORTD_PIN7          (uint32)0x00000067
#define  PORTD_PIN8          (uint32)0x00000068
#define  PORTD_PIN9          (uint32)0x00000069
#define  PORTD_PIN10         (uint32)0x0000006A
#define  PORTD_PIN11         (uint32)0x0000006B
#define  PORTD_PIN12         (uint32)0x0000006C
#define  PORTD_PIN13         (uint32)0x0000006D
#define  PORTD_PIN14         (uint32)0x0000006E
#define  PORTD_PIN15         (uint32)0x0000006F
#define  PORTD_PIN16         (uint32)0x00000070
#define  PORTD_PIN17         (uint32)0x00000071
#define  PORTD_PIN18         (uint32)0x00000072
#define  PORTD_PIN19         (uint32)0x00000073
#define  PORTD_PIN20         (uint32)0x00000074
#define  PORTD_PIN21         (uint32)0x00000075
#define  PORTD_PIN22         (uint32)0x00000076
#define  PORTD_PIN23         (uint32)0x00000077
#define  PORTD_PIN24         (uint32)0x00000078
#define  PORTD_PIN25         (uint32)0x00000079
#define  PORTD_PIN26         (uint32)0x0000007A
#define  PORTD_PIN27         (uint32)0x0000007B
#define  PORTD_PIN28         (uint32)0x0000007C
#define  PORTD_PIN29         (uint32)0x0000007D
#define  PORTD_PIN30         (uint32)0x0000007E
#define  PORTD_PIN31         (uint32)0x0000007F

#define  PORTE_PIN0          (uint32)0x00000080
#define  PORTE_PIN1          (uint32)0x00000081
#define  PORTE_PIN2          (uint32)0x00000082
#define  PORTE_PIN3          (uint32)0x00000083
#define  PORTE_PIN4          (uint32)0x00000084
#define  PORTE_PIN5          (uint32)0x00000085
#define  PORTE_PIN6          (uint32)0x00000086
#define  PORTE_PIN7          (uint32)0x00000087
#define  PORTE_PIN8          (uint32)0x00000088
#define  PORTE_PIN9          (uint32)0x00000089
#define  PORTE_PIN10         (uint32)0x0000008A
#define  PORTE_PIN11         (uint32)0x0000008B
#define  PORTE_PIN12         (uint32)0x0000008C
#define  PORTE_PIN13         (uint32)0x0000008D
#define  PORTE_PIN14         (uint32)0x0000008E
#define  PORTE_PIN15         (uint32)0x0000008F
#define  PORTE_PIN16         (uint32)0x00000090
#define  PORTE_PIN17         (uint32)0x00000091
#define  PORTE_PIN18         (uint32)0x00000092
#define  PORTE_PIN19         (uint32)0x00000093
#define  PORTE_PIN20         (uint32)0x00000094
#define  PORTE_PIN21         (uint32)0x00000095
#define  PORTE_PIN22         (uint32)0x00000096
#define  PORTE_PIN23         (uint32)0x00000097
#define  PORTE_PIN24         (uint32)0x00000098
#define  PORTE_PIN25         (uint32)0x00000099
#define  PORTE_PIN26         (uint32)0x0000009A
#define  PORTE_PIN27         (uint32)0x0000009B
#define  PORTE_PIN28         (uint32)0x0000009C
#define  PORTE_PIN29         (uint32)0x0000009D
#define  PORTE_PIN30         (uint32)0x0000009E
#define  PORTE_PIN31         (uint32)0x0000009F

#define  PORTF_PIN0          (uint32)0x000000A0
#define  PORTF_PIN1          (uint32)0x000000A1
#define  PORTF_PIN2          (uint32)0x000000A2
#define  PORTF_PIN3          (uint32)0x000000A3
#define  PORTF_PIN4          (uint32)0x000000A4
#define  PORTF_PIN5          (uint32)0x000000A5
#define  PORTF_PIN6          (uint32)0x000000A6
#define  PORTF_PIN7          (uint32)0x000000A7
#define  PORTF_PIN8          (uint32)0x000000A8
#define  PORTF_PIN9          (uint32)0x000000A9
#define  PORTF_PIN10         (uint32)0x000000AA
#define  PORTF_PIN11         (uint32)0x000000AB
#define  PORTF_PIN12         (uint32)0x000000AC
#define  PORTF_PIN13         (uint32)0x000000AD
#define  PORTF_PIN14         (uint32)0x000000AE
#define  PORTF_PIN15         (uint32)0x000000AF
#define  PORTF_PIN16         (uint32)0x000000B0
#define  PORTF_PIN17         (uint32)0x000000B1
#define  PORTF_PIN18         (uint32)0x000000B2
#define  PORTF_PIN19         (uint32)0x000000B3
#define  PORTF_PIN20         (uint32)0x000000B4
#define  PORTF_PIN21         (uint32)0x000000B5
#define  PORTF_PIN22         (uint32)0x000000B6
#define  PORTF_PIN23         (uint32)0x000000B7
#define  PORTF_PIN24         (uint32)0x000000B8
#define  PORTF_PIN25         (uint32)0x000000B9
#define  PORTF_PIN26         (uint32)0x000000BA
#define  PORTF_PIN27         (uint32)0x000000BB
#define  PORTF_PIN28         (uint32)0x000000BC
#define  PORTF_PIN29         (uint32)0x000000BD
#define  PORTF_PIN30         (uint32)0x000000BE
#define  PORTF_PIN31         (uint32)0x000000BF
 
#define  PORTG_PIN0          (uint32)0x000000C0
#define  PORTG_PIN1          (uint32)0x000000C1
#define  PORTG_PIN2          (uint32)0x000000C2
#define  PORTG_PIN3          (uint32)0x000000C3
#define  PORTG_PIN4          (uint32)0x000000C4
#define  PORTG_PIN5          (uint32)0x000000C5
#define  PORTG_PIN6          (uint32)0x000000C6
#define  PORTG_PIN7          (uint32)0x000000C7
#define  PORTG_PIN8          (uint32)0x000000C8
#define  PORTG_PIN9          (uint32)0x000000C9
#define  PORTG_PIN10         (uint32)0x000000CA
#define  PORTG_PIN11         (uint32)0x000000CB
#define  PORTG_PIN12         (uint32)0x000000CC
#define  PORTG_PIN13         (uint32)0x000000CD
#define  PORTG_PIN14         (uint32)0x000000CE
#define  PORTG_PIN15         (uint32)0x000000CF
#define  PORTG_PIN16         (uint32)0x000000D0
#define  PORTG_PIN17         (uint32)0x000000D1
#define  PORTG_PIN18         (uint32)0x000000D2
#define  PORTG_PIN19         (uint32)0x000000D3
#define  PORTG_PIN20         (uint32)0x000000D4
#define  PORTG_PIN21         (uint32)0x000000D5
#define  PORTG_PIN22         (uint32)0x000000D6
#define  PORTG_PIN23         (uint32)0x000000D7
#define  PORTG_PIN24         (uint32)0x000000D8
#define  PORTG_PIN25         (uint32)0x000000D9
#define  PORTG_PIN26         (uint32)0x000000DA
#define  PORTG_PIN27         (uint32)0x000000DB
#define  PORTG_PIN28         (uint32)0x000000DC
#define  PORTG_PIN29         (uint32)0x000000DD
#define  PORTG_PIN30         (uint32)0x000000DE
#define  PORTG_PIN31         (uint32)0x000000DF

/*********************************  Function prototype *****************************************/ 

/* Description: Initializes the Port Driver module              */
void Port_Init (const Port_ConfigType* ConfigPtr);   
   
/* Description: Sets the port pin direction                     */
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction);

/* Description: Refreshes port direction.                       */
void Port_RefreshPortDirection (void);

/* Description: Returns the version information of this module. */
void Port_GetVersionInfo (Std_VersionInfoType* versioninfo);

/* Description: Sets the port pin mode                          */
void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode);


extern Port_ConfigType Port_Config_Global; 
#endif




