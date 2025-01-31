%{
    #include <math.h>
    #include <ctype.h>
    #include "parser.h"

    extern int calculation_mode;
%}

%define api.prefix {arithmetic_}

%start input

%token ARITHMETIC_DIGIT ARITHMETIC_PLUS ARITHMETIC_MINUS ARITHMETIC_MULT ARITHMETIC_DIV ARITHMETIC_EXP ARITHMETIC_MOD ARITHMETIC_LPAREN ARITHMETIC_RPAREN ARITHMETIC_NEWLINE ARITHMETIC_UMINUS

%left ARITHMETIC_PLUS ARITHMETIC_MINUS
%left ARITHMETIC_MULT ARITHMETIC_DIV ARITHMETIC_MOD
%right ARITHMETIC_EXP
%precedence ARITHMETIC_UMINUS

%%

input : expr ARITHMETIC_NEWLINE { if(calculation_mode == 0) printf("Original Result: %d\n", $1); else printf("Result: %d\n", $1); yylval = $1; }
     ;

expr : expr ARITHMETIC_PLUS expr { $$ = $1 + $3; }
     | expr ARITHMETIC_MINUS expr { $$ = $1 - $3; }
     | expr ARITHMETIC_MULT expr { $$ = $1 * $3; }
     | expr ARITHMETIC_DIV expr { $$ = $1 / $3; if($3 == 0) yyerror("Division by zero"); }
     | expr ARITHMETIC_EXP expr { $$ = pow($1, $3); }
     | expr ARITHMETIC_MOD expr { $$ = $1 % $3; }
     | ARITHMETIC_LPAREN expr ARITHMETIC_RPAREN { $$ = $2; }
     | ARITHMETIC_MINUS expr %prec ARITHMETIC_UMINUS { $$ = -$2; }
     | ARITHMETIC_DIGIT { $$ = $1; }
     ;
%%