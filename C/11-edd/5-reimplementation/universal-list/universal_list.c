// Compilar de forma separada:
// gcc -c unviersal_list.c

#include "universal_list.h"

tList* newList(){
    // Asignar memoria para la lista
    tList* L = (tList*)malloc(sizeof(tList));

    // Asignar memoria para el primer nodo
    L->head = L->tail = L->curr = (tListNode*)malloc(sizeof(tListNode));

    L->curr->info = 0;
    L->curr->ant = NULL;
    L->curr->sig = NULL;

    L->pos = 0; L->len = 0;

    return L;
}

void insert(tList* L, tListElem item){
    tListNode* aux = L->curr->sig;

    L->curr->sig = (tListNode*)malloc(sizeof(tListNode));
    L->curr->sig->info = item;
    L->curr->sig->ant = L->curr;
    L->curr->sig->sig = aux;

    // Solo se podra modificar ant si no es el ultimo.
    if (aux != NULL) {
        aux->ant = L->curr->sig;
    }

    // Si el cursor esta al final, el tail debe moverse.
    if (L->curr == L->tail) {
        L->tail = L->curr->sig;
    }

    L->len++;
}

void append(tList* L, tListElem item){
    tListNode* aux = L->tail;

    L->tail->sig = (tListNode*)malloc(sizeof(tListNode));
    L->tail->sig->info = item;
    L->tail->sig->ant = L->tail;
    L->tail->sig->sig = NULL;

    L->tail = aux->sig;

    L->len++;
}

void printList(tList* L){
    tListNode* view = L->head;

    printf("-----LIST-----\nLen: %d - Pos: %d - Curr: %d\n", getLength(L), getPos(L), getValue(L));
    for (int i = -1; i < getLength(L); i++) {
        printf("[%d] %d ", i, view->info);
        if (L->head == view) {
            printf("| H ");
        }
        if (L->curr == view) {
            printf("| C ");
        }
        if (L->tail == view) {
            printf("| T ");
        }
        printf("\n");
        view = view->sig;
    }
    printf("==============\n");
}

int erase(tList* L){
    // Si la lista esta vacia, entonces no hacer nada
    if (getLength(L) == 0) {
        return 0;
    }

    // Si el cursor esta al final, mover cursor hacia atras
    if (L->curr == L->tail) {
        prev(L);
    }

    tListNode* aux = L->curr->sig;

    L->curr->sig = L->curr->sig->sig;

    // Si el tail esta en el nodo a eliminarse, el tail debe moverse.
    if (aux != L->tail) {
        aux->sig->ant = L->curr;
    } else {
        L->tail = L->curr;
    }

    free(aux);

    L->len--;

    return 1;
}

int next(tList* L){
    // Si la lista esta vacia, entonces no hacer nada
    if (getLength(L) == 0) {
        return 0;
    }

    // Se puede mover hacia adelante hasta que el cursor llegue al tail
    if (L->curr != L->tail) {
        L->curr = L->curr->sig;
        L->pos++;
        return 1;
    }

    return 0;
}

int prev(tList* L){
    // Si la lista esta vacia, entonces no hacer nada
    if (getLength(L) == 0) {
        return 0;
    }

    // Se puede mover hacia atras hasta que el cursor llegue al head
    if (L->curr != L->head) {
        L->curr = L->curr->ant;
        L->pos--;
        return 1;
    }

    return 0;
}

void clearList(tList* L){
    while(erase(L)){
        continue;
    }
}

void deleteList(tList* L){
    clearList(L);
    tListNode* aux = L->curr;

    free(aux);

    free(L);
}

tListElem getValue(tList* L){
    // Si la lista esta vacia, retornar valor actual
    if (getLength(L) == 0) {
        return L->curr->info;
    }

    // Si el cursor esta al final, retornar valor actual
    if (L->curr == L->tail) {
        return L->curr->info;
    }

    return L->curr->sig->info;
}

int getLength(tList* L){
    return L->len;
}

int getPos(tList* L){
    return L->pos;
}

int moveToPos(tList* L, int target){
    // Si la posicion es negativa, es invalido
    if (target < 0) {
        return 0;
    }

    // Si la posicion sale del rango, es invalido
    if (target >= getLength(L)) {
        return 0;
    }

    moveToStart(L);

    for (int i = 0; i < target; i++) {
        next(L);
    }

    return 1;

}

void moveToStart(tList* L){
    L->curr = L->head;
    L->pos = 0;
}

void moveToEnd(tList* L){
    L->curr = L->tail;
    L->pos = getLength(L);
}
