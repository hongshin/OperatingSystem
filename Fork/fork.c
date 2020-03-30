#include <stdio.h>
#include <unistd.h>

int
main () 
{
	printf("Begin\n") ;

	fork() ;

	printf("End\n") ;

	while (1) ;
}
