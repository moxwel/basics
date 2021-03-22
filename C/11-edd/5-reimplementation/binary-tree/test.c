// gcc -c binary_tree.c test.c && gcc binary_tree.o test.o && ./a.out

#include <stdio.h>

#include "binary_tree.h"

int main() {
    tABB* miArbol = newABB();

    printf("%d\n", insertNode(miArbol, 8));
    printf("%d\n", insertNode(miArbol, 15));
    printf("%d\n", insertNode(miArbol, 13));
    printf("%d\n", insertNode(miArbol, 20));
    printf("%d\n", insertNode(miArbol, 9));
    printf("%d\n", insertNode(miArbol, 14));

    printf("%d\n", removeNode(miArbol, 8));
    printf("%d\n", removeNode(miArbol, 13));
    printf("%d\n", removeNode(miArbol, 14));
    printf("%d\n", removeNode(miArbol, 15));
    printf("%d\n", removeNode(miArbol, 20));
    printf("%d\n", removeNode(miArbol, 9));

    printf("%d\n", getSize(miArbol));

    printf("%d\n", insertNode(miArbol, 20));
    printf("%d\n", insertNode(miArbol, 21));

    printf("%d\n", removeNode(miArbol, 20));
    printf("%d\n", removeNode(miArbol, 21));


    return 0;
}
