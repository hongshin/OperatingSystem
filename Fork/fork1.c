#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int 
main() 
{
	pid_t child_pid ;

	printf("Begin \n") ;

	child_pid = fork() ;

	if (child_pid == 0) {
		//printf("Hello\n") ;
		execl("./hello", "hello", (char *) 0x0) ;
	}
	printf("End\n") ;
}
