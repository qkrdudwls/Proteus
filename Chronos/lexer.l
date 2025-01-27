%{
    #include <stdio.h>

    extern int yylval;
    #define __PLUS__ 1
    #define __MINUS__ 2
    #define __MULT__ 3
    #define __DIV__ 4
    #define __LPAREN__ 5
    #define __RPAREN__ 6
    #define __SQUR__ 7
    #define __DIGIT__ 8
%}

%%
[0-9]+ {yylval=atoi(yytext); return __DIGIT__;}
"+" {return __PLUS__;}
"-" {return __MINUS__;}
"*" {return __MULT__;}
"/" {return __DIV__;}
"(" {return __LPAREN__;}
")" {return __RPAREN__;}
"^" {return __SQUR__;}
[ \t]+ {}
\n {return '\n';}
. {printf("Error: %c\n", yytext[0]); exit(1);}
%%
int yylval;

int yywrap(){
    return 1;
}

int main(){
    int token;
    printf("Enter the expression: ");
    while((token=yylex())!=0){
        switch(token){
            case __PLUS__:
                printf("+ ");
                break;
            case __MINUS__:
                printf("- ");
                break;
            case __MULT__:
                printf("* ");
                break;
            case __DIV__:
                printf("/ ");
                break;
            case __LPAREN__:
                printf("( ");
                break;
            case __RPAREN__:
                printf(") ");
                break;
            case __SQUR__:
                printf("^ ");
                break;
            case __DIGIT__:
                printf("%d ", yylval);
                break;
            case '\n':
                printf("\nEnter the expression: ");
                break;
        }
    }
    return 0;
}