#include "notation.h"
#include "notation_parser.tab.h"

Node* createNode(int token, int is_operator, Node *left, Node *right){
    Node *node = (Node*)malloc(sizeof(Node));
    node->token = token;
    node->is_operator = is_operator;
    node->left = left;
    node->right = right;
    return node;
}

Node* createLeaf(int value){
    return createNode(value, 0, NULL, NULL);
}

void printToken(Node *node){
    if(node->is_operator){
        switch(node->token){
            case '+':
                printf("+ ");
                break;
            case '-':
                printf("- ");
                break;
            case '*':
                printf("* ");
                break;
            case '/':
                printf("/ ");
                break;
            case '%':  
                printf("%% ");
                break;
            case '^':
                printf("^ ");
                break;
            case '(':
                printf("( ");
                break;
            case ')':
                printf(") ");
                break;
            case 'u':
                printf("- ");
                break;
            default:
                printf("%d ", node->token);
                break;
        }
    }else{
        printf("%d ", node->token);
    }
}

void inorder(Node *node){
    if(node != NULL){
        if(node->is_operator && node->token != 'u'){
            printf("( ");
        }
        inorder(node->left);
        printToken(node);
        inorder(node->right);
        if(node->is_operator && node->token != 'u'){
            printf(") ");
        }
    } else {
        return;
    }
}

void preorder(Node *node){
    if(node != NULL){
        printToken(node);
        preorder(node->left);
        preorder(node->right);
    } else {
        return;
    }
}

void postorder(Node *node){
    if(node != NULL){
        postorder(node->left);
        postorder(node->right);
        printToken(node);
    } else {
        return;
    }
}

void free_tree(Node *node){
    if(node != NULL){
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    } else {
        return;
    }
}