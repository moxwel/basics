// gcc -c binary_tree.c test.c && gcc binary_tree.o test.o && ./a.out

#include <stdio.h>

#include "binary_tree.h"

int main() {
    tABB* miArbol = newABB();

    insertNode(miArbol, 4);
    insertNode(miArbol, 2);
    insertNode(miArbol, 6);
    insertNode(miArbol, 1);
    insertNode(miArbol, 3);
    insertNode(miArbol, 5);
    insertNode(miArbol, 7);

    preOrden(miArbol);

    printf("=====\n");

    printf("Altura: %d\n" ,getHeight(miArbol));

    printf("=====\n");

    deleteABB(miArbol);

    return 0;
}
