EXECS = p1 p2 p3 p4 p5
LIBS = -lpthread
OPTIONS = -Wall

all:	$(EXECS)

p1:	p1-basic.c
	gcc $(OPTIONS) -o p1 p1-basic.c $(LIBS)

p2:	p2-gen.c
	gcc $(OPTIONS) -o p2 p2-gen.c $(LIBS)

p3:	p3-bad-data.c
	gcc $(OPTIONS) -o p3 p3-bad-data.c $(LIBS)

p4:	p4-sem-bad.c
	gcc $(OPTIONS) -o p4 p4-sem-bad.c $(LIBS)

p5:	p5-sem-good.c
	gcc $(OPTIONS) -o p5 p5-sem-good.c $(LIBS)

clean:
	rm -f $(EXECS)

