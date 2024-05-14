#include <stdio.h>
#include <stdint.h>
#include "smalloc.h"

int main ()
{
	void *p1, *p2, *p3, *p4, *p5, *p6, *p7 ; 

	smdump() ;

	p1 = smalloc(2000) ; 
	printf("smalloc(2000):%p\n", p1) ; 
	smdump() ;

	p2 = smalloc(1000) ; 
	printf("smalloc(1000):%p\n", p2) ; 
	smdump() ;

	p3 = smalloc(3000) ; 
	printf("smalloc(3000):%p\n", p3) ; 
	smdump() ;

	p4 = smalloc(2000) ; 
	printf("smalloc(2000):%p\n", p4) ; 
	smdump() ;

	sfree(p1) ; 
	printf("sfree(%p)\n", p1) ; 
	smdump() ;

	sfree(p2) ; 
	printf("sfree(%p)\n", p2) ; 
	smdump() ;

	smcoalesce();
	printf("smcoalesce()\n") ;
	smdump();

	p5 = smalloc_mode(1500, worstfit) ;
	printf("smalloc_mode(1500, worstfit):%p\n", p5) ;
	smdump() ;

	p6 = smalloc_mode(2000, worstfit) ;
	printf("smalloc_mode(2000, worstfit):%p\n", p6) ;
	smdump() ;

	p7 = smalloc_mode(1500, worstfit) ;
	printf("smalloc_mode(1500, worstfit):%p\n", p7) ;
	smdump() ;
	
}
