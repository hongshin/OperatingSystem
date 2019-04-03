#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int 
main() {
	pid_t curr_pid, hello_pid, goodbye_pid ;

	curr_pid = getpid() ;

	printf("Begin %d\n", curr_pid) ;

	hello_pid = fork() ;
	if (hello_pid == 0) { /* child */
		printf(" Begin %d\n", getpid()) ;

		execl("./printsleep", "printsleep", "Hello", (char *) 0x0) ;
	}
	else { /* parent */
		printf("Process %d spawned process %d\n", curr_pid, hello_pid) ;

		goodbye_pid = fork() ;		
		if (goodbye_pid == 0) { /* child */
			printf(" Begin %d\n", getpid()) ;
			execl("./printsleep", "printsleep", "Goodbye", "0", (char *) 0x0) ;
		}
		else { /* parent */
			pid_t term_pid ;
			int exit_code ;

			printf("Process %d spawned process %d\n", curr_pid, goodbye_pid) ;

			term_pid = wait(&exit_code) ;
			printf("Process %d is finisehd with exit code %d\n", term_pid, WEXITSTATUS(exit_code)) ;
			term_pid = wait(&exit_code) ;
			printf("Process %d is finisehd with exit code %d\n", term_pid, WEXITSTATUS(exit_code)) ;

		}
	}
	printf("End\n") ;
}
