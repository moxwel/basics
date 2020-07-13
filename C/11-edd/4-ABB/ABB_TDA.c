#include <stdio.h>
#include <stdlib.h>

// ====================
// CREACION DEL TDA
// ====================

// Vamos a suponer que los elementos del arbol van a ser 'ints'
typedef int tElemArbolBin;

// Vamos a definir un nuevo tipo 'tNodoArbolBin'
typedef struct nodoArbolBin {

    tElemArbolBin info; // El elemento que se va a almacenar

    struct nodoArbolBin *izq; // Un puntero al nodo hijo izquierdo.

    struct nodoArbolBin *der; // Un puntero al nodo hijo derecho.

} tNodoArbolBin;

// Se define la estructura "ABB"
typedef struct {

    tNodoArbolBin *raiz; // Puntero al nodo que esta en la raiz

    int nElem; // La cantidad de nodos

} tABB;


// ====================
// PROTOTIPOS DE INTERFAZ
// ====================
// Necesario para las funciones recursivas.

void insertAux(tNodoArbolBin *nodo, tElemArbolBin elem);
tNodoArbolBin *newNode(tElemArbolBin item);
void clearAux(tNodoArbolBin *nodo);
void setValue(tNodoArbolBin *nodo, tElemArbolBin elem);
tElemArbolBin getValue(tNodoArbolBin *nodo);
void preOrdenAux(tNodoArbolBin *nodo);
void inOrdenAux(tNodoArbolBin *nodo);
void postOrdenAux(tNodoArbolBin *nodo);
int findAux(tNodoArbolBin *nodo, tElemArbolBin elem);
void removeNode(tABB *T, tElemArbolBin item);
void removeAux(tNodoArbolBin *nodo, tElemArbolBin elem, tABB *T);
int find(tABB *T, tElemArbolBin elem);

// ====================
// CREACION DE INTERFAZ
// ====================

// Inicializador del arbol.
void initABB(tABB *T) {
    // Desde la entrada, no hay raiz, se apunta a NULL
    T->raiz = NULL;
    T->nElem = 0;
}



// Insertar elemento en el arbol.
void insert(tABB *T, tElemArbolBin elem) {

    // Caso especial cuando Raiz es vacia
    if (T->raiz == NULL) {
        T->raiz = newNode(elem);
        T->nElem++;
        return;
    }

    insertAux(T->raiz, elem);
    T->nElem++;
}
void insertAux(tNodoArbolBin *nodo, tElemArbolBin elem) {
    // Si el nodo actual ES el elemento, no ocurre nada
    if (getValue(nodo) == elem) {
        return;
    }

    // Si el elemento es menor al nodo actual, entonces se revisa el hijo izquierdo
    // Si el hijo izquierdo es NULL, se inserta alli.
    if (elem < getValue(nodo)) {
        if (nodo->izq == NULL) {
            nodo->izq = newNode(elem);
        } else {
            insertAux(nodo->izq, elem);
        }
    }
    if (elem > getValue(nodo)) {
        if (nodo->der == NULL) {
            nodo->der = newNode(elem);
        } else{
            insertAux(nodo->der, elem);
        }
    }
}

// Crear nuevo nodo con un elemento.
tNodoArbolBin *newNode(tElemArbolBin item) {
    tNodoArbolBin* temp = (tNodoArbolBin*)malloc(sizeof(tNodoArbolBin));
    temp->info = item;
    temp->der = NULL;
    temp->izq = NULL;
    return temp;
}

// Reinicializa una lista, liberando memoria, y dejandolo vacio
void clear(tABB *T) {
    clearAux(T->raiz);
    T->raiz = NULL;
    T->nElem = 0;
}
// Funcion auxiliar para eliminar los nodos
void clearAux(tNodoArbolBin *nodo) {
    if (nodo == NULL) {
        return;
    }
    clearAux(nodo->izq);
    clearAux(nodo->der);
    free(nodo);
}

// Obtener elemento de un nodo
tElemArbolBin getValue(tNodoArbolBin *nodo) {
    return nodo->info;
}

// Retorna el tamaño de la lista
int size(tABB *T) {
    return T->nElem;
}





void removeNode(tABB *T, tElemArbolBin item) {
    if (find(T,item)) {
        // Primero hay que buscar el nodo que se quiere borrar

        // Si el arbol esta vacio
        if (T->raiz == NULL) {
            return;
        }

        // Si el unico elemento esta en la raiz y se elimina.
        if (T->raiz->info == item && T->raiz->der == NULL && T->raiz->izq == NULL) {
            free(T->raiz);
            T->raiz = NULL;
            return;
        }


        removeAux(T->raiz, item, T);
        T->nElem--;
    }
}
void removeAux(tNodoArbolBin *nodo, tElemArbolBin elem, tABB* T) {

    // Primero hay que encontrar el nodo a borrar
    if (getValue(nodo) == elem) {

        // Es hoja
        if (nodo->izq == NULL && nodo->der == NULL) {

            tNodoArbolBin *htemp = T->raiz;
            tNodoArbolBin *ptemp = NULL;

            while (htemp->info != elem) {
                if (elem > htemp->info) {
                    ptemp = htemp;
                    htemp = htemp->der;
                }
                if (elem < htemp->info) {
                    ptemp = htemp;
                    htemp = htemp->izq;
                }
            }

            if (elem > ptemp->info) {
                free(htemp);
                ptemp->der = NULL;
            }
            if (elem < ptemp->info) {
                free(htemp);
                ptemp->izq = NULL;
            }

            return;

        }


        // Tiene solo un hijo derecho
        if (nodo->izq == NULL && nodo->der != NULL) {

            tNodoArbolBin *htemp = T->raiz;
            tNodoArbolBin *ptemp = NULL;

            while (htemp->info != elem) {
                if (elem > htemp->info) {
                    ptemp = htemp;
                    htemp = htemp->der;
                }
                if (elem < htemp->info) {
                    ptemp = htemp;
                    htemp = htemp->izq;
                }
            }

            if (elem > ptemp->info) {

                ptemp->der = htemp->der;
                free(htemp);
            }
            if (elem < ptemp->info) {
                ptemp->izq = htemp->der;
                free(htemp);
            }

            return;

        }


        tNodoArbolBin *temp = nodo->izq;
        tNodoArbolBin *hijotemp = NULL;

        if (temp->der == NULL) {
            nodo->info = temp->info;
            free(temp);
            nodo->izq = NULL;
            return;
        }

        hijotemp = temp->der;

        while (hijotemp->der != NULL) {
            temp = temp->der;
            hijotemp = temp->der;
        }

        nodo->info = hijotemp->info;

        free(hijotemp);
        temp->der = NULL;

        return;
    }
    if (elem < getValue(nodo)) {
        removeAux(nodo->izq, elem, T);
    }
    if (elem > getValue(nodo)) {
        removeAux(nodo->der, elem, T);
    }

}



// Recorrer arbol Pre-Orden
void preOrden(tABB *T) {
    preOrdenAux(T->raiz);
}
void preOrdenAux(tNodoArbolBin *nodo) {
    if (nodo == NULL) {
        return;
    }
    printf("%i\n",getValue(nodo)); // Procesar nodo
    preOrdenAux(nodo->izq);
    preOrdenAux(nodo->der);
}

// Recorrer arbol In-Orden
void inOrden(tABB *T) {
    inOrdenAux(T->raiz);
}
void inOrdenAux(tNodoArbolBin *nodo) {
    if (nodo == NULL) {
        return;
    }
    inOrdenAux(nodo->izq);
    printf("%i\n",getValue(nodo)); // Procesar nodo
    inOrdenAux(nodo->der);
}

// Recorrer arbol Post-Orden
void postOrden(tABB *T) {
    postOrdenAux(T->raiz);
}
void postOrdenAux(tNodoArbolBin *nodo) {
    if (nodo == NULL) {
        return;
    }
    postOrdenAux(nodo->izq);
    postOrdenAux(nodo->der);
    printf("%i\n",getValue(nodo)); // Procesar nodo
}

// True-False. Buscar un elemento en el arbol.
int find(tABB *T, tElemArbolBin elem) {
    return findAux(T->raiz, elem);
}
int findAux(tNodoArbolBin *nodo, tElemArbolBin elem) {
    if (nodo == NULL) {
        return 0;
    }
    if (getValue(nodo) == elem) {
        return 1;
    }
    if (elem < getValue(nodo)) {
        return findAux(nodo->izq, elem);
    }
    if (elem > getValue(nodo)) {
        return findAux(nodo->der, elem);
    }
    return 0;
}




void infoABB(tABB *T) {
    printf("=======::ABB::======\n");
    printf("Raiz: %p - N Elems: %i\n\n",T->raiz,T->nElem);
}
