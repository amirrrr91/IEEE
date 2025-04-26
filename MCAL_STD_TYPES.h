/* 
 * File:   MCAL_STD_TYPES.h
 * Author: AMIR
 *
 * Created on April 23, 2025, 9:32 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/////////////include part///////////////////////////////////////
#include "xc.h"
#include "stdlib.h"

/*******************MACROS*****************/
#define STD_LOW  0X00U
#define STD_HIGH 0X01U

#define STD_IDEAL  0X00U
#define STD_ACTIVE 0X01U

#define STD_OFF 0XO0U
#define STD_ON  0X01U

#define E_NOK 0X00U
#define E_OK  0X01U
/*******************USER DATA TYPES********/
typedef unsigned char uint8;
typedef signed char   sint8;

typedef unsigned short uint16;
typedef signed short   sint16;

typedef unsigned int uint32;
typedef signed int   sint32;

typedef unsigned long long  uint64;
typedef signed long long    sint64;

typedef uint8 STD_RETURN_TYPE;
/***********************************************/
#endif	/* MCAL_STD_TYPES_H */

