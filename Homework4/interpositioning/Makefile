all:
	gcc -o test1 test1.c
	gcc -shared -fPIC -o myrand.so myrand.c -ldl
	gcc -o test2 test2.c
	gcc -shared -fPIC -o mymalloc.so mymalloc.c -ldl
	gcc -o test3 -g test3.c
	gcc -shared -fPIC -o mymalloc2.so mymalloc2.c -ldl
