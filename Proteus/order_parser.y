%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "compiler.h"

    Node *root;
%}

%union{
    int num;
    char *str;
    Node *node;
}
%start input

%token <str> __DIGIT__
%token __PLUS__ __MINUS__ __MULT__ __DIV__ __EXP__ __MOD__ __LPAREN__ __RPAREN__ __NEWLINE__

%type <node> expr

%left __PLUS__ __MINUS__
%left __MULT__ __DIV__ __MOD__
%right __EXP__
%precedence UMINUS

%%
input: expr { root = $1; }
    ;

expr: expr __PLUS__ expr { $$ = create_node($1, $3, '+'); }
    | expr __MINUS__ expr { $$ = create_node($1, $3, '-'); }
    | expr __MULT__ expr { $$ = create_node($1, $3, '*'); }
    | expr __DIV__ expr { $$ = create_node($1, $3, '/'); }
    | expr __EXP__ expr { $$ = create_node($1, $3, '^'); }
    | expr __MOD__ expr { $$ = create_node($1, $3, '%'); }
    | __LPAREN__ expr __RPAREN__ { $$ = $2; }
    | __MINUS__ expr %prec UMINUS { $$ = create_node($2, NULL, '-'); }
    | __DIGIT__ { $$ = create_node(NULL, NULL, $1); }
    ;