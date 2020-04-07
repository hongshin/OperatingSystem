#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/wait.h>

void
sigchld_handler(int sig)
{
	pid_t child ;
	int exitcode ;
	child = wait(&exitcode) ;

	printf("> child process %d is terminated with exitcode %d\n", 
			child, WEXITSTATUS(exitcode)) ;
}

int
main ()
{
	signal(SIGCHLD, sigchld_handler) ;

	pid_t child ;
	if (child = fork()) {
		sleep(3) ;
		kill(child, SIGTERM) ;
		while (1) ;
	}
	else {
		while (1) ;
	}

}
