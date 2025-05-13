#ifndef _BST_H
#define _BST_H

typedef struct _Bst Bst;

Bst* bst_create();

void bst_insert(Bst* bst, int key);

void bst_print_height(Bst* bst);

void bst_destroy(Bst* bst);

#endif