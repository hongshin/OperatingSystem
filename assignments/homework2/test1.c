#include <stdio.h>
#include <stdint.h>
#include "smalloc.h"

int main ()
{
	void *p1, *p2, *p3, *p4 ;

	smdump() ;

	p1 = smalloc(2000) ; 
	printf("smalloc(2000):%p\n", p1) ; 
	smdump() ;

	p2 = smalloc(2500) ; 
	printf("smalloc(2500):%p\n", p2) ; 
	smdump() ;

	sfree(p1) ; 
	printf("sfree(%p)\n", p1) ; 
	smdump() ;

	p3 = smalloc(1000) ; 
	printf("smalloc(1000):%p\n", p3) ; 
	smdump() ;

	p4 = smalloc(1000) ; 
	printf("smalloc(1000):%p\n", p4) ; 
	smdump() ;
}
