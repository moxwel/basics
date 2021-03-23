// gcc -c binary_tree.c test.c && gcc binary_tree.o test.o && ./a.out

#include <stdio.h>

#include "binary_tree.h"

int main() {
    tABB* miArbol = newABB();

    printf("%d\n", insertNode(miArbol, 10));
    printf("%d\n", insertNode(miArbol, 7));
    printf("%d\n", insertNode(miArbol, 15));
    printf("%d\n", insertNode(miArbol, 4));
    printf("%d\n", insertNode(miArbol, 9));
    printf("%d\n", insertNode(miArbol, 13));
    printf("%d\n", insertNode(miArbol, 18));
    printf("%d\n", insertNode(miArbol, 2));
    printf("%d\n", insertNode(miArbol, 5));
    printf("%d\n", insertNode(miArbol, 11));
    printf("%d\n", insertNode(miArbol, 14));
    printf("%d\n", insertNode(miArbol, 5));

    inOrden(miArbol);

    deleteABB(miArbol);

    return 0;
}
