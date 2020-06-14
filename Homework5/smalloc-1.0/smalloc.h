typedef enum {
	Busy, Unused
} sm_container_status ;

struct _sm_container_t {
	sm_container_status status ;
	struct _sm_container_t * next ;
	struct _sm_container_t * prev ;
	size_t dsize ;
} ;
typedef struct _sm_container_t 		sm_container_t ;
typedef struct _sm_container_t * 	sm_container_ptr ;

void * smalloc (size_t size) ; 
//void * srealloc (void * p, size_t newsize) ;
void sfree (void * p) ;
//void sshrink() ;

void print_sm_containers () ;
// void print_mem_uses() ;
