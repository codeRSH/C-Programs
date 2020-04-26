//codeRSH	DS: 03.08.2011	DE: 03.08.2011

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

int isprime(int);

int main()
{
	int num, i, j = 0;
	char string[20];

	do {
		printf("\nNumber? ");
		num = atoi(gets(string));
			
		if (isprime(num))
			printf("%i is itself a prime number", num);
		else {
			printf("The prime factorization of %d is: ", num);
		
			for (i = 2; i <= num/2;i++) {
				if ((num%i == 0) && isprime(i))
					printf("%i", i);
					
				
			}
		}

			
	} while(++j<2);
	
	printf("Goodbye!\n");
	return 0;
}

int isprime(int num)
{
	int i;
	
	for (i = 2; i <= num/2; i++)
		if (num%i == 0)
			return FALSE;
	
	return TRUE;
}
