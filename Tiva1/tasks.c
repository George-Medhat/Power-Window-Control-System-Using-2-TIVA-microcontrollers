#include "tasks.h"

 

char Task1(void){
int LS1= LimitState();
int LS2= LockState();
int DS= DriverState();
int PS=PassengerState();
 char C= Command(LS1,LS2 ,DS,PS);
  return(C);
  }

void Task2(char C){
  
UART5Tx(C);
  
  }

