#include <stdio.h>
void printScore(int*);
void compareArrays(int*, int*, int*);
int readGuessCode (int*);

int main(void) 
{
  int score[2];
  int secretCode[5];
  int guessCode[5];
  int errorCode = 1;
  secretCode[0]=1;
  secretCode[1]=3;
  secretCode[2]=7;
  secretCode[3]=2;
  secretCode[4]=9;
  
  while (errorCode == 1)
  {
    errorCode = readGuessCode(guessCode);
  }
  compareArrays(secretCode, guessCode, score);
  printScore(&score[0]);
  return 0;
}

void printScore (int* a)
{
  printf("Exact matches: %d, Inexact matches: %d\n", a[0], a[1]);
}

void compareArrays (int* inputArray1, int* inputArray2, int* scoreArray)
{
  int countMatch=0;
  for (int index=0; index<5; index++)
  {
    if (inputArray1[index] == inputArray2[index])
    {
      countMatch++;
    }
  }
  scoreArray[0]=countMatch;

  int countOverall=0;
  for (int index1=0; index1<5; index1++)
  {
    for (int index2=0; index2<5; index2++)
    {
      if (inputArray1[index1] == inputArray2[index2])
      {
        countOverall++;
      }
    }
  }
  int countMisses = countOverall - countMatch;

  scoreArray[1]=countMisses;
}

int readGuessCode(int* inputArray)
{
  char input[256];
  int userInput;

  while (1)
  {
    printf ("Please input a 5 digit guess code: ");
    fgets(input, 256, stdin);
    if (sscanf(input, "%d", &userInput) == 1) break;
    printf("Not a valid number - try again!\n");
  }
  printf("You entered the number %d\n", userInput);
  inputArray[0] = userInput/10000;
  userInput = userInput - inputArray[0]*10000;
  inputArray[1] = userInput/1000;
  userInput = userInput - inputArray[1]*1000;
  inputArray[2] = userInput/100;
  userInput = userInput - inputArray[2]*100;
  inputArray[3] = userInput/10;
  userInput = userInput - inputArray[3]*10;
  inputArray[4] = userInput;
  printf ("Your code is: %d-%d-%d-%d-%d\n", inputArray[0], inputArray[1], inputArray[2], inputArray[3], inputArray[4]);
  for (int index=0; index<5; index++)
  {
    if (inputArray[index] < 0 || inputArray[index] > 9)
    {
      printf("The number %d is not a legal digit\n", inputArray[index]);
      return 1;
    }
  }
  for (int index1=0; index1<5; index1++)
  {
    for (int index2=index1+1; index2<5; index2++)
    {
      if (inputArray[index1] == inputArray[index2])
      {
        printf("The number %d appears too many times\n", inputArray[index1]);
        return 1;
      }
    }
  }
  return 0;
}
