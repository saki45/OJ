allExec = arithProg bBoard

all:	$(allExec)

arithProg: arithProg.o
	g++ -o arithProg arithProg.o
bBoard: bBoard.o
	gcc -o bBoard bBoard.o

clean:
	rm $(allExec)
	rm *.o
