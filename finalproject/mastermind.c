#include <stdio.h>
#include <string.h>

int playerGame (void);
int computerGame (int);

void main()

{
	printf("Mastermind game\n\n");
	printf("Rules of the game: one player selects a 5 digit secret code, with the condition that all digits are different. The other player attempts to guess it, in as few tries as possible. Every time a guess is made, feedback is given, counting the number of exact matches and inexact matches.\n\n"); 

	printf("Example:\n");
	printf("Secret code is: 54218\n");
	printf("Guess code is:  84653\n");
	printf("Exact matches: 1 (number 4). Inexact matches: 2 (numbers 5 and 8).\n\n");
	
	int a = 1;
	while (a == 1)
	{
		char input [256];
		float choice;
		printf("Do you want to guess the five integers of the computer (1), or do you want the computer to guess your five integers (2)?\n");

	fgets (input, 256, stdin);
	sscanf (input, "%f", &choice);

		if (choice == 1)
		{
			printf("\nUser playing the game...\n\n");
			int errorCode = playerGame();
			break;
		}
		else if (choice == 2)
		{
			printf("\nComputer playing the game...\n\n");
			char input[256];
			printf ("Please enter your secret code: ");
			fgets(input, 256, stdin);
			int numericSecretCode;
			if (sscanf(input, "%d", &numericSecretCode) != 1)
			{
				printf("Error: not a valid number!\n");
			}
			else
			{
				int errorCode = computerGame(numericSecretCode);
			}
			break;
		}
		else
		{
			printf("Not a valid choice, please try again.\n\n");
		}
	}
}
