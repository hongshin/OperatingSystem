typedef enum {
	Busy, Unused
} sm_container_status ;

typedef struct _sm_container_t {
	sm_container_status status ;
	struct _sm_container_t * next ;
	/* struct _sm_container_t * next_unused ; */
	size_t dsize ;
	void * data ;
} sm_container_t ;

typedef sm_container_t * sm_container_ptr ;

void * smalloc(size_t size) ; 
void sfree(void * p) ;
void print_sm_containers() ;
/* void print_sm_uses() ; */
