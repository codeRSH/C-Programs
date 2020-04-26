//codeRSH	DS: 01.08.2011	DE: 01.08.2011

#include<stdio.h>

#define ELMNTS 4

int main()
{
	int i;
	float flt[ELMNTS], max, min;
	
	printf("Enter %d float values: \n", ELMNTS);
	
	for (i = 0; i<ELMNTS; i++ ) {
		scanf("%f", &flt[i]);		
	}

	max = min = flt[0];
	
	for (i = 0; i<ELMNTS; i++ ) {
		if (flt[i] > max)
			max = flt[i];
		else if (flt[i] < min)
			min = flt[i];
	}
	
	printf("The maximum of all is %f\n", max);
	printf("The minimum of all is %f\n", min);

	return 0;	
}
