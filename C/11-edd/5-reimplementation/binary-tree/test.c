// gcc -c binary_tree.c test.c && gcc binary_tree.o test.o && ./a.out

#include <stdio.h>

#include "binary_tree.h"

int main() {
    tABB* miArbol = newABB();

    insertNode(miArbol, 10);
    insertNode(miArbol, 7);
    insertNode(miArbol, 15);
    insertNode(miArbol, 4);
    insertNode(miArbol, 9);
    insertNode(miArbol, 13);
    insertNode(miArbol, 18);
    insertNode(miArbol, 2);
    insertNode(miArbol, 5);
    insertNode(miArbol, 11);
    insertNode(miArbol, 14);
    insertNode(miArbol, 5);

    inOrden(miArbol);

    deleteABB(miArbol);

    return 0;
}
