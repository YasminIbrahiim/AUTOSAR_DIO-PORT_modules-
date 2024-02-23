/**********************************************************************************************/
/************ File Name  : PlatformTypes.h                               **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/

typedef unsigned char            boolean;

typedef signed   char            sint8  ;
typedef unsigned char            uint8  ;
typedef signed   short int       sint16 ;
typedef unsigned short int       uint16 ;
typedef signed   int             sint32 ;
typedef unsigned int             uint32 ;
typedef signed   long long int   sint64 ;
typedef unsigned long long int   uint64 ;

typedef signed   char    sint8_least;
typedef unsigned char    uint8_least;
typedef signed   short   sint16_least;
typedef unsigned short   uint16_least;
typedef signed   long    sint32_least;
typedef unsigned long    uint32_least;

typedef float               float32;
typedef double              float64;

#define CPU_TYPE_8    8
#define CPU_TYPE_16   16
#define CPU_TYPE_32   32
#define CPU_TYPE_64   64

#define MSB_FIRST     0
#define LSB_FIRST     1

#define HIGH_BYTE_FIRST  0
#define LOW_BYTE_FIRST   1

#define CPU_TYPE        CPU_TYPE_32
#define CPU_BIT_ORDER   LSB_FIRST
#define CPU_BYTE_ORDER  LOW_BYTE_FIRST

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
