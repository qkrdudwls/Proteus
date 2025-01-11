%{
    #include "parser.h"
%}

%%

"+" {yylval=yytext[0]; return PLUS;}
"-" {yylval=yytext[0]; return MINUS;}
"*" {yylval=yytext[0]; return MULT;}
"/" {yylval=yytext[0]; return DIV;}
"(" {yylval=yytext[0]; return LPAREN;}
")" {yylval=yytext[0]; return RPAREN;}
[0-9]+ {yylval=atoi(yytext); return DIGIT;}
[ \t\n] {;}
. {printf("Error: %c\n", yytext[0]); exit(1);}

%%
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
        else if(token==NUM){
            printf("DIGIT: %d\n", yylval);
        }
    }
}
*/