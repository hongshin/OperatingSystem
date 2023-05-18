#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

int m[17][17] ;
int min = -1 ;
int num_paths = 0 ;

pthread_mutex_t lock ; 

int path[17] ;
int used[17] ;
int length = 0 ;

typedef 
	struct _subtask {
		int path[17] ;
		int used[17] ;
		int length ;
	}
	subtask ;


pthread_mutex_t lock_n_threads ;
int n_threads = 0 ;
const int max_threads = 8 ;

int threads[8] ;

subtask * subtasks[8] ;
int head = 0 ;
int tail = 0 ;
int done = 0 ;

sem_t unused ;
sem_t inused ;
pthread_mutex_t subtasks_lock ;

void put_subtask (subtask * s) 
{
	sem_wait(&unused) ;
	pthread_mutex_lock(&subtasks_lock) ;
		subtasks[tail] = s ;
		tail = (tail + 1) % 8 ;
	pthread_mutex_unlock(&subtasks_lock) ;
	sem_post(&inused) ;
}

subtask * get_subtask () 
{
	subtask * s ;
	sem_wait(&inused) ;
	pthread_mutex_lock(&subtasks_lock) ;
		s = subtasks[head] ;
		head = (head + 1) % 8 ;
	pthread_mutex_unlock(&subtasks_lock) ;
	sem_post(&unused) ;

	return s ;
}

void _travel (int idx, int * path, int * used, int * length, int * thread_local_min) {
	int i ;

	if (idx == 17) {
		*length += m[path[16]][path[0]] ;

		if (*thread_local_min == -1 || *length < *thread_local_min) {	
			pthread_mutex_lock(&lock) ; 
				if (min == -1 || *length < min) {
					min = *length ;
					printf("%d (", *length) ;
					for (i = 0 ; i < 17 ; i++) 
						printf("%d ", path[i]) ;
					printf("%d)\n", path[0]) ;	
				}

				*thread_local_min = min ;
			pthread_mutex_unlock(&lock) ;
		}
		*length -= m[path[16]][path[0]] ;

	}
	else {
		for (i = 0 ; i < 17 ; i++) {
			if (used[i] == 0) {
				path[idx] = i ;
				used[i] = 1 ;
				*length += m[path[idx-1]][i] ;
				_travel(idx+1, path, used, length, thread_local_min) ;
				*length -= m[path[idx-1]][i] ;
				used[i] = 0 ;
			}
		}
	}
}

void * travel (void * arg) {

	subtask * s = (subtask *) arg ;

	int path[17] ;
	int used[17] ;
	int length ;
	int thread_local_min = -1; 

	memcpy(path, s->path, sizeof(int) * 17) ;
	memcpy(used, s->used, sizeof(int) * 17) ;
	length = s->length ;
	free(arg) ;

	_travel(6, path, used, &length, &thread_local_min) ;

	pthread_mutex_lock(&lock_n_threads) ;
	n_threads-- ;

	pthread_t t = pthread_self() ;

	for (int i = 0 ; i < max_threads ; i++) {
		if (threads[i] == t) 
			threads[i] = 0 ;
	}

	pthread_mutex_unlock(&lock_n_threads) ;

	return NULL ;
}

void * worker (void * arg)
{
	subtask * s ;

	while ((s = get_subtask())) {
		travel(s) ;
	}
	return NULL ;
}

void main_travel (int idx)
{
	int i ;


	if (idx < 6) {
		for (i = 0 ; i < 17 ; i++) {
			if (used[i] == 0) {
				path[idx] = i ;
				used[i] = 1 ;
				length += m[path[idx-1]][i] ;

				main_travel(idx+1) ;

				length -= m[path[idx-1]][i] ;
				used[i] = 0 ;
			}
		}
	}
	else /* idx == 6 */ {
		pthread_t thread ;

		subtask * s = (subtask *) malloc(sizeof(subtask)) ;
		memcpy(s->path, path, sizeof(int) * 17) ;
		memcpy(s->used, used, sizeof(int) * 17) ;
		s->length = length ;

		put_subtask(s) ;
	}
}

int main () {
	int i, j, t ;

	pthread_t threads[17] ;

	pthread_mutex_init(&lock, NULL) ;
	pthread_mutex_init(&lock_n_threads, NULL) ;
	pthread_mutex_init(&subtasks_lock, NULL) ;

	sem_init(&inused, 0, 0) ;
	sem_init(&unused, 0, 8) ;

	FILE * fp = fopen("gr17.tsp", "r") ;

	for (i = 0 ; i < 17 ; i++) {
		for (j = 0 ; j < 17 ; j++) {
			fscanf(fp, "%d", &t) ;
			m[i][j] = t ;
		}
	}
	fclose(fp) ;


	for (i = 0 ; i < max_threads ; i++) {
		pthread_create(&(threads[i]), NULL, worker, NULL) ;
	}

	main_travel(0) ;

	for (i = 0 ; i < max_threads ; i++) 
		put_subtask(NULL) ;

	pthread_mutex_lock(&lock_n_threads) ;
		pthread_join(threads[i], NULL) ;
	pthread_mutex_unlock(&lock_n_threads) ;
}
