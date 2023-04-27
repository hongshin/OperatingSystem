all: bmalloc.h bmalloc.c test1.c test2.c test3.c
	gcc -o test1 test1.c bmalloc.c
	gcc -o test2 test2.c bmalloc.c
	gcc -o test3 test3.c bmalloc.c 

clean:
	rm -rf test1 test2 test3 bmalloc.o
