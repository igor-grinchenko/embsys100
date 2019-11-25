/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"
#include "assert.h"

char *myCstr;
extern int sqrAsm();
extern int div2Asm(uint8_t val);

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

/*******************************************************************************
Function Name   : main
Description     : 
Parameters      :
Return value    :               */
void main() {
uint8_t foo;
int result;

  foo = 10;
  Hw_init();

  PrintString(clr_scrn); /* Clear entire screen */
  // Change [My name] to your name      //
  PrintString("Igor's Nucleo STM32F401 is ... alive and well!!!\n");
  RETAILMSG(1, ("Programming Assignment #5: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__));  

  myCstr = "div2Asm was here\n";
  result = div2Asm(foo);
  assert(result==5);
  
  myCstr = "sqrAsm was here\n";
  sqrAsm();
  
  while (foo) {
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    PrintString("EMBSYS CP100A: University of Washington - UART Test Application \n");
    delay(1000);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    
    delay(1000);
    foo--;
  }
  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {
  
  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
  