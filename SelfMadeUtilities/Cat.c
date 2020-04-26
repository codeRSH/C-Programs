#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BUFFSIZE 2048

int main(int argc, char *argv[]) 
{
	int fd1, n;
	char buf[BUFFSIZE];

/*	
	if (strcmp(argv[1], ">")) {
		fd1 = open(argv[2], O_WRONLY | O_TRUNC);
		if (fd1 == -1) {
			perror(argv[2]);
			exit(1);
		}		

		while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) 
		write (fd1, buf, n);
	}
	
	else if (strcmp(argv[1], ">>")) {
		fd1 = open(argv[2], O_WRONLY | O_APPEND);
		if (fd1 == -1) {
			perror(argv[2]);
			exit(1);
		}		
		
		while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) 
		write (fd1, buf, n);
	}
*/
//	else {
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1) {
			perror(argv[1]);
			exit(2);
		}
		while ((n = read(fd1, buf, BUFFSIZE)) > 0) 
		write (STDOUT_FILENO, buf, n);
//	}
		
	close(fd1);
		
	exit(0);
}
