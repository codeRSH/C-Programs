//codeRSH	DS: 02.08.2011	DE: 02.08.2011

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1

int main()
{
	double bal, amnt;
	char str[10], amntstr[20];

	printf("BANK ACCOUNT PROGRAM\n");
	printf("--------------------\n");
	
	printf("Enter the old balance:  ");
	bal = atof(gets(amntstr));
	printf("Enter the transactions now.\n");
	
	while (TRUE) {
		printf("\nTransaction Type (D=deposit, W=withdrawal, F=Finished) : ");
		gets(str);

		if (*str == 'F')
			break;

		printf("Amount: ");
		amnt = atof(gets(amntstr));

		if (*str == 'D')
			bal += amnt;
		else if (*str == 'W')
			bal -= amnt;
	}

	printf("\nYour ending balance is $%lf\n", bal);
	printf("Program Ending\n\n");

	return 0;
}
