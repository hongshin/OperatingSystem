#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int 
main ()
{
	int fd = open("channel", O_RDONLY | O_SYNC) ;

	while (1) {
		char s[128] ;
		int len ;
		if ((len = read(fd, s, 128)) == -1)
			break ;
		if (len > 0) 
			printf("%s\n", s) ;
	}
	close(fd) ;
	return 0 ;
}
