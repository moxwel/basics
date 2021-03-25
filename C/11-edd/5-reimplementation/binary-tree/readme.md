# Documentación: Árbol binario de busqueda (ABB)

Esta es una implementacion de un árbol binario de busqueda (ABB) en C.

Consiste en un arbol binario en donde dependiendo del valor de los nodos, se ubican en los subarboles izquierdos (menor) o derechos (mayor).

## Compilación

Para poder usarse, se debe utilizar compilacion separada. Para ello, se debe incluir el header del TDA de árbol binario en tu codigo principal:

```c
// tu_archivo.c

#include "binary_tree.h"

int main() {
     /* ... */
    return 0;
}
```

Y luego compilar y enlazar de forma separada:

```shell
$ gcc -c binary_tree.c tu_archivo.c
$ gcc binary_tree.o tu_archivo.o
```

## Estructuras

* `tABBElem` : **Elemento** del árbol.

* `tABBNode` : **Nodo** del árbol. Cada nodo podra tener **2 hijos**.

  * `info` : Alberga un _elemento_ de tipo `tABBElem`.

  * `izq` : Un puntero que apunta a otro _nodo_ `tABBNode`, quien es el **hijo izquierdo**.

  * `der` : Un puntero que apunta a otro _nodo_ `tABBNode`, quien es **hijo derecho**.

* `tABB` : Estructura principal de la lista. Desde aqui esta la entrada al resto de nodos del arbol.

  * `root` : Puntero que apunta al _nodo raiz_, es decir, al inicio del árbol.

  * `size` : Numero que representa el tamaño del arbol, es decir, la cantidad de elementos que hay en el arbol.

## Funciones

**Operaciones de inicializacion:**

* `newABB` : Crea un nuevo arbol. Retorna una direccion de memoria donde el arbol esta ubicada.\
**Retorno:** Puntero a un `tABB` en memoria.

* `deleteABB` : Elimina un arbol completo y libera su memoria.\
Deberia usarse en todos los arboles que se hayan creado en el progama, antes de que éste termine para evitar fugas de memoria.

**Operaciones de elemento:**

* `preOrden` : Algoritmo que recorre el arbol en **pre-orden**.

* `inOrden` : Algoritmo que recorre el arbol en **in-orden**.

* `postOrden` : Algoritmo que recorre el arbol en **post-orden**.

**Operaciones de elemento:**

* `insertNode` : Agrega un _elemento_ al arbol.\
**Retorno:** 1 = Exito; 0 = Sin exito (el elemento ya existe)

* `removeNode` : Elimina un _elemento_ del arbol.\
**Retorno:** 1 = Exito; 0 = Sin exito (no existe el elemento)

* `clearABB` : Elimina **todos** los _elementos_ del arbol.

**Operaciones de obtencion:**

* `getSize` : Obtiene el _tamaño_ del arbol, es decir, la cantidad de elementos que hay dentro del arbol.\
**Retorno:** `int`

* `getHeight` : Obtiene la _altura_ del arbol.\
**Retorno:** `int`

* `findNode` : Revisa si el _elemento_ dado esta en el arbol.\
**Retorno:** 1 = Exito (existe); 0 = Sin exito (no existe)
