%{
    #include <math.h>
    #include <ctype.h>
    #include "parser.h"
%}

%define api.prefix {arithmetic_}

%union{
    int ival;
}

%start input

%token ARITHMETIC_INFIX ARITHMETIC_PREFIX ARITHMETIC_POSTFIX

%token <ival> ARITHMETIC_DIGIT ARITHMETIC_PLUS ARITHMETIC_MINUS ARITHMETIC_MULT ARITHMETIC_DIV ARITHMETIC_EXP ARITHMETIC_MOD ARITHMETIC_LPAREN ARITHMETIC_RPAREN ARITHMETIC_NEWLINE ARITHMETIC_UPLUS ARITHMETIC_UMINUS

%type <ival> input infix_expr prefix_expr postfix_expr unary_expr

%left ARITHMETIC_PLUS ARITHMETIC_MINUS
%left ARITHMETIC_MULT ARITHMETIC_DIV ARITHMETIC_MOD
%right ARITHMETIC_EXP
%precedence ARITHMETIC_UPLUS ARITHMETIC_UMINUS

%%

input : 
     ARITHMETIC_PREFIX prefix_expr ARITHMETIC_NEWLINE { printf("Original Result: %d\n", $2); yylval.ival = $2; }
     | ARITHMETIC_INFIX infix_expr ARITHMETIC_NEWLINE { printf("Original Result: %d\n", $2); yylval.ival = $2; }
     | ARITHMETIC_POSTFIX postfix_expr ARITHMETIC_NEWLINE { printf("Original Result: %d\n", $2); yylval.ival = $2; }
     | ARITHMETIC_PREFIX unary_expr ARITHMETIC_NEWLINE { printf("Original Result: %d\n", $2); yylval.ival = $2; }
     | ARITHMETIC_POSTFIX unary_expr ARITHMETIC_NEWLINE { printf("Original Result: %d\n", $2); yylval.ival = $2; }
     ;

infix_expr : 
     infix_expr ARITHMETIC_PLUS infix_expr { $$ = $1 + $3; }
     | infix_expr ARITHMETIC_MINUS infix_expr { $$ = $1 - $3; }
     | infix_expr ARITHMETIC_MULT infix_expr { $$ = $1 * $3; }
     | infix_expr ARITHMETIC_DIV infix_expr { $$ = $1 / $3; if($3 == 0) yyerror("Division by zero"); }
     | infix_expr ARITHMETIC_EXP infix_expr { $$ = pow($1, $3); }
     | infix_expr ARITHMETIC_MOD infix_expr { $$ = $1 % $3; }
     | ARITHMETIC_LPAREN infix_expr ARITHMETIC_RPAREN { $$ = $2; }
     | ARITHMETIC_PLUS infix_expr %prec ARITHMETIC_UPLUS { $$ = $2; }
     | ARITHMETIC_MINUS infix_expr %prec ARITHMETIC_UMINUS { $$ = -$2; }
     | ARITHMETIC_DIGIT { $$ = $1; }
     ;

prefix_expr :
     ARITHMETIC_PLUS prefix_expr prefix_expr { $$ = $2 + $3; }
     | ARITHMETIC_MINUS prefix_expr prefix_expr { $$ = $2 - $3; }
     | ARITHMETIC_MULT prefix_expr prefix_expr { $$ = $2 * $3; }
     | ARITHMETIC_DIV prefix_expr prefix_expr { $$ = $2 / $3; if($3 == 0) yyerror("Division by zero"); }
     | ARITHMETIC_EXP prefix_expr prefix_expr { $$ = pow($2, $3); }
     | ARITHMETIC_MOD prefix_expr prefix_expr { $$ = $2 % $3; }
     | ARITHMETIC_DIGIT { $$ = $1; }
     ;

postfix_expr : 
     postfix_expr postfix_expr ARITHMETIC_PLUS { $$ = $1 + $2; }
     | postfix_expr postfix_expr ARITHMETIC_MINUS { $$ = $1 - $2; }
     | postfix_expr postfix_expr ARITHMETIC_MULT { $$ = $1 * $2; }
     | postfix_expr postfix_expr ARITHMETIC_DIV { $$ = $1 / $2; if($2 == 0) yyerror("Division by zero"); }
     | postfix_expr postfix_expr ARITHMETIC_EXP { $$ = pow($1, $2); }
     | postfix_expr postfix_expr ARITHMETIC_MOD { $$ = $1 % $2; }
     | ARITHMETIC_DIGIT { $$ = $1; }
     ;

unary_expr :
     ARITHMETIC_PLUS ARITHMETIC_DIGIT %prec ARITHMETIC_UPLUS { $$ = $2; }
     | ARITHMETIC_MINUS ARITHMETIC_DIGIT %prec ARITHMETIC_UMINUS { $$ = -$2; }
     ;
%%