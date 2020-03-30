#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int 
main() {
	pid_t hello_pid, goodbye_pid ;

	printf("Begin %d\n", getpid()) ;

	hello_pid = fork() ;
	if (hello_pid == 0) { /* child */
		printf("Begin %d\n", getpid()) ;
		execl("./deferred", "Hello", "Hello", "3", (char *) 0x0) ;
	}
	else { /* parent */
		printf("Process %d spawned process %d\n", getpid(), hello_pid) ;

		goodbye_pid = fork() ;		
		if (goodbye_pid == 0) { /* child */
			printf("Begin %d\n", getpid()) ;
			execl("./deferred", "Goodbye", "Goodbye", "3", (char *) 0x0) ;
		}
		else { /* parent */
			pid_t term_pid ;
			int exit_code ;

			printf("Process %d spawned process %d\n", getpid(), goodbye_pid) ;

			term_pid = wait(&exit_code) ;
			printf("Process %d is finisehd with exit code %d\n", term_pid, exit_code) ;
			term_pid = wait(&exit_code) ;
			printf("Process %d is finisehd with exit code %d\n", term_pid, exit_code) ;

		}
	}
	printf("End %d\n", getpid()) ;
}
