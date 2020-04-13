#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

char * message ;

void *print_message_function( void *ptr )
{
	char * name = (char *) ptr ;

	usleep((unsigned int) rand() % 1000) ;

	printf("%s: %s \n", name, message);
	message = strdup("Goodbye") ;
}

int
main()
{
	pthread_t thread1, thread2;

	struct timeval tv ; 
	gettimeofday(&tv, 0x0) ;
	srand(1000000 * tv.tv_sec + tv.tv_usec) ;

	message = strdup("Hello") ;

	pthread_create(&thread1, NULL, print_message_function, "Thread 1");
	pthread_create(&thread2, NULL, print_message_function, "Thread 2");

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL); 

	exit(0);
}


