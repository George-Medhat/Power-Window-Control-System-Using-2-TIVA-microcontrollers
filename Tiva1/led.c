#include "led.h"


void UART_Init(void){

   /* UART5 initialization */
UART5_CTL_R = 0; /* disable UART5 */
UART5_IBRD_R = 104; /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
UART5_FBRD_R = 11; /* fraction part, see Example 4-4 */
UART5_CC_R = 0; /* use system clock */
UART5_LCRH_R = 0x60; /* 8-bit, no parity, 1-stop bit, no FIFO */
UART5_CTL_R = 0x301; /* enable UART5, TXE, RXE */
   
}



void PortE_Init(void){

   SYSCTL_RCGCGPIO_R |= Port_E;
GPIO_PORTE_DEN_R =  0x030; /* Make PE4 and PE as digital */
GPIO_PORTE_AMSEL_R = 0; /* turn off analog function */
GPIO_PORTE_AFSEL_R = 0x030; /* Use PE4,PE5 alternate function */
GPIO_PORTE_PCTL_R = 0x00110000; /* configure PE4 and PE5 for UART */
 }

void UART5Tx(char c)
{
while((UART5_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
UART5_DR_R = c; /* before giving it another byte */
}


void PortB_Init(void){
  // 7 switchs initialization
   SYSCTL_RCGCGPIO_R |= Port_B; 
   SYSCTL_RCGCUART_R |= 0x020;
   GPIO_PORTB_LOCK_R= Password;
   GPIO_PORTB_CR_R =  0x01;
   GPIO_PORTB_DEN_R =  0x7F; 
   GPIO_PORTB_DIR_R = 0x00;
   GPIO_PORTB_PUR_R |= 0x7F;
 }


int LimitState(void){
  return(GPIO_PORTB_DATA_R &0x60);
}

int LockState(void){
  return(GPIO_PORTB_DATA_R &0x04);
}

int DriverState(void){
  return(GPIO_PORTB_DATA_R &0x03);
}
int PassengerState(void){
  return(GPIO_PORTB_DATA_R &0x18);
}

char Command(int LimitState,int LockState ,int DriverState,int PassengerState){
  switch(LockState){
  case UnLocked:   // if the Lock bottom is not pressed 
       switch(LimitState){   //check Limit switchs are pressed 
           case LimitUp:   //if limit up is pressed
                 if((DriverState==DriverDown) && (PassengerState !=PassengerUp))
                 { return(Opening);}
                 else   if((DriverState!=DriverUp) && (PassengerState ==PassengerDown))
                {  return(Opening);}
                 else {
                  return(FullClosed);}
                  break;

          case LimitDown: //if limit down is pressed
            if((DriverState!=DriverDown) && (PassengerState ==PassengerUp))
            { return(Closing);}
            else   if((DriverState==DriverUp) && (PassengerState !=PassengerDown))
             {  return(Closing);}
             else {
              return(FullOpened);}
              break;
      
         case NotLimit: //if NO limit  is pressed
            if((DriverState==DriverDown) && (PassengerState !=PassengerUp))
           { return(Opening);}
           else   if((DriverState!=DriverUp) && (PassengerState ==PassengerDown))
           {  return(Opening);}
                  if((DriverState!=DriverDown) && (PassengerState ==PassengerUp))
            { return(Closing);}
           else   if((DriverState==DriverUp) && (PassengerState !=PassengerDown))
           {  return(Closing);}
          else{    return(NotFullOpenedOrClosed);}
           break;}
    
    
  case Locked: // if the Lock bottom is pressed 
    switch(LimitState){
         case LimitUp:  //if limit up is pressed
           if(DriverState==DriverDown )
           { return(Opening);}
            else {
            return(FullClosed);}
            break;

        case LimitDown:   //if limit down is pressed

          if(DriverState==DriverUp )
         {  return(Closing);}
          else {
           return(FullOpened);}
          break;
      
       case NotLimit:   //if NO limit  is pressed
            if(DriverState==DriverDown )
          { return(Opening);}

           else   if(DriverState==DriverUp )
           {  return(Closing);}
           else{    return(NotFullOpenedOrClosed);}
           break;
  }
  }
return(ERROR);
}


