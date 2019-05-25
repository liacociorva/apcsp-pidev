
#include <stdio.h>

void arrayAdd(int*, int, int);

int main() 
{
  int arr [100];
  for (int i = 0; i < 100; ++i)
  {
    arr[i] = i * i;
  }

  for (int i = 0; i < 100; ++i)
  {
    printf ("%d > %d\n" , i, arr[i]);
  }
  arrayAdd(arr, 100, 5);
  printf ("adding 5: \n");
  for (int i = 0; i < 100; ++i)
  {
    printf ("%d > %d\n" , i, arr[i]);
  }
}
void arrayAdd(int* inputArray, int s, int n)
{
  for (int i = 0; i < s; ++i)
  {
    inputArray[i]+=n;
  }
}
