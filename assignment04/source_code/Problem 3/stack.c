#include "stack.h"

#define STACK_SIZE 5 

int stack[STACK_SIZE]; // define stack
int *pushPtr;
int *popPtr;

// Provide a function to initialize the stack internals
void stack_init(void){
  pushPtr = &stack[0];
  popPtr = &stack[0];
 
  for (int i=0; i<STACK_SIZE; i++)
  {
    stack[i]=0;
  }
}

// Provide a function to push an element onto the stack
int stack_push (int data){
  if (pushPtr == &stack[STACK_SIZE-1] && popPtr == pushPtr)  // check if stack is full
  {
    return 1;    // stack is full
  }
  else
  {
    *pushPtr = data;    // add data to stack
    popPtr = pushPtr;   // update stack pop pointer
    if (pushPtr != &stack[STACK_SIZE-1])
    {
        pushPtr++;  // increment stack push pointer 
    }
    return 0;
  }
}

// Provide a function to pop an element off the stack
int stack_pop (int* data){
  if (popPtr == &stack[0] && pushPtr== &stack[0])       // check if stack is empty
  {
    return 1;   // stack is empty
  }
  else
  {
    *data = *popPtr;
    *popPtr = 0; // Clean up removed items
    pushPtr = popPtr; // update stack push pointer
    if (popPtr != &stack[0])
    {
      popPtr--;   // decrement stack pop pointer
    }
    return 0;
  }
}