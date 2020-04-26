// Program: Ls.c -- Used to show the files inside a directory
  
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    DIR *dir;		// Returned by opendir
    struct dirent *direntry;    // Returned by readdir
    char thisDir[201];
    char *dirName;
    
    // If there is no argument with the program name use current directory
    if (argc <= 1 ) {
	    if (getcwd(thisDir, 200) == -1) {   // Getting current directory
    	    perror("getcwd");
    	    exit(1);
		}
		
		dirName = thisDir;
	}
		
	else // Use the directory name specified
		dirName = argv[1];
		
	// Directory must exist and have read permission
    if ((dir = opendir(dirName)) == NULL) {      
        perror("opendir");
        exit(2);                    
    } 	   
	
    // Till there are entries inside the directory
    while ((direntry = readdir(dir)) != NULL)
        printf("%10d %s\n", direntry->d_ino, direntry->d_name);
  
    closedir(dir);
    exit(0);
}

