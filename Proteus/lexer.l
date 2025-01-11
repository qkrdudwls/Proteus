%{
    #include <stdlib.h>
    #include "parser.h"
    extern int yylval;
%}

%%

"+" {yylval=yytext[0]; return __PLUS__;}
"-" {yylval=yytext[0]; return __MINUS__;}
"*" {yylval=yytext[0]; return __MULT__;}
"/" {yylval=yytext[0]; return __DIV__;}
"(" {yylval=yytext[0]; return __LPAREN__;}
")" {yylval=yytext[0]; return __RPAREN__;}
[0-9]+ {yylval=atoi(yytext); return __DIGIT__;}
[ \t\n] {;}
. {printf("Error: %c\n", yytext[0]); exit(1);}

%%
int yywrap(){
    return 1;
}

/*
int yylval;
int main(void){
    int token;
    while((token=yylex())!=0){
        if(token==PLUS){
            printf("PLUS: %c\n", yylval);
        }
        else if(token==MINUS){
            printf("MINUS: %c\n", yylval);
        }
        else if(token==MULT){
            printf("MULT: %c\n", yylval);
        }
        else if(token==DIV){
            printf("DIV: %c\n", yylval);
        }
        else if(token==LPAREN){
            printf("LPAREN: %c\n", yylval);
        }
        else if(token==RPAREN){
            printf("RPAREN: %c\n", yylval);
        }
        else if(token==DIGIT){
            printf("DIGIT: %d\n", yylval);
        }
    }
}
*/