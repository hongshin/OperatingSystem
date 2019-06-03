#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char etext, edata, end ; 

int 
main()
{
	void * p1, *p2 ;

	printf("text segment up to: %p\n", (void *) &etext) ;
	printf("data segment up to: %p\n", (void *) &edata) ;
	printf("end segment up to:  %p\n", (void *) &end) ;
	printf("program break at :  %p\n", sbrk(0)) ;

	p1 = sbrk(0) ;
	sbrk(10) ;
	p2 = sbrk(0) ;
	printf("%p %p\n", p1, p2) ;
}
