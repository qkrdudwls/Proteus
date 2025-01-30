%{
    #include "parser.h"
    #include "arithmetic_parser.tab.h"
%}

%%
[0-9]+ {yylval=atoi(yytext); return __DIGIT__;}
"+" {return __PLUS__;}
"-" {return __MINUS__;}
"*" {return __MULT__;}
"/" {return __DIV__;}
"^" {return __EXP__;}
"%" {return __MOD__;}
"(" {return __LPAREN__;}
")" {return __RPAREN__;}
[ \t]+ {}
\n {return __NEWLINE__;} 
. {printf("Error: %c\n", yytext[0]); exit(1);}
%%

int yywrap(){
    return 1;
}