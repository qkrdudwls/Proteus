%{
    #include "parser.h"
    #include "arithmetic_parser.tab.h"
    #include "notation_parser.tab.h"

    extern int mode;
    int arithmetic_lex();
    int notation_lex();
    int arithmetic_error(char* msg);
    int notation_error(char* msg);
%}

%%
[0-9]+ {
    if(mode == 1){
        arithmetic_lval = atoi(yytext); 
        return ARITHMETIC_DIGIT;
    }else if(mode == 2){
        notation_lval.ival = atoi(yytext); 
        return NOTATION_DIGIT;
    }
}
"+" {
    if(mode == 1) return ARITHMETIC_PLUS;
    else if(mode == 2) return NOTATION_PLUS;
}
"-" {
    if(mode == 1) return ARITHMETIC_MINUS;
    else if(mode == 2) return NOTATION_MINUS;
}
"*" {
    if(mode == 1) return ARITHMETIC_MULT;
    else if(mode == 2) return NOTATION_MULT;
}
"/" {
    if(mode == 1) return ARITHMETIC_DIV;
    else if(mode == 2) return NOTATION_DIV;
}
"^" {
    if(mode == 1) return ARITHMETIC_EXP;
    else if(mode == 2) return NOTATION_EXP;
}
"%" {
    if(mode == 1) return ARITHMETIC_MOD;
    else if(mode == 2) return NOTATION_MOD;
}
"(" {
    if(mode == 1) return ARITHMETIC_LPAREN;
    else if(mode == 2) return NOTATION_LPAREN;
}
")" {
    if(mode == 1) return ARITHMETIC_RPAREN;
    else if(mode == 2) return NOTATION_RPAREN;
}
[ \t]+ {}
\n {
    if(mode == 1) return ARITHMETIC_NEWLINE;
    else if(mode == 2) return NOTATION_NEWLINE;
}
. {printf("Error: %c\n", yytext[0]); exit(1);}
%%

int yywrap(){
    return 1;
}

int arithmetic_lex(){
    return yylex();
}

int notation_lex(){
    return yylex();
}

int arithmetic_error(char* msg){
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

int notation_error(char* msg){
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}