#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printScore(int*);
void compareArrays(int*, int*, int*);
int readCode (int*, int);
int checkDuplicates (int*);
void createCodes (int*); 

int playerGame(void) 
{
  int totalValidCodes = 30241;
  int secretCode[5];
  int guessCode[5];
  int allCodes[totalValidCodes][5];

  createCodes(&allCodes[0][0]);
  srand(time(NULL));
  int randomCode = rand() % totalValidCodes;

  for (int index = 0; index < 5; index++)
  {
    secretCode[index]=allCodes[randomCode][index];
  }
  printf ("Secret code is: %d-%d-%d-%d-%d\n", secretCode[0], secretCode[1], secretCode[2], secretCode[3], secretCode[4]);

  int tryCount = 0;
  int score[2] = {0,0};
  while (score[0] != 5 && tryCount<20)
  {
    int errorCode = 1;
    while (errorCode == 1)
    {
      int numericGuessCode;
      char input[256];
      printf ("\nPlease input a 5 digit guess code: ");
      fgets(input, 256, stdin);
      if (sscanf(input, "%d", &numericGuessCode) != 1) 
      {
        printf("Error: not a valid number - try again!\n");
      }
      else
      {
        errorCode = readCode(guessCode, numericGuessCode);
      }
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
