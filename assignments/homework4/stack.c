#include <stdlib.h>
#include "stack.h"

struct stack_t * 
create_stack (int capacity) 
{
	struct stack_t * stack = (struct stack_t *) malloc(sizeof(struct stack_t)) ;
	stack->capacity = capacity ;
	stack->size = 0 ;
	stack->buffer = (int *) calloc(capacity, sizeof(int)) ;
	return stack ; 
}

void
delete_stack (struct stack_t * stack) 
{
	free(stack->buffer) ;
	free(stack) ;
}

int 
push (struct stack_t * stack, int elem)
{
	if (is_full(stack))
		return 0 ;
	
	stack->buffer[stack->size] = elem ;
	stack->size += 1 ;
	return 1 ;
}

int
pop (struct stack_t * stack, int * elem)
{
	if (is_empty(stack)) 
		return 0 ;
	
	*elem = stack->buffer[stack->size - 1] ;
	stack->size -= 1 ;
	return 1;
}

int 
top (struct stack_t * stack, int * elem)
{
	if (is_empty(stack)) 
		return 0 ;
	
	*elem = stack->buffer[stack->size - 1] ;
	return 1;
}

int 
is_empty (struct stack_t * stack) 
{
	return (stack->size == 0) ;
}

int 
is_full (struct stack_t * stack) 
{
	return (stack->size == stack->capacity) ;
}

int
get_size (struct stack_t * stack) 
{
	return stack->size ;
}

int
get_elem (struct stack_t * stack, int index, int * elem)
{
	if (index < 0)
		return 0 ;
	if (stack->size <= index)
		return 0 ;

	*elem = stack->buffer[index] ;
	return 1 ;
}
