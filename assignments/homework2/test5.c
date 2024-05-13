#include <stdio.h>
#include <stdint.h>
#include "smalloc.h"

int main ()
{
	void *p1, *p2, *p3, *p4, *p5 ; 

	smdump() ;

	p1 = smalloc(1000) ; 
	printf("smalloc(1000):%p\n", p1) ; 
	smdump() ;

	p2 = smalloc(1000) ; 
	printf("smalloc(1000):%p\n", p2) ; 
	smdump() ;

	p3 = smalloc(1000) ; 
	printf("smalloc(1000):%p\n", p3) ; 
	smdump() ;

	p4 = smalloc(3000) ; 
	printf("smalloc(3000):%p\n", p4) ; 
	smdump() ;

	srealloc(p2, 500) ;
	printf("srealloc(p2, 500):%p\n", p2) ;
	smdump() ;

	srealloc(p4, 1500) ;
	printf("srealloc(p4, 1500):%p\n", p4) ;
	smdump() ;

	sfree(p1) ; 
	printf("sfree(%p)\n", p1) ; 
	smdump() ;

	sfree(p3) ; 
	printf("sfree(%p)\n", p3) ; 
	smdump() ;

	smcoalesce();
	printf("smcoalesce()\n") ;
	smdump();

	p5 = smalloc_mode(2500, firstfit) ;
	printf("smalloc_mode(p5, firstfit):%p\n", p5) ;
	smdump() ;
	
}
