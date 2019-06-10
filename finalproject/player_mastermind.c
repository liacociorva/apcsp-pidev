#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printScore (int*);
void compareArrays (int*, int*, int*);
int readCode (int*, int);
int checkDuplicates (int*);
void createCodes (int*); 
int playerGame (void);

int main(void)
{
  int errorCode = playerGame();
  return errorCode;
}
