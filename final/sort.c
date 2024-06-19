#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

enum task_status { UNSORTED, SORTED, COMPLETE } ;

struct sorting_task {
	task_status status ;
	int n_a ;
	double * a ;
} ;

// You must use at least one conditional variable.

/* For your information: How to use Mutex and Conditional Variable

	pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER ;
 	pthread_mutex_lock(&m) ; 
 	pthread_mutex_unlock(&m) ;
 	pthread_cond_t cv = PTHREAD_COND_INITIALIZER ; 
 	pthread_cond_signal(&cv) ;
 	pthread_cond_wait(&cv, &m) ;
*/

void * 
sort_thread (void * ptr)
{
	// 1. Receive a sorting_task object via ptr.
	// 2. Sort the given array in ascending order, and then update the status as SORTED.
	// 3. Wait until the main thread updates the status as COMPLETE.
	// 4. Free the sorting_task object.

	
	/* For your reference: Sorting algorithm
	
	int i, j ;
	for (i = 0 ; i < N - 1 ; i++) {
		for (j = i + 1 ; j < N ; j++) {
			if (!(a[i] < a[j])) {
				double tmp ;
				tmp = a[i] ;
				a[i] = a[j] ;
				a[j] = tmp ;
			}
		}
	}
	*/

}

int main ()
{
	int i ;

	struct sorting_task * t = 
		(struct sorting_task *) malloc(sizeof(sorting_task)) ;

	t->status = UNSORTED ;
	t->n_a = 1000 ;
	t->a = (double *) calloc(1000, sizeof(double)) ;
	for (i = 0 ; i < t->n_a ; i++) {
		int num = rand() ;
		int den = rand() ;
		if (den != 0.0)			
			t->a[i] = ((double) num) / ((double) den) ;
		else
			t->a[i] = ((double) num) ;

	}

	pthread_t thread ;
	pthread_create(&tread, NULL, sort_thread, &t) ;

	// 1. Wait until the child thread to finish sorting and update the task status as SORTED.
	// 2. Print out the sorted numbers.
	// 3. Update the task status as COMPLETE

	return EXIT_SUCCESS ;
}
