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

%start input

%token NOTATION_PREFIX NOTATION_INFIX NOTATION_POSTFIX

%token <ival> NOTATION_DIGIT NOTATION_PLUS NOTATION_MINUS NOTATION_MULT NOTATION_DIV NOTATION_EXP NOTATION_MOD NOTATION_LPAREN NOTATION_RPAREN NOTATION_NEWLINE NOTATION_UMINUS

%type <node> input preorder_expr inorder_expr postorder_expr preorder_subexpr postorder_subexpr

%left NOTATION_PLUS NOTATION_MINUS
%left NOTATION_MULT NOTATION_DIV NOTATION_MOD
%right NOTATION_EXP
%precedence NOTATION_UPLUS NOTATION_UMINUS

%%

input:
    NOTATION_PREFIX preorder_expr NOTATION_NEWLINE { root = $2; if(notation_mode == 1) preorder(root); else if(notation_mode == 2) postorder(root); free_tree(root); }
    | NOTATION_INFIX inorder_expr NOTATION_NEWLINE { root = $2; if(notation_mode == 1) inorder(root); else if(notation_mode == 2) postorder(root); free_tree(root); }
    | NOTATION_POSTFIX postorder_expr NOTATION_NEWLINE { root = $2; if(notation_mode == 1) preorder(root); else if(notation_mode == 2) inorder(root); free_tree(root); }
    ;

inorder_expr: 
    inorder_expr NOTATION_PLUS inorder_expr { $$ = createNode('+', 1, $1, $3); }
    | inorder_expr NOTATION_MINUS inorder_expr { $$ = createNode('-', 1, $1, $3); }
    | inorder_expr NOTATION_MULT inorder_expr { $$ = createNode('*', 1, $1, $3); }
    | inorder_expr NOTATION_DIV inorder_expr { $$ = createNode('/', 1, $1, $3); }
    | inorder_expr NOTATION_EXP inorder_expr { $$ = createNode('^', 1, $1, $3); }
    | inorder_expr NOTATION_MOD inorder_expr { $$ = createNode('%', 1, $1, $3); }
    | NOTATION_LPAREN inorder_expr NOTATION_RPAREN { $$ = $2; }
    | NOTATION_PLUS inorder_expr %prec NOTATION_UPLUS { $$ = createNode('p', 1, $2, NULL); }
    | NOTATION_MINUS inorder_expr %prec NOTATION_UMINUS { $$ = createNode('u', 1, $2, NULL); }
    | NOTATION_DIGIT { $$ = createLeaf($1); }
    ;

preorder_expr:
    NOTATION_PLUS preorder_subexpr { $$ = $2; }
    | NOTATION_MINUS preorder_subexpr { $$ = $2; }
    | NOTATION_PLUS preorder_expr preorder_expr { $$ = createNode('+', 1, $1, $2); }
    | NOTATION_MINUS preorder_expr preorder_expr { $$ = createNode('-', 1, $1, $2); }
    | NOTATION_MULT preorder_expr preorder_expr { $$ = createNode('*', 1, $1, $2); }
    | NOTATION_DIV preorder_expr preorder_expr { $$ = createNode('/', 1, $1, $2); }
    | NOTATION_EXP preorder_expr preorder_expr { $$ = createNode('^', 1, $1, $2); }
    | NOTATION_MOD preorder_expr preorder_expr { $$ = createNode('%', 1, $1, $2); }
    | DIGIT { $$ = createLeaf($1); }
    ;

preorder_subexpr:
    DIGIT { $$ = createLeaf($1); }
    ;

postorder_expr:
    postorder_expr postorder_expr NOTATION_PLUS { $$ = createNode('+', 1, $1, $2); }
    | postorder_expr postorder_expr NOTATION_MINUS { $$ = createNode('-', 1, $1, $2); }
    | postorder_expr postorder_expr NOTATION_MULT { $$ = createNode('*', 1, $1, $2); }
    | postorder_expr postorder_expr NOTATION_DIV { $$ = createNode('/', 1, $1, $2); }
    | postorder_expr postorder_expr NOTATION_EXP { $$ = createNode('^', 1, $1, $2); }
    | postorder_expr postorder_expr NOTATION_MOD { $$ = createNode('%', 1, $1, $2); }
    | NOTATION_LPAREN postorder_expr NOTATION_RPAREN { $$ = $2; }
    | NOTATION_MINUS postorder_expr %prec NOTATION_UMINUS { $$ = createNode('u', 1, $2, NULL); }
    | NOTATION_DIGIT { $$ = createLeaf($1); }
    ;

%%