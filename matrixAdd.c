// Program to add two Matrices.
// 15.11.10 - 15.11.10 codeRSH

#include<stdio.h>

int main() 
{
	//clrscr();
	
	int a[3][3], b[3][3], c[3][3];
	int i, j;
	
	printf("Enter values for first matrix: \n");	
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++) 
			scanf("%d", &a[i][j]);
	}
	
	printf("\n\nFirst Matrix: \n");	
	for (i=0; i<3; i++)
	{
		printf("\n");
		for (j=0; j<3; j++)
		{ 
			printf("%5d", a[i][j]);
		}
	}
	
	printf("\n\nEnter values for second matrix: \n");	
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++) 
		{
			scanf("%d", &b[i][j]);
		}
	}
	
	printf("\n\nSecond Matrix: \n");
	
	for (i=0; i<3; i++)
	{
		printf("\n");
		for (j=0; j<3; j++)
		{ 
			printf("%5d", b[i][j]);
		}
	}

	
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++) 
		{
			c[i][j] = a[i][j] +  b[i][j];
		}
	}
	
	printf("\n\nAddition of Matrix A and Matrix B: \n");
	
	for (i=0; i<3; i++)
	{
		printf("\n");
		for (j=0; j<3; j++)
		{ 
			printf("%5d", c[i][j]);
		}
	}
	
	printf("\n\n");
	//getch();
	return 0;	
}
