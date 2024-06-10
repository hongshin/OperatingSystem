struct stack_t {
	int * buffer ;
	int capacity ;
	int size ;
} ;

struct stack_t * 
create_stack (int capacity) ;

void
delete_stack (struct stack_t * stack) ;

int 
push (struct stack_t * stack, int elem) ;

int
pop (struct stack_t * stack, int * elem) ;

int
top (struct stack_t * stack, int * elem) ;

int 
is_empty (struct stack_t * stack) ;

int 
is_full (struct stack_t * stack) ;

int
get_size (struct stack_t * stack) ;

int 
get_elem (struct stack_t * stack, int index, int * elem) ;
