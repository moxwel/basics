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
    if (node != NULL) {
        return node->info;
    } else {
        return -1;
    }
}

int insertNode(tABB* T, tABBElem item) {
    // Si el arbol esta vacio
    if (T->root == NULL) {
        T->root = newNode(item);
        T->size++;
        return 1;
    }

    // Si hubo exito, entonces aumentar tamano
    if (insertAux(T->root, item)) {
        T->size++;
        return 1;
    } else {
        return 0;
    }
}

int insertAux(tABBNode* node, tABBElem item) {
    // Si el nodo actual ya posee el elemento, entonces no hacer nada
    if (item == getValue(node)) {
        return 0;
    }

    // Si el elemento es mayor al nodo actual, ir por la derecha, sino, por la izquierda
    if (item > getValue(node)) {
        // Si no hay nada en la derecha, insertar el nodo alli
        if (node->der == NULL) {
            node->der = newNode(item);
            return 1;
        } else {
            return insertAux(node->der, item);
        }
    } else {
        // Si no hay nada en la izquierda, insertar el nodo alli
        if (node->izq == NULL) {
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

int findNode(tABB* T, tABBElem item) {
    return findAux(T->root, item);
}

int findAux(tABBNode* node, tABBElem item) {
    // Si el nodo actual esta vacio, se llegó al final del arbol, no hay nada
    if (node == NULL) {
        return 0;
    }

    // Si el nodo actual ya posee el elemento, se encontró
    if (getValue(node) == item) {
        return 1;
    }

    // Si el elemento es mayor al nodo actual, ir por la derecha, sino, por la izquierda
    if (item > getValue(node)) {
        return findAux(node->der, item);
    } else {
        return findAux(node->izq, item);
    }
}

int removeNode(tABB* T, tABBElem item) {
    // Solo borrar elementos si es que existe
    if (findNode(T, item)) {
        // Si la raiz es el unico nodo que hay en el arbol, hay que borrarlo, si no, hay que buscar en el arbol
        if ((T->root->der == NULL) && (T->root->izq == NULL)) {
            free(T->root);
            T->root = NULL;
        } else {
            removeAux(T, T->root, T->root, item);
        }

        T->size--;
        return 1;
    } else {
        return 0;
    }
}

void removeAux(tABB* T, tABBNode* node, tABBNode* penult, tABBElem item) {
    // Si se encuentra el nodo, borrarlo
    if (getValue(node) == item) {

        // Caso 1: El nodo es una hoja
        if ((node->izq == NULL) && (node->der == NULL)) {
            // Dependiendo del lugar donde esta el hijo, hay que cambiar los punteros del padre
            if (item > getValue(penult)) {
                penult->der = NULL;
            } else {
                penult->izq = NULL;
            }

            free(node);
        }

        // Caso 2: El nodo tiene solo un hijo (derecho)
        else if ((node->izq == NULL) && (node->der != NULL)) {
            // Si el nodo a eliminar es la raiz, hay que cambiar los punteros del TDA
            if (node == T->root) {
                T->root = node->der;
                free(node);
                return;
            }

            // Dependiendo del lugar donde esta el hijo, hay que cambiar los punteros del padre
            if (item > getValue(penult)) {
                penult->der = node->der;
            } else {
                penult->izq = node->der;
            }

            free(node);

        }

        // Caso 3: El nodo tiene solo un hijo (izquierdo)
        else if ((node->izq != NULL) && (node->der == NULL)) {
            // Si el nodo a eliminar es la raiz, hay que cambiar los punteros del TDA
            if (node == T->root) {
                T->root = node->izq;
                free(node);
                return;
            }

            // Dependiendo del lugar donde esta el hijo, hay que cambiar los punteros del padre
            if (item > getValue(penult)) {
                penult->der = node->izq;
            } else {
                penult->izq = node->izq;
            }

            free(node);
        }

        // Caso 4: El nodo tiene dos hijos
        else if ((node->izq != NULL) && (node->der != NULL)) {
            tABBNode* temp = sucesor(node);
            tABBElem valor = getValue(temp);

            // Eliminar el sucesor y reemplazar el valor
            removeNode(T, valor);
            node->info = valor;

            // Contrarrestar la disminucion duplicada del tamano del arbol
            T->size++;
        }

        return;
    }

    // Seguir buscando si no se encuentra el elemento
    if (item > getValue(node)) {
        return removeAux(T, node->der, node, item);
    } else {
        return removeAux(T, node->izq, node, item);
    }
}

tABBNode* sucesor(tABBNode* node) {
    tABBNode* succ = node;

    // Si es posible, moverse una vez hacia la derecha y luego todo lo que se pueda hacia la izquierda
    if (node->der != NULL) {
        succ = node->der;
    } else {
        return succ;
    }

    while (succ->izq != NULL) {
        succ = succ->izq;
    }

    return succ;
}

void clearABB(tABB* T) {
    while (T->root != NULL) {
        removeNode(T, getValue(T->root));
    }
}

void deleteABB(tABB* T) {
    clearABB(T);
    free(T);
}

void preOrden(tABB* T) {
    preOrdenAux(T->root);
}

void preOrdenAux(tABBNode* node) {
    // Ya no hay mas profundidad, devolverse un nodo hacia arriba
    if (node == NULL) {
        return;
    }

    printf("[preOrdenAux] Nodo actual: %d\n", getValue(node));

    preOrdenAux(node->izq);

    preOrdenAux(node->der);
}

void inOrden(tABB* T) {
    inOrdenAux(T->root);
}

void inOrdenAux(tABBNode* node) {
    // Ya no hay mas profundidad, devolverse un nodo hacia arriba
    if (node == NULL) {
        return;
    }

    inOrdenAux(node->izq);

    printf("[inOrdenAux] Nodo actual: %d\n", getValue(node));

    inOrdenAux(node->der);
}

void postOrden(tABB* T) {
    postOrdenAux(T->root);
}

void postOrdenAux(tABBNode* node) {
    // Ya no hay mas profundidad, devolverse un nodo hacia arriba
    if (node == NULL) {
        return;
    }

    postOrdenAux(node->izq);

    postOrdenAux(node->der);

    printf("[postOrdenAux] Nodo actual: %d\n", getValue(node));
}
