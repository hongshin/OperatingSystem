#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
	pthread_mutex_t mutex ;

	pthread_cond_t writers_cv ; 
	pthread_cond_t readers_cv ; 

 	int to_read ;
	int to_write ;
	int reading ;
	int writing ;
} rwlock_t ;

char shared[128] = { 0x0 } ;
rwlock_t * l ;

void
rwlock_init(rwlock_t * l)
{
	l->to_read = 0 ;
	l->to_write = 0 ;
	l->reading = 0 ;
	l->writing = 0 ;
	pthread_mutex_init(&(l->mutex), 0x0) ;
	pthread_cond_init(&(l->readers_cv), 0x0) ;
	pthread_cond_init(&(l->writers_cv), 0x0) ;
}

void 
reader_lock(rwlock_t * l) 
{
	pthread_mutex_lock(&(l->mutex)) ;
		l->to_read += 1 ;
		while (l->to_write > 0 || l->writing > 0) 
			pthread_cond_wait(&(l->readers_cv), &(l->mutex)) ;

		l->to_read -= 1 ;
		l->reading += 1 ;
	pthread_mutex_unlock(&(l->mutex)) ;
}

void
reader_unlock(rwlock_t * l)
{
	pthread_mutex_lock(&(l->mutex)) ;
		l->reading -= 1 ;

		if (l->to_write > 0 && l->reading == 0) 
			pthread_cond_signal(&(l->writers_cv)) ;
	pthread_mutex_unlock(&(l->mutex)) ;
}

void 
writer_lock(rwlock_t * l) 
{
	pthread_mutex_lock(&(l->mutex)) ;
		l->to_write += 1 ;
		while (l->reading > 0 || l->writing > 0)
			pthread_cond_wait(&(l->writers_cv), &(l->mutex)) ;

		l->to_write -= 1 ;
		l->writing += 1 ;
	pthread_mutex_unlock(&(l->mutex)) ;
}

void
writer_unlock(rwlock_t * l)
{
	pthread_mutex_lock(&(l->mutex)) ;
		l->writing -= 1 ;

		if (l->to_write > 0)
			pthread_cond_signal(&(l->writers_cv)) ;
		else 
			pthread_cond_broadcast(&(l->readers_cv)) ;
	pthread_mutex_unlock(&(l->mutex)) ;
}

void *
reader (void * arg)
{
	unsigned long tid ;
	int i ;

	tid = pthread_self() ;

	for (i = 0 ; i < 10 ; i++) {
		usleep(rand() % 1000) ;
		reader_lock(l) ;
			printf("%ld reads \"%s\"\n", tid, shared) ;
		reader_unlock(l) ;
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
		writer_lock(l) ;
			snprintf(shared, 128, "(%ld, %d)", tid, i) ;
		writer_unlock(l) ;
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

	l = (rwlock_t *) malloc(sizeof(rwlock_t)) ;
	rwlock_init(l) ;

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
