#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

void *print_message_function( void *ptr )
{
	char *message;
	message = (char *) ptr;

	int i = 0 ;
	for (i = 0 ; i < 10 ; i++)  {
		printf("%s\n", message) ;
		//sleep(1) ;
		sched_yield() ;
	}
}

int
main()
{
	pthread_t thread1, thread2;

	char *message1 = "Thread 1";
	char *message2 = "Thread 2";

	pthread_create( &thread1, NULL, print_message_function, (void*) message1);
	pthread_create( &thread2, NULL, print_message_function, (void*) message2);


	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL); 

	exit(0);
}


