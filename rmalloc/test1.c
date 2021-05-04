#include <stdio.h>
#include "rmalloc.h"

int 
main ()
{
	void *p1, *p2, *p3, *p4 ;

	rmprint() ;

	p1 = rmalloc(2000) ; 
	printf("rmalloc(2000):%p\n", p1) ; 
	rmprint() ;

	p2 = rmalloc(2500) ; 
	printf("rmalloc(2500):%p\n", p2) ; 
	rmprint() ;

	rfree(p1) ; 
	printf("rfree(%p)\n", p1) ; 
	rmprint() ;

	p3 = rmalloc(1000) ; 
	printf("rmalloc(1000):%p\n", p3) ; 
	rmprint() ;

	p4 = rmalloc(1000) ; 
	printf("rmalloc(1000):%p\n", p4) ; 
	rmprint() ;
}
