proteus-gcc: arithmetic_parser lexer main.c baseConversion.c
	gcc -o proteus arithmetic_parser.tab.c lex.yy.c main.c baseConversion.c

proteus-clang: arithmetic_parser lexer main.c baseConversion.c
	clang -o proteus arithmetic_parser.tab.c lex.yy.c main.c baseConversion.c

proteus-debug: arithmetic_parser lexer main.c baseConversion.c
	gcc -g -o proteus arithmetic_parser.tab.c lex.yy.c main.c baseConversion.c
	gdb proteus

arithmetic_parser: arithmetic_parser.y
	bison -d arithmetic_parser.y

arithmetic-parsing-table: arithmetic_parser.y
	bison -d -v arithmetic_parser.y

lexer: lexer.l
	flex lexer.l

clean:
	rm -f proteus arithmetic_parser.tab.c arithmetic_parser.tab.h lex.yy.c