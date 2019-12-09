//Igor Grinchenko
//EMBSYS100
//Assignment 7, problem 1

#include "stm32f401xe.h"
#define SYS_CLOCK_HZ 16000000u

void main()
{
  // RCC base address 0x40023800
  // peripheral clock enable register (RCC_AHB1ENR)
  // Address offset: 0x30
  // Write: 0x1 (enable peripheral clock)
  RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
  // Configure I/O direction mode
  // GPIOA Base Address: 0x40020000
  // GPIO port mode register (GPIOA_MODER)
  // Address offset: 0x00
  // Write: 0x400 (MODER5 to output)
  GPIOA -> MODER |= GPIO_MODER_MODE5_0;
  
  SysTick->LOAD = SYS_CLOCK_HZ -1;      // Counts from 0
  SysTick->VAL = 0x0;                   // Clear initial value
  SysTick->CTRL = 0x7;                  // Enable interrupts

  while (1)
  {    
  }
}
