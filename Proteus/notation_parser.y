%{
    #include "notation.h"
    #include "parser.h"

    extern int notation_mode;
    extern char* yytext;
    Node* root;
%}

%define api.prefix {notation_}

%union {
    int ival;
    struct Node* node;
}

%token <ival> NOTATION_DIGIT NOTATION_PLUS NOTATION_MINUS NOTATION_MULT NOTATION_DIV NOTATION_EXP NOTATION_MOD NOTATION_LPAREN NOTATION_RPAREN NOTATION_NEWLINE NOTATION_UMINUS

%type <node> expr

%left NOTATION_PLUS NOTATION_MINUS
%left NOTATION_MULT NOTATION_DIV NOTATION_MOD
%right NOTATION_EXP
%precedence NOTATION_UMINUS

%%
input:
    expr NOTATION_NEWLINE { root = $1; if(notation_mode == 1) preorder(root); else if(notation_mode == 2) postorder(root); free_tree(root); }
    ;

expr: 
    expr NOTATION_PLUS expr { $$ = createNode('+', 1, $1, $3); }
    | expr NOTATION_MINUS expr { $$ = createNode('-', 1, $1, $3); }
    | expr NOTATION_MULT expr { $$ = createNode('*', 1, $1, $3); }
    | expr NOTATION_DIV expr { $$ = createNode('/', 1, $1, $3); }
    | expr NOTATION_EXP expr { $$ = createNode('^', 1, $1, $3); }
    | expr NOTATION_MOD expr { $$ = createNode('%', 1, $1, $3); }
    | NOTATION_LPAREN expr NOTATION_RPAREN { $$ = $2; }
    | NOTATION_MINUS expr %prec NOTATION_UMINUS { $$ = createNode('u', 1, $2, NULL); }
    | NOTATION_DIGIT { $$ = createLeaf($1); }
    ;
%%