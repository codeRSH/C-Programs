// Program: Pwd.c -- To find the present working directory
  
#include <stdio.h>
#include <stdlib.h>
#define PATH_LENGTH 200

  
int main(int argc, char **argv) {
    char olddir[PATH_LENGTH + 1];
    
    if (getcwd(olddir, PATH_LENGTH) == -1) {   // Getting current directory
        perror("getcwd");
        exit(1);
	}
	
    printf("pwd: %s\n", olddir);

    exit(0);
}

