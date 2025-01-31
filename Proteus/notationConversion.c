#include "notation.h"
#include "notation_parser.tab.h"

Node* createNode(int token, Node *left, Node *right){
    Node *node = (Node*)malloc(sizeof(Node));
    node->token = token;
    node->left = left;
    node->right = right;
    return node;
}

void print_token(int token){
    switch(token){
        case __PLUS__:
            printf("+ ");
            break;
        case __MINUS__:
            printf("- ");
            break;
        case __MULT__:
            printf("* ");
            break;
        case __DIV__:
            printf("/ ");
            break;
        case __MOD__:
            printf("%% ");
            break;
        case __EXP__:
            printf("^ ");
            break;
        case __LPAREN__:
            printf("( ");
            break;
        case __RPAREN__:    
            printf(") ");
            break;
        default:
            printf("%d ", token);
            break;
    }
}

void preorder(Node *node){
    if(node != NULL){
        print_token(node->token);
        preorder(node->left);
        preorder(node->right);
    }else{
        return;
    }
}

void postorder(Node *node){
    if(node != NULL){
    postorder(node->left);
    postorder(node->right);
    print_token(node->token);
    }else{
        return;
    }
}

void free_tree(Node *node){
    if(node != NULL){
    free_tree(node->left);
    free_tree(node->right);
    free(node);
    }else{
        return;
    }
}