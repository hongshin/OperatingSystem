#include <stdio.h>
#include "bmalloc.h"

int 
main ()
{
	void *p1, *p2, *p3, *p4 ;

	bmprint() ;

	p1 = bmalloc(2000) ; 
	printf("bmalloc(2000):%p\n", p1) ; 
	bmprint() ;

	p2 = bmalloc(2500) ; 
	printf("bmalloc(2500):%p\n", p2) ; 
	bmprint() ;

	bfree(p1) ; 
	printf("bfree(%p)\n", p1) ; 
	bmprint() ;

	p3 = bmalloc(1000) ; 
	printf("bmalloc(1000):%p\n", p3) ; 
	bmprint() ;

	p4 = bmalloc(1000) ; 
	printf("bmalloc(1000):%p\n", p4) ; 
	bmprint() ;
}
