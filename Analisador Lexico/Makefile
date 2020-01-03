alg1: all
	./scanner < algoritmo1.por
alg2: all
	./scanner < algoritmo2.por
alg3: all
	./scanner < algoritmo3.por
alg4: all
	./scanner < algoritmo4.por
alg5: all
	./scanner < algoritmo5.por
all: clean
	clear
	flex sintatico.l
	gcc lex.yy.c -o scanner
clean:
	rm -f lex.yy.c scanner