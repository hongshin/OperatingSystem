#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int 
main() 
{
	pid_t child_pid ;


	child_pid = fork() ;
	if (child_pid == 0) {
		char * args[] = {"hello", 0x0} ;

		int fd = open("hello.out", O_WRONLY | O_CREAT, 0644) ;
		dup2(fd, 1) ;
		close(fd) ;

		execl("./hello", "hello", (char *) 0x0) ;
	}

	wait(0x0) ;
}
