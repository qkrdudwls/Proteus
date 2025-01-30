proteus-gcc: parser lexer main.c baseConversion.c
	gcc -o proteus arithmetic_parser.tab.c lex.yy.c main.c baseConversion.c

proteus-clang: parser lexer main.c baseConversion.c
	clang -o proteus arithmetic_parser.tab.c lex.yy.c main.c baseConversion.c

proteus-debug: parser lexer main.c baseConversion.c
	gcc -g -o proteus arithmetic_parser.tab.c lex.yy.c main.c baseConversion.c
	gdb proteus

parser: arithmetic_parser.y
	bison -d arithmetic_parser.y

parsing-table: arithmetic_parser.y
	bison -d -v arithmetic_parser.y
	
lexer: lexer.l
	flex lexer.l

clean:
	rm -f proteus arithmetic_parser.tab.c arithmetic_parser.tab.h lex.yy.c