#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <execinfo.h>


void * 
malloc (size_t size)
{
	void * (*mallocp)(size_t size) ; 
	char * error ;
	
	mallocp = dlsym(RTLD_NEXT, "malloc") ;
	if ((error = dlerror()) != 0x0) 
		exit(1) ;

	char * ptr = mallocp(size) ;

	//printf("malloc(%d)=%p\n", (int) size, ptr) ;
	char buf[50] ;
	snprintf(buf, 50, "malloc(%d)=%p\n", (int) size, ptr) ;
	fputs(buf, stderr) ;

	return ptr ; 	
}

void 
free (void * ptr)
{
	
	void (*freep)(void *) = NULL ;
	char * error ;

	if (ptr == 0x0)
		return ;
	
	freep = dlsym(RTLD_NEXT, "free") ;
	if ((error = dlerror()) != 0x0) 
		exit(1) ;

	char buf[50] ;
	snprintf(buf, 50, "free(%p)\n", ptr) ;
	fputs(buf, stderr) ;
	
	freep(ptr) ;
}
