/*******************************************************************************
Igor Grinchenko
EMBSYS 100, Assignment 6, problem 2
*******************************************************************************/  
#include "stdint.h"

#define LED_ON 1
#define LED_OFF 0
#define DELAY_DURATION 1000000

extern void control_user_led(uint8_t state, uint32_t duration);

void main(void)
{
   while(1)
    {
        control_user_led(LED_ON, DELAY_DURATION);
        control_user_led(LED_OFF, DELAY_DURATION);
    }
}
