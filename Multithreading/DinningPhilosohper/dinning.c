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
	pthread_cond_t cv ;
} chopstick_t ;

chopstick_t chopstick[5] ;

pthread_mutex_t lock ;

void
chopstick_init(chopstick_t * c)
{
	c->status = avail ;
	pthread_cond_init(&(c->cv), 0x0) ;
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

	pthread_mutex_lock(&lock) ;
		while ( chopstick[left].status == held || chopstick[right].status == held ) {
			if (chopstick[left].status == held)
				pthread_cond_wait(&(chopstick[left].cv), &lock) ;
			else 
				pthread_cond_wait(&(chopstick[right].cv), &lock) ;
		}

		chopstick[left].status = held ;
		chopstick[right].status = held ;
	pthread_mutex_unlock(&lock) ;
}

void
putdown(int phid)
{
	int left = phid ;
	int right = (phid + 1) % 5 ;

	pthread_mutex_lock(&lock) ;
		chopstick[left].status = avail ;
		chopstick[right].status = avail ;

		pthread_cond_signal(&(chopstick[left].cv)) ;
		pthread_cond_signal(&(chopstick[right].cv)) ;
	pthread_mutex_unlock(&lock) ;
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
	int phids[5] = { 0, 1, 2, 3, 4 } ;
	pthread_t threads[5] ;
	int i ;

	srand(time(0x0)) ;

	pthread_mutex_init(&lock, 0x0) ;

	for (i = 0 ; i < 5 ; i++) 
		pthread_create(&(threads[i]), 0x0, philosopher, &(phids[i])) ;

	for (i = 0 ; i < 5 ; i++) 
		pthread_join(threads[i], 0x0) ;

	exit(0) ;
}
