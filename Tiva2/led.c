#include "led.h"


void PortE_Init(void){
  
   SYSCTL_RCGCGPIO_R |= Port_E;
   SYSCTL_RCGCUART_R |= 0x020;
GPIO_PORTE_DEN_R =  0x030; /* Make PE4 and PE as digital */
//GPIO_PORTE_AMSEL_R = 0; /* turn off analog function */
GPIO_PORTE_AFSEL_R = 0x030; /* Use PE4,PE5 alternate function */
GPIO_PORTE_PCTL_R = 0x00110000; /* configure PE4 and PE5 for UART */
}

void UART_Init(void){

   /* UART5 initialization */
UART5_CTL_R = 0; /* disable UART5 */
UART5_IBRD_R = 104; /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
UART5_FBRD_R = 11; /* fraction part, see Example 4-4 */
UART5_CC_R = 0; /* use system clock */
UART5_LCRH_R = 0x60; /* 8-bit, no parity, 1-stop bit, no FIFO */
UART5_CTL_R = 0x301; /* enable UART5, TXE, RXE */
   
}


/* UART5 Receive */
/* This function waits until a character is received then returns it. */
char UART5Rx(void)
{
char c;
while((UART5_FR_R & 0x10) != 0); /* wait until the buffer is not empty */
c = UART5_DR_R; /* read the received data */
return c; /* and return it */
}

void PrintString ( char * string)
{
    while (*string)
    {
        PrintChar (*(string++));
    }
}
void PrintChar(char x){
    while ((UART0_FR_R & 0x20)!=0){}  // Wait for buffer to clear
    UART0_DR_R = x;                   // Write the char
 }

void UART0_Init(void)
{
    SYSCTL_RCGCUART_R   |= UART0;        // Enable clock to UART0
    SYSCTL_RCGCGPIO_R   |= UART_Port_A;  // Enable clock to PortA
    GPIO_PORTA_DEN_R    |= 0x03;         // Set pins as output
    GPIO_PORTA_AFSEL_R  |= 0x03;         // Alternative function for pin 0 & 1
    GPIO_PORTA_PCTL_R   |= 0x11;         // Setting Rx & Tx
    UART0_CTL_R          = 0x00;         // Disable UART0
    UART0_IBRD_R        |= 104;          // Setting baud rate to 9600
    UART0_FBRD_R        |= 11;           // Setting baud rate to 9600
    UART0_LCRH_R        |= 0x60;         // Configure 8 bit
    UART0_CTL_R         |= 0x301;        // Enable UART
}
