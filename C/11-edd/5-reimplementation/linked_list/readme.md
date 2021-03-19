# Documentacion: Lista enlazada

Esta es una implementacion de una lista enlazada en C.

Consiste en una estructura donde bloques llamados _nodos_ estan unidos mediante punteros.

## Compilacion

Para poder usarse, se debe utilizar compilacion separada. Para ello, se debe incluir el header del TDA de lista enlazada en tu codigo principal:

```c
// tu_archivo.c

#include "linked.list.h"

int main() {
     /* ... */
    return 0;
}
```

Y luego compilar y enlazar de forma separada:

```shell
$ gcc -c linked_list.c tu_archivo.c

$ gcc linked_list.o tu_archivo.o
```

## Estructuras

* `tListElem` : **Elemento** de la lista. Puede modificarse para poder albergar otro tipo de dato.

* `tListNode` : **Nodo** de la lista. Estos nodos estaran conectados entre si mediante punteros.

  * `info` : Alberga un _elemento_ de tipo `tListElem`.

  * `sig` : Un puntero que apunta a otro _nodo_ `tListNode`, quien es siguiente en la lista.

* `tList` : Estructura principal de la lista. Desde aqui nacen los punteros a los _nodos_ para que sean accesibles.

  * `head` : Puntero que apunta al _nodo cabeza_, es decir, al inicio de la lista.

  * `tail` : Puntero que apunta al _nodo cola_, es decir, al final de la lista.

  * `curr` : Puntero **cursor** que apunta al _nodo actual_.

  * `pos` : `int` que denota la **posicion** actual del _cursor_.

  * `len` : `int` que denota el **tamaño** de la lista, es decir, la cantidad de elementos guardados.

## Funciones

**Operaciones de inicializacion:**

* `newList` : Crea una nueva lista. Retorna una direccion de memoria donde la lista esta ubicada.\
**Retorno:** Puntero a un `tList` en memoria.

* `deleteList` : Elimina una lista completa y libera su memoria.\
Deberia usarse en todas las listas que se hayan creado en el progama, antes de que este termine para evitar fugas de memoria.

**Operaciones de elemento:**

* `insert` : Agrega un _elemento_ **despues** del _cursor_.

* `append` : Agrega un _elemento_ **al final** de la lista.

* `erase` : Elimina el _elemento_ **despues** del _cursor_.\
**Retorno:** 1 = exito; 0 = Sin exito (lista vacia)

* `clearList` : Elimina **todos** los _elementos_ de la lista.

**Operaciones de cursor:**

* `next` : Mueve el _cursor_ un elemento hacia **adelante**.\
**Retorno:** 1 = exito; 0 = Sin exito (cursor en `tail`)

* `prev` : Mueve el _cursor_ un elemento hacia **atras**.\
**Retorno:** 1 = exito; 0 = Sin exito (cursor en `head`)

* `moveToPos` : Mueve el _cursor_ a una **posicion especificada**.\
**Retorno:** 1 = exito; 0 = Sin exito (posicion invalida)

* `moveToStart` : Mueve el _cursor_ al **inicio de la lista**.

* `moveToEnd` : Mueve el _cursor_ al **final de la lista**.

**Operaciones de obtencion:**

* `getValue` : Obtiene el valor del _elemento_ siguiente al _cursor_.\
**Retorno:** Valor de tipo `tListElem`.

* `getLength` : Obtiene el _tamaño_ de la lsita.\
**Retorno:** `int`

* `getPos` : Obtiene la _posicion_ del _cursor_.\
**Retorno:** `int`

## Comportamiento

Para representar la lista y el codigo, se utilizara el siguiente formato:

```txt
Len: <num> - Pos: <num>
[<posicion>] <valor> | H | C | T

> input
>>> output
```

Donde `H` corresponde a `head`, `C` corresponde a `curr` y `T` corresponde a `tail`.

Al crear una nueva lista, esta comienza con un _nodo_ "especial", pues es util porque de esta forma no es necesario cambiar el puntero `head` de la lista; ademas comienza con `len = 0` y `pos = 0`:

```txt
> tList* miLista = newList();

Len: 0 - Pos: 0
[-1] 0 | H | C | T
```

Cuando hay elementos, el _cursor_ sirve como referencia para saber en que nodo estamos, pero la mayoria de operaciones se realizan siempre **delante de este**, es decir:

```txt
Len: 4 - Pos: 2
[-1] 0 | H
 [0] 789
 [1] 9928 | C
 [2] 456
 [3] 123 | T

> insert(miLista, 2233);

Len: 5 - Pos: 2
[-1] 0 | H
 [0] 789
 [1] 9928 | C
 [2] 2233
 [3] 456
 [4] 123 | T
```

Notese el valor de `pos`, pues, en cierto modo quiere decir "cual nodo es el que va a ser manipulado".

```txt
Len: 5 - Pos: 2
[-1] 0 | H
 [0] 789
 [1] 9928 | C
 [2] 2233
 [3] 456
 [4] 123 | T

> next(miLista);

Len: 5 - Pos: 3
[-1] 0 | H
 [0] 789
 [1] 9928
 [2] 2233 | C
 [3] 456
 [4] 123 | T

> erase(miLista);

Len: 4 - Pos: 3
[-1] 0 | H
 [0] 789
 [1] 9928
 [2] 2233 | C
 [3] 123 | T

> getValue(miLista);
>>> 123
```

## Casos especiales

Como dijimos anteriormente que **el elemento siguiente al _cursor_** es el que va a ser manipulado, ¿que pasa cuando el cursor esta al final de la lista?.

```txt
Len: 4 - Pos: 4
[-1] 0 | H
 [0] 789
 [1] 9928
 [2] 2233
 [3] 123 | C | T
```

En el caso de `erase`, el _cursor_ primero se devuelve un nodo (utilizando `prev`) y luego procede a eliminar el nodo.

```txt
Len: 4 - Pos: 4
[-1] 0 | H
 [0] 789
 [1] 9928
 [2] 2233
 [3] 123 | C | T

> erase(miLista);

Len: 3 - Pos: 3
[-1] 0 | H
 [0] 789
 [1] 9928
 [2] 2233 | C | T
```

En el caso de `getValue`, se obtiene el _elemento_ del nodo al que apunta `curr` (ya no es al nodo siguiente, sino al mismo nodo al que apunta).

```txt
Len: 3 - Pos: 3
[-1] 0 | H
 [0] 789
 [1] 9928
 [2] 2233 | C | T

> getValue(miLista);
>>> 2233

> prev(miLista);

Len: 3 - Pos: 2
[-1] 0 | H
 [0] 789
 [1] 9928 | C
 [2] 2233 | T

> getValue(miLista);
>>> 2233

> prev(miLista);

Len: 3 - Pos: 1
[-1] 0 | H
 [0] 789 | C
 [1] 9928
 [2] 2233 | T

> getValue(miLista);
>>> 9928
```

## Cambio de tipo de dato

Al cambiar el tipo de dato de `tListElem`, hay que tener en cuenta las funciones que manejan los _elementos_ de la lista, como `newList`, `insert`, `append` y `getValue`; hay que adaptarlos para que tambien puedan manejar ese tipo de dato.

## Funcion de imprimir lista

La funcion `printList` es una funcion auxiliar que sirve para poder ver la tabla en este caso. Sirve para depurar listas enlazadas creadas con esta implementacion. Si se cambia el tipo de dato de `tListElem`, se debe reimplementar esta funcion.
