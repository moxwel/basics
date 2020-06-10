#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Este archivo puede incluirse de forma individual en cualquier
// programa en el que se necesiten listas.

// Como los elementos se van a guardar en un arreglo, significa que tienen un tamaño maximo
// Suponemos que el tamaño maximo de la lista es 'MAX_SIZE'
#define MAX_SIZE 1000000
#define INVALID_ELEMENT INT_MIN



// ====================
// CREACION DEL TDA
// ====================

// Vamos a suponer que los elementos de la lista van a ser 'ints'
typedef int tElemLista;

// Se define la estructura "Lista", en este caso, basada en un arreglo
typedef struct {

    unsigned int maxSize; // El tamaño maximo del arreglo

    unsigned int listSize; // EL tamaño de la "porcion del arreglo" que se esta utilizando

    unsigned int curr; // El cursor que denota la posicion actual

    tElemLista* listArray; // El arreglo en donde se van a guardar los elementos

    // Unsigned significa "sin signo", no hay negativos. Tiene logica ya que los indices
    // de los arreglos son desde el 0 en adelante.
} tLista;



// ====================
// CREACION DE INTERFAZ
// ====================

// Inicializador de lista. Asigna memoria.
void initList(tLista *L) {
    L->maxSize = MAX_SIZE;
    L->listSize = 0;
    L->curr = 0;
    L->listArray = (tElemLista*)malloc(L->maxSize * sizeof(tElemLista));
}

// Borrar lista. Libera memoria.
void deleteList(tLista *L) {
    free(L->listArray);
}



// Insertar elemento en la ubicacion del cursor (retorna la cantidad de elementos insertados)
int insert(tLista *L, tElemLista item) {
    // Si el tamaño de la lista ya es el maximo posible, entonces no agrega nada
    if (L->listSize >= L->maxSize) {
        return 0;
    }

    // Hay que mover todos los elementos despues del cursor una casilla mas a la derecha
    unsigned int i = 0;
    for (i = L->listSize; i > L->curr; i--) {
        L->listArray[i] = L->listArray[i-1];
    }

    // Al final, la casilla en donde esta el cursor, se podra insertar el elemento deseado
    L->listArray[L->curr] = item;
    L->listSize++;
    return 1;
}

// Agregar un elemento al final de la lista (retorna la cantidad de elementos insertados)
int append(tLista *L, tElemLista item) {
    // Si el tamaño de la lista ya es el maximo posible, entonces no agrega nada
    if (L->listSize >= L->maxSize) {
        return 0;
    }

    // Agrega un elemento al final de la lista.
    L->listArray[L->listSize] = item;
    L->listSize++;
    return 1;
}

// Elimina el elemento de la ubicacion del cursor (retorna el valor eliminado)
tElemLista erase(tLista *L) {
    // Asegurarse de que no se pueden eliminar elementos si no hay nada en la lista
    if (L->listSize == 0) {
        return INVALID_ELEMENT;
    }

    // Se guarda el elemento actual para despues retornarlo
    tElemLista item = L->listArray[L->curr];

    // Si el cursor esta en la ultima posicion de la lista y
    // ademas no es el unico elemento, entonces se mueve un puesto mas atras
    if (L->curr == (L->listSize - 1) && L->listSize > 1) {
        L->curr--;
        L->listSize--;
        return item;
    }

    // Sino, hay que mover todos los elementos despues del cursor una casilla mas a la izquierda
    int i = 0;
    for (i = L->curr; i < (L->listSize - 1); i++) {
        L->listArray[i] = L->listArray[i+1];
    }

    // Al final, el tamaño de la lista disminuye
    L->listSize--;
    return item;
}

// Limpiar lista
void clear(tLista *L) {
    //Liberar y volver a declarar
    free(L->listArray);
    L->listSize = 0;
    L->curr = 0;
    L->listArray = (tElemLista*)malloc(L->maxSize * sizeof(tElemLista));
}

// Retorna el tamaño de la lista
int length(tLista *L) {
    return L->listSize;
}



// Retorna la ubicacion del cursor
int currPos(tLista *L) {
    return L->curr;
}

// Retorna el valor del cursor actual
tElemLista getValue(tLista *L) {
    return L->listArray[L->curr];
}

// Mover el cursor una casilla mas adelante
void next(tLista *L) {
    // Solo lo mueve si el cursor no esta al final de la lista
    if (L->curr < (L->listSize - 1)) {
        L->curr++;
    }
}

// Mover el cursor una casilla mas atras
void prev(tLista *L) {
    // Solo lo mueve si el cursor no esta al inicio de la lista
    if (L->curr > 0) {
        L->curr--;
    }
}

// Mover el cursor a la posicion indicada (1 = exito)
int moveToPos(tLista *L, int pos) {
    // Asegurarse que la posicion a la que se quiere mover sea valido
    if (pos < 0 || pos >= L->listSize) {
        return 0;
    }

    L->curr = pos;
    return 1;
}

// Mover el cursor hacia el inicio de la lista
void moveToStart(tLista *L) {
    L->curr = 0;
}

// Mover el cursor hacia el final de la lista
void moveToEnd(tLista *L) {
    L->curr = (L->listSize - 1);
}



// Imprimir lista
void printList(tLista *L) {
    printf("\n==========::LISTA::==========\n");
    printf("Pos:\tVal:\tLen:%i\tCur:%i\n",length(L),currPos(L));

    for (int i = 0; i < length(L); i++) {
        if (i == currPos(L)) {
            printf(">%i\t%i\n",i,L->listArray[i]);
        } else {
            printf("%i\t%i\n",i,L->listArray[i]);
        }
    }

    printf("=============================\n\n");
}
