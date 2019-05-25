#include <stdio.h>
#include <math.h>
#define PI 3.142
int main() 
{
  float area;
  for (float radius=3.5; radius < 13.5; radius++)
  {
    area = PI * pow(radius, 2);
  printf (" Radius: %f, Area: %f", radius, area);
  }
}
