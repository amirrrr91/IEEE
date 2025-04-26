/* 
 * File:   gpio.h
 * Author: amir
 *
 * Created on April 23, 2025, 9:15 PM
 */

#ifndef GPIO_H
#define	GPIO_H
/******************INCLUDE PART************/
#include "pic18f4620.h"
#include "MCAL_STD_TYPES.h"
#include"stdio.h"

/******************MACROS*****************/
#define PIN_MAX_NUMBER   8
#define PORT_MAX_NUMBER  5

#define CONFIG_ENABLE    0X01
#define CONFIG_DISABLE   0X00

#define GPIO_PIN_CONFIG    CONFIG_ENABLE
#define GPIO_PORT_CONFIG   CONFIG_ENABLE

/************MACRO FUNTIONS**************/
#define HWREG (_address)   (*((unsigned char*)(_address)))//i say to the code i need to but a value in this address(_address)

#define SET_BIT(REG, BIT_POS)   ((REG) |= (1<<(BIT_POS)))    
#define CLEAR_BIT(REG, BIT_POS) ((REG) &= ~(1<<(BIT_POS))) 
#define TOGGLE_BIT(REG, BIT_POS)((REG) ^= (1<<(BIT_POS))) 
#define READ_BIT(REG, BIT_POS)  (((REG) >> (BIT_POS)) & 1)


/***************USER DATA TYPE ************************/
typedef enum{
GPIO_PORTA,
GPIO_PORTB,
GPIO_PORTC,
GPIO_PORTD,
GPIO_PORTE
}PORT_T;

typedef enum{
GPIO_PIN0,
GPIO_PIN1,
GPIO_PIN2,
GPIO_PIN3,
GPIO_PIN4,
GPIO_PIN5,
GPIO_PIN6,
GPIO_PIN7
}PIN_T;

typedef enum{
GPIO_HIGH,
GPIO_LOW
}LOGIC_T;

typedef enum{
    GPIO_IN,
    GPIO_OUT
}DIR_T;

typedef struct{
 uint8 port:3;
 uint8 pin:3;
 uint8 dir:1;
 uint8 logic:1;
}GPIO_PIN_CFG;

/***************FUNCTION PROTOTYPE********/
STD_RETURN_TYPE GPIO_PIN_INIT(GPIO_PIN_CFG* PTR);
STD_RETURN_TYPE GPIO_PIN_SET_DIR(GPIO_PIN_CFG* PTR,DIR_T state);
STD_RETURN_TYPE GPIO_PIN_READ_DIR(GPIO_PIN_CFG* PTR,DIR_T* state);
STD_RETURN_TYPE GPIO_PIN_SET_LOG(GPIO_PIN_CFG* PTR,LOGIC_T LOGC);
STD_RETURN_TYPE GPIO_PIN_READ_LOG(GPIO_PIN_CFG* PTR,LOGIC_T* LOGC);
STD_RETURN_TYPE GPIO_PIN_TOGGLE(GPIO_PIN_CFG* PTR);


STD_RETURN_TYPE GPIO_PORT_INIT(PORT_T port, uint8 dir, uint8 logic);
STD_RETURN_TYPE GPIO_PORT_SET_DIR(PORT_T port, DIR_T state);
STD_RETURN_TYPE GPIO_PORT_READ_DIR(PORT_T port,uint8 * state);
STD_RETURN_TYPE GPIO_PORT_SET_LOG(PORT_T port,LOGIC_T LOGC);
STD_RETURN_TYPE GPIO_PORT_READ_LOG(PORT_T port, uint8 * LOGC);
STD_RETURN_TYPE GPIO_PORT_TOGGLE(PORT_T port);

/********************************************************************/
#endif	/* GPIO_H */

