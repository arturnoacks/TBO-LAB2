#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

int main(int argc, char **argv) {
    if(argc != 2){
        printf("Uso: %s <n_keys>\n", argv[0]);
        return 1;
    }
    srand(time(NULL));

    Bst* bst = bst_create();
    int n;
    int n_keys = atoi(argv[1]);
    
    for(int i=0; i<n_keys; i++){
        int r = rand();
        bst_insert(bst, r);
    }

    bst_print_height(bst);

    bst_destroy(bst);
    
    return 0;
}