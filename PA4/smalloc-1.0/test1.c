#include <stdio.h>
#include "smalloc.h"

int 
main()
{
	void *p1, *p2, *p3, *p4 ;

	print_sm_containers() ;

	p1 = smalloc(2000) ; 
	printf("smalloc(2000)\n") ; 
	print_sm_containers() ;

	p2 = smalloc(2500) ; 
	printf("smalloc(2500)\n") ; 
	print_sm_containers() ;

	sfree(p1) ; 
	printf("sfree(%p)\n", p1) ; 
	print_sm_containers() ;

	p3 = smalloc(1000) ; 
	printf("smalloc(1000)\n") ; 
	print_sm_containers() ;

	p4 = smalloc(1000) ; 
	printf("smalloc(1000)\n") ; 
	print_sm_containers() ;
}
