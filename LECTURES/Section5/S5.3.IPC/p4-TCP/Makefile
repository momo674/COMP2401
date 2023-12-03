DEBUG= 
EXECS= server client

all:	$(EXECS)

server:	server.c
	gcc -Wall $(DEBUG) -o server server.c

client:	client.c
	gcc -Wall $(DEBUG) -o client client.c

clean:
	rm -f client server
