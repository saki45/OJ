allExec = arithProg bBoard triplet

all:	$(allExec)

arithProg: arithProg.o
	g++ -o arithProg arithProg.o
bBoard: bBoard.o
	gcc -o bBoard bBoard.o
triplet: triplet.o
	g++ -o triplet triplet.o

clean:
	rm $(allExec)
	rm *.o
