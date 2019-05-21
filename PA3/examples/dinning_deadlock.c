#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#define LEFT(i) (i)
#define RIGHT(i) ((i+1) % 5)

typedef enum {
	avail, 
	held 
} status_t ;

typedef struct {
	status_t status ;
	pthread_mutex_t mutex ;
} chopstick_t ;

chopstick_t chopstick[5] ;

void
chopstick_init(chopstick_t * c)
{
	c->status = avail ;
	pthread_mutex_init(&(c->mutex), 0x0) ;
}

void
thinking()
{
	usleep(rand() % 1000) ;
}

void
eating(int phid)
{
	printf("Philosopher %d eats.\n", phid) ;
	usleep(rand() % 1000) ;
}

void
pickup(int phid)
{
	int left = phid ;
	int right = (phid + 1) % 5 ;

	pthread_mutex_lock(&(chopstick[left].mutex)) ;
	pthread_mutex_lock(&(chopstick[right].mutex)) ;
}

void
putdown(int phid)
{
	int left = phid ;
	int right = (phid + 1) % 5 ;

	pthread_mutex_unlock(&(chopstick[right].mutex)) ;
	pthread_mutex_unlock(&(chopstick[left].mutex)) ;
}

void *
philosopher(void * arg)
{
	int phid = *((int *) arg) ;
	int i ;

	for (i = 0 ; i < 10 ; i++) {
		thinking() ;
		pickup(phid) ;
		eating(phid) ;
		putdown(phid) ;
	}
}

int
main () 
{
	int phids[5] = {0, 1, 2, 3, 4} ;
	pthread_t threads[5] ;
	int i ;

	srand(time(0x0)) ;

	for (i = 0 ; i < 5 ; i++) {
		pthread_create(&(threads[i]), 0x0, philosopher, &(phids[i])) ;
	}

	for (i = 0 ; i < 5 ; i++) {
		pthread_join(threads[i], 0x0) ;
	}
	exit(0) ;

}
