#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char ** args)
{
	if (argc != 3)
		exit(1) ;

	printf("%s\n", args[1]) ;
	sleep(atoi(args[2])) ;
	return 0 ;
}
