#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %d\n", ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %d\n", &a);
 float d=3.21;
 float e=5.75;
printf("The value of d is %f\n", d);
printf("The value of e is %f\n", e);
printf("The address of d is %d\n", &d);
printf("The address of e is %d\n", &e);
float *ptrtod = &d;
float *ptrtoe = &e;
float temp;
temp=d;
d=e;
e=temp;
printf("The value of d is %f\n", d);
printf("The value of e is %f\n", e);
}
