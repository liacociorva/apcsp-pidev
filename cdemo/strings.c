#include <stdio.h>
#include <string.h>

int main()
{
	char alphabetstr1[27];
	char c = 'a';
	for (int i = 0; i < 26; i++)
	{
		alphabetstr1[i] = c;
		c++;
	}
	printf("alphabetstr1 is %s\n", alphabetstr1);
	char alphabetstr2[] = "abcdefghijklmnopqrstuvwxyz";
	printf("alphabetstr2 is %s\n", alphabetstr2);
	if (strcmp(alphabetstr1, alphabetstr2) ==  0)
		printf("The two strings are equal.\n");
	else
		printf("The two strings are not equal.\n");
	int a = 65;
	char n;
	for (int x = 0; x < 26; x++)
	{
		n = a;
		alphabetstr2[x] =  n; 
		a++;
	}
	printf("alphabetstr2 is now %s\n", alphabetstr2);
  if (strcmp(alphabetstr1, alphabetstr2) ==  0)
		printf("The two strings are equal.\n");
	else
		printf("The two strings are not equal.\n");
	char alphabetstr3[53];
	strcpy(alphabetstr3, alphabetstr2);
	strcat(alphabetstr3, alphabetstr1);
	printf("alphabetstr3 is %s\n", alphabetstr3);
} 
