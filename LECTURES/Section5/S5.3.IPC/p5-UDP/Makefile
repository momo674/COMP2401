DEBUG= 
EXECS= server client

all:	$(EXECS)

server:	server.c
	gcc $(DEBUG) -o server server.c

client:	client.c
	gcc $(DEBUG) -o client client.c

clean:
	rm -f client server
