#include <stdio.h>
#include <stdint.h>
#include "smalloc.h"

int main ()
{
	void *p1, *p2, *p3, *p4, *p5, *p6 ;

	smdump() ;

	p1 = smalloc(3000) ; 
	printf("smalloc(3000):%p\n", p1) ; 
	smdump() ;

	p2 = smalloc(3000) ; 
	printf("smalloc(3000):%p\n", p2) ; 
	smdump() ;

	p3 = smalloc(2000) ; 
	printf("smalloc(2000):%p\n", p3) ; 
	smdump() ;

	p4 = smalloc(2000) ; 
	printf("smalloc(2000):%p\n", p4) ; 
	smdump() ;

	p5 = smalloc(3500) ; 
	printf("smalloc(3500):%p\n", p5) ; 
	smdump() ;

	sfree(p3) ; 
	printf("sfree(%p)\n", p3) ; 
	smdump() ;

	sfree(p4) ; 
	printf("sfree(%p)\n", p4) ; 
	smdump() ;

	smcoalesce();
	printf("smcoalesce()\n") ;
	smdump();

	srealloc(p1, 4000) ;
	printf("srealloc(p1, 4000):%p\n", p1) ;
	smdump() ;

	srealloc(p2, 2500) ;
	printf("srealloc(p2, 2500):%p\n", p2) ;
	smdump() ;

	p6 = smalloc_mode(500, bestfit) ;
	printf("smalloc_mode(p6, bestfit):%p\n", p6) ;
	smdump() ;
	
}
