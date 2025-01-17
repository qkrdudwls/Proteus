%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern void yyerror(const char *s);

%}
%start line
%token __PLUS__ __MINUS__ __MULT__ __DIV__ __LPAREN__ __RPAREN__ __DIGIT__
%debug
%%
line : expr '\n' { printf("Result: %d\n", $1); }
     ;

expr : expr __PLUS__ term { $$ = $1 + $3; }
     | expr __MINUS__ term { $$ = $1 - $3; }
     | term 
     ;

term : term __MULT__ factor { $$ = $1 * $3; }
     | term __DIV__ factor { 
        if($3 == 0){
            yyerror("Division by zero");
            exit(1);
        }
        $$ = $1 / $3; }
     | factor 
     ;

factor : __LPAREN__ expr __RPAREN__ { $$ = $2; }
       | __DIGIT__ 
       ;

%%
void yyerror(const char *s){
    fprintf(stderr, "%s\n", s);
    exit(1);
}

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}