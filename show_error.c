#include<stdio.h>
#include<string.h>

int main() 
{

	int i;
	extern int sys_nerr;
	
	for (i=0; i<sys_nerr; i++) {
		printf("\n%d : %s", i, strerror(i));
	}
	
	printf("\n\nTotal errors: %i\n", sys_nerr);
	
	return 0;
}
