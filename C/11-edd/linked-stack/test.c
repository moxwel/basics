#include <stdio.h>

#include "linked_stack.h"

int main() {
    tStack* miStack = newStack();

    printStack(miStack);

    int input;
    int ret = -1;
    int flag = 1;
    while (flag) {
        printf("Ultimo retorno: %d\n1 - push\n2 - pop\n3 - clear\nSeleccione accion: ", ret);
        scanf("%d",&input);

        switch (input) {
            case 1:
                printf("Accion PUSH - Añadir valor: ");
                scanf("%d",&input);
                push(miStack, input);
                printStack(miStack);
                break;

            case 2:
                printf("Accion POP\n");
                ret = pop(miStack);
                printStack(miStack);
                break;

            case 3:
                printf("Accion CLEAR\n");
                clearStack(miStack);
                printStack(miStack);
                break;

            default:
                printf("No valido\n");
                flag = 0;
        }
        printf("\n");
    }

    deleteStack(miStack);

    return 0;
}
