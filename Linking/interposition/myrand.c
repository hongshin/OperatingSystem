#define _GNU_SOURCE

static int count = 0 ;

int rand()
{
	return count++ ; 
}
