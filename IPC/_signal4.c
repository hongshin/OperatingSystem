#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/wait.h>

void
handler (int sig)
{
	printf("> signal %d is received.\n", sig) ;
}

void
sigchld_handler(int sig)
{
	pid_t child ;
	int exitcode ;
	child = wait(&exitcode) ;

	printf("> child process %d is terminated with exitcode %d\n", child, WEXITSTATUS(exitcode)) ;
}

int
main ()
{
	pid_t child ;

	void (* ret)(int) ;

	ret = signal(SIGKILL, handler) ;
	printf("%d\n", ret == SIG_ERR) ;

	ret = signal(SIGCHLD, sigchld_handler) ;
	printf("%d\n", ret == SIG_ERR) ;

	if (child = fork()) {
		sleep(3) ;
		kill(child, SIGKILL) ;
		while (1) ;
	}
	else {
		while (1) ;
	}

}
