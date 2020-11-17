EXECS = p1 p2 p3 p4 p5 p6

all:	$(EXECS)

p1:	p1-sh.c
	gcc -o p1 p1-sh.c

p2:	p2-fork.c
	gcc -o p2 p2-fork.c

p3:	p3-fbomb.c
	gcc -o p3 p3-fbomb.c

p4:	p4-morph.c
	gcc -o p4 p4-morph.c

p5:	p5-wait.c
	gcc -o p5 p5-wait.c

p6:	p6-cmd.c
	gcc -o p6 p6-cmd.c

clean:
	rm -f $(EXECS)

