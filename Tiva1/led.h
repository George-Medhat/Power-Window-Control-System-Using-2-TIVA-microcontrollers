#ifndef __LED_H__
#define __LED_H__
#include <stdbool.h>
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "tasks.h"
#include "schedule.h"
#include "systick.h"

#define Opening                 'A'
#define Closing                 'B'
#define FullOpened              'C'
#define FullClosed              'D'
#define NotFullOpenedOrClosed   'E'
#define ERROR                   'K'


#define NotLimit                0x00000060
#define LimitUp                 0x00000040
#define LimitDown               0x00000020
#define Locked                  0x00000000
#define UnLocked                0x00000004
#define DriverNotPressed        0x00000003
#define DriverUp                0x00000002
#define DriverDown              0x00000001
#define PassengerNotPressed     0x00000018
#define PassengerUp             0x00000010
#define PassengerDown           0x00000008



#define Password 0x4C4F434B    
#define Port_E   0x00000010 
#define Port_B   0x00000002 

int LimitState(void);
int LockState(void);
int DriverState(void);
int PassengerState(void);
char Command(int LimitState,int LockState ,int DriverState,int PassengerState);

void PortB_Init(void);
void PortE_Init(void);
void UART_Init(void);
void UART5Tx(char c);



#endif //__LED_H__
