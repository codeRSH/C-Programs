//codeRSH	DS: 01.08.2011	DE: 01.08.2011

#include<stdio.h>

#define ELMNTS 20

int main()
{
	int intgr[ELMNTS], i, sum = 0;
	float avg;
	
	printf("Enter %d Integers: \n", ELMNTS);
	
	for (i = 0; i<ELMNTS; i++ ) {
		scanf("%d", &intgr[i]);
		sum += intgr[i];
	}
		
	printf("The sum is %d\n", sum);
	
	avg = (float)sum/ELMNTS;
	
	if ((avg-sum/ELMNTS) >= 0.5)
		printf("The average is %d\n", sum/ELMNTS + 1);
	else
		printf("The average is %d\n", sum/ELMNTS);
	
	return 0;	
}
