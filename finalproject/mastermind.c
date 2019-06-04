#include <stdio.h>
void printScore(int*);
void compareArrays(int*, int*, int*);


int main(void) 
{
  int score[2];
  int secretCode[5];
  int guessCode[5];
  secretCode[0]=1;
  secretCode[1]=3;
  secretCode[2]=7;
  secretCode[3]=2;
  secretCode[4]=9;
  guessCode[0]=1;
  guessCode[1]=0;
  guessCode[2]=9;
  guessCode[3]=2;
  guessCode[4]=7;
  printScore(&score[0]);
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




