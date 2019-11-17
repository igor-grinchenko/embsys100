#include "assert.h"

int sum(int var0,int var1,int var2,int var3,int var4);

int main()
{
  int result;
  
  result = sum(1,2,3,4,5);
  assert(result == 15);
  
  return 0;
}

int sum(int var0,int var1,int var2,int var3,int var4) {
    int sum;
    
    sum = var0 + var1 + var2 + var3 + var4;

    return sum;
}