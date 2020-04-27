#include<stdio.h>

int square ()
{
  int a=9;
  return(a*a);
}

int main ()
{
  int num=2;
  int num2 = square();

  printf("Square of %d is %d", num, num2);

  return 0;
}