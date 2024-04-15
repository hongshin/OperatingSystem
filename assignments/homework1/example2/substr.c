#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substr (char * s, char * input, int start, int end) {

	int i = 0;
	char * c = input + start ;
	while ( c < input + end ) {
		if (*c != ' ') {
			s[i] = *c;
		}

		if (s[i] != '\0') {
			c++ ;
			i++ ;
		}
	}
	s[i] = '\0';
}

int main () {

	char input[128] ;

	int start = 0, end = 0;
	scanf("%[^\n]s", input);
	scanf("%d %d", &start, &end);

	char * s = (char *) malloc (sizeof(char) * (end - start + 1)) ;
	memset(s, 1, end - start + 1) ;
	substr(s, input, start, end);
	printf("%s\n", s);

	free(s);

	return EXIT_SUCCESS ;
}
