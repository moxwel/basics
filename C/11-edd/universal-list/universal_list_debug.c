// Compilar de forma separada:
// gcc -c unviersal_list_debug.c

#include "universal_list.h"

tList* newList() {
    printf("[newList] Creando lista nueva. Asignando memoria...\n");

    // Asignar memoria para la lista
    tList* L = (tList*)malloc(sizeof(tList));

    printf("[newList] Creando primer nodo. Asignando memoria...\n");
    // Asignar memoria para el primer nodo
    L->head = L->tail = L->curr = (tListNode*)malloc(sizeof(tListNode));

    L->curr->info = 0;
    L->curr->ant = NULL;
    L->curr->sig = NULL;

    L->pos = 0; L->len = 0;

    return L;
}

void insert(tList* L, tListElem item) {
    printf("[insert] Insertando elemento despues del cursor. Asignando memoria...\n");
    tListNode* aux = L->curr->sig;

    L->curr->sig = (tListNode*)malloc(sizeof(tListNode));
    L->curr->sig->info = item;
    L->curr->sig->ant = L->curr;
    L->curr->sig->sig = aux;

    // Solo se podra modificar ant si no es el ultimo.
    if (aux != NULL) {
        printf("[insert] Cambiando puntero -ant- del elemento siguiente al insertado.\n");
        aux->ant = L->curr->sig;
    }

    // Si el cursor esta al final, el tail debe moverse.
    if (L->curr == L->tail) {
        printf("[insert] El cursor estaba en el tail. Moviendo tail.\n");
        L->tail = L->curr->sig;
    }

    printf("[insert] Aumentando tamano...\n");
    L->len++;
}

void append(tList* L, tListElem item) {
    printf("[append] Insertando elemento despues del tail. Asignando memoria...\n");
    tListNode* aux = L->tail;

    L->tail->sig = (tListNode*)malloc(sizeof(tListNode));
    L->tail->sig->info = item;
    L->tail->sig->ant = L->tail;
    L->tail->sig->sig = NULL;

    printf("[append] Cambiando tail al elemento siguiente...\n");
    L->tail = aux->sig;

    printf("[append] Aumentando tamano...\n");
    L->len++;
}

void printList(tList* L) {
    tListNode* view = L->head;

    printf("-----LIST-----\nLen: %d - Pos: %d - Curr: %d - Front: %d - Top: %d\n", getLength(L), getPos(L), getValue(L), frontValue(L), topValue(L));
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

int erase(tList* L) {
    printf("[erase] Eliminando elemento siguiente al cursor...\n");
    // Si la lista esta vacia, entonces no hacer nada
    if (getLength(L) == 0) {
        printf("[erase] La lista esta vacia, no hacer nada.\n");
        return 0;
    }

    // Si el cursor esta al final, mover cursor hacia atras
    if (L->curr == L->tail) {
        printf("[erase] El cursor esta en el tail, mover cursor hacia atras...\n");
        prev(L);
    }

    printf("[erase] Cambiando puntero -sig- del elemento del cursor...\n");
    tListNode* aux = L->curr->sig;
    L->curr->sig = L->curr->sig->sig;

    // Si el tail esta en el nodo a eliminarse, el tail debe moverse.
    if (aux != L->tail) {
        printf("[erase] Cambiando puntero -ant- del elemento siguiente al elemento a eliminar...\n");
        aux->sig->ant = L->curr;
    } else {
        printf("[erase] El nodo a eliminar esta en el tail. Moviendo tail...\n");
        L->tail = L->curr;
    }

    printf("[erase] Liberando memoria...\n");
    free(aux);

    printf("[erase] Disminuyendo tamano...\n");
    L->len--;

    return 1;
}

int next(tList* L) {
    printf("[next] Mover cursor hacia adelante...\n");

    // Si la lista esta vacia, entonces no hacer nada
    if (getLength(L) == 0) {
        printf("[next] La lista esta vacia, no hacer nada.\n");
        return 0;
    }

    // Se puede mover hacia adelante hasta que el cursor llegue al tail
    if (L->curr != L->tail) {
        printf("[next] Cambiando cursor al siguiente. Aumentando posicion.\n");
        L->curr = L->curr->sig;
        L->pos++;
        return 1;
    } else {
        printf("[next] El cursor esta en el tail, no hacer nada.\n");
    }

    return 0;
}

int prev(tList* L) {
    printf("[prev] Mover cursor hacia atras...\n");

    // Si la lista esta vacia, entonces no hacer nada
    if (getLength(L) == 0) {
        printf("[prev] La lista esta vacia, no hacer nada.\n");
        return 0;
    }

    // Se puede mover hacia atras hasta que el cursor llegue al head
    if (L->curr != L->head) {
        printf("[prev] Cambiando cursor al anterior. Disminuyendo posicion.\n");
        L->curr = L->curr->ant;
        L->pos--;
        return 1;
    } else {
        printf("[prev] El cursor esta en el head, no hacer nada.\n");
    }

    return 0;
}

void clearList(tList* L) {
    printf("[clearList] Limpiando lista...\n");
    while(erase(L)) {
        continue;
    }
    printf("[clearList] Terminado.\n");
}

void deleteList(tList* L) {
    printf("[deleteList] Eliminando lista...\n");
    clearList(L);
    tListNode* aux = L->curr;

    printf("[deleteList] Liberando memoria de primer elemento...\n");
    free(aux);

    printf("[deleteList] Liberando memoria de TDA...\n");
    free(L);
}

tListElem getValue(tList* L) {
    // Si la lista esta vacia, retornar valor actual
    if (getLength(L) == 0) {
        printf("[getValue] Lista vacia, devolviendo valor del head.\n");
        return L->curr->info;
    }

    // Si el cursor esta al final, retornar valor actual
    if (L->curr == L->tail) {
        printf("[getValue] Cursor en tail, devolviendo valor del tail.\n");
        return L->curr->info;
    }

    return L->curr->sig->info;
}

int getLength(tList* L) {
    return L->len;
}

int getPos(tList* L) {
    return L->pos;
}

int moveToPos(tList* L, int target) {
    printf("[moveToPos] Moviendo cursor a la posicion %d...\n", target);

    // Si la posicion es negativa, es invalido
    if (target < 0) {
        printf("[moveToPos] Posicion negativa, invalido. No hacer nada.\n");
        return 0;
    }

    // Si la posicion sale del rango, es invalido
    if (target >= getLength(L)) {
        printf("[moveToPos] Posicion fuera del rango, invalido. No hacer nada\n");
        return 0;
    }

    moveToStart(L);

    printf("[moveToPos] Avanzar posiciones correspondientes.\n");
    for (int i = 0; i < target; i++) {
        next(L);
    }

    printf("[moveToPos] Listo.\n");
    return 1;

}

void moveToStart(tList* L) {
    printf("[moveToStart] Cambiando cursor y posicion a 0.\n");
    L->curr = L->head;
    L->pos = 0;
}

void moveToEnd(tList* L) {
    printf("[moveToEnd] Cambiando cursor y posicion a %d.\n", getLength(L));
    L->curr = L->tail;
    L->pos = getLength(L);
}

void push(tList* L, tListElem item) {
    printf("[push] Ingresando elemento al final de la lista.\n");
    append(L, item);
}

int pop(tList* L) {
    printf("[pop] Eliminando el ultimo elemento de la lista.\n");
    int ret = 0;

    // Si la lista esta vacia, entonces no hacer nada
    if (getLength(L) == 0) {
        printf("[pop] Lista vacia, no hacer nada.\n");
        return ret;
    }

    // Si el cursor no esta al final, guardar ubicacion actual del cursor para no modificarlo
    if (L->curr != L->tail) {
        printf("[pop] El cursor no esta en el tail, guardar posicion actual.\n");
        tListNode* tempCurr = L->curr;
        int tempPos = L->pos;

        moveToEnd(L);
        ret = erase(L);

        printf("[pop] Devolver posicion anterior del cursor: %d.\n", tempPos);
        L->curr = tempCurr;
        L->pos = tempPos;
    } else {
        printf("[pop] El cursor esta en el tail, eliminacion simple.\n");

        // El cursor esta al final
        ret = erase(L);
    }

    printf("[pop] Listo.\n");
    return ret;
}

tListElem topValue(tList* L) {
    return L->tail->info;
}


void enqueue(tList* L, tListElem item) {
    printf("[enqueue] Ingresando elemento al final de la lista.\n");
    append(L, item);
}

int dequeue(tList* L) {
    printf("[dequeue] Eliminando el primer elemento de la lista.\n");
    int ret = 0;

    // Si la lista esta vacia, entonces no hacer nada
    if (getLength(L) == 0) {
        printf("[dequeue] Lista vacia, no hacer nada.\n");
        return ret;
    }

    // Si el nodo anterior no es el head, guardar ubicacion actual del cursor para no modificarlo
    if (L->curr->ant != L->head) {
        printf("[dequeue] El elemento anterior al cursor no es el head, guardar posicion actual...\n");
        tListNode* temp = L->curr;
        int tempPos = L->pos;

        moveToStart(L);
        ret = erase(L);

        L->curr = temp;

        // Cuando se elimina un elemento, su posicion debe disminuir, excepto cuando es el head
        if (L->curr != L->head) {
            printf("[dequeue] El cursor es diferente al head, disminuir posicion.\n");
            L->pos = tempPos - 1;
        } else {
            printf("[dequeue] El cursor esta en el head, no disminuir posicion, ya es 0.\n");
        }
    } else {
        printf("[dequeue] El elemento anterior al cursor es el head, mover cursor alli.\n");
        // El cursor esta justo despues del head
        moveToStart(L);
        ret = erase(L);
    }

    printf("[dequeue] Listo.\n");
    return ret;
}

tListElem frontValue(tList* L) {
    // Si la lista esta vacia, retornar valor del head
    if (getLength(L) == 0) {
        printf("[frontValue] Lista vacia, devolviendo valor del head.\n");
        return L->head->info;
    }

    return L->head->sig->info;
}
