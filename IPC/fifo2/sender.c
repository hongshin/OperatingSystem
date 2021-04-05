#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int 
write_bytes (int fd, void * a, int len)
{
	char * s = (char *) a ;

	int i = 0 ; 
	while (i < len) {
		int b ;
		b = write(fd, s + i, len - i) ;
		if (b == 0)
			break ;
		i += b ;
	}
	return i ;	
}


int 
main ()
{
	if (mkfifo("channel", 0666)) {
		if (errno != EEXIST) {
			perror("fail to open fifo: ") ;
			exit(1) ;
		}
	}

	int fd = open("channel", O_WRONLY | O_SYNC) ;
	printf("--") ;

	while (1) {
		char s[128] ;
		char newline ;

		size_t len = 0 ;
		while (len < 128) {
			char c ;
			c = getchar() ; 
			if ((c == EOF || c == '\n') && (len > 0))
				break ; 
			s[len++] = c ;
		}		

		if (write_bytes(fd, &len, sizeof(len)) != sizeof(len))
			break ;

		if (write_bytes(fd, s, len) != len) 
			break ;
	}
	close(fd) ;
	return 0 ;
}
