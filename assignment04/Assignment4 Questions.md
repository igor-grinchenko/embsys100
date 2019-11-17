EMBSYS100 <br>
Assignment 04 <br>
Igor Grinchenko <br>

1.
B) MOVS - Move
   LDR.N - Load register from memory
   STR - Store register word

C) LDR.N - Load register from memory
   MOVS - Move
   STR - Store register word

2.
A) The compiler moved the first variable onto stack and the rest into registers R0-R3. Once the compiler branched to the called function, it loaded variable from the stack into register R5.

B) I did not observe any extra assembly code (other than what I specified above) before the compiler branched to the called function.

C) Compiler pushed register R4-R5 data to the stack and loaded variable from stack into register R5.

D) After returning from function the compiler loaded the data from stack into registers R1, R2, R4, and PC.