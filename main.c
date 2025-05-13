#include <stdio.h>
#include "bst.h"

int main(int argc, char **argv) {
    Bst* bst = bst_create();
    int n;

    for(int i=0; i<10; i++){
        scanf("%d", &n);
        bst_insert(bst, n);
    }

    bst_destroy(bst);
    
    return 0;
}