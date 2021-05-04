typedef enum {
	BestFit, WorstFit, FirstFit
} rm_option ;


struct _rm_header {
	struct _rm_header * next ;
	size_t size ;
} ;

typedef struct _rm_header 	rm_header ;
typedef struct _rm_header *	rm_header_ptr ;


void * rmalloc (size_t s) ;

void rfree (void * p) ;

void * rrealloc (void * p, size_t s) ;

void rmshrink () ;

void rmconfig (rm_option opt) ;

void rmprint () ;
