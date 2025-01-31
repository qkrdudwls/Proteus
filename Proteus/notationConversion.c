#include "notation.h"
#include "notation_parser.tab.h"

Node* createNode(int token, Node *left, Node *right){
    Node *node = (Node*)malloc(sizeof(Node));
    node->token = token;
    node->left = left;
    node->right = right;
    return node;
}

Node* createLeaf(int token){
    return createNode(token, NULL, NULL);
}

void preorder(Node *node){
    if(node != NULL){
        switch(node->token){
            case NOTATION_PLUS:
                printf("+ ");
                break;
            case NOTATION_MINUS:
                printf("- ");
                break;
            case NOTATION_MULT:
                printf("* ");
                break;
            case NOTATION_DIV:
                printf("/ ");
                break;
            case NOTATION_MOD:  
                printf("%% ");
                break;
            case NOTATION_EXP:
                printf("^ ");
                break;
            case NOTATION_LPAREN:
                printf("( ");
                break;
            case NOTATION_RPAREN:
                printf(") ");
                break;
            default:
                printf("%d ", node->token);
                break;
        }
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
        switch(node->token){
            case NOTATION_PLUS:
                printf("+ ");
                break;
            case NOTATION_MINUS:
                printf("- ");
                break;
            case NOTATION_MULT:
                printf("* ");
                break;
            case NOTATION_DIV:
                printf("/ ");
                break;
            case NOTATION_MOD:  
                printf("%% ");
                break;
            case NOTATION_EXP:
                printf("^ ");
                break;
            case NOTATION_LPAREN:
                printf("( ");
                break;
            case NOTATION_RPAREN:
                printf(") ");
                break;
            default:
                printf("%d ", node->token);
                break;
        }
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