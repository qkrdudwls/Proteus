%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <ctype.h>
    #include "parser.h"
%}
%start line

%token __DIGIT__ __PLUS__ __MINUS__ __MULT__ __DIV__ __EXP__ __MOD__ __LPAREN__ __RPAREN__ __NEWLINE__

%left __PLUS__ __MINUS__
%left __MULT__ __DIV__ __MOD__
%right __EXP__
%precedence UMINUS

%%
line : expr __NEWLINE__ { printf("Original Result: %d\n", $1); yylval = $1; }
     ;

expr : expr __PLUS__ expr { $$ = $1 + $3; }
     | expr __MINUS__ expr { $$ = $1 - $3; }
     | expr __MULT__ expr { $$ = $1 * $3; }
     | expr __DIV__ expr { $$ = $1 / $3; if($3 == 0) yyerror("Division by zero"); }
     | expr __EXP__ expr { $$ = pow($1, $3); }
     | expr __MOD__ expr { $$ = $1 % $3; }
     | __LPAREN__ expr __RPAREN__ { $$ = $2; }
     | __MINUS__ expr %prec UMINUS { $$ = -$2; }
     | __DIGIT__ { $$ = $1; }
     ;
%%