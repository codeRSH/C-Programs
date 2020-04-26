// Program: Rmdir.c -- To create a directory

#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv) {

	if (rmdir(argv[1]) == -1) {
		perror(argv[1]);
		exit(1);
	}

	printf("%s removed\n", argv[1]);
	exit(0);
}
