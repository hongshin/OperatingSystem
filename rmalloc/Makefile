all: rmalloc.h rmalloc.c test1.c test2.c test3.c
	gcc -o test1 test1.c rmalloc.c
	gcc -o test2 test2.c rmalloc.c
	gcc -o test3 test3.c rmalloc.c 

clean:
	rm -rf test1 test2 test3 rmalloc.o
