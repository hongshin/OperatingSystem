all:
	gcc -c syscall.s
	gcc -c -nostdlib write.c
	gcc -o a.out write.o syscall.o

clean:
	rm -rf syscall.o write.o a.out
