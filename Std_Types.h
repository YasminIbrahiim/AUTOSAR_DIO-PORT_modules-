/*******************************************************************************************************/
/************ STM32f103xx standard types                          **************************************/ 
/************ File Name  : Std_Types.h                            **************************************/ 
/************ Author     : Yasmeen Ibrahim                        **************************************/           
/************ Description:                                        **************************************/
/*******************************************************************************************************/

#ifndef  STD_TYPES_H
#define  STD_TYPES_H

/* Module Version 1.0.0 */
#define STD_TYPES_SW_MAJOR_VERSION              (1U)
#define STD_TYPES_SW_MINOR_VERSION              (0U)
#define STD_TYPES_SW_PATCH_VERSION              (0U)

/* AUTOSAR Version 4.4.0 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION      (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION      (4U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION      (0U)

/* This type can be used as standard API return type which is shared between the RTE and the BSW modules. */
typedef uint8  Std_ReturnType; 

typedef uint8  Std_TransformerErrorCode;
typedef uint8  Std_TransformerForwardCode;
typedef uint8  Std_TransformerClass;

/* This type is used to encode the different type of messages. - Currently this encoding is limited to
the distinction between requests and responses in C/S communication. */
typedef uint8  Std_MessageTypeType;

/* This type is used to encode different types of results for response messages. - Currently this
encoding is limited to the distinction between OK and ERROR responses. */
typedef uint8  Std_MessageResultType;


#define	STD_TRANSFORMER_UNSPECIFIED   ((Std_TransformerClass)0x00) /* Transformer of a unspecifiedtransformer class. */
#define	STD_TRANSFORMER_SERIALIZER    ((Std_TransformerClass)0x01) /* Transformer of a serializer class.             */
#define	STD_TRANSFORMER_SAFETY        ((Std_TransformerClass)0x02) /* Transformer of a safety class.                 */
#define	STD_TRANSFORMER_SECURITY      ((Std_TransformerClass)0x03) /* Transformer of a security class.               */
#define	STD_TRANSFORMER_CUSTOM        ((Std_TransformerClass)0xFF) /* Transformer of a custom class not standardized by AUTOSAR. */


#define E_OK           ((Std_ReturnType)0)
#define E_NOT_OK       ((Std_ReturnType)1)

#define E_OK                   ((Std_TransformerForwardCode)0x00)  /* No specific error to be injected    */
#define E_SAFETY_INVALID_REP   ((Std_TransformerForwardCode)0x01)  /* Repeat the last used sequencenumber */
#define E_SAFETY_INVALID_CRC   ((Std_TransformerForwardCode)0x03)  /* Generate a deliberately wrong CRC   */
#define E_SAFETY_INVALID_SEQ   ((Std_TransformerForwardCode)0x02)  /* Use a wrong sequence number         */


#define STD_MESSAGETYPE_REQUEST   ((Std_MessageTypeType)0x00)     /* Message type for a request message  */
#define STD_MESSAGETYPE_RESPONSE  ((Std_MessageTypeType)0x01)     /* Message type for a response message */

#define STD_MESSAGERESULT_OK      ((Std_MessageResultType)0x00)   /* STD_MESSAGERESULT_OK                */
#define STD_MESSAGERESULT_ERROR   ((Std_MessageResultType)0x01)   /* Message result for an ERROR response */


#define STD_HIGH   0x01u /* Physical state 5V or 3.3V */
#define STD_LOW    0x00u /* Physical state 0V */

#define STD_ACTIVE 0x01u /* Logical state active */
#define STD_IDLE   0x00u /* Logical state idle */

#define STD_ON  0x01u
#define STD_OFF 0x00u

#define NULL_PTR  ((void *)0)

typedef struct
{
	uint16  vendorID;
	uint16  moduleID;
	uint8   sw_major_version;
	uint8   sw_minor_version;
	uint8   sw_patch_version;
}Std_VersionInfoType;

/* This type shall be used to request the version of a BSW module 
using the <Module name>_GetVersionInfo() function.*/
typedef struct
{
	Std_TransformerErrorCode   errorCode;
    Std_TransformerClass       transformerClass;
}Std_TransformerError;

/*
@Name 		         : Std_ExtractProtocolHeaderFieldsType
@Kind 		         : Function Pointer
@Parameters (in)     : (buffer) Buffer allocated by the RTE, where the transformed data has to be stored by the transformer
				       (bufferLength) Length of the buffer
@Parameters (inout)  : None
@Parameters (out)    : (messageResult) Canonical representation of the message result type (extracted from the transformers protocol header).
				       (messageType) Canonical representation of the message type (extracted from the transformers protocol header).
@Return value        : Std_ReturnType 
@Description         : Type for the function pointer to extract the relevant protocol header fields of the message and
					   the type of the message result of a transformer. - At the time being, this is limited to the types
					   used for C/S communication (i.e., REQUEST and RESPONSE and OK and ERROR). */

Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType) (const uint8* buffer,
uint32 bufferLength,
Std_MessageTypeType* messageType,
Std_MessageResultType* messageResult);

#endif


