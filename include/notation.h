#ifndef NOTATION_H
#define NOTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int token;
    int is_operator;
    struct Node *left;
    struct Node *right;
} Node;

extern Node* createNode(int token, int is_operator, Node *left, Node *right);
extern Node* createLeaf(int token);
extern void preorder(Node *node);
extern void inorder(Node *node);
extern void postorder(Node *node);
extern void free_tree(Node *node);

#endif