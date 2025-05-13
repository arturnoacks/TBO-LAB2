#include "bst.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>

struct _Bst {
    Node* head;
    int height;
};

Bst* bst_create() {
    Bst* bst = malloc(sizeof(Bst));
    bst->head = NULL;
    bst->height = -1;
    return bst;
}

void bst_insert(Bst* bst, int key) {
    Node* new_node = node_create(key); 
    Node* tmp = bst->head;
    int tmp_height = -1;
    
    if(tmp == NULL){
        bst->head = new_node;
        bst->height++;
        return;
    }

    while(1) {
        if(new_node->key > tmp->key) {
            if(tmp->right != NULL){
                tmp = tmp->right;
                tmp_height++;
            }
            else {
                tmp->right = new_node;
                break;
            }
        }

        else if(new_node->key < tmp->key) {
            if(tmp->left != NULL){
                tmp = tmp->left;
                tmp_height++;
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

        if(tmp_height > bst->height) bst->height = tmp_height;
    }
}

void bst_print_height(Bst* b) {
    printf("Height: %d\n", b->height);
}

void bst_destroy(Bst* bst) {
    if(bst->head != NULL) node_destroy(bst->head);
    free(bst);
}