#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int 
main() {
	printf("Begin \n") ;
	execl("./hello", "hello", (char *) 0x0) ;
	printf("End\n") ;
}
