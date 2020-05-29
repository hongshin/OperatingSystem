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
	if (mkfifo("channel", 0666)) {
		if (errno != EEXIST) {
			perror("fail to open fifo: ") ;
			exit(1) ;
		}
	}

	int fd = open("channel", O_WRONLY | O_SYNC) ;

	while (1) {
		char s[128] ;
		char newline ;

		int i = 0 ;
		while (i < 128 && ((s[i] = getchar()) != EOF && s[i++] != '\n')) ;
		s[i - 1] = 0x0 ;
		
		if (s[0] == 0x0) 
			break ;

		for (int i = 0 ; i < 128 ; ) {
			i += write(fd, s + i, 128) ;
		} 
	}
	close(fd) ;
	return 0 ;
}
