%{
    #include "parser.h"
    #include "arithmetic_parser.tab.h"
    #include "notation_parser.tab.h"
    #include "notation.h"
    extern int mode;
%}

%%
[0-9]+ {if(mode == 1){
            yylval.integer = atoi(yytext);
        }else if(mode == 2){
            yylval.string = strdup(yytext);
        }
        return __DIGIT__;}
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