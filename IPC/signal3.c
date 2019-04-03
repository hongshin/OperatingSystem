#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void
handler(int sig)
{
	printf("Ring\n") ;
}

int
main()
{
	struct itimerval t ;

	signal(SIGALRM, handler) ;

	t.it_value.tv_sec = 1 ;
	t.it_value.tv_usec = 100000 ; // 1.1 sec
	t.it_interval = t.it_value ;

	setitimer(ITIMER_REAL, &t, 0x0) ;

	while (1) ;
}
