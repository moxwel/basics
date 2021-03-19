// Compilar de forma separada:
// gcc -c linked_stack.c

#include "linked_stack.h"

tStack* newStack(){
    // Asignar memoria para la pila
    tStack* S = (tStack*)malloc(sizeof(tStack));

    // Asignar memoria para el primer nodo
    S->head = S->tail = (tStackNode*)malloc(sizeof(tStackNode));

    S->tail->info = 0; S->tail->sig = NULL;

    S->len = 0;

    return S;
}

void push(tStack* S, tStackElem item){
    tStackNode* aux = S->tail;

    S->tail->sig = (tStackNode*)malloc(sizeof(tStackNode));
    S->tail->sig->info = item;
    S->tail->sig->sig = NULL;

    S->tail = aux->sig;

    S->len++;
}


int pop(tStack* S){
    // Si la pila esta vacia, entonces no hacer nada
    if (getLength(S) == 0) {
        return 0;
    }

    // Establecer un puntero auxiliar que apunte al penultimo nodo
    tStackNode* penult = S->head;

    while (penult->sig != S->tail) {
        penult = penult->sig;
    }

    tStackNode* aux = penult->sig;

    penult->sig = penult->sig->sig;

    S->tail = penult;

    free(aux);

    S->len--;

    return 1;
}



void clearStack(tStack* S){
    while(pop(S)){
        continue;
    }
}

void deleteStack(tStack* S){
    clearStack(S);
    tStackNode* aux = S->tail;

    free(aux);

    free(S);
}

tStackElem topValue(tStack* S){
    // Si la pila esta vacia, retornar valor actual
    if (getLength(S) == 0) {
        return S->tail->info;
    }

    return S->tail->info;
}

int getLength(tStack* S){
    return S->len;
}

void printStack(tStack* L){
    tStackNode* view = L->head;

    printf("-----STACK-----\nLen: %d - Top: %d\n", getLength(L), topValue(L));
    for (int i = -1; i < getLength(L); i++) {
        printf("[%d] %d ", i, view->info);
        if (L->head == view) {
            printf("| H ");
        }
        if (L->tail == view) {
            printf("| T ");
        }
        printf("\n");
        view = view->sig;
    }
    printf("==============\n");
}
