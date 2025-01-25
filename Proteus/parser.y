%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "compiler.h"


%}
%start line

%token __DIGIT__ 

%left '-' '+'
%left '*' '/' 
%right UMINUS

%%
line : expr '\n' { printf("Original Result: %d\n", $1); yylval = $1; }
     ;

expr : expr '+' expr { $$ = $1 + $3; }
     | expr '-' expr { $$ = $1 - $3; }
     | expr '*' expr { $$ = $1 * $3; }
     | expr '/' expr { $$ = $1 / $3; if($3 == 0) yyerror("Division by zero"); }
     | '(' expr ')' { $$ = $2; }
     | '-' expr %prec UMINUS { $$ = -$2; }
     | __DIGIT__ { $$ = $1; }
     ;
%%