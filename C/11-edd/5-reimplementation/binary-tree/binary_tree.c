// Compilar de forma separada:
// gcc -c binary_tree.c

#include "binary_tree.h"

tABB* newABB() {
    tABB* T = (tABB*)malloc(sizeof(tABB));

    T->root = NULL;
    T->size = 0;

    return T;
}

tABBNode* newNode(tABBElem item) {
    tABBNode* temp = (tABBNode*)malloc(sizeof(tABBNode));

    temp->info = item;
    temp->izq = NULL;
    temp->der = NULL;

    return temp;
}

tABBElem getValue(tABBNode* node) {
    return node->info;
}

int insert(tABB* T, tABBElem item) {
    printf("[1] Insertando elemento: %d\n", item);

    // Si el arbol esta vacio
    if (T->root == NULL) {
        printf("[1] La raiz esta vacia, insertando elemento: %d\n", item);
        T->root = newNode(item);
        T->size++;
        return 1;
    }

    printf("[1] La raiz no esta vacia, entrando a la raiz...\n");

    // Si hubo exito, entonces aumentar tamano
    if (insertAux(T->root, item)) {
        T->size++;
        return 1;
    } else {
        return 0;
    }
}

int insertAux(tABBNode* node, tABBElem item) {
    printf("[2] Insertando elemento: %d - Nodo actual: %d\n", item, getValue(node));

    // Si el nodo actual ya posee el elemento, entonces no hacer nada
    if (item == getValue(node)) {
        printf("[2] El elemento es igual al nodo, no hacer nada, ya existe.\n");
        return 0;
    }

    // Si el elemento es mayor al nodo actual, ir por la derecha, sino, por la izquierda
    if (item > getValue(node)) {
        printf("[2] El elemento es mayor al nodo, buscar por la derecha...\n");

        // Si no hay nada en la derecha, insertar el nodo alli
        if (node->der == NULL) {
            printf("[2] En la derecha no hay nada, insertando elemento: %d\n", item);
            node->der = newNode(item);
            return 1;
        } else {
            return insertAux(node->der, item);
        }
    } else {
        printf("[2] El elemento es menor al nodo, buscar por la izquierda...\n");

        // Si no hay nada en la izquierda, insertar el nodo alli
        if (node->izq == NULL) {
            printf("[2] En la izquierda no hay nada, insertando elemento: %d\n", item);
            node->izq = newNode(item);
            return 1;
        } else {
            return insertAux(node->izq, item);
        }
    }
}

int getSize(tABB* T) {
    return T->size;
}

int find(tABB* T, tABBElem item) {
    printf("[3] Buscando elemento: %d. Entrando en la raiz...\n", item);
    return findAux(T->root, item);
}

int findAux(tABBNode* node, tABBElem item) {
    // Si el nodo actual esta vacio, se llegó al final del arbol, no hay nada
    if (node == NULL) {
        printf("[4] Aqui no hay nada, no esta el elemento.\n");
        return 0;
    }

    printf("[4] Buscando elemento: %d - Nodo actual: %d\n", item, getValue(node));

    // Si el nodo actual ya posee el elemento, se encontró
    if (getValue(node) == item) {
        printf("[4] Se encontro el elemento.\n");
        return 1;
    }

    // Si el elemento es mayor al nodo actual, ir por la derecha, sino, por la izquierda
    if (item > getValue(node)) {
        printf("[4] El elemento es mayor al nodo, buscar por la derecha...\n");
        return findAux(node->der, item);
    } else {
        printf("[4] El elemento es menor al nodo, buscar por la izquierda...\n");
        return findAux(node->izq, item);
    }
}
