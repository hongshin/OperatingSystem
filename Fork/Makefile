all : hello deferred exec fork1 fork2 fork3

hello : hello.c
	gcc -o hello hello.c

deferred : deferred.c
	gcc -o deferred deferred.c

exec : hello exec.c
	gcc -o exec exec.c

fork0: fork0.c
	gcc -o fork0 fork0.c

fork1 : hello fork1.c
	gcc -o fork1 fork1.c

fork2 : deferred fork2.c
	gcc -o fork2 fork2.c

fork3 : hello fork3.c
	gcc -o fork3 fork3.c

clean :
	rm -rf hello deferred exec fork0 fork1 fork2 fork3
