#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUGGY_STRING "][]*[]["

int
main (int argc, char *argv[]) {

    int alloc_size = 256;
    char *buffer = (char*)malloc(sizeof(char)*alloc_size);
    memset((void*)buffer, 0, sizeof(char)*alloc_size);


    int size = 0;
    while (! feof(stdin)) {

        char c;
	fread(&c, sizeof(char), 1, stdin);

	if (c == '\n')
	    break;

	if (size >= alloc_size) {
	    alloc_size *= 2;
	    buffer = (char*)realloc(buffer, sizeof(char)*alloc_size);
            memset((void*)buffer+size, 0, sizeof(char)*alloc_size-size);
	}

	buffer[size] = c;
        size++;
    }
    buffer[size] = 0x0;


    int bug_str_len = strlen(BUGGY_STRING);
    for (int i = 0; i < size - bug_str_len + 1; i++) {
        if (! strncmp(buffer, BUGGY_STRING, bug_str_len))
	    i--;
    }
    

    int balance = 0;
    while (size > 0) {

        if (buffer[size-1] == ']') {
	    balance++;

	}
	else if (buffer[size-1] == '[') {
	    balance--;

	}

	if (balance < 0)
	    break;

	size--;
    }

    if (balance != 0) {

	fprintf(stdout, "Unbalanced: %s \n", buffer);
        free(buffer);
        return 0;
    }

    printf("Balanced: %s \n", buffer);
    free(buffer);
    return 0;
}
