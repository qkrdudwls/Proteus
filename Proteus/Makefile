proteus-gcc: arithmetic-parser notation-parser lexer main.c baseConversion.c notationConversion.c
	gcc -o proteus arithmetic_parser.tab.c notation_parser.tab.c lex.yy.c main.c baseConversion.c notationConversion.c -lm

proteus-clang: arithmetic-parser notation-parser lexer main.c baseConversion.c notationConversion.c
	clang -o proteus arithmetic_parser.tab.c notation_parser.tab.c lex.yy.c main.c baseConversion.c notationConversion.c -lm

proteus-debug: arithmetic-parser notation-parser lexer main.c baseConversion.c notationConversion.c
	gcc -g -o proteus arithmetic_parser.tab.c notation_parser.tab.c lex.yy.c main.c baseConversion.c notationConversion.c -lm
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
	rm -f proteus arithmetic_parser.tab.c arithmetic_parser.tab.h notation_parser.tab.c notation_parser.tab.h lex.yy.c