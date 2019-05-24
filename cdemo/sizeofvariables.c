#include <stdio.h>
int main()
{
int a = 10;
char c= 'a';
float f=12.345;
double d=123.456;
short int b=7;
unsigned int h=45;
printf("My int is : %d, my char is %c, my float is %f, my double is %f\n", a, c, f, d);
printf("My int has a size of %d bytes, my char has a size of %d bytes, my float has a size of %d bytes, my double has a size of %d bytes, my unsigned int has a size of %d, my short int has a size of %d\n", sizeof(a),
sizeof(c), sizeof(f), sizeof(d), sizeof(h), sizeof(b));

}
