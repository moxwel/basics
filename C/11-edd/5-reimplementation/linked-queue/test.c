#include <stdio.h>

#include "linked_queue.h"

int main() {
    tQueue* miQueue = newQueue();

    printQueue(miQueue);

    int input;
    int ret = -1;
    int flag = 1;
    while (flag) {
        printf("Ultimo retorno: %d\n1 - enqueue\n2 - dequeue\n3 - clear\nSeleccione accion: ", ret);
        scanf("%d",&input);

        switch (input) {
            case 1:
                printf("Accion ENQUEUE - Añadir valor: ");
                scanf("%d",&input);
                enqueue(miQueue, input);
                printQueue(miQueue);
                break;

            case 2:
                printf("Accion DEQUEUE\n");
                ret = dequeue(miQueue);
                printQueue(miQueue);
                break;

            case 3:
                printf("Accion CLEAR\n");
                clearQueue(miQueue);
                printQueue(miQueue);
                break;

            default:
                printf("No valido\n");
                flag = 0;
        }
        printf("\n");
    }

    deleteQueue(miQueue);

    return 0;
}
