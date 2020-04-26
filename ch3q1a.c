//codeRSH	DS: 01.08.2011	DE: 01.08.2011

#include<stdio.h>

int main()
{
	int intgr[20], i, sum = 0;
	
	printf("Enter 20 Integers: \n");
	
	for (i = 0; i<20; i++ ) {
		scanf("%d", &intgr[i]);
		sum += intgr[i];
	}
		
	printf("The sum is %d\n", sum);
	printf("The average is %f\n", (float)sum/20);
	
	return 0;	
}
