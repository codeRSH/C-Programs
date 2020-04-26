//codeRSH	DS: 13.08.2011	DE: 13.08.2011

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define CORRECT 23

int check(int);

int main()
{
	int num, i = 0, j = 0;
	char string[20], ans = 'y';

	printf("Welcome to the Game of Guess It.\n");
	printf("I will choose a number between 1 and 100.\n");
	printf("You will try to guess that number. If you gues wrong,");
	printf("I will tell you if you guessed too high or too low.\n");
	printf("You have 6 tries to guess the number.\n\n");
	printf("OK, I am thinking of a number. Try to guess it.\n\n");

	while ((ans=='y') && i<6) {
		printf("\nYour Guess? ");

		if (!check(num = atoi(gets(string)))) {
			if (++i == 6) {
				printf("\nYour 6 tries are over.");

				printf("\n\nWant to play again? (y/n)  ");
				ans = *gets(string);
				i = 0;
			}
		}
		else {
			printf("\n\nWant to play again? (y/n)  ");
			ans = *gets(string);
			i = 0;
		}
	}

	printf("Goodbye, it was fun. Play again soon.\n");
	return 0;
}

int check(int num)
{
	if ((num<1) || (num>100)) {
		printf("Illegal guess. Your guess must be between 1 and 100.\n");
		printf("Try again.\n");
	}
	else if (num < CORRECT)
		printf("Too low!\n");
	else if (num > CORRECT)
		printf("Too high!\n");
	else {
		printf("**** CORRECT ****\n");
		return TRUE;
	}

	return FALSE;
}
