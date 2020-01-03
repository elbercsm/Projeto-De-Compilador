all: clean run

run:
	flex -i scanner.l
	bison parser.y -v
	gcc -c hash.c
	gcc -o parser parser.tab.c -lfl hash.o


clean: 
	-rm -f *.o *.output lex.yy.c parser.tab.c
