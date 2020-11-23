EXECS = p1 p2 p3
LIBS = -lpthread

all:	$(EXECS)

p1:	p1-thr.c
	gcc -o p1 p1-thr.c $(LIBS)

p2:	p2-bad.c
	gcc -o p2 p2-bad.c $(LIBS)

p3:	p3-sem.c
	gcc -o p3 p3-sem.c $(LIBS)

clean:
	rm -f $(EXECS)

