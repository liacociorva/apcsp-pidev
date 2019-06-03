#include <stdio.h>
#include <string.h>
int comparestrings (int* inputarray1; int* inputarray2)
{
for (int index=0; index<5; index++)
{
if (inputarray1[index]==inputarray2[index])
{
printf ("1 perfect match\n");
}
}
}
int main()
{
comparestrings (12345, 32567);
}
