/* 
 * File:   PB.h
 * Author: alaml
 *
 * Created on April 26, 2025, 11:40 PM
 */

#ifndef PB_H
#define	PB_H

/*****************INCLUDE PART***************/
#include "gpio.h"
/****************MACROS**********************/

/****************USER DATA TYPES*************/
typedef enum
{
    PB_ACTIVE_LOW,
    PB_ACTIVE_HIGH
}CON_STATE_PB;

typedef enum{
    PRE,
    REL
}LOGIC_PB;

typedef struct
{
 uint8 port:3;
 uint8 pin:3;
 uint8 conction:1;
 uint8 logic:1;
}PB_CFG;
/*************FUNCTION PROTOTYPES****************/
STD_RETURN_TYPE PB_INIT (PB_CFG *PTR);
STD_RETURN_TYPE PB_READ_LOG (PB_CFG *PTR,LOGIC_PB *logc);
        
    

#endif	/* PB_H */

