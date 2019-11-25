
void swap_pointer(int **x, int **y);

int main()
{
  int x = 2000000;
  int y = 1000000;
  
  int *xPtr = &x;
  int *yPtr = &y;
 
  swap_pointer (&xPtr, &yPtr);
 
  return 0;
}

void swap_pointer(int **x, int **y){
 int *tempPtr = *x;
 *x = *y;
 *y = tempPtr;
}
