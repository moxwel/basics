// Compilar de forma separada:
// gcc -c linked_list.c

#include "linked_list.h"

tList* newList(){
    tList* L = (tList*)malloc(sizeof(tList));

    L->head = L->tail = L->curr = (tListNode*)malloc(sizeof(tListNode));

    L->curr->sig = NULL; L->pos = 0; L->len = 0;

    return L;
}

void insert(tList* L, tListElem item){
    tListNode* aux = L->curr->sig;

    L->curr->sig = (tListNode*)malloc(sizeof(tListNode));
    L->curr->sig->info = item;
    L->curr->sig->sig = aux;

    if (L->curr == L->tail) {
        L->tail = L->curr->sig;
    }

    L->len++;
}

void append(tList* L, tListElem item){
    tListNode* aux = L->tail;

    L->tail->sig = (tListNode*)malloc(sizeof(tListNode));
    L->tail->sig->info = item;
    L->tail->sig->sig = NULL;

    L->tail = aux->sig;

    L->len++;
}

void printList(tList* L){
    tListNode* view = L->head;
    int pos = 0;

    printf("=====LIST=====\nLen: %d - Pos: %d\n", L->len, L->pos);
    for (int i = 0; i <= L->len; i++) {
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
    if (L->len == 0) {
        return 0;
    }

    if (L->curr == L->tail) {
        prev(L);
    }

    tListNode* aux = L->curr->sig;

    L->curr->sig = L->curr->sig->sig;

    if (L->tail == aux) {
        L->tail = L->curr;
    }

    free(aux);

    L->len--;

    return 1;
}

void next(tList* L){
    if (L->curr->sig != NULL) {
        L->curr = L->curr->sig;
        L->pos++;
    }
}

void prev(tList* L){
    if (L->curr != L->head) {
        tListNode* aux = L->head;

        while (aux->sig != L->curr) {
            aux = aux->sig;
        }

        L->curr = aux;

        L->pos--;
    }
}

void clear(tList* L){
    while(erase(L)){
        continue;
    }
}

void deleteList(tList* L){
    clear(L);
    tListNode* aux = L->curr;

    free(aux);

    free(L);
}
