#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main() {
    printf("1-Inicializando lista...\n");
    tList* mi_lista = newList();

    printList(mi_lista);

    printf("2-Agregando elementos...\n");
    append(mi_lista, 54);
    printList(mi_lista);
    append(mi_lista, 4);
    printList(mi_lista);
    append(mi_lista, 3214);
    printList(mi_lista);
    append(mi_lista, 24);
    printList(mi_lista);
    append(mi_lista, 100);
    printList(mi_lista);
    append(mi_lista, 8367);
    printList(mi_lista);

    printf("3-Moviendo cursor a la posicion 4...\n");
    moveToPos(mi_lista, 4);
    printList(mi_lista);

    printf("4-Insertando elemento despues de la posicion 4...\n");
    insert(mi_lista,9876);
    printList(mi_lista);

    printf("5-Moviendo cursor a la posicion 6...\n");
    moveToPos(mi_lista, 6);
    printList(mi_lista);

    printf("6-Eliminando elemento...\n");
    erase(mi_lista);
    printList(mi_lista);

    printf("7-Moviendo cursor hacia atras...\n");
    prev(mi_lista);
    printList(mi_lista);

    printf("8-Eliminando elemento...\n");
    erase(mi_lista);
    printList(mi_lista);


    printf("10-Liberando memoria...\n");
    deleteList(mi_lista);
    return 0;
}
