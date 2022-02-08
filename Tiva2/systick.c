#include "systick.h"
#include "tm4c123gh6pm.h"
#include "led.h"
#include <stdio.h>



void SysTickEnable(void){

NVIC_ST_CTRL_R |=0x05 ; // 0b0000000101
}



void SysTickDisable(void){

NVIC_ST_CTRL_R &=~0x05 ;
}



void SysTickPeriodSet(uint32_t x){
  
  NVIC_ST_RELOAD_R =x ;
}

//
//Return the value inside the counter
//

int SysTickValueGet (void) {
  return (NVIC_ST_CURRENT_R);
}






void delay(int time){
    int i;
  for( i=0; i<time;i++){
    while((NVIC_ST_CTRL_R & 0x10000)==0){} // polling 
  }
}


int SysTick_Is_Time_out(void){
  return((NVIC_ST_CTRL_R & 0x10000));
}

  
