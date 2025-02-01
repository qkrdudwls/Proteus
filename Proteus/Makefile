proteus-gcc: arithmetic_parser notation_parser lexer main.c baseConversion.c notationConversion.c
	gcc -o proteus arithmetic_parser.tab.c notation_parser.tab.c lex.yy.c main.c baseConversion.c notationConversion.c

proteus-clang: arithmetic_parser notation_parser lexer main.c baseConversion.c notationConversion.c
	clang -o proteus arithmetic_parser.tab.c notation_parser.tab.c lex.yy.c main.c baseConversion.c notationConversion.c

proteus-debug: arithmetic_parser notation_parser lexer main.c baseConversion.c notationConversion.c
	gcc -g -o proteus arithmetic_parser.tab.c notation_parser.tab.c lex.yy.c main.c baseConversion.c notationConversion.c
	gdb proteus

arithmetic-parser: arithmetic_parser.y
	bison -d arithmetic_parser.y

notation-parser: notation_parser.y
	bison -d notation_parser.y	

arithmetic-parsing-table: arithmetic_parser.y
	bison -d -v arithmetic_parser.y

notation-parsing-table: notation_parser.y
	bison -d -v notation_parser.y

lexer: lexer.l
	flex lexer.l

clean:
	rm -f proteus arithmetic_parser.tab.c arithmetic_parser.tab.h lex.yy.c