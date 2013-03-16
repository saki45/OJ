allExec = arithProg bBoard triplet coins require lucky

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
lucky: lucky.o
	gcc -o lucky lucky.o

clean:
	rm $(allExec)
	rm *.o
