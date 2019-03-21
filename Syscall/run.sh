gcc -c syscall.S
gcc -c -nostdlib write.c
gcc -o a.out write.o syscall.o
