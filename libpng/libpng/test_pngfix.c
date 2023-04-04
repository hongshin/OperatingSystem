#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>

int main (int argc, char ** argv)
{
	char buf[BUFSIZ] ;

	char * dirpath ;

	dirpath = dirname(argv[0]) ;

	FILE * ftest = fopen(strcat(strdup(dirpath), "/testdata"), "w") ;
	if (ftest == 0x0) 
		exit(1) ;
	while (!feof(stdin)) {
		size_t b ;

		b = fread(buf, 1, sizeof(buf), stdin) ;
		fwrite(buf, 1, b, ftest) ;
	}
	fclose(ftest) ;

	execl(strcat(strdup(dirpath), "/pngfix"), "pngfix", strcat(strdup(dirpath), "/testdata"), (char *)0x0) ;

	return 0 ;
}
