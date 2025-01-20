%{
    #define YYDEBUG 1
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>

    extern int yylex();
    extern void yyerror(const char *s);
    int yylval;

%}
%start line

%token __DIGIT__ 

%left '-' '+'
%left '*' '/' 
%right UMINUS

%%
line : expr '\n' { printf("Result: %d\n", $1); return 0; }
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

void yyerror(const char *s){
    fprintf(stderr, "Error: %s at token '%c'\n", s, yychar);
    exit(1);
}

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}