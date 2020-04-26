//codeRSH	DS: 03.08.2011	DE: 03.08.2011

#include<stdio.h>
#include<stdlib.h>

#define MAX 6

int main()
{
	unsigned num, regular, special, vip, i;
	char str[20];
	double bal;	
	regular = special = vip = i = 0;
	
	printf("\nEnter the number of customers (max %d):\t", MAX);
	num = atoi(gets(str));
	
	printf("Enter the bank balance of each customers: \n\n");
	while (i++ < num) {
		printf("Customer %d:", i);
		bal = atof(gets(str));
		
		if (bal < 10000)
			regular++;
		else if (bal > 50000)
			vip++;
		else
			special++;
	}
	
	printf("\nRegular customers: %d", regular);
	printf("\nSpecial customers: %d", special);
	printf("\nVIP customers: %d", vip);
	printf("\n\nGoodbye!\n");
	return 0;
}
