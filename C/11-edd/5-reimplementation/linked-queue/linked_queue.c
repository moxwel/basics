// Compilar de forma separada:
// gcc -c linked_Queue.c

#include "linked_queue.h"

tQueue* newQueue(){
    // Asignar memoria para la cola
    tQueue* Q = (tQueue*)malloc(sizeof(tQueue));

    // Asignar memoria para el primer nodo
    Q->head = Q->tail = (tQueueNode*)malloc(sizeof(tQueueNode));

    Q->head->info = 0; Q->head->sig = NULL;

    Q->len = 0;

    return Q;
}

void enqueue(tQueue* Q, tQueueElem item){
    tQueueNode* aux = Q->tail;

    Q->tail->sig = (tQueueNode*)malloc(sizeof(tQueueNode));
    Q->tail->sig->info = item;
    Q->tail->sig->sig = NULL;

    Q->tail = aux->sig;

    Q->len++;
}

int dequeue(tQueue* Q){
    // Si la pila esta vacia, entonces no hacer nada
    if (getLength(Q) == 0) {
        return 0;
    }

    tQueueNode* aux = Q->head->sig;

    Q->head->sig = Q->head->sig->sig;

    // Si el nodo que se va a eliminar es el ultimo, el tail debe volver al head
    if (aux == Q->tail) {
        Q->tail = Q->head;
    }

    free(aux);

    Q->len--;

    return 1;
}

void clearQueue(tQueue* Q){
    while(dequeue(Q)){
        continue;
    }
}

void deleteQueue(tQueue* Q){
    clearQueue(Q);
    tQueueNode* aux = Q->head;

    free(aux);

    free(Q);
}

tQueueElem frontValue(tQueue* Q){
    // Si la Queuea esta vacia, retornar valor actual
    if (getLength(Q) == 0) {
        return Q->head->info;
    }

    return Q->head->sig->info;
}

int getLength(tQueue* Q){
    return Q->len;
}

void printQueue(tQueue* L){
    tQueueNode* view = L->head;

    printf("-----STACK-----\nLen: %d - Front: %d\n", getLength(L), frontValue(L));
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
