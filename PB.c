
/**************************************/
#include "PB.h"
/**************************************/
STD_RETURN_TYPE PB_INIT (PB_CFG *PTR)
{
 STD_RETURN_TYPE RET;
    
    if (PTR==NULL)
    {
        RET = E_NOK;
    }
    else
    { 
        switch (PTR->conction)
        {
            case PB_ACTIVE_HIGH:
            {
              GPIO_PIN_CFG PTR_PIN={.port=PTR->port,.pin=PTR->pin,.dir=GPIO_IN,GPIO_LOW};
               RET = GPIO_PIN_INIT(&PTR_PIN); 
              break;
            }
             case PB_ACTIVE_LOW:
            {
              GPIO_PIN_CFG PTR_PIN={.port=PTR->port,.pin=PTR->pin,.dir=GPIO_IN,GPIO_HIGH};
               RET = GPIO_PIN_INIT(&PTR_PIN); 
              break;
            }
        }
        
        
    }
  return RET;
}
STD_RETURN_TYPE PB_READ_LOG (PB_CFG *PTR,LOGIC_PB *logc)
{
    STD_RETURN_TYPE RET;
    //uint8 LOGC;
    LOGIC_T LOGC;
    if (PTR==NULL)
    {
        RET = E_NOK;
    }
    else
    {
      GPIO_PIN_CFG PTR_PIN={.port=PTR->port,.pin=PTR->pin,.dir=GPIO_IN,.logic=PTR->logic};
      GPIO_PIN_READ_LOG(&PTR_PIN,&LOGC);
      
      switch (PTR->conction)
        {
            case PB_ACTIVE_HIGH:
            {
                switch (LOGC)
                {
                  case GPIO_LOW:
                    {
                      *logc=REL;
                      break;
                    }
                  case GPIO_HIGH:
                    {
                      *logc=PRE;
                      break;
                    }
                } 
              break;
            }
            ////////////////////////////////
             case PB_ACTIVE_LOW:
            {
               switch (LOGC)
                {
                  case GPIO_LOW:
                    {
                      *logc=PRE;
                      break;
                    }
                  case GPIO_HIGH:
                    {
                      *logc=REL;
                      break;
                    }
                } 
              break;
            }
        }
      
    }
     return RET;
}
