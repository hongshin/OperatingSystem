#include <stdio.h>
#include <stdlib.h>

int f() {
	int * p = malloc(32) ;
}

int main()
{
	printf("Hello\n") ;

	int * p = malloc(32) ;
	f() ;
	free(p) ;
	return 0 ;
}
