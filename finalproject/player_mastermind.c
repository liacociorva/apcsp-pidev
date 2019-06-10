#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerGame (void);

// Main program for the player version of Mastermind. The function playerGame is called. 
int main(void)
{
  int errorCode = playerGame();
  return errorCode;
}
