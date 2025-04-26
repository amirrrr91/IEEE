/* 
 * File:   LED.h
 * Author: alaml
 *
 * Created on April 25, 2025, 11:33 PM
 */

#ifndef LED_H
#define	LED_H
/*****************INCLUDE PART***************/
#include "gpio.h"
/****************MACROS**********************/

/****************USER DATA TYPES*************/
typedef enum
{
    ACTIVE_LOW,
    ACTIVE_HIGH
}CON_STATE;

typedef enum{
    OFF,
    ON
}LOGIC_LED;

typedef struct
{
 uint8 port:3;
 uint8 pin:3;
 uint8 conction:1;
 uint8 logic:1;
}LED_CFG;

/*************FUNCTION PROTOTYPES****************/
STD_RETURN_TYPE LED_INIT(LED_CFG *PTR);
STD_RETURN_TYPE LED_ON  (LED_CFG *PTR);
STD_RETURN_TYPE LED_OFF (LED_CFG *PTR);
STD_RETURN_TYPE LED_TOGGLE(LED_CFG *PTR);

#endif	/* LED_H */

