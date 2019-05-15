#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct {
	pthread_mutex_t lock ;
	char ** elem ;
	int capacity ;
	int num ; 
	int front ;
	int rear ;
} bounded_buffer ;

bounded_buffer * buf = 0x0 ;

void 
bounded_buffer_init(bounded_buffer * buf, int capacity) {
	pthread_mutex_init(&(buf->lock), 0x0) ;
	buf->capacity = capacity ;
	buf->elem = (char **) calloc(sizeof(char *), capacity) ;
	buf->num = 0 ;
	buf->front = 0 ;
	buf->rear = 0 ;
}

void 
bounded_buffer_queue(bounded_buffer * buf, char * msg) 
{
	pthread_mutex_lock(&(buf->lock)) ;
	if (buf->num < buf->capacity) {
		buf->elem[buf->rear] = msg ;
		buf->rear = (buf->rear + 1) % buf->capacity ;
		buf->num += 1 ;
	}
	pthread_mutex_unlock(&(buf->lock)) ;
}

char * 
bounded_buffer_dequeue(bounded_buffer * buf) 
{
	char * r = 0x0 ;
	pthread_mutex_lock(&(buf->lock)) ;
	if (buf->num > 0) {
		r = buf->elem[buf->front] ;
		buf->front = (buf->front + 1) % buf->capacity ;
		buf->num -= 1 ;
	}
	pthread_mutex_unlock(&(buf->lock)) ;
	return r ;
}


void * 
producer(void * ptr) 
{
	char msg[128] ;
	pthread_t tid ;
	int i ;
	
	tid = pthread_self() ;
	for (i = 0 ; i < 10 ; i++) {
		snprintf(msg, 128, "(%ld,%d)", (unsigned long) tid, i) ;
		bounded_buffer_queue(buf, strdup(msg)) ;
	}
	return 0x0 ;
}

void * 
consumer(void * ptr) 
{
	pthread_t tid ;
	char * msg ; 
	int i ;

	tid = pthread_self() ;

	for (i = 0 ; i < 10 ; i++) {
		msg = bounded_buffer_dequeue(buf) ;
		if (msg != 0x0) {
			printf("[%ld] reads %s\n", (unsigned long) tid, msg) ;
			free(msg) ;
		}
	}
}

int 
main() 
{
	pthread_t prod[5] ;
	pthread_t cons[5] ;
	int i ;

	buf = malloc(sizeof(bounded_buffer)) ;
	bounded_buffer_init(buf, 3) ;

	for (i = 0 ; i < 5 ; i++) {
		pthread_create(&(prod[i]), 0x0 , producer, 0x0) ;
		pthread_create(&(cons[i]), 0x0, consumer, 0x0) ;
	}

	for (i = 0 ; i < 5 ; i++) {
		pthread_join(prod[i], 0x0) ;
		pthread_join(cons[i], 0x0) ;
	}
	exit(0) ;
}
