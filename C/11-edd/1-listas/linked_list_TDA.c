#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INVALID_ELEMENT INT_MIN

// ====================
// CREACION DEL TDA
// ====================

// Vamos a suponer que los elementos de la lista van a ser 'ints'
typedef int tElemLista;

// Vamos a definir un nuevo tipo 'tNodo'. Posee dos celdas:
typedef struct nodo {

    tElemLista info; // El elemento que se va a almacenar

    struct nodo *sig; // Un puntero al nodo siguiente.

    // Notese que el tipo que estamos redefiniendo como 'tNodo' es un 'struct nodo'.
    // Y el puntero 'sig' esta apuntando a un tipo 'struct nodo', es decir, el mismo tipo.

    // En otras palabras, el puntero va a apuntar a otro nodo.
    // El conjunto de estas dos variables es lo que nosotros llamaremos 'tNodo'.
} tNodo;

// Se define la estructura "Lista", en este caso, enlazada.
typedef struct {

    tNodo* head; // Puntero al nodo que esta en la cabeza de la lista

    tNodo* curr; // Puntero al nodo donde esta ubicado el cursor
    // Vale la pena mencionar que el "elemento actual" sera el nodo siguiente al cursor (auxiliar)

    tNodo* tail; // Puntero al nodo que esta en la cola de la lista

    unsigned int listSize; // El tamaño de la lista, es decir, la cantidad de nodos

    unsigned int pos; // Posicion actual en la lista

} tLista;



// ====================
// CREACION DE INTERFAZ
// ====================

// Inicializador de lista.
void initList(tLista *L) {
    // Head, Curr, y Tail van a apuntar al primer nodo 'cabecera'
    L->head = L->curr = L->tail = (tNodo*)malloc(sizeof(tNodo));

    L->curr->info = -1;
    L->curr->sig = NULL;

    // Comienza con tamaño 1
    L->listSize = 1;
    L->pos = 0;
}

// Borrar lista. Hay que liberar de la memoria a cada nodo.
void deleteList(tLista *L) {
    // Se mueve el cursor al head
    L->curr = L->head;
    L->pos = 0;

    // Puntero auxiliar. Apunta al nodo siguiente del cursor.
    tNodo* aux;

    // Ir eliminando uno a uno hasta que no hayan mas nodos
    while (L->listSize != 0) {
        aux = L->curr->sig;

        L->curr->sig = L->curr->sig->sig;

        free(aux);

        L->listSize--;
    }
}



// Insertar elemento despues del cursor
int insert(tLista *L, tElemLista item) {
    // Puntero auxiliar. Apunta al nodo siguiente del cursor.
    tNodo* aux = L->curr->sig;

    // Hacemos que el nodo del cursor apunte a un nuevo nodo, "desconectandolo" del anterior
    L->curr->sig = (tNodo*)malloc(sizeof(tNodo));

    // En el nodo siguiente al cursor (el que acabamos de crear), ingresamos sus campos:
    L->curr->sig->info = item; // Su campo de elemento "info"
    L->curr->sig->sig  = aux;  // Hacemos que el nodo nuevo apunte al auxiliar, que viene siendo el siguiente.

    // Caso especial: si el cursor coincide con el tail de la lista, entonces
    // el tail se cambia y apunta al nuevo nodo que acabamos de crear, que es el ultimo.
    if (L->curr == L->tail) {
        L->tail = L->curr->sig;
    }

    // Al agregar elementos, es necesario aumentar el numero que nos indica el tamaño de la lista
    L->listSize++;

    return L->pos;
}

// Insertar elemento al final de la lista
int append(tLista *L, tElemLista item) {
    // Puntero auxiliar. Apunta al ultimo nodo de la lista.
    tNodo* aux = L->tail;

    // Hacemos que el nodo del auxiliar apunte a un nuevo nodo.
    aux->sig = (tNodo*)malloc(sizeof(tNodo));

    // En el nodo siguiente al auxiliar (el que acabamos de crear), ingresamos sus campos:
    aux->sig->info = item; // Su campo de elemento "info"
    aux->sig->sig  = NULL;  // Hacemos que este ultimo nodo apunte a NULL.

    // Ahora el puntero 'tail' debe apuntar al siguiente del auxiliar.
    L->tail = aux->sig;

    // Al agregar elementos, es necesario aumentar el numero que nos indica el tamaño de la lista
    L->listSize++;

    return 1;
}

// Eliminar elemento despues del cursor (se retorna el elemento que se borra)
tElemLista erase(tLista *L) {
    // Si el cursor esta en la misma posicion que la cola, entonces no se puede borrar el elemento siguiente (NULL).
    // Ademas, tampoco se puede borrar elementos si la lista esta vacia.
    if (L->curr == L->tail || L->listSize == 0) {
        return INVALID_ELEMENT;
    }

    // Variable que va a almacenar el elemento antes de borrarlo, para despues retornarlo
    tElemLista elem = L->curr->sig->info;

    // Puntero auxiliar. Apunta al nodo siguiente del cursor.
    tNodo* aux = L->curr->sig;

    // Hacemos que el nodo del cursor apunte al siguiente nodo del auxiliar, "desconectandolo" del siguiente al cursor.
    L->curr->sig = L->curr->sig->sig;

    // Si el auxiliar (el que se va a eliminar) es el tail, entonces hay que mover el 'tail' a la posicion del cursor.
    if (aux == L->tail) {
        L->tail = L->curr;
    }

    // Liberamos de la memoria al auxiliar, es decir, el nodo siguiente al cursor
    free(aux);

    // Al eliminar elementos, es necesario disminiur el numero que nos indica el tamaño de la lista
    L->listSize--;

    return elem;
}

// Reinicializa una lista, liberando memoria, y dejandolo vacio
void clear(tLista *L) {
    // Se mueve el cursor al head
    L->curr = L->head;
    L->tail = L->curr;
    L->pos = 0;

    // Puntero auxiliar. Apunta al nodo siguiente del cursor.
    tNodo* aux;

    // Ir eliminando uno a uno hasta que no hayan mas nodos
    while (L->listSize != 1) {
        aux = L->curr->sig;

        L->curr->sig = L->curr->sig->sig;

        free(aux);

        L->listSize--;
    }
}

// Retorna el tamaño de la lista
int length(tLista *L) {
    return L->listSize;
}



// Retorna la ubicacion del cursor
int currPos(tLista *L) {
    return L->pos;
}

// Retorna el valor del elemento siguiente al actual
tElemLista getValue(tLista *L) {
    if (L->curr == L->tail) {
        return INVALID_ELEMENT;
    }
    return L->curr->sig->info;
}

// Mover el cursor un puesto hacia adelante
void next(tLista *L) {
    // Hay que asegurarse que el cursor no esta en la cola, de forma contraria, ya no hay
    // mas elementos siguientes
    if (L->curr != L->tail) {
        L->curr = L->curr->sig;
        L->pos++;
    }
}

// Mover el cursor un puesto hacia atras
void prev(tLista *L) {
    // No hay forma de ver el elemento anterior en una lista enlazada simple.
    // El unico puntero que hay en cada nodo es al elemento siguiente.

    // Hay que asegurarse que el cursor no esta en la cabeza, de forma contraria, ya no hay
    // mas elementos anteriores
    if (L->curr != L->head) {

        // Es necesario crear un puntero temporal que apunte al nodo head, y recorrer toda la lista, hasta llegar al cursor actual
        tNodo *temp = L->head;

        // Si el nodo siguiente al 'temp' no es el cursor, se sigue avanzando
        while (temp->sig != L->curr) {
            temp = temp->sig;
        }

        // Cuando el nodo temporal este justo antes del cursor, ya estamos en el nodo anterior del cursor
        L->curr = temp;

        L->pos--;
    }
}

// Mover el cursor a una posicion determinada (1 = exito)
int moveToPos(tLista *L, int pos) {
    // Asegurarse que la posicion a la que se quiere mover sea valido
    if (pos < 0 || pos >= L->listSize) {
        return 0;
    }

    // Se movera el cursor al head, y se movera el cursor tantas veces como posiciones sean
    L->curr = L->head;
    L->pos = 0;

    for (int i = 0; i < pos; i++) {
        L->curr = L->curr->sig;
        L->pos++;
    }

    return 1;
}

// Mover el cursor hacia el inicio de la lista
void moveToStart(tLista *L) {
    L->curr = L->head;
    L->pos = 0;
}

// Mover el cursor hacia el final de la lista
void moveToEnd(tLista *L) {
    L->curr = L->tail;
    L->pos = (L->listSize - 1);
}



// Imprimir lista
void printList(tLista *L) {
    tNodo* aux = L->head;

    printf("\n==========::LISTA::==========\n");
    printf("Len:%i\tCur:%i\tVal:%i\nHead:%p\tTail:%p\n\n",length(L),currPos(L),getValue(L),L->head,L->tail);

    printf("Mem:\t\tPos:\tInfo:\tSig:\n");

    for (int i = 0; i < length(L); i++) {

        printf("%p\t", aux);

        if (i == currPos(L)) {
            printf(">");
        }
        if (i == currPos(L) + 1) {
            printf(">>");
        }

        printf("%i ", i);

        if (aux == L->head) {
            printf("H");
        }
        if (aux == L->tail) {
            printf("T");
        }

        printf("\t%i\t%p\n",aux->info,aux->sig);

        aux = aux->sig;
    }

    printf("=============================\n\n");
}
