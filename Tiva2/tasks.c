#include "tasks.h"

 

char Task1(void){

char c= UART5Rx();
  return(c);
  }
void Task2(char T1){

    switch(T1){
      case 'A':
          PrintString("Opening\n\r");
          break;
            case 'B':
                PrintString("Closing\n\r");
          break;
            case 'C':
                PrintString("FullOpened\n\r");
          break;
            case 'D':
                PrintString("FullClosed\n\r");
          break;
            case 'E':
                PrintString("NotFullOpenedOrClosed\n\r");
          break;
    case 'K':
        PrintString("ERROR\n\r");
          break;
    }
      }
