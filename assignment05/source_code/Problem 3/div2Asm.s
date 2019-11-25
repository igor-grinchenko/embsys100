/*******************************************************************************
File name       : div2Asm.s
Description     : Assembly language function for dividing input by 2
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file
    EXTERN myCstr       // myCstr is global pointer to the string
    
    PUBLIC div2Asm   // Making div2Asm available to other modules
    
    SECTION .text:CODE:REORDER:NOROOT(2)
    // The (2) is for the (align)
    // The power of two to which the address should be aligned.
    // The permitted range is 0 to 8. 
    // Code aligned at 4 Bytes.
    
    THUMB    // Indicates THUMB code is used
             // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : div2Asm
Description     : Calls C code to print a string; 
                  Computes the division by 2 of its input argument
C Prototype     : int div2Asm(val)
                : Where val is the input value
Parameters      : R0: Address of val
Return value    : R0
*******************************************************************************/  
  
div2Asm
   PUSH {R0,LR}     // save the input argument and return address to stack
   LDR R0,=myCstr   // load (global) address of myCstr string into R0
   LDR R0,[R0]      // dereference myCstr into R0
   BL  PrintString  // call PrintString function to print myCstr
    
   POP {R0, LR}     // load input argument and return address
   ASR R0, R0, #1   // arithmetic shift right 1 to divide value by 2
   BX LR            // return (with function result in R0)
   END
