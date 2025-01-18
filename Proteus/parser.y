%{
    #define YYDEBUG 1
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern void yyerror(const char *s);

%}
%start line

%token __DIGIT__ 


%left '-' '+'
%left '*' '/' 
%right UMINUS

%%
line : expr '\n' { printf("Result: %d\n", $1); }
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
    fprintf(stderr, "%s\n", s);
    exit(1);
}

int yylex(){
    int c = getchar();
    if(isdigit(c)){
        yylval = c - '0';
        return __DIGIT__;
    }
    return c;
}

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}