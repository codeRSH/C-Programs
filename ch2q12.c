//codeRSH	DS: 13.08.2011	DE: 13.08.2011

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

int isprime(int);

int main()
{
	int num, i, j = 0;
	char string[20];
	
	printf("So you want to two numbers factored.\n");
	printf("Give them to me one by one and I will do the factoring.\n\n");
	
	do {
		printf("\nNumber? ");
		num = atoi(gets(string));
			
		if (isprime(num))
			printf("%i is itself a prime number", num);
		else {
			printf("The prime factorization of %d is: ", num);
		
			for (i = 2; i <= num;i++) {
				if ((num%i == 0) && isprime(i)) {
					num /= i;
					printf("%i", i--);	// Same factor may occur multiple times
					
					if (num && (num != 1))
						printf(" * ");
					else
						printf(".\n\n");
				}
			}
		}			
	} while(++j<2);
	
	printf("You are welcome. The bill is in the mail.\n");
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
