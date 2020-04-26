//codeRSH	DS: 01.08.2011	DE: 01.08.2011

#include<stdio.h>
#define ELMNTS 4

int main()
{
	int i, intgr[ELMNTS];
	
	printf("Enter %d integer values: \n", ELMNTS);
	
	for (i = 0; i < ELMNTS; i++ ) {
		scanf("%d", &intgr[i]);		
	}

	printf("Checking for Divisibility by 4...\n");
	for (i = 0; i < ELMNTS; i++ ) {
		if ((intgr[i] & 3) == 0)
			printf("%d is divisible by 4\n", intgr[i]);			
		else
			printf("%d is Not divisible by 4\n", intgr[i]);			
	}

	printf("\n");
	return 0;	
}
