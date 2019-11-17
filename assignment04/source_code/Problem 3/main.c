#include "assert.h"
#include "stack.h"

int main()
{
  int testData = 100; 
  int result1, result2, result3, result4, result5, result6;
   
  // *******************************************************************
  // Test 1: Pop an item from empty stack
  // *******************************************************************
  // Arrange:
  stack_init();
  // Act:
  result1 = stack_pop(&testData);
  // Assert:
  assert (result1 == 1);
  assert (testData == 100);
  
  // *******************************************************************
  // Test 2: Push an item on stack and then pop an item
  // *******************************************************************
  // Arrange:
  stack_init();
  // Act:
  result1 = stack_push(50);
  result2 = stack_pop(&testData);
  // Assert:
  assert (result1 == 0);
  assert (result2 == 0);
  assert (testData == 50);
  
  // *******************************************************************
  // Test 3: Push an item to a full stack
  // *******************************************************************
  // Arrange:
  stack_init();
  
  // Act:
  result1 = stack_push(10);
  result2 = stack_push(20);
  result3 = stack_push(30);
  result4 = stack_push(40);
  result5 = stack_push(50);
  result6 = stack_push(60);
  
  // Assert:
  assert (result1 == 0);
  assert (result2 == 0);
  assert (result3 == 0);
  assert (result4 == 0);
  assert (result5 == 0);
  assert (result6 == 1);
  
  // *******************************************************************
  // Test 4: Fill the stack and then pop all items
  // *******************************************************************
  // Arrange:
  stack_init();
  // Act:
  result1 = stack_push(10);
  result2 = stack_push(20);
  result3 = stack_push(30);
  result4 = stack_push(40);
  result5 = stack_push(50);
  // Assert:
  assert (result1 == 0);
  assert (result2 == 0);
  assert (result3 == 0);
  assert (result4 == 0);
  assert (result5 == 0);
  
  assert (stack_pop(&testData) == 0);
  assert (testData == 50);
  assert (stack_pop(&testData) == 0);
  assert (testData == 40);
  assert (stack_pop(&testData) == 0);
  assert (testData == 30);
  assert (stack_pop(&testData) == 0);
  assert (testData == 20);
  assert (stack_pop(&testData) == 0);
  assert (testData == 10);
  
  // ***************************************************************************
  // Test 5: Fill the stack, pop one item, push one item, and then pop all items
  // ***************************************************************************
  // Arrange:
  stack_init();
  // Act and Assert:
  assert (stack_push(100) == 0);
  assert (stack_push(200) == 0);
  assert (stack_push(300) == 0);
  assert (stack_push(400) == 0);
  assert (stack_push(500) == 0);
  
  assert (stack_pop(&testData) == 0);
  assert (testData == 500);
  
  assert (stack_push(800) == 0);
  
  assert (stack_pop(&testData) == 0);
  assert (testData == 800);
  assert (stack_pop(&testData) == 0);
  assert (testData == 400);
  assert (stack_pop(&testData) == 0);
  assert (testData == 300);
  assert (stack_pop(&testData) == 0);
  assert (testData == 200);
  assert (stack_pop(&testData) == 0);
  assert (testData == 100);

  return 0;
}