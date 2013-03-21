allExec = arithProg bBoard triplet coins lucky2

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
lucky2: lucky2.o
	g++ -o lucky2 lucky2.o

clean:
	rm $(allExec)
	rm *.o
