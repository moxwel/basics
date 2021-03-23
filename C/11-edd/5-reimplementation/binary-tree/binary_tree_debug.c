// Compilar de forma separada:
// gcc -c binary_tree_debug.c

#include "binary_tree.h"

tABB* newABB() {
    printf("[newABB] Creando arbol nuevo. Asignando memoria...\n");
    tABB* T = (tABB*)malloc(sizeof(tABB));

    T->root = NULL;
    T->size = 0;

    return T;
}

tABBNode* newNode(tABBElem item) {
    printf("[newNode] Creando nodo nuevo con elemento: %d. Asignando memoria...\n", item);
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
    printf("[insertNode] Insertando elemento: %d\n", item);

    // Si el arbol esta vacio
    if (T->root == NULL) {
        printf("[insertNode] La raiz esta vacia, insertando elemento: %d. Y aumentando tamano...\n", item);
        T->root = newNode(item);
        T->size++;
        return 1;
    }

    printf("[insertNode] La raiz no esta vacia, entrando a la raiz...\n");

    // Si hubo exito, entonces aumentar tamano
    if (insertAux(T->root, item)) {
        printf("[insertNode] Insercion con exito, aumentando tamano...\n");
        T->size++;
        return 1;
    } else {
        printf("[insertNode] Insercion sin exito, no aumentar tamano.\n");
        return 0;
    }
}

int insertAux(tABBNode* node, tABBElem item) {
    printf("[insertAux] Insertando elemento: %d - Nodo actual: %d\n", item, getValue(node));

    // Si el nodo actual ya posee el elemento, entonces no hacer nada
    if (item == getValue(node)) {
        printf("[insertAux] El elemento es igual al nodo, no hacer nada, ya existe.\n");
        return 0;
    }

    // Si el elemento es mayor al nodo actual, ir por la derecha, sino, por la izquierda
    if (item > getValue(node)) {
        printf("[insertAux] El elemento es mayor al nodo, buscar por la derecha...\n");

        // Si no hay nada en la derecha, insertar el nodo alli
        if (node->der == NULL) {
            printf("[insertAux] En la derecha no hay nada, insertando elemento: %d\n", item);
            node->der = newNode(item);
            return 1;
        } else {
            return insertAux(node->der, item);
        }
    } else {
        printf("[insertAux] El elemento es menor al nodo, buscar por la izquierda...\n");

        // Si no hay nada en la izquierda, insertar el nodo alli
        if (node->izq == NULL) {
            printf("[insertAux] En la izquierda no hay nada, insertando elemento: %d\n", item);
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
    printf("[findNode] Buscando elemento: %d. Entrando en la raiz...\n", item);
    return findAux(T->root, item);
}

int findAux(tABBNode* node, tABBElem item) {
    // Si el nodo actual esta vacio, se llegó al final del arbol, no hay nada
    if (node == NULL) {
        printf("[findAux] Aqui no hay nada, no esta el elemento.\n");
        return 0;
    }

    printf("[findAux] Buscando elemento: %d - Nodo actual: %d\n", item, getValue(node));

    // Si el nodo actual ya posee el elemento, se encontró
    if (getValue(node) == item) {
        printf("[findAux] Se encontro el elemento.\n");
        return 1;
    }

    // Si el elemento es mayor al nodo actual, ir por la derecha, sino, por la izquierda
    if (item > getValue(node)) {
        printf("[findAux] El elemento es mayor al nodo, buscar por la derecha...\n");
        return findAux(node->der, item);
    } else {
        printf("[findAux] El elemento es menor al nodo, buscar por la izquierda...\n");
        return findAux(node->izq, item);
    }
}

int removeNode(tABB* T, tABBElem item) {
    printf("[removeNode] Elemento a borrar: %d ...\n", item);

    // Solo borrar elementos si es que existe
    if (findNode(T, item)) {
        printf("[removeNode] El elemento existe. Proceder a borrar...\n");

        // Si la raiz es el unico nodo que hay en el arbol, hay que borrarlo, si no, hay que buscar en el arbol
        if ((T->root->der == NULL) && (T->root->izq == NULL)) {
            printf("[removeNode] El elemento a eliminar es el unico nodo del arbol. Liberando memoria...\n");
            free(T->root);
            T->root = NULL;
        } else {
            printf("[removeNode] Hay mas nodos. Entrando en la raiz...\n");
            removeAux(T, T->root, T->root, item);
        }

        printf("[removeNode] Eliminacion completada. Disminuyendo tamano...\n");
        T->size--;
        return 1;
    } else {
         printf("[removeNode] El elemento no existe. No hacer nada.\n");
        return 0;
    }
}

void removeAux(tABB* T, tABBNode* node, tABBNode* penult, tABBElem item) {
    printf("[removeAux] Elemento a borrar: %d - Nodo actual: %d - Nodo padre: %d\n", item, getValue(node), getValue(penult));

    // Si se encuentra el nodo, borrarlo
    if (getValue(node) == item) {
        printf("[removeAux] Se encontro el nodo, analizar caso...\n");

        // Caso 1: El nodo es una hoja
        if ((node->izq == NULL) && (node->der == NULL)) {
            printf("[removeAux] Caso 1: El nodo es una hoja (no tiene hijos)\n");

            // Dependiendo del lugar donde esta el hijo, hay que cambiar los punteros del padre
            if (item > getValue(penult)) {
                printf("[removeAux] El nodo a eliminar esta a la derecha del padre. Desvinculando padre->derecho...\n");
                penult->der = NULL;
            } else {
                printf("[removeAux] El nodo a eliminar esta a la izquierda del padre. Desvinculando padre->izquierdo...\n");
                penult->izq = NULL;
            }

            printf("[removeAux] Liberando memoria...\n");
            free(node);
        }

        // Caso 2: El nodo tiene solo un hijo (derecho)
        else if ((node->izq == NULL) && (node->der != NULL)) {
            printf("[removeAux] Caso 2: El nodo tiene solo un hijo (derecho)...\n");

            // Si el nodo a eliminar es la raiz, hay que cambiar los punteros del TDA
            if (node == T->root) {
                printf("[removeAux] El nodo a eliminar es la raiz, cambiar raiz al hijo derecho...\n");
                T->root = node->der;

                printf("[removeAux] Liberando memoria...\n");
                free(node);
                return;
            }

            printf("[removeAux] Conectando padre con el hijo derecho del nodo a eliminar.\n");
            // Dependiendo del lugar donde esta el hijo, hay que cambiar los punteros del padre
            if (item > getValue(penult)) {
                printf("[removeAux] El nodo a eliminar esta a la derecha del padre. Conectando padre->derecho...\n");
                penult->der = node->der;
            } else {
                printf("[removeAux] El nodo a eliminar esta a la izquierda del padre. Conectando padre->izquierdo...\n");
                penult->izq = node->der;
            }

            printf("[removeAux] Liberando memoria...\n");
            free(node);

        }

        // Caso 3: El nodo tiene solo un hijo (izquierdo)
        else if ((node->izq != NULL) && (node->der == NULL)) {
            printf("[removeAux] Caso 3: El nodo tiene solo un hijo (izquierdo)...\n");

            // Si el nodo a eliminar es la raiz, hay que cambiar los punteros del TDA
            if (node == T->root) {
                printf("[removeAux] El nodo a eliminar es la raiz, cambiar raiz al hijo izquierdo...\n");
                T->root = node->izq;

                printf("[removeAux] Liberando memoria...\n");
                free(node);
                return;
            }

            printf("[removeAux] Conectando padre con el hijo izquierdo del nodo a eliminar.\n");
            // Dependiendo del lugar donde esta el hijo, hay que cambiar los punteros del padre
            if (item > getValue(penult)) {
                printf("[removeAux] El nodo a eliminar esta a la derecha del padre. Conectando padre->derecho...\n");
                penult->der = node->izq;
            } else {
                printf("[removeAux] El nodo a eliminar esta a la izquierda del padre. Conectando padre->izquierdo...\n");
                penult->izq = node->izq;
            }

            printf("[removeAux] Liberando memoria...\n");
            free(node);
        }

        // Caso 4: El nodo tiene dos hijos
        else if ((node->izq != NULL) && (node->der != NULL)) {
            printf("[removeAux] Caso 4: El nodo tiene dos hijos...\n");

            tABBNode* temp = sucesor(node);
            tABBElem valor = getValue(temp);
            printf("[removeAux] Obteniendo valor de sucesor... Es %d\n", valor);

            // Eliminar el sucesor y reemplazar el valor
            printf("[removeAux] Eliminar nodo sucesor...\n");
            removeNode(T, valor);

            printf("[removeAux] Reemplazando valores %d -> %d ...\n", getValue(node), valor);
            node->info = valor;

            // Contrarrestar la disminucion duplicada del tamano del arbol
            printf("[removeAux] Contrarrestar disminucion de tamaño de arbol. Aumentar tamaño...\n");
            T->size++;
        }

        return;
    }

    // Seguir buscando si no se encuentra el elemento
    if (item > getValue(node)) {
        printf("[removeAux] El elemento es mayor al nodo, buscar por la derecha...\n");
        return removeAux(T, node->der, node, item);
    } else {
        printf("[removeAux] El elemento es menor al nodo, buscar por la izquierda...\n");
        return removeAux(T, node->izq, node, item);
    }
}

tABBNode* sucesor(tABBNode* node) {
    printf("[sucesor] Buscando sucesor desde: %d\n", getValue(node));
    tABBNode* succ = node;

    // Si es posible, moverse una vez hacia la derecha y luego todo lo que se pueda hacia la izquierda
    if (node->der != NULL) {
        succ = node->der;
        printf("[sucesor] Moverse derecha. Sucesor hasta ahora: %d\n", getValue(succ));
    } else {
        printf("[sucesor] No es posible moverse a la derecha. Sucesor sigue siendo el mismo: %d\n", getValue(succ));
        return succ;
    }

    while (succ->izq != NULL) {
        succ = succ->izq;
        printf("[sucesor] Moverse izquierda. Sucesor hasta ahora: %d\n", getValue(succ));
    }

    printf("[sucesor] No se puede mover mas a la izquierda. Sucesor de %d es %d\n", getValue(node), getValue(succ));

    return succ;
}

void clearABB(tABB* T) {
    printf("[clearABB] Iniciando limpieza del arbol...\n");
    while (T->root != NULL) {
        printf("[clearABB] Eliminando la raiz... Nodo: %d\n", getValue(T->root));
        removeNode(T, getValue(T->root));
    }
}

void deleteABB(tABB* T) {
    printf("[deleteABB] Iniciando eliminacion del arbol...\n");
    clearABB(T);

    printf("[deleteABB] Liberando memoria...\n");
    free(T);
}

void preOrden(tABB* T) {
    printf("[preOrden] Iniciando recorrido en pre-orden. Entrando en raiz\n");
    preOrdenAux(T->root);
}

void preOrdenAux(tABBNode* node) {
    // Ya no hay mas profundidad, devolverse un nodo hacia arriba
    if (node == NULL) {
        printf("[preOrdenAux] Aqui no hay nada, devolverse...\n");
        return;
    }

    printf("[preOrdenAux] Nodo actual: %d\n", getValue(node));

    printf("[preOrdenAux] Ir a izquierda...\n");
    preOrdenAux(node->izq);

    printf("[preOrdenAux] Ir a derecha...\n");
    preOrdenAux(node->der);
}

void inOrden(tABB* T) {
    printf("[inOrden] Iniciando recorrido en in-orden. Entrando en raiz\n");
    inOrdenAux(T->root);
}

void inOrdenAux(tABBNode* node) {
    // Ya no hay mas profundidad, devolverse un nodo hacia arriba
    if (node == NULL) {
        printf("[inOrdenAux] Aqui no hay nada, devolverse...\n");
        return;
    }

    printf("[inOrdenAux] Ir a izquierda...\n");
    inOrdenAux(node->izq);

    printf("[inOrdenAux] Nodo actual: %d\n", getValue(node));

    printf("[inOrdenAux] Ir a derecha...\n");
    inOrdenAux(node->der);
}

void postOrden(tABB* T) {
    printf("[postOrden] Iniciando recorrido en in-orden. Entrando en raiz\n");
    postOrdenAux(T->root);
}

void postOrdenAux(tABBNode* node) {
    // Ya no hay mas profundidad, devolverse un nodo hacia arriba
    if (node == NULL) {
        printf("[postOrdenAux] Aqui no hay nada, devolverse...\n");
        return;
    }

    printf("[postOrdenAux] Ir a izquierda...\n");
    postOrdenAux(node->izq);

    printf("[postOrdenAux] Ir a derecha...\n");
    postOrdenAux(node->der);

    printf("[postOrdenAux] Nodo actual: %d\n", getValue(node));
}
