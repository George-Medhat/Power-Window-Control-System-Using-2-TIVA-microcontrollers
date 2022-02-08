#include "schedule.h"



void schedule(void){
   static int counter=0;
 char TA1;
   while(SysTick_Is_Time_out()==0){}
  
   counter++;
  
   if((counter%1)==0){
    
    TA1=  Task1();
    } 
   if((counter%3)==0){
    
     Task2(TA1);
     
   }
 
  
  }

