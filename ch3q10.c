//codeRSH	DS: 14.08.2011	DE: 14.08.2011

#include<stdio.h>
#include<stdlib.h>

#define MAX 6

int main()
{
	int studio, oneb, twob, s1, s2, s3, i1, i2, i3, ans;
	
	printf("ACME REAL ESTATE PLANNING PROGRAM\n");
	printf("----------------------------------\n");
	
	do {
		printf("How many studio apartments?  ");
		scanf("%d", &studio);
		printf("How many one-bedroom apartments?  ");
		scanf("%d", &oneb);
		printf("How many two-bedroom apartments?  ");
		scanf("%d", &twob);
		fflush(stdin);	

		printf("\nReport for %d studio apartments\n", studio);
		printf("%d one-bedroom apartments\n", oneb);
		printf("%d two-bedroom apartments\n", twob);
		
		printf("\t\t\tSpace\t\tCosts\t\tIncome\n");
		printf("\nStudios:\t\t%d\t\t%d\t\t%d", s1 = studio*200, studio*200*75, i1 = studio*450*12);
		printf("\nOne-Bedrooms:\t\t%d\t\t%d\t\t%d", s2 = oneb*300, oneb*300*75, i2 = oneb*550*12);
		printf("\nTwo-Bedrooms:\t\t%d\t\t%d\t\t%d", s3 = twob*450, twob*450*75, i3 = twob*700*12);	
		printf("\nTotals:\t\t\t%d\t\t%d\t\t%d", s1+s2+s3, (s1+s2+s3)*75, i1+i2+i3);
		
		printf("\n\nDo you want to enter another set of data (y/n)? ");
		fflush(stdin);
		getchar();
		ans = getchar();
	} while (ans == 'y' || ans == 'Y');
	
	printf("\nThank you\n\n");
	return 0;
}
