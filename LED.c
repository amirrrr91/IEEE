
/****************************/
#include "LED.h"
/*****************************/
STD_RETURN_TYPE LED_INIT(LED_CFG *PTR)
{
    STD_RETURN_TYPE RET;
    
    if (PTR==NULL)
    {
        RET = E_NOK;
    }
    else
    {
        GPIO_PIN_CFG PTR_PIN={.port=PTR->port,.pin=PTR->pin,.dir=GPIO_OUT,.logic=GPIO_LOW};
        
        RET = GPIO_PIN_INIT(&PTR_PIN);  
    }
  return RET;
}

STD_RETURN_TYPE LED_ON  (LED_CFG *PTR)
{
   
    STD_RETURN_TYPE RET;
    if (PTR==NULL)
    {
        RET = E_NOK;
    }
    else
    {
         GPIO_PIN_CFG PTR_PIN={.port=PTR->port,.pin=PTR->pin,.dir=GPIO_OUT,.logic=PTR->logic};
         switch (PTR->conction)
         {
           case ACTIVE_LOW:
           {
              RET = GPIO_PIN_SET_LOG(&PTR_PIN,GPIO_LOW);
              break;
           }
         case ACTIVE_HIGH:
           {
              RET = GPIO_PIN_SET_LOG(&PTR_PIN,GPIO_HIGH);
              break;
           }
             default :
            {
              RET = E_NOK;
              break;
            }
                 
         }
    }
    return RET;
}
STD_RETURN_TYPE LED_OFF (LED_CFG *PTR)
{ 
    
    STD_RETURN_TYPE RET;
    if (PTR==NULL)
    {
        RET = E_NOK;
    }
    else
    {
        GPIO_PIN_CFG PTR_PIN={.port=PTR->port,.pin=PTR->pin,.dir=GPIO_OUT,.logic=PTR->logic};
         switch (PTR->conction)
         {
           case ACTIVE_LOW:
           {
              RET = GPIO_PIN_SET_LOG(&PTR_PIN,GPIO_HIGH);
              break;
           }
         case ACTIVE_HIGH:
           {
              RET = GPIO_PIN_SET_LOG(&PTR_PIN,GPIO_LOW);
              break;
           }
             default :
            {
              RET = E_NOK;
              break;
            }
                 
         }
    }
    return RET;

}
STD_RETURN_TYPE LED_TOGGLE(LED_CFG *PTR)
{
    
    STD_RETURN_TYPE RET;
    if (PTR==NULL)
    {
        RET = E_NOK;
    }
    else
    {
      GPIO_PIN_CFG PTR_PIN={.port=PTR->port,.pin=PTR->pin,.dir=GPIO_OUT,.logic=PTR->logic};
      RET = GPIO_PIN_TOGGLE (&PTR_PIN);
    }
    return RET;
}
