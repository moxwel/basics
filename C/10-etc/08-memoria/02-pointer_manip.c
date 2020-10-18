#include <stdio.h>

int main() {
    // Recordemos que los arreglos son sectores contiguos de memoria que se esta asignado.

    int arr[5] = {15,16,17,18,19};

    // Tecnicamente, un arreglo es un puntero constante que apunta a la direccion de memoria
    // de la base del arreglo (la direccion del primer elemento).

    int* ptr;

    ptr = arr;
    // ptr = &arr[0]; // Esto es equivalente

    // Como 'arr' es un puntero de tipo 'int', el compilador sabe exactamente la "separacion en bytes"
    // de cada elemento del arreglo (4 bytes).

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n\n", arr[2]);

    // Esto es equivalente a...

    printf("%d\n", *(arr + 0));

    // Como 'arr' es un puntero de tipo 'int'.
    // Aumentar 1 significa en realidad, buscar 4 bytes mas adelante
    printf("%d\n", *(arr + 1));

    printf("%d\n\n", *(arr + 2));

    // Por lo tanto, tambien a...

    printf("%d\n", *(ptr + 0));
    printf("%d\n", *(ptr + 1));
    printf("%d\n", *(ptr + 2));



    return 0;
}
