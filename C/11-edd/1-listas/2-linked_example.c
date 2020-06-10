#include <stdio.h>
#include <stdlib.h>
#include "./linked_list_TDA.c"

int main() {
    tLista mi_lista;
    tLista *pl = &mi_lista;

    printf("1-Inicializando lista...\n");
    initList(pl);
    printList(pl);

    printf("2-Agregando elementos...\n");
    append(pl, 54);
    append(pl, 4);
    append(pl, 3214);
    append(pl, 24);
    append(pl, 100);
    append(pl, 8367);
    printList(pl);

    printf("3-Moviendo cursor a la posicion 4...\n");
    moveToPos(pl, 4);
    printList(pl);

    printf("4-Insertando elemento despues de la posicion 4...\n");
    insert(pl,9876);
    printList(pl);

    printf("5-Moviendo cursor a la posicion 6...\n");
    moveToPos(pl, 6);
    printList(pl);

    printf("6-Eliminando elemento %i...\n",erase(pl));
    printList(pl);

    printf("7-Moviendo cursor hacia atras\n");
    prev(pl);
    printList(pl);

    printf("8-Eliminando elemento %i...\n",erase(pl));
    printList(pl);

    clear(pl);

    printList(pl);
    return 0;
}
