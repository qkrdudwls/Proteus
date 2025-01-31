#ifndef NOTATION_H
#define NOTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int token;
    struct Node *left;
    struct Node *right;
} Node;

extern Node* createNode(int token, Node *left, Node *right);
extern void print_token(int token);
extern void preorder(Node *node);
extern void postorder(Node *node);
extern void free_tree(Node *node);

#endif