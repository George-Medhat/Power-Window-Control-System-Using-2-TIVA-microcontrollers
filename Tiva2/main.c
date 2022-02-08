
#include "led.h"



int main(){
  
 PortE_Init();
 UART_Init();
 UART0_Init();
SysTickPeriodSet(cycles);  
SysTickEnable(); 
 while(1){

 schedule();
   


}
}

 
