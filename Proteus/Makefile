proteus: parser flex main.c util.c
	gcc -o proteus parser.tab.c lex.yy.c main.c util.c
parser: parser.y
	bison -d parser.y
flex: lexer.l
	flex lexer.l
clean:
	rm -f proteus parser.tab.c parser.tab.h lex.yy.c