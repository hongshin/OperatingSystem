#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

char shared[128] ;
pthread_rwlock_t l ;

void *
reader (void * arg)
{
	unsigned long tid ;
	int i ;

	tid = pthread_self() ;

	for (i = 0 ; i < 10 ; i++) {
		usleep(rand() % 1000) ;

		pthread_rwlock_rdlock(&l) ;
			printf("%ld reads \"%s\"\n", tid, shared) ;
		pthread_rwlock_unlock(&l) ;
		usleep(rand() % 1000) ;
	}
	return 0x0 ;
}

void *
writer (void * arg)
{
	unsigned long tid ;
	int i ;

	tid = pthread_self() ;

	for (i = 0 ; i < 10 ; i++) {
		usleep(rand() % 1000) ;
		pthread_rwlock_wrlock(&l) ;
			snprintf(shared, 128, "(%ld, %d)", tid, i) ;
		pthread_rwlock_unlock(&l) ;
		usleep(rand() % 1000) ;
	}
	return 0x0 ;
}


int
main () 
{
	pthread_t readers[5] ;
	pthread_t writers[5] ;
	int i ;

	srand(time(0x0)) ;

	pthread_rwlock_init(&l, 0x0) ;

	for (i = 0 ; i < 5 ; i++) {
		pthread_create(&(readers[i]), 0x0, reader, 0x0) ;
		pthread_create(&(writers[i]), 0x0, writer, 0x0) ;
	}

	for (i = 0 ; i < 5 ; i++) {
		pthread_join(readers[i], 0x0) ;
		pthread_join(writers[i], 0x0) ;
	}
	exit(0) ;

}
