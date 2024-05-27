#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define n_data 40000000

double data[n_data] ;


void merge_lists (double * a1, int n_a1, double * a2, int n_a2)
{
	double * a_m = (double *) calloc(n_a1 + n_a2, sizeof(double)) ;
	int i = 0 ;

	int top_a1 = 0 ; 
	int top_a2 = 0 ; 

	for (i = 0 ; i < n_a1 + n_a2 ; i++) {
		if (top_a2 >= n_a2) {
			a_m[i] = a1[top_a1] ;
			top_a1++ ;
		}
		else if (top_a1 >= n_a1) {
			a_m[i] = a2[top_a2] ;
			top_a2++ ;
		}
		else if (a1[top_a1] < a2[top_a2]) {
			a_m[i] = a1[top_a1] ;
			top_a1++ ;
		}
		else {
			a_m[i] = a2[top_a2] ;
			top_a2++ ;
		}
	}
	memcpy(a1, a_m, (n_a1 + n_a2) * sizeof(double)) ;
}


void merge_sort (double * a, int n_a)
{
	if (n_a < 2)
		return ;

	double * a1 ;
	int n_a1 ;
	double * a2 ;
	int n_a2 ;

	a1 = a ;
	n_a1 = n_a / 2 ;

	a2 = a + n_a1 ;
	n_a2 = n_a - n_a1 ;

	merge_sort(a1, n_a1) ;
	merge_sort(a2, n_a2) ;

	merge_lists(a1, n_a1, a2, n_a2) ;
}

int main ()
{
	struct timeval ts ;
	gettimeofday(&ts, NULL) ;
	srand(ts.tv_usec * ts.tv_sec) ;

	int i ;
	for (i = 0 ; i < n_data ; i++) {
		int num = rand() ;
		int den = rand() ;
		if (den != 0.0)			
			data[i] = ((double) num) / ((double) den) ;
		else
			data[i] = ((double) num) ;

	}

	merge_sort(data, n_data) ;
	
	//for (int i = 0 ; i < n_data ; i++) {
	//		printf("%lf ", data[i]) ;
	//}
	
	return EXIT_SUCCESS ;
}
