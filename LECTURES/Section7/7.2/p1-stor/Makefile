p1:	main.o array.o
	gcc -o p1 main.o array.o

main.o:	main.c defs.h
	gcc -c main.c

array.o:	array.c defs.h
	gcc -c array.c

clean:
	rm -f *.o p1
