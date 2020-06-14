#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char etext, edata, end ; 

int 
main()
{
	void * p ;

	printf("text segment up to: %p\n", (void *) &etext) ;
	printf("data segment up to: %p\n", (void *) &edata) ;
	printf("end segment up to:  %p\n", (void *) &end) ;
	printf("program break at :  %p\n", sbrk(0)) ;

	sbrk(10) ;
	p = sbrk(0) ;
	printf("%p\n", p) ;
}
