#include "notation.h"
#include "notation_parser.tab.h"

Node* createNode(int token, Node *left, Node *right){
    Node *node = (Node*)malloc(sizeof(Node));
    node->token = token;
    node->left = left;
    node->right = right;
    return node;
}

Node* createLeaf(int value){
    return createNode(value, NULL, NULL);
}

void preorder(Node *node){
    if(node != NULL){
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
            default:
                printf("%d ", node->token); // 숫자를 출력
                break;
        }
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
            default:
                printf("%d ", node->token); // 숫자를 출력
                break;
        }
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