proteus-gcc: arithmetic-parser notation-parser lex ./src/main.c ./src/baseConversion.c ./src/notationConversion.c
	gcc -o proteus -I./include ./src/arithmetic_parser.tab.c ./src/notation_parser.tab.c ./src/lex.yy.c ./src/main.c ./src/baseConversion.c ./src/notationConversion.c -lm

proteus-clang: arithmetic-parser notation-parser lex ./src/main.c ./src/baseConversion.c ./src/notationConversion.c
	clang -o proteus -I./include ./src/arithmetic_parser.tab.c ./src/notation_parser.tab.c ./src/lex.yy.c ./src/main.c ./src/baseConversion.c ./src/notationConversion.c -lm

proteus-debug: arithmetic-parser notation-parser lex main.c baseConversion.c notationConversion.c
	gcc -g -o proteus -I./include ./src/arithmetic_parser.tab.c ./src/notation_parser.tab.c ./src/lex.yy.c ./src/main.c ./src/baseConversion.c ./src/notationConversion.c -lm
	gdb proteus

arithmetic-parser: ./parser/arithmetic_parser.y
	bison -d ./parser/arithmetic_parser.y
	mv arithmetic_parser.tab.h include/
	mv arithmetic_parser.tab.c src/

notation-parser: ./parser/notation_parser.y
	bison -d ./parser/notation_parser.y	
	mv notation_parser.tab.h include/
	mv notation_parser.tab.c src/

arithmetic-parsing-table: ./parser/arithmetic_parser.y
	bison -d -v ./parser/arithmetic_parser.y
	mv arithmetic_parser.tab.h include/
	mv arithmetic_parser.tab.c src/

notation-parsing-table: ./parser/notation_parser.y
	bison -d -v ./parser/notation_parser.y
	mv notation_parser.tab.h include/
	mv notation_parser.tab.c src/

lex: ./lexer/lexer.l
	flex -o src/lex.yy.c ./lexer/lexer.l

clean:
	rm -f proteus src/arithmetic_parser.tab.c src/notation_parser.tab.c src/lex.yy.c include/arithmetic_parser.tab.h include/notation_parser.tab.h
