#include <stdio.h>

#include "binary_tree.h"

int main() {
    tABB* miArbol = newABB();

    printf("%d\n", insert(miArbol, 4));
    printf("%d\n", insert(miArbol, 6));
    printf("%d\n", insert(miArbol, 5));
    printf("%d\n", insert(miArbol, 6));
    printf("%d\n", insert(miArbol, 4));
    printf("%d\n", insert(miArbol, 8));
    printf("%d\n", insert(miArbol, 7));
    printf("%d\n", insert(miArbol, 3));


    return 0;
}
