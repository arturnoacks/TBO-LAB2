#ifndef _NODE_H
#define _NODE_H

typedef struct _Node Node;

struct _Node {
    int key;
    Node* left;
    Node* right;
};

Node* node_create(int key);

void node_destroy(Node* n);

#endif