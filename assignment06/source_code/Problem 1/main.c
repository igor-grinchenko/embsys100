// Igor Grinchenko
// EMBSYS 100
// Assignment 6, Problem 1

#include "stm32f401xe.h"

void unit_delay(){
  for (int i=0; i<500000; i++);
}

int main()
{
  // RCC base address 0x40023800
  // peripheral clock enable register (RCC_AHB1ENR)
  // Address offset: 0x30
  // Enable peripheral clock
  RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
  // Configure I/O direction mode
  // GPIOA Base Address: 0x40020000
  // GPIO port mode register (GPIOA_MODER)
  // Address offset: 0x00
  // Set MODER5 to output
  GPIOA -> MODER |= GPIO_MODER_MODE5_0;
  
  for (int i=0; i<10; i++){
  // GPIOA Base Address: 0x40020000
  // GPIO port output data register (GPIOA_ODR)
  // Address offset: 0x14
  // Enable ODR5 to set LED2 ON
  GPIOA -> ODR |= GPIO_ODR_OD5;
  unit_delay();
  // Disable ODR5 to set LED2 OFF
  GPIOA -> ODR ^= GPIO_ODR_OD5;
  unit_delay();
  }
  return 0;
}
