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

/* AUTOSAR checking between Std Types and Port  */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "PlatformTypes.h"

/* AUTOSAR checking between Platform_Types and Port */
#if ((PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PlatformTypes.h does not match the expected version"
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


typedef enum
{
	PORT_PIN_LEVEL_HIGH,          /* Port Pin level is High  */
	PORT_PIN_LEVEL_LOW            /* Port Pin level is LOW   */
}PortPinLevelValueType;

typedef struct
{
	Port_PinType              	    PortPinId;                  /* Pin Id of the port pin. This value will be assigned to the symbolic name derived from
																   the port pin container short name. */
	Port_PinModeType          	    PortPinMode;
	enuInput_PinType	            Input_PinType;              /* parameter to set the Type of input pins and it takes one of the following values:
																   INPUT_FLOATING, INPUT_PULLUP_PULLDOWN , ANALOG */
	                                                             
	enuOutput_PinType               Output_PinType;             /* parameter to set the Type of Output pins and it takes one of the following values:
																   OUTPUT_OPEN_DRAIN, OUTPUT_PUSH_PULL,
																   ALTERNATE_FUNCTION_PUSH_PULL , ALTERNATE_FUNCTION_OPEN_DRAIN */
	enuOutputMax_speed				OutputMaxSpeed;	            /* This parameter is used to set the Maximumm speed of the output pin */
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

typedef enum
{
	ANALOG,
	INPUT_FLOATING, 
	INPUT_PULLUP_PULLDOWN,
	OUTPUT_PIN_NONE
} enuInput_PinType;

typedef enum
{
	OUTPUT_OPEN_DRAIN,
	OUTPUT_PUSH_PULL,
	ALTERNATE_FUNCTION_PUSH_PULL,
	ALTERNATE_FUNCTION_OPEN_DRAIN,
	INPUT_PIN_NONE
} enuOutput_PinType;

typedef enum 
{
	INPUT_NONE,
	OUTPUT_MAX_SPEED_10MHZ,
	OUTPUT_MAX_SPEED_2MHZ ,
	OUTPUT_MAX_SPEED_50MHZ
} enuOutputMax_speed;

/*Port_Pin_ID */
#define  PORTA_PIN0          (Port_PinType)0x00000000
#define  PORTA_PIN1          (Port_PinType)0x00000001
#define  PORTA_PIN2          (Port_PinType)0x00000002
#define  PORTA_PIN3          (Port_PinType)0x00000003
#define  PORTA_PIN4          (Port_PinType)0x00000004
#define  PORTA_PIN5          (Port_PinType)0x00000005
#define  PORTA_PIN6          (Port_PinType)0x00000006
#define  PORTA_PIN7          (Port_PinType)0x00000007
#define  PORTA_PIN8          (Port_PinType)0x00000008
#define  PORTA_PIN9          (Port_PinType)0x00000009
#define  PORTA_PIN10         (Port_PinType)0x0000000A
#define  PORTA_PIN11         (Port_PinType)0x0000000B
#define  PORTA_PIN12         (Port_PinType)0x0000000C
#define  PORTA_PIN13         (Port_PinType)0x0000000D
#define  PORTA_PIN14         (Port_PinType)0x0000000E
#define  PORTA_PIN15         (Port_PinType)0x0000000F

                                     
#define  PORTB_PIN0          (Port_PinType)0x00000010
#define  PORTB_PIN1          (Port_PinType)0x00000011
#define  PORTB_PIN2          (Port_PinType)0x00000012
#define  PORTB_PIN3          (Port_PinType)0x00000013
#define  PORTB_PIN4          (Port_PinType)0x00000014
#define  PORTB_PIN5          (Port_PinType)0x00000015
#define  PORTB_PIN6          (Port_PinType)0x00000016
#define  PORTB_PIN7          (Port_PinType)0x00000017
#define  PORTB_PIN8          (Port_PinType)0x00000018
#define  PORTB_PIN9          (Port_PinType)0x00000019
#define  PORTB_PIN10         (Port_PinType)0x0000001A
#define  PORTB_PIN11         (Port_PinType)0x0000001B
#define  PORTB_PIN12         (Port_PinType)0x0000001C
#define  PORTB_PIN13         (Port_PinType)0x0000001D
#define  PORTB_PIN14         (Port_PinType)0x0000001E
#define  PORTB_PIN15         (Port_PinType)0x0000001F

#define  PORTC_PIN0          (Port_PinType)0x00000020
#define  PORTC_PIN1          (Port_PinType)0x00000021
#define  PORTC_PIN2          (Port_PinType)0x00000022
#define  PORTC_PIN3          (Port_PinType)0x00000023
#define  PORTC_PIN4          (Port_PinType)0x00000024
#define  PORTC_PIN5          (Port_PinType)0x00000025
#define  PORTC_PIN6          (Port_PinType)0x00000026
#define  PORTC_PIN7          (Port_PinType)0x00000027
#define  PORTC_PIN8          (Port_PinType)0x00000028
#define  PORTC_PIN9          (Port_PinType)0x00000029
#define  PORTC_PIN10         (Port_PinType)0x0000002A
#define  PORTC_PIN11         (Port_PinType)0x0000002B
#define  PORTC_PIN12         (Port_PinType)0x0000002C
#define  PORTC_PIN13         (Port_PinType)0x0000002D
#define  PORTC_PIN14         (Port_PinType)0x0000002E
#define  PORTC_PIN15         (Port_PinType)0x0000002F

#define  PORTD_PIN0          (Port_PinType)0x00000030
#define  PORTD_PIN1          (Port_PinType)0x00000031
#define  PORTD_PIN2          (Port_PinType)0x00000032
#define  PORTD_PIN3          (Port_PinType)0x00000033
#define  PORTD_PIN4          (Port_PinType)0x00000034
#define  PORTD_PIN5          (Port_PinType)0x00000035
#define  PORTD_PIN6          (Port_PinType)0x00000036
#define  PORTD_PIN7          (Port_PinType)0x00000037
#define  PORTD_PIN8          (Port_PinType)0x00000038
#define  PORTD_PIN9          (Port_PinType)0x00000039
#define  PORTD_PIN10         (Port_PinType)0x0000003A
#define  PORTD_PIN11         (Port_PinType)0x0000003B
#define  PORTD_PIN12         (Port_PinType)0x0000003C
#define  PORTD_PIN13         (Port_PinType)0x0000003D
#define  PORTD_PIN14         (Port_PinType)0x0000003E
#define  PORTD_PIN15         (Port_PinType)0x0000003F

#define  PORTE_PIN0          (Port_PinType)0x00000040
#define  PORTE_PIN1          (Port_PinType)0x00000041
#define  PORTE_PIN2          (Port_PinType)0x00000042
#define  PORTE_PIN3          (Port_PinType)0x00000043
#define  PORTE_PIN4          (Port_PinType)0x00000044
#define  PORTE_PIN5          (Port_PinType)0x00000045
#define  PORTE_PIN6          (Port_PinType)0x00000046
#define  PORTE_PIN7          (Port_PinType)0x00000047
#define  PORTE_PIN8          (Port_PinType)0x00000048
#define  PORTE_PIN9          (Port_PinType)0x00000049
#define  PORTE_PIN10         (Port_PinType)0x0000004A
#define  PORTE_PIN11         (Port_PinType)0x0000004B
#define  PORTE_PIN12         (Port_PinType)0x0000004C
#define  PORTE_PIN13         (Port_PinType)0x0000004D
#define  PORTE_PIN14         (Port_PinType)0x0000004E
#define  PORTE_PIN15         (Port_PinType)0x0000004F

#define  PORTF_PIN0          (Port_PinType)0x00000050
#define  PORTF_PIN1          (Port_PinType)0x00000051
#define  PORTF_PIN2          (Port_PinType)0x00000052
#define  PORTF_PIN3          (Port_PinType)0x00000053
#define  PORTF_PIN4          (Port_PinType)0x00000054
#define  PORTF_PIN5          (Port_PinType)0x00000055
#define  PORTF_PIN6          (Port_PinType)0x00000056
#define  PORTF_PIN7          (Port_PinType)0x00000057
#define  PORTF_PIN8          (Port_PinType)0x00000058
#define  PORTF_PIN9          (Port_PinType)0x00000059
#define  PORTF_PIN10         (Port_PinType)0x0000005A
#define  PORTF_PIN11         (Port_PinType)0x0000005B
#define  PORTF_PIN12         (Port_PinType)0x0000005C
#define  PORTF_PIN13         (Port_PinType)0x0000005D
#define  PORTF_PIN14         (Port_PinType)0x0000005E
#define  PORTF_PIN15         (Port_PinType)0x0000005F
 
#define  PORTG_PIN0          (Port_PinType)0x00000060
#define  PORTG_PIN1          (Port_PinType)0x00000061
#define  PORTG_PIN2          (Port_PinType)0x00000062
#define  PORTG_PIN3          (Port_PinType)0x00000063
#define  PORTG_PIN4          (Port_PinType)0x00000064
#define  PORTG_PIN5          (Port_PinType)0x00000065
#define  PORTG_PIN6          (Port_PinType)0x00000066
#define  PORTG_PIN7          (Port_PinType)0x00000067
#define  PORTG_PIN8          (Port_PinType)0x00000068
#define  PORTG_PIN9          (Port_PinType)0x00000069
#define  PORTG_PIN10         (Port_PinType)0x0000006A
#define  PORTG_PIN11         (Port_PinType)0x0000006B
#define  PORTG_PIN12         (Port_PinType)0x0000006C
#define  PORTG_PIN13         (Port_PinType)0x0000006D
#define  PORTG_PIN14         (Port_PinType)0x0000006E
#define  PORTG_PIN15         (Port_PinType)0x0000006F

/*********************************  Function prototype *****************************************/ 

/* Description: Initializes the Port Driver module              */
void Port_Init (const Port_ConfigType* ConfigPtr);   
   
#if PortSetPinDirectionApi == STD_ON    
/* Description: Sets the port pin direction                     */
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction);
#endif

#if  PortVersionInfoApi == STD_ON
/* Description: Refreshes port direction.                       */
void Port_RefreshPortDirection (void);
#endif

#if  PortVersionInfoApi == STD_ON
/* Description: Returns the version information of this module. */
void Port_GetVersionInfo (Std_VersionInfoType* versioninfo);
#endif 

#if PortSetPinModeApi == STD_ON
/* Description: Sets the port pin mode                          */
void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode);
#endif
 
#endif




