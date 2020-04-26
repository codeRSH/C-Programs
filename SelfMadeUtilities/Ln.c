// Program: Ln.c -- To create hard and symbolic links

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv) {

	// If -s option specified
	if (strcmp(argv[1], "-s") == 0) {
	// Use symbolic Link
		if (symlink(argv[2], argv[3]) == -1) {
			perror("Symbolic Link: ");
			exit(1);
		}
		printf("%s --> %s\n", argv[2], argv[3]);
	}	
	
	else { // Use hard link.
		if (link(argv[1], argv[2]) == -1) {
			perror("Hard Link: ");
			exit(2);
		}
		printf("%s --> %s\n", argv[1], argv[2]);
	}
	
	exit(0);
}
