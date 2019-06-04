#include <stdio.h>
void printScore(int*);



int main(void) {
int score[2];
score[0] = 2;
score[1] = 3;
printScore(&score[0]);
  return 0;
}

void printScore (int* a)
{
  printf("Exact matches: %d, Inexact matches: %d\n", a[0], a[1]);
}
