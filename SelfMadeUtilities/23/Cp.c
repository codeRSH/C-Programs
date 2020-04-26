// Cp.c -- Copies a file with the read and write system calls
  
#include <fcntl.h>             // For O_RDONLY, O_WRONLY, O_CREAT etc.
#include <sys/stat.h>          // For S_IRUSR, S_IWUSR, S_IRGRP etc. 
#include <stdlib.h> 
#define BUFSIZE 1024
  
int main(int argc, char **argv) {
    int fd1, fd2;              // File descriptors for read and write
    int n;                     // Number of characters returned by read
    char buf[BUFSIZE];         // BUFSIZE should be carefully chosen

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
		perror(argv[1]);	// Shows the error description
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 
               S_IRUSR | S_IWUSR | S_IRGRP |S_IWGRP | S_IROTH);   // Mode 664
  	if (fd2 == -1)
		perror(argv[2]);
		
    while ((n = read(fd1, buf, BUFSIZE)) > 0)   // Return value of read is
        write(fd2, buf, n) ;                    // used by write as argument
  
    close(fd1);	// Closing the files
    close(fd2);
    exit(0);
}

