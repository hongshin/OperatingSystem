#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <execinfo.h>

void * 
malloc (size_t size)
{
	static __thread int n_malloc = 0 ; //https://gcc.gnu.org/onlinedocs/gcc-3.3/gcc/Thread-Local.html
	n_malloc += 1 ;

	void *(*mallocp)(size_t size) ;
	char * error ;
	
	mallocp = dlsym(RTLD_NEXT, "malloc") ;
	if ((error = dlerror()) != 0x0) 
		exit(1) ;
	
	char * ptr = mallocp(size) ;

	if (n_malloc == 1) {
		int i ;
		void * arr[10] ;
		char ** stack ;

		fprintf(stderr, "malloc(%d)=%p\n", (int) size, ptr) ;

		size_t sz = backtrace(arr, 10) ;
		stack = backtrace_symbols(arr, sz) ;

		fprintf(stderr, "Stack trace\n") ;
		fprintf(stderr, "============\n") ;
		for (i = 0 ; i < sz ; i++)
			fprintf(stderr, "[%d] %s\n", i, stack[i]) ;
		fprintf(stderr, "============\n\n") ;
	}

	n_malloc -= 1 ;
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
	sprintf(buf, "free(%p)\n", ptr) ;
	fputs(buf, stderr) ;
	
	freep(ptr) ;
}
