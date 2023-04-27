typedef enum {
	BestFit, FirstFit
} bm_option ;


struct _bm_header {
	unsigned int used : 1 ;
	unsigned int size : 4 ;
	struct _bm_header * next ;
} ;

typedef struct _bm_header 	bm_header ;
typedef struct _bm_header *	bm_header_ptr ;


void * bmalloc (size_t s) ;

void bfree (void * p) ;

void * brealloc (void * p, size_t s) ;

void bmconfig (bm_option opt) ;

void bmprint () ;
