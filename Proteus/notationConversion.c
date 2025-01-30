#include "util.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node* create_node(Node *left, Node *right, char *value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->left = left;
    node->right = right;
    node->value = strdup(value);
    return node;
}

void preorder(Node *node) {
    if (node != NULL) {
        printf("%s ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Node *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%s ", node->value);
    }
}

void free_tree(Node *node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node->value);
    free(node);
}