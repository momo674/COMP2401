OBJ = main.o connect.o escape.o flyer.o hero.o view.o spectator.o
EXE = a5
CC = gcc -Wall 

$(EXE):	$(OBJ)
	$(CC) -o $(EXE) $(OBJ)

main.o:	main.c defs.h
	$(CC) -c main.c

connect.o:	connect.c defs.h
	$(CC) -c connect.c

escape.o:	escape.c defs.h flyer.c hero.c view.c
	$(CC) -c escape.c defs.h flyer.c hero.c view.c

flyer.o: 	flyer.c hero.c escape.c view.c defs.h
	$(CC) -c escape.c defs.h flyer.c hero.c view.c

hero.o: 	hero.c flyer.c escape.c view.c defs.h
	$(CC) -c escape.c defs.h flyer.c hero.c view.c

view.o: 	hero.c flyer.c escape.c view.c defs.h
	$(CC) -c escape.c defs.h flyer.c hero.c view.c

spectator.o: hero.c flyer.c escape.c view.c defs.h connect.c main.c spectator.c
	$(CC) -c hero.c flyer.c escape.c view.c defs.h connect.c main.c	spectator.c

clean:
	rm -f $(EXE) $(OBJ)

