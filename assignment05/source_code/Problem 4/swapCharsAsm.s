/*******************************************************************************
File name       : swapCharsAsm.s
Description     : This function takes two variables as input of char data type and swaps the two chars
*******************************************************************************/   

    PUBLIC swapCharsAsm   // Making swapCharsAsm available to other modules
    
    SECTION .text:CODE:REORDER:NOROOT(2)
    // The (2) is for the (align)
    // The power of two to which the address should be aligned.
    // The permitted range is 0 to 8. 
    // Code aligned at 4 Bytes.
    
    THUMB    // Indicates THUMB code is used
             // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Swaps two variables of char data type

C Prototype     : swapCharsAsm(char *var1, char *var2)
                : 
Parameters      : R0: address of var1, R1: address of var2
Return value    : R0
*******************************************************************************/  
  
swapCharsAsm
    PUSH {R2, R3}    // save values in registers R2 and R3 in case they're needed
    LDRB R2, [R0]     // Dereference var1
    LDRB R3, [R1]     // Dereference var2
    STRB R2, [R1]     // Store var1 value in var2 address
    STRB R3, [R0]     // Store var2 value in var1 address
    POP {R2, R3}     // Restore previous values in registers R2 and R3
    BX LR            // return back to the calling function (nothing is returned)
    END
