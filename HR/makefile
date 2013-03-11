allExec = arithProg bBoard triplet coins require

all:	$(allExec)

arithProg: arithProg.o
	g++ -o arithProg arithProg.o
bBoard: bBoard.o
	gcc -o bBoard bBoard.o
triplet: triplet.o
	g++ -o triplet triplet.o
coins: coins.o
	g++ -o coins coins.o
require: require.o
	g++ -o require require.o

clean:
	rm $(allExec)
	rm *.o
