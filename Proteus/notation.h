#ifndef NOTATION_H
#define NOTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *value;
    struct Node *left;
    struct Node *right;
} Node;

typedef union {
    int integer;
    char *string;
    Node *node;
} C_YYSTYPE;

#define YYSTYPE C_YYSTYPE

extern Node* create_node(Node *left, Node *right, char *value);
extern void preorder(Node *node);
extern void postorder(Node *node);
extern void free_tree(Node *node);

#endif
