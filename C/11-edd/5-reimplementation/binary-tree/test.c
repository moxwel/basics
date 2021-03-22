// gcc -c binary_tree.c test.c && gcc binary_tree.o test.o && ./a.out

#include <stdio.h>

#include "binary_tree.h"

int main() {
    tABB* miArbol = newABB();

    printf("%d ", insertNode(miArbol, 4));

    printf("%d ", insertNode(miArbol, 6));

    printf("%d ", insertNode(miArbol, 5));

    printf("%d ", insertNode(miArbol, 6));

    printf("%d ", insertNode(miArbol, 4));

    printf("%d ", insertNode(miArbol, 15));

    printf("%d ", insertNode(miArbol, 7));

    printf("%d ", insertNode(miArbol, 3));

    printf("%d ", insertNode(miArbol, 2));

    printf("%d\n", findNode(miArbol, 8));

    return 0;
}
