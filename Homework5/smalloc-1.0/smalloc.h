typedef enum {
	Busy, Unused
} sm_container_status ;

struct _sm_container_t {
	sm_container_status status ;
	struct _sm_container_t * next ;
	struct _sm_container_t * prev ;
	/* struct _sm_container_t * next_unused ; */
	size_t dsize ;
	void * data ;
} ;
typedef struct _sm_container_t 		sm_container_t ;
typedef struct _sm_container_t * 	sm_container_ptr ;

void * smalloc(size_t size) ; 
void * srealloc(void * p, size_t newsize) ;
void sfree(void * p) ;
//void sshrink() ;

void print_sm_containers() ;
/* void print_mem_uses() ; */
