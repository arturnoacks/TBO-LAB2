#include "node.h"
#include <stdlib.h>

Node* node_create(int key) {
    Node* n = malloc(sizeof(Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
}

void node_destroy(Node* n) {
    if(n->left != NULL) node_destroy(n->left);
    if(n->right != NULL) node_destroy(n->right);
    free(n);
}

