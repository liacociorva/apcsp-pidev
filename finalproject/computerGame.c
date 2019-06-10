#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printScore (int*);
void compareArrays (int*, int*, int*);
int readCode (int*, int);
int checkDuplicates (int*);
void createCodes (int*); 

int computerGame(int numericSecretCode)
{
  int numValidCodes = 30241;
  int secretCode[5];
  int guessCode[5];
  int validCodes[numValidCodes][5];

  int errorCode = readCode(secretCode, numericSecretCode);
  if (errorCode == 1) 
    return errorCode;

  createCodes(&validCodes[0][0]);
  srand(time(NULL));

  int tryCount = 0;
  int score[2] = {0,0};
  while (score[0] != 5 && tryCount<20)
  {

    // First step: choose a random guess code among the remaining possible ones
    printf("\nChoosing from %d possible codes...\n", numValidCodes);
    int randomCode = rand() % numValidCodes;
    for (int index = 0; index < 5; index++)
    {
      guessCode[index]=validCodes[randomCode][index];
    }
    printf ("My guess code is: %d-%d-%d-%d-%d\n", guessCode[0], guessCode[1], guessCode[2], guessCode[3], guessCode[4]);

    // Second step: compare the guess code with the actual secret code and return the score (normally the player does that, interactively, and returns the score)
    compareArrays(secretCode, guessCode, score);
    printScore(&score[0]);
    tryCount++;
    printf ("I tried %d times.\n", tryCount);

    // Third step: heart of the algorithm. Go through the entire list of remaining possible codes and keep only those that would give the same score to the comparison. Any code that gives a different score is discarded. 
    int validCount = 0;
    for (int validIndex = 0; validIndex < numValidCodes; validIndex++)
    {
      int tempScore[2];
      compareArrays(guessCode, &validCodes[validIndex][0],tempScore);
      if (tempScore[0] == score[0] && tempScore[1] == score[1])
      {
        for (int index = 0; index < 5; index++)
        {
          validCodes[validCount][index] = validCodes[validIndex][index];
        }
        validCount++;
      }
    }
    numValidCodes = validCount;
  }


  // The game ends when either the code is cracked or after 20 tries. Print the appropriate message in each case. 
  if (score[0]==5)
  {
    printf("I cracked the code in %d tries!\n", tryCount);
  }
  else 
  {
    printf("I failed to crack the code in under 20 tries. \n");
  }
  return 0;
}
