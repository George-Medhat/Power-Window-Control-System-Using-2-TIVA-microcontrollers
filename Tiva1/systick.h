#ifndef __SYSTICK_H__
#define __SYSTICK_H__
#include <stdint.h>

#define cycles 1000000-1 // cycles needed to count

void SysTickEnable(void);
void SysTickDisable(void);
void SysTickPeriodSet(uint32_t time);
int SysTickValueGet (void) ;
int SysTickPeriodGet (void);
void delay(int time);
void schedule(void);
int SysTick_Is_Time_out(void);

#endif //__SYSTICK_H__
