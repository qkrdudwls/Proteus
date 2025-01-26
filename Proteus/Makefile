proteus-gcc: parser flex main.c util.c
	gcc -o proteus parser.tab.c lex.yy.c main.c util.c
proteus-clang: parser flex main.c util.c
	clang -o proteus parser.tab.c lex.yy.c main.c util.c
proteus-debug: parser flex main.c util.c
	gcc -g -o proteus parser.tab.c lex.yy.c main.c util.c
	gdb proteus
parser: parser.y
	bison -d parser.y
parsing-table: parser.y
	bison -d -v parser.y 
lexer: lexer.l
	flex lexer.l
clean:
	rm -f proteus parser.tab.c parser.tab.h lex.yy.c