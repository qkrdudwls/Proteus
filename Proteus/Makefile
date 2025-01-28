proteus-gcc: parser lexer main.c baseConversion.c
	gcc -o proteus parser.tab.c lex.yy.c main.c 
proteus-clang: parser lexer main.c baseConversion.c
	clang -o proteus parser.tab.c lex.yy.c main.c baseConversion.c
proteus-debug: parser lexer main.c baseConversion.c
	gcc -g -o proteus parser.tab.c lex.yy.c main.c baseConversion.c
	gdb proteus
parser: parser.y
	bison -d parser.y
parsing-table: parser.y
	bison -d -v parser.y 
lexer: lexer.l
	flex lexer.l
clean:
	rm -f proteus parser.tab.c parser.tab.h lex.yy.c