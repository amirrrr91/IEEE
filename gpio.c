

#include"gpio.h"
/********************************************************/

uint8*TRIS_REG[5]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
uint8*PORT_REG[5]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
uint8*LAT_REG[5]={&LATA,&LATB,&LATC,&LATD,&LATE};

/*****************FUNCTIONS DEFINATION************/

STD_RETURN_TYPE GPIO_PIN_INIT(GPIO_PIN_CFG* PTR)
{
    STD_RETURN_TYPE RET = E_OK;
    if ((PTR==NULL)||(PTR->pin> PIN_MAX_NUMBER -1 )||(PTR->port>PORT_MAX_NUMBER-1))
    {
        RET = E_NOK;
    }
    else 
    {
        RET = GPIO_PIN_SET_DIR (PTR,PTR->dir);
        RET = GPIO_PIN_SET_LOG (PTR,PTR->logic);
        /*switch (PTR->dir)
        {
         case GPIO_IN :
              RET = GPIO_PIN_SET_DIR (PTR,GPIO_IN );
              break;
         case GPIO_OUT:
              RET = GPIO_PIN_SET_DIR (PTR,GPIO_OUT );
              break;
         default:
             RET = E_NOK;  
             break;
        }*/
    }
    return RET;
}


STD_RETURN_TYPE GPIO_PIN_SET_DIR(GPIO_PIN_CFG* PTR, DIR_T state)
{
    STD_RETURN_TYPE RET = E_OK;  

    if ((PTR == NULL) || (PTR->pin > PIN_MAX_NUMBER - 1) || (PTR->port > PORT_MAX_NUMBER-1))
    {
        RET = E_NOK;
    }
    else 
    {
        switch (state)
        {
            case GPIO_IN:
                SET_BIT(*(TRIS_REG[PTR->port]), PTR->pin);
                break;

            case GPIO_OUT:
                CLEAR_BIT(*(TRIS_REG[PTR->port]), PTR->pin);
                break;

            default:
                RET = E_NOK;  
                break;
        } 
    }

    return RET;
}

STD_RETURN_TYPE GPIO_PIN_READ_DIR(GPIO_PIN_CFG* PTR,DIR_T* state)
{
   STD_RETURN_TYPE RET = E_OK;
    if ((PTR==NULL)||(PTR->pin> PIN_MAX_NUMBER -1 )||(PTR->port>PORT_MAX_NUMBER-1)||(state==NULL))
    {
        RET = E_NOK;
    }
    else 
    {
     * state=READ_BIT (*(TRIS_REG[PTR->port]), PTR->pin);
     //* state=READ_BIT (PTR->port,PTR->pin); it isn't true cause the function RAED need register like (tris_reg or or )
    }
   return RET;
}

STD_RETURN_TYPE GPIO_PIN_SET_LOG(GPIO_PIN_CFG* PTR,LOGIC_T LOGC)
{
   STD_RETURN_TYPE RET = E_OK;
    if ((PTR==NULL)||(PTR->pin> PIN_MAX_NUMBER -1 )||(PTR->port>PORT_MAX_NUMBER-1))
    {
        RET = E_NOK;
    }
    else 
    {
        switch(LOGC)
        {
            case GPIO_HIGH:
               SET_BIT(*(LAT_REG[PTR->port]), PTR->pin);
               break; 
            case GPIO_LOW:
               CLEAR_BIT(*(LAT_REG[PTR->port]), PTR->pin);
               break;
            default:
                RET = E_NOK;  
                break;
        }
    }
   return RET;
}

STD_RETURN_TYPE GPIO_PIN_READ_LOG(GPIO_PIN_CFG* PTR,LOGIC_T* LOGC)
{
   STD_RETURN_TYPE RET = E_OK;
    if ((PTR==NULL)||(PTR->pin> PIN_MAX_NUMBER -1 )||(PTR->port>PORT_MAX_NUMBER-1)||(LOGC==NULL))
    {
        RET = E_NOK;
    }
    else 
    {
     * LOGC=READ_BIT (*(PORT_REG[PTR->port]), PTR->pin);
    }
   return RET;
}

STD_RETURN_TYPE GPIO_PIN_TOGGLE(GPIO_PIN_CFG* PTR)
{
  STD_RETURN_TYPE RET = E_OK;
    if ((PTR==NULL)||(PTR->pin> PIN_MAX_NUMBER -1 )||(PTR->port>PORT_MAX_NUMBER-1))
    {
        RET = E_NOK;
    }
    else 
    {
      TOGGLE_BIT(*(LAT_REG[PTR->port]),PTR->pin);
    }
  return RET;
}
/******************************************************************************************************************************/

/******************************************************************************************************************************/
STD_RETURN_TYPE GPIO_PORT_INIT(PORT_T port, uint8 dir, uint8 logic)
{
    
    STD_RETURN_TYPE RET = E_OK;
    if (port<PORT_MAX_NUMBER)
    {
         RET = GPIO_PORT_SET_DIR (port,dir);
         RET = GPIO_PORT_SET_LOG (port,logic);
     /*   switch (PTR->dir)
        {
         case GPIO_IN :
              RET = GPIO_PORT_SET_DIR (PTR,PTR->dir);
              break;
         case GPIO_OUT:
              RET = GPIO_PORT_SET_DIR (PTR,GPIO_OUT);
              break;
         default:
              RET = E_NOK;  
              break;
        }*/
        }
    return RET;
}


STD_RETURN_TYPE GPIO_PORT_SET_DIR(PORT_T port,DIR_T state)
{
    STD_RETURN_TYPE RET = E_OK;
    if (port<PORT_MAX_NUMBER)
    {
        switch (state)
        {
            case GPIO_IN:
                *(TRIS_REG[port])=0xff;
                break;

            case GPIO_OUT:
                *(TRIS_REG[port])=0x00;
                break;

            default:
                RET = E_NOK;  
                break;
        } 
    }

    return RET;
}

STD_RETURN_TYPE GPIO_PORT_READ_DIR(PORT_T port,uint8 *state) 
{
    STD_RETURN_TYPE RET = E_OK;
    if(port<PORT_MAX_NUMBER)
    {
     *state=*(TRIS_REG[port]);
    
    }
   return RET;
}

STD_RETURN_TYPE GPIO_PORT_SET_LOG(PORT_T port,LOGIC_T LOGC)
{
    STD_RETURN_TYPE RET = E_OK;
    if(port<PORT_MAX_NUMBER)
    {
        switch(LOGC)
        {
            case GPIO_HIGH:
               *(LAT_REG[port]) = 0XFF;
               break; 
            case GPIO_LOW:
               *(LAT_REG[port]) = 0X00;
               break;
            default:
                RET = E_NOK;  
                break;
        }
    }
   return RET;
}

STD_RETURN_TYPE GPIO_PORT_READ_LOG(PORT_T port, uint8 * LOGC)
{
   STD_RETURN_TYPE RET = E_OK;
   if(port<PORT_MAX_NUMBER)
    {
     *LOGC = *(PORT_REG[port]);
    }
   return RET;
}

STD_RETURN_TYPE GPIO_PORT_TOGGLE(PORT_T port)
{
  STD_RETURN_TYPE RET = E_OK;
   
  if(port<PORT_MAX_NUMBER)
    {
       *(LAT_REG[port])^=0xff;
       
        /*for(uint8 count = 0;count<PIN_MAX_NUMBER;count=count+1)
        {
           TOGGLE_BIT(*(LAT_REG[PTR->port]),count);
        */
    }
  return RET;
}

