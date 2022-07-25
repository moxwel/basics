#include <stdio.h>

#include "universal_list.h"

int main() {
    tList* miLista = newList();

    printList(miLista);

    int input;
    int ret = -1;
    int flag = 1;
    while (flag) {
        printf("Ultimo retorno: %d\n1 - prev = 11 - start\n2 - next = 22 - end\n3 - insert = 33 - push = 333 - enqueue\n4 - append\n5 - erase = 55 - pop = 555 - dequeue\n6 - clear\n7 - movetopos\nSeleccione accion: ", ret);
        scanf("%d",&input);

        switch (input) {
            case 1:
                printf("Accion PREV\n");
                ret = prev(miLista);
                printList(miLista);
                break;

            case 11:
                printf("Accion START\n");
                moveToStart(miLista);
                printList(miLista);
                break;

            case 2:
                printf("Accion NEXT\n");
                ret = next(miLista);
                printList(miLista);
                break;

            case 22:
                printf("Accion END\n");
                moveToEnd(miLista);
                printList(miLista);
                break;

            case 3:
                printf("Accion INSERT - Añadir valor: ");
                scanf("%d",&input);
                insert(miLista, input);
                printList(miLista);
                break;

            case 33:
                printf("Accion PUSH - Añadir valor: ");
                scanf("%d",&input);
                push(miLista, input);
                printList(miLista);
                break;

            case 333:
                printf("Accion ENQUEUE - Añadir valor: ");
                scanf("%d",&input);
                enqueue(miLista, input);
                printList(miLista);
                break;

            case 4:
                printf("Accion APPEND - Añadir valor: ");
                scanf("%d",&input);
                append(miLista, input);
                printList(miLista);
                break;

            case 5:
                printf("Accion ERASE\n");
                ret = erase(miLista);
                printList(miLista);
                break;

            case 55:
                printf("Accion POP\n");
                ret = pop(miLista);
                printList(miLista);
                break;

            case 555:
                printf("Accion DEQUEUE\n");
                ret = dequeue(miLista);
                printList(miLista);
                break;

            case 6:
                printf("Accion CLEAR\n");
                clearList(miLista);
                printList(miLista);
                break;

            case 7:
                printf("Accion MOVETOPOS - Posicion: ");
                scanf("%d",&input);
                ret = moveToPos(miLista, input);
                printList(miLista);
                break;

            case 0:
                flag = 0;
                break;

            default:
                printf("No valido\n");
        }
        printf("\n");
    }

    deleteList(miLista);

    return 0;
}
