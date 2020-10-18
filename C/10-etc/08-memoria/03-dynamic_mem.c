#include <stdio.h>
#include <stdlib.h>

int main() {

    // Malloc es una funcion que nos permite asignar memoria dinamica en el HEAP.
    // Este pregunta por espacio disponible en la memoria al sistema operativo, y
    // cuando encuentra uno, lo reserva, y RETORNA UN PUNTERO A VOID (void*) ya que
    // en realidad no se sabe que tipo de datos se van a guardar alli.

    // Por esta razon, es necesario hacer un typecast a malloc, con el tipo de puntero
    // correspondiente.
    int* ptr1 = (int*)malloc(sizeof(int));
    *ptr1 = 155;

    printf("Direccion de 'ptr1': %p\n",ptr1);
    printf("Valor al que apunta 'ptr1': %d\n",*ptr1);

    printf("\n");



    // Los arreglos son sectores contiguos de memoria, por lo tanto, tambien podriamos
    // crear sectores contiguos de memoria con malloc, en este caso, podemos reservar
    // un sector de memoria que pueda almacenar 5 enteros (20 bytes contiguos).
    int* ptr2 = (int*)malloc(5*sizeof(int));

    printf("Direccion de 'ptr2': %p\n",ptr2);

    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]);
    }

    printf("\n\n");



    // Tambien se puede usar la funcion Calloc, que tambien permite poder asignar
    // memoria contigua, pero la diferencia es que admite 2 parametros: la cantidad de
    // elementos que se van a guardar, y la cantidad de bytes del tipo que se va a guardar.

    // La mayor diferencia es que Calloc INICIALIZA las celdas de memoria a 0. (Esto tambien
    // puede ocurrir en malloc, pero depende del sistema operativo). Puede ser mas lento.

    int* ptr3 = (int*)calloc(5, sizeof(int));

    printf("Direccion de 'ptr3': %p\n",ptr3);

    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr3[i]);
    }

    printf("\n\n");




    // Existe otro comando que se llama Realloc, que permite cambiar el tamaño de la memoria
    // que se asignó con Malloc.

    // Recibe un puntero (el que se creo con malloc), y el nuevo tamaño del bloque de memoria.

    int* ptr4 = (int*)realloc(ptr2, 10*sizeof(int));

    // La funcion copia literalmente todos los bytes del antiguo bloque de memoria
    // a un nuevo bloque de memoria. Si es posible extender el bloque de memoria, lo hará,
    // y la direccion de memoria no cambiará. Si no, entonces se creara un nuevo bloque
    // en otra direccion de memoria, y el bloque antiguo se liberara.

    printf("Direccion antigua: %p - Direccion nueva %p\n",ptr2,ptr4);

    // Como el bloque ptr2 esta rodeado de variables en el heap (ptr1 y ptr3), es muy seguro
    // que no se pueda extender la memoria, por lo tanto, se va a crear un nuevo bloque, y el
    // anterior se va a liberar.


    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr4[i]);
    }

    printf("\n");


    // realloc(puntero, 0) --> equivalente a free(puntero)
    // realloc(NULL, size) --> equivalente a malloc(size)





    // Como es memoria dinamica, es necesario liberarla de forma manual,
    // para eso existe free()-
    free(ptr1);
    // free(ptr2); // Ya fue liberado al hacer el realloc con 'ptr4'
    free(ptr3);
    free(ptr4);


    return 0;
}
