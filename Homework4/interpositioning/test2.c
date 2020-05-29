#include <stdio.h>
#include <stdlib.h>

int main()
{
	int * p ;
	p = malloc(32) ; 
	free(p) ;
	return 0 ;
}
