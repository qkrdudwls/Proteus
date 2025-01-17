%{
    #include "y.tab.h"
%}

%%

"+" {yylval=yytext[0]; return __PLUS__;}
"-" {yylval=yytext[0]; return __MINUS__;}
"*" {yylval=yytext[0]; return __MULT__;}
"/" {yylval=yytext[0]; return __DIV__;}
"(" {yylval=yytext[0]; return __LPAREN__;}
")" {yylval=yytext[0]; return __RPAREN__;}
[0-9]+ {yylval=atoi(yytext); return __DIGIT__;}
[ \t] {;}
\n { return 0; } // EOF 
. {printf("Error: %c\n", yytext[0]); exit(1);}

%%

int yywrap(){
    return 1;
}