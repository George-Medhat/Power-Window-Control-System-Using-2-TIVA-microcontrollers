
#include "led.h"



int main(){
  
PortB_Init();
UART_Init();
PortE_Init();
SysTickPeriodSet(cycles);  
    SysTickEnable(); 
 while(1){
schedule();

}
}
