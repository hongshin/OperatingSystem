all:
	gcc -c syscall.s
	gcc -c -nostdlib write.c
	gcc -o write write.o syscall.o
	gcc -o write_asm write_asm.c

clean:
	rm -rf syscall.o write.o a.out
