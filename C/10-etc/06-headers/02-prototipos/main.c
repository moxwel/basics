#include <stdio.h>
#include <stdlib.h>

// Ahora solo usamos el header
#include "empleado.h"

/*
Ahora si, la compilacion separada si va a funcionar.

$ gcc -c main.c        ----->    main.o
$ gcc -c empleado.c    ----->    empleado.o

$ gcc main.o empleado.o -o programa
*/

int main() {
    emp *max = crearEmpleado(30661, 10.56, 'A');
    emp *bro = crearEmpleado(30662, 5.56, 'D');

    printf("Sueldo de Max: %f\nSueldo de Bro: %f\n",sueldo(max),sueldo(bro));

    borrarEmpleado((void*)max);
    borrarEmpleado((void*)bro);

    return 0;
}
