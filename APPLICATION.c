
#define _XTAL_FREQ 8000000 

#include "APPLICATION.h"

/***************************************/
#include "LED.h"
#include "PB.h" 
/**/
LED_CFG LEDs[6] = {
    {.port = GPIO_PORTB,.pin = GPIO_PIN0,.conction = ACTIVE_HIGH,.logic= OFF},
    {.port = GPIO_PORTB,.pin = GPIO_PIN1,.conction = ACTIVE_HIGH,.logic= OFF},
    {.port = GPIO_PORTB,.pin = GPIO_PIN2,.conction = ACTIVE_HIGH,.logic= OFF},
    {.port = GPIO_PORTB,.pin = GPIO_PIN3,.conction = ACTIVE_HIGH,.logic= OFF},
    {.port = GPIO_PORTB,.pin = GPIO_PIN4,.conction = ACTIVE_HIGH,.logic= OFF},
    {.port = GPIO_PORTB,.pin = GPIO_PIN5,.conction = ACTIVE_HIGH,.logic= OFF}
};/**/

LED_CFG red1   = {.port = GPIO_PORTC,.pin = GPIO_PIN0,.conction = ACTIVE_HIGH,.logic= OFF};
LED_CFG green1 = {.port = GPIO_PORTC,.pin = GPIO_PIN1,.conction = ACTIVE_HIGH,.logic= OFF};
LED_CFG red2   = {.port = GPIO_PORTC,.pin = GPIO_PIN2,.conction = ACTIVE_HIGH,.logic= OFF};
LED_CFG green2 = {.port = GPIO_PORTC,.pin = GPIO_PIN3,.conction = ACTIVE_HIGH,.logic= OFF};
PB_CFG PB1     = {.port = GPIO_PORTC,.pin = GPIO_PIN6,.conction = PB_ACTIVE_HIGH};
//GPIO_PIN_CFG PB= {.port = GPIO_PORTC,.pin = GPIO_PIN6,.dir = GPIO_IN     ,.logic=GPIO_LOW};
  
      uint64 timer = 0;
       LOGIC_PB logc = REL;
        


//LED_CFG LED1 = {.port = GPIO_PORTB,.pin = GPIO_PIN0,.conction = ACTIVE_HIGH,.logic= OFF};

int main(void)
{
    /*******************************/
    for (uint8 i = 0; i < 6; i++)
    {
        LED_INIT(&LEDs[i]);
        
    }/**/
    
    LED_INIT(&red1);
    LED_INIT(&red2);
    LED_INIT(&green1);
    LED_INIT(&green2);
    PB_INIT(&PB1);
    
   
    while (1)
    {
        
        //LED_ON(&LED1);
        /**************1st question**********************
        for (uint8 i = 0; i < 4; i++)
        {
            LED_ON(&LEDs[i]);
            __delay_ms(500);
            LED_OFF(&LEDs[i]);
            __delay_ms(500);
        }/**/
        
        /**************2nd question*********************
        for (uint8 i =0; i<3  ; i++)
        {
            LED_ON(&LEDs[i]);
            __delay_ms(1000);
        }
        __delay_ms(1500);
        for (uint8 i =3; i>0  ; i--)
        {
            LED_OFF(&LEDs[i-1]);
            __delay_ms(1000);
        }/**/
        
        /**************3rd question*********************
        for (uint8 i = 0; i < 4; i++)
        {
            LED_ON(&LEDs[i]);
             __delay_ms(400);
            LED_OFF(&LEDs[i]);
            
        }/**/
        
        /***************4th question******************/
       char flag=0;
        
      
        LED_ON(&red1);
        LED_ON(&green2);
     
          while (timer<3000)
        {
           
           PB_READ_LOG (&PB1,&logc);
          if (logc == REL)
          {  
              flag=1;
          }
          __delay_ms(100);
          timer=timer+100;
        } timer=0;/**/
        LED_OFF(&red1);
        LED_OFF(&green2);
        
        if (flag == 1)
        {
            LED_ON(&red2);
            LED_ON(&red1);
            __delay_ms(3000);
            LED_OFF(&red1);
            LED_OFF(&red2);
           
        }
         flag=0;/*/*/
        /********************************************************/
        
        LED_ON(&red2);   
        LED_ON(&green1);
    
        while (timer<3000)
        {
           
           PB_READ_LOG (&PB1,&logc);
          if (logc == REL)
          {  
              flag=1;
          }
          __delay_ms(100);
          timer=timer+100;
        }
        timer=0;/**/
        LED_OFF(&red2);   
        LED_OFF(&green1);
         
        if (flag == 1)
        {
            LED_ON(&red1);
            LED_ON(&red2);
            __delay_ms(3000);
            LED_OFF(&red2);
            LED_OFF(&red1);
            
        }/**/
        
        
        
        
        
    }
    
    
    return 0;
}
