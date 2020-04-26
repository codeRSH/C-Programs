// Program: Mkdir.c -- To create a directory

#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv) {

	// Second argument takes the new directory permission
	if (mkdir(argv[1], 0664) == -1) {
		perror(argv[1]);
		exit(1);
	}
	
	printf("%s created\n", argv[1]);	
	exit(0);
}
