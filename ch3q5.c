//codeRSH	DS: 02.08.2011	DE: 02.08.2011

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1

int main()
{
	double bal, amnt;
	char str[10], amntstr[20];

	printf("INTEGER CONVERSION PROGRAM\n");
	printf("--------------------\n");
		
	while (TRUE) {
		printf("\nBase of Input (d=decimal, h=hexadecimal, o=octal) : ");
		gets(str);

		printf("Number: ");
		if (*str == 'd')
			scanf("%d", &num);
		else if (*str == 'h')
			scanf("%x", &num);
		else if (*str == 'o')
			scanf("%o", &num);

		fflush(stdin);

		printf("\nBase of Output (d=decimal, h=hexadecimal, o=octal) : ");
		gets(str);

		if (*str == 'd')
			printf("The integer %d", &num);
		else if (*str == 'h')
			scanf("%x", &num);
		else if (*str == 'o')
			scanf("%o", &num);
		
		printf("Another Number? (Y/N)");
		gets(choice);
		if (*choice == 'N' || *choice == 'n')
			break;
	}

	printf("\nYour ending balance is $%lf\n", bal);
	printf("Program Ending\n\n");

	return 0;
}
