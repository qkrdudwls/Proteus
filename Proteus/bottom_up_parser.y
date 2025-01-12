%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern int yylex();
    extern void yyerror(const char *s);
%}
%token DIGIT
%%
line : expr '\n' { printf("Result: %d\n", $1); }
     ;

expr : expr '+' expr { $$ = $1 + $3; }
     | expr '-' expr { $$ = $1 - $3; }
     | expr '*' expr { $$ = $1 * $3; }
     | expr '/' expr { $$ = $1 / $3; }
     | '(' expr ')' { $$ = $2; }
     | DIGIT { $$ = $1; }
     ;
%%
int main() {
    yyparse();
    return 0;
}