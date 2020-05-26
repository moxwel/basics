#include <stdio.h>

int main() {

    int a = 50;

    // Variable constante
    const int b = 174;
    // No se puede modificar la variable

    // Puntero constante
    int *const pa = &a;
    // No se puede modificar la direccion de memoria del puntero
    // Pero el valor al que apunta si puede. (Hay que desreferenciar)

    // Valor apuntado constante
    const int *pa2 = &a;
    // No se puede modificar el valor apuntado.
    // Pero si se puede modificar la direccion de memoria.

    return 0;
}
