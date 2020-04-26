//codeRSH	DS: 03.08.2011	DE: 03.08.2011

#include<stdio.h>

int main()
{
	unsigned char chr = 0;

	printf("The ASCII Character Set\n\n");
	printf("DEC\tHEX\tCHAR\tDEC\tHEX\tCHAR\tDEC\tHEX\tCHAR\n");
	do {
		printf("%d\t%X\t%c\t", chr, chr, chr);
		printf("%d\t%X\t%c\t", chr+32, chr+32, chr+32);
		printf("%d\t%X\t%c", chr+64, chr+64, chr+64);
		printf("\n");
	} while(++chr < 32);
	
	printf("\n\nGoodbye!\n");
	return 0;
}
