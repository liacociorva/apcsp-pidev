#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printScore(int*);
void compareArrays(int*, int*, int*);
int readGuessCode (int*);
int checkDuplicates (int*);
void createAllCodes (int*); 

int main(void) 
{
  int totalValidCodes = 30241;
  int score[2] = {0,0};
  int secretCode[5];
  int guessCode[5];
  int allCodes[totalValidCodes][5];
  int errorCode = 1;
  int tryCount = 0;

  createAllCodes(&allCodes[0][0]);
  srand(time(NULL));
  int randomCode = rand() % totalValidCodes;

  for (int index = 0; index < 5; index++)
  {
    secretCode[index]=allCodes[randomCode][index];
  }
  printf ("Secret code is: %d-%d-%d-%d-%d\n", secretCode[0], secretCode[1], secretCode[2], secretCode[3], secretCode[4]);


  while (score[0] != 5 && tryCount<20)
  {
    errorCode = 1;
    while (errorCode == 1)
    {
      errorCode = readGuessCode(guessCode);
    }
    compareArrays(secretCode, guessCode, score);
    printScore(&score[0]);
    tryCount++;
    printf ("You tried %d times.\n", tryCount);
  }
  if (score[0]==5)
  {
    printf("You cracked the code in %d tries!\n", tryCount);
  }
  else 
  {
    printf("You failed to crack the code in under 20 tries. \n");
  }
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

int checkDuplicates (int* inputArray)
{
 for (int index1=0; index1<5; index1++)
  {
    for (int index2=index1+1; index2<5; index2++)
    {
      if (inputArray[index1] == inputArray[index2])
      {
        return 1;
      }
    }
  }
  return 0;
} 

void createAllCodes (int* arrayList)
{
int count = 0;
int tempArray[5];

  for (int index0=0; index0<10; index0++)
  {
    for (int index1=0; index1<10; index1++)
    {
      for (int index2=0; index2<10; index2++)
      {
        for (int index3=0; index3<10; index3++)
        {
          for (int index4=0; index4<10; index4++)
          {
            tempArray[0] = index0;
            tempArray[1] = index1;
            tempArray[2] = index2;
            tempArray[3] = index3;
            tempArray[4] = index4;
            int check = checkDuplicates(tempArray);
            if (check == 0)
            {
              arrayList[5*count+0] = tempArray[0];
              arrayList[5*count+1] = tempArray[1];
              arrayList[5*count+2] = tempArray[2];
              arrayList[5*count+3] = tempArray[3];
              arrayList[5*count+4] = tempArray[4];
              count++;
            // printf("%d  -  %d-%d-%d-%d-%d\n", count, index0, index1, index2, index3, index4);
            }
          }
        }
      }
    }
  }

}
