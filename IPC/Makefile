all: pipe server client signals

signals: signal1.c signal2.c signal3.c signal4.c
	gcc -o signal1 signal1.c
	gcc -o signal2 signal2.c
	gcc -o signal3 signal3.c
	gcc -o signal4 signal4.c

pipe: pipe1.c pipe2.c
	gcc -o pipe1 pipe1.c
	gcc -o pipe2 pipe2.c

server: server.c
	gcc -g -o server server.c

client: client.c
	gcc -o client client.c

clean:
	rm -rf pipe1 pipe2 client server signal1 signal2 signal3 signal4
