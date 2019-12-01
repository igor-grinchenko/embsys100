/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
Igor Grinchenko
EMBSYS 100, Assignment 6, problem 2
*******************************************************************************/   

    EXTERN delay  // delay() is defined outside this file.

    PUBLIC control_user_led         // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led
Description     : - Uses Peripheral registers at base 0x4000.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

control_user_led
    // Enable clock to peripheral
    PUSH {R2, R3, R4} 	// save R2, R3, R4 registers on CSTACK
    MOV R2, #0x3830	// load RCC_AHB1ENR address into R2 register
    MOVT R2, #0x4002 // load RCC_AHB1ENR address into R2 register
    LDR R3, [R2]	// dereference RCC_AHB1ENR to R3 register
    MOV R4, #0x1	// Write 0x1 to enable clock to peripheral
    ORR R3, R3, R4	// Write 0x1 to enable clock to peripheral
    STR R3, [R2]	// Write 0x1 to enable clock to peripheral
    // Enable GPIO5 to be an output
    MOV R2, #0
    MOVT R2, #0x4002        // load GPIOA_MODER address into R2 register
    LDR R3, [R2]	// Dereference GPIOA_MODER to R3 register
    MOV R4, #0x0400	// Write 0xA8000400 to GPIOA_MODER register to configure MODER5 to output
    MOVT R4, #0xA800 // Write 0xA8000400 to GPIOA_MODER register to configure MODER5 to output
    ORR R3, R3, R4	// Write 0xA8000400 to GPIOA_MODER register to configure MODER5 to output
    STR R3, [R2]	// Write 0xA8000400 to GPIOA_MODER register to configure MODER5 to output
	
    MOV R2, #0x0014   // Load ODR5 register to control LED2
    MOVT R2, #0x4002   // Load ODR5 register to control LED2
    MOV R3, #0x0020   // LED ON
    MOVT R3, #0xA800  // LED ON
    MOV R4, #0   // LED OFF
    MOVT R4, #0xA800   // LED OFF
	
    // The function takes as input the LED requested state (0 == OFF, 1 == ON)
    CBZ R0, LEDoff  // Compare and Branch on Zero for user input
    CMP R0, #1      // Compare and Branch for user input
    BEQ LEDon       // Compare and Branch for user input
    B Return	// Exit if user input is invalid
LEDon
    STR R3, [R2]    // LED ON
    PUSH {LR}       // Save LR
    BL delay
    POP {LR}        // Restore LR
    B Return
	
LEDoff	
    STR R4, [R2]    // LED OFF
    PUSH {LR}       // Save LR
    BL delay
    POP {LR}        // Restore LR
	
Return
    POP {R2, R3, R4}	// restore R2, R3, R4 registers from CSTACK
    BX LR           // Return
    END