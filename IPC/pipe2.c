#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int pipes[2] ;

void
child_proc()
{
	dup2(pipes[1], 1 /*standard output*/) ;
	execl("./hello", "hello", (char *) 0x0) ;
}

void
parent_proc()
{
	char buf[32] ;
	ssize_t s ;

	close(pipes[1]) ;

	while ((s = read(pipes[0], buf, 31)) > 0) {
		buf[s + 1] = 0x0 ;
		printf(">%s\n", buf) ;
	}
	exit(0) ;
}

int
main()
{
	pid_t child_pid ;
	int exit_code ;

	if (pipe(pipes) != 0) {
		perror("Error") ;
		exit(1) ;
	}

	if (child_pid = fork()) {
		parent_proc() ;
	}
	else {
		child_proc() ;
	}
	wait(&exit_code) ;

	exit(0) ;
}
