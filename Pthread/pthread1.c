#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>

void spin ()
{
	int i ;
	for (i = 0 ; i < 50000 ; i++) ;
}

void * print_message_function (void *ptr)
{
	char *message;
	message = strdup((char *) ptr) ;

	int i = 0 ;
	for (i = 0 ; i < 10 ; i++)  {
		printf("%s\n", message) ;
		//spin() ;
		sched_yield() ;
	}

	return (void *) message ;  
}

int
main()
{
	pthread_t thread1, thread2;

	char *message1 = "Thread 1";
	char *message2 = "Thread 2";

	pthread_create(&thread1, NULL, print_message_function, (void*) message1);
	pthread_create(&thread2, NULL, print_message_function, (void*) message2);

	char * r1, * r2 ;

	pthread_join(thread1, (void *) &r1);
	pthread_join(thread2, (void *) &r2); 

	printf("r1: %s\n", r1) ;
	printf("r2: %s\n", r2) ;

	exit(0);
}


