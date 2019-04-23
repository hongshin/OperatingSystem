all : hello printsleep execl fork1 fork2 fork3

hello : hello.c
	gcc -o hello hello.c

printsleep : printsleep.c
	gcc -o printsleep printsleep.c

execl : hello execl.c
	gcc -o execl execl.c

fork1 : hello fork1.c
	gcc -o fork1 fork1.c

fork2 : printsleep fork2.c
	gcc -o fork2 fork2.c

fork3 : hello fork3.c
	gcc -o fork3 fork3.c

clean :
	rm -rf hello printsleep execl fork1 fork2


