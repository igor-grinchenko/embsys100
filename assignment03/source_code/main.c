/*
This program does Morse Code of name "Igor"

RCC base address 0x40023800
peripheral clock enable register (RCC_AHB1ENR)
Address offset: 0x30
Write: 0x1 (enable peripheral clock)

Configure I/O direction mode
GPIOA Base Address: 0x40020000
GPIO port mode register (GPIOA_MODER)
Address offset: 0x00
Write: 0x400 (MODER5 to output)

GPIOA Base Address: 0x40020000
GPIO port output data register (GPIOA_ODR)
Address offset: 0x14
Write 0x20 (to set LED2 ON)
*/

void unit_delay(){
  unsigned int i;
  for (i=0;i<500000; i++);
}

int main()
{
  // Enable clock to peripheral
  *((unsigned int*)0x40023830) = 0x1;
  // Enable GPIO5 to be an output
  *((unsigned int*)0x40020000) = 0xA8000400;
  // Initialize LED2 to be initially OFF
  *((unsigned int*)0x40020014)= 0xA8000000;

  // 'I'
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  unit_delay();
  unit_delay();
  // 'G'
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  unit_delay();
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  unit_delay();
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  unit_delay();
  unit_delay();
  // 'O'
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  unit_delay();
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  unit_delay();
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  unit_delay();
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  unit_delay();
  unit_delay();
  // 'R'
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  unit_delay();
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000020;    // LED ON
  unit_delay();
  *((unsigned int*)0x40020014)= 0xA8000000;    // LED OFF
  return 0;
}


