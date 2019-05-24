#include <stdio.h>

int main()
{
  int a = 0;
  int b=5;


  if (a == 0)
  {
    printf("a is 0\n");
  }
  else
  {
    printf("a is not 0\n");
  }

  if (b == 5)
  {
    printf("b is 5\n");
  }
  else
  {
    printf("b is not 5\n");
  }
if (a != b)
  {
    printf("a is not b\n");
  }
  else
  {
    printf("a is b\n");
  }    
if (a >  b)
  {
    printf("a is greater than b\n");
  }
  else
  {
    printf("a is not greater than b\n");
  }        

if (a <  b)
  {
    printf("a is less than b\n");
  }
  else
  {
    printf("a is not less than b\n");
  }    
if (a <= b)
  {
    printf("a is less than or equal to b\n");
  }
  else
  {
    printf("a is not less than or equal to b\n");
  }    
if (a == 0 && b == 0)
  {
    printf("a is 0 and b is 0\n");
  }
  else
  {
    printf("a is not 0 or b is not 0\n");
  }   
 if (a == 0 || b == 0)
  {
    printf("a is 0 or b is 0\n");
  }
  else
  {
    printf("neither a nor b are 0\n");
  }    
if (!(b == 0))
  {
    printf("b is not 0\n");
  }
  else
  {
    printf("b is 0\n");
  }    
}

