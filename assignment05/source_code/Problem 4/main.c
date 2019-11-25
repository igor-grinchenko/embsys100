
extern void swapCharsAsm(char *x, char *y);

int main()
{
  char var1 = {'A'};
  char var2 = {'B'};
  
  swapCharsAsm(&var1, &var2);
  
  return 0;
}
