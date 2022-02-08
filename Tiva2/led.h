#ifndef __LED_H__
#define __LED_H__
#include <stdbool.h>
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "tasks.h"
#include "schedule.h"
#include "systick.h"
  
#define Password 0x4C4F434B    
#define Port_E   0x00000010 

  #define UART0             0x00000001
#define UART_Port_A       0x00000001
#define UART1             0x00000002
#define UART_Port_B       0x00000002

void UART0_Init(void);
void PrintChar(char x);
void PrintString ( char * string);
void PortE_Init(void);
void UART_Init(void);
char UART5Rx(void);




#endif //__LED_H__
