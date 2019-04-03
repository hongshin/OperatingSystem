all: pipe server client signals

signals: signal1.c signal2.c signal3.c
	gcc -o signal1 signal1.c
	gcc -o signal2 signal2.c
	gcc -o signal3 signal3.c


pipe: pipe.c
	gcc -o pipe pipe.c

server: server.c
	gcc -g -o server server.c

client: client.c
	gcc -o client client.c

clean:
	rm -rf pipe client server signal1 signal2 signal3
