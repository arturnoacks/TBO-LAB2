#include "bst.h"
#include "node.h"

#include <stdlib.h>

struct _Bst {
    Node* head;
};

Bst* bst_create() {
    Bst* bst = malloc(sizeof(bst));
    bst->head = NULL;
    return bst;
}

void bst_insert(Bst* bst, int key) {
    Node* new_node = node_create(key); 
    Node* tmp = bst->head;

    if(tmp == NULL){
        bst->head = new_node;
        return;
    }

    while(1) {
        if(new_node->key > tmp->key) {
            if(tmp->right != NULL){
                tmp = tmp->right;
            }
            else {
                tmp->right = new_node;
                break;
            }
        }

        else if(new_node->key < tmp->key) {
            if(tmp->left != NULL){
                tmp = tmp->left;
            }
            else {
                tmp->left = new_node;
                break;
            }
        }

        else {
            node_destroy(new_node);
            break;
        }
    }
}

void bst_destroy(Bst* bst) {
    node_destroy(bst->head);
    free(bst);
}