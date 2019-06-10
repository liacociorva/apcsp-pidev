#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int computerGame (int);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Error - program %s expects one input code!\n", argv[0]);
    return 1;
  }

  int numericSecretCode;
  int found = sscanf(argv[1], "%d", &numericSecretCode);
  if (found != 1)
  {
    printf("Error - secret code %s is not numeric!\n", argv[1]);
    return 1;
  }

  int errorCode = computerGame(numericSecretCode);
  return errorCode;
}
