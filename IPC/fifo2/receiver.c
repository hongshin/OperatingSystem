#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>


int
read_bytes (int fd, void * a, int len)
{
	char * s = (char *) a ;
	
	int i ;
	for (i = 0 ; i < len ; ) {
		int b ;
		b = read(fd, s + i, len - i) ;
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

	int fd = open("channel", O_RDONLY | O_SYNC) ;

	while (1) {
		char s[128] ;

		size_t len, bs ;

		flock(fd, LOCK_EX) ;

		printf("--\n") ;
		if (read_bytes(fd, &len, sizeof(len)) != sizeof(len)) {
			flock(fd, LOCK_UN) ;
			break ;
		}

		bs = read_bytes(fd, s, len) ;

		flock(fd, LOCK_UN) ;

		for (int i = 0 ; i < bs ; i++) {
			putchar(s[i]) ;
		}
		printf("\n") ;

		if (bs != len)
			break ;
	}


	close(fd) ;

	return 0 ;
}
