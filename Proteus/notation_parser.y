%{
    #include "notation.h"
    #include <stdio.h>

    extern int yylex();
    int yyerror(char *s);
    extern char* yytext;

    Node* root;
%}

%union {
    int ival;
    Node* node;
}

%token <ival> __DIGIT__ __PLUS__ __MINUS__ __MULT__ __DIV__ __EXP__ __MOD__ __LPAREN__ __RPAREN__ __NEWLINE__

%type <node> expression term factor primary

%%
notation:
    expression __NEWLINE__ { root = $1; postorder(root); free_tree(root); }
    ;

expression:
    term                    { $$ = $1; }
    | expression __PLUS__ term   { $$ = createNode(__PLUS__, $1, $3); }
    | expression __MINUS__ term  { $$ = createNode(__MINUS__, $1, $3); }
    ;

term:
    factor                  { $$ = $1; }
    | term __MULT__ factor  { $$ = createNode(__MULT__, $1, $3); }
    | term __DIV__ factor   { $$ = createNode(__DIV__, $1, $3); }
    | term __MOD__ factor   { $$ = createNode(__MOD__, $1, $3); }
    ;

factor:
    primary                 { $$ = $1; }
    | primary __EXP__ factor   { $$ = createNode(__EXP__, $1, $3); }
    ;

primary:
    __DIGIT__               { $$ = createNode(atoi(yytext), NULL, NULL); }
    | __LPAREN__ expression __RPAREN__ { $$ = $2; }
    ;

%%
int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

int main() {
    yyparse();
    return 0;
}
