/*******************************************************************************
Igor Grinchenko
EMBSYS 100, Assignment 6, problem 2
*******************************************************************************/  
#include "stdint.h"

#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))
#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define LED_ON 1
#define LED_OFF 0
#define DELAY_DURATION 1000000

extern void control_user_led(uint8_t state, uint32_t duration);

void main(void)
{
    // Enable clock to Peripheral
    RCC_AHB1ENR |= 0x1;
  
    // Set Port5 as output
    GPIOA_MODER |= 0x400;
 
   while(1)
    {
        control_user_led(LED_ON, DELAY_DURATION);
        control_user_led(LED_OFF, DELAY_DURATION);
    }
}
