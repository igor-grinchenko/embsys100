/*
Assignment 4, Problem 1

RCC base address 0x40023800
peripheral clock enable register (RCC_AHB1ENR)
Address offset: 0x30
Set bit[0] to 1 (enable peripheral clock)

Configure I/O direction mode
GPIOA Base Address: 0x40020000
GPIO port mode register (GPIOA_MODER)
Address offset: 0x00
Set bit [11:10] to 0x01 (MODER5 to output)

GPIOA Base Address: 0x40020000
GPIO port output data register (GPIOA_ODR)
Address offset: 0x14
Set bit[5] to 1 (LED ON)
Set bit[5] to 0 (LED OFF)
*/

void unit_delay(void);

void unit_delay(){
  unsigned int i;
  for (i=0;i<500000; i++);
}

int main()
{
  // Enable clock to peripheral
  *((unsigned int*)((0x42000000)+(0x23830*32)+(0*4))) = 0x1;
  
  // Enable GPIO5 to be an output
  *((unsigned int*)((0x42000000)+(0x20000*32)+(10*4))) = 0x1;  

  // LED OFF
  *((unsigned int*)((0x42000000)+(0x20014*32)+(5*4))) = 0;  
  unit_delay();
  // LED ON
  *((unsigned int*)((0x42000000)+(0x20014*32)+(5*4))) = 0x1;
  unit_delay();
  // LED OFF
  *((unsigned int*)((0x42000000)+(0x20014*32)+(5*4))) = 0;  
  unit_delay();
  // LED ON
  *((unsigned int*)((0x42000000)+(0x20014*32)+(5*4))) = 0x1;
  unit_delay();
    // LED OFF
  *((unsigned int*)((0x42000000)+(0x20014*32)+(5*4))) = 0;  
  unit_delay();
  // LED ON
  *((unsigned int*)((0x42000000)+(0x20014*32)+(5*4))) = 0x1;
  unit_delay();
  // LED OFF
  *((unsigned int*)((0x42000000)+(0x20014*32)+(5*4))) = 0;

  return 0;
}


