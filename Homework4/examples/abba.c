#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void 
noise()
{
	usleep(rand() % 1000) ;
}

void *
thread(void *arg) 
{
		pthread_mutex_lock(&mutex);	 noise() ;
		pthread_mutex_lock(&mutex2); noise() ;
		pthread_mutex_unlock(&mutex2); noise() ;
		pthread_mutex_unlock(&mutex); noise() ;

		return NULL;
}

int 
main(int argc, char *argv[]) 
{
	pthread_t tid;
	srand(time(0x0)) ;

	pthread_create(&tid, NULL, thread, NULL);
		
	pthread_mutex_lock(&mutex2); noise() ; 
	pthread_mutex_lock(&mutex);	noise() ; 
	pthread_mutex_unlock(&mutex); noise() ;
	pthread_mutex_unlock(&mutex2); noise() ;

	pthread_join(tid, NULL);
	return 0;
}

