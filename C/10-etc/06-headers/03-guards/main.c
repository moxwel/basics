#include <stdio.h>
#include <stdlib.h>

#include "empleado.h"
#include "sueldos.h"
/*
Si intentamos compilar todo esto, de forma separada, va a funcionar, pero este "main" no, ya que
si bien, tiene los prototipos de todo, si notamos el archivo "sueldos.h", nos podemos fijar que
se incluye nuevamente el archivo "empleado.h".

Al final, lo que causa esto seria redefiniciones nuevamente. Habrian dos prototipos con exactamente
el mismo nombre, cosa que C no le gusta.

Para eso, en el archivo "empleado.h" podemos poder un "guard".
*/

int main() {
    emp *max = crearEmpleado(30661, 10.56, 'A');
    emp *bro = crearEmpleado(30662, 5.56, 'D');

    printf("Sueldo de Max: %f\nSueldo de Bro: %f\n",sueldo(max),sueldo(bro));

    pagarEmpleado(max, 1000);

    printf("Sueldo de Max: %f\nSueldo de Bro: %f\n",sueldo(max),sueldo(bro));

    borrarEmpleado((void*)max);
    borrarEmpleado((void*)bro);

    return 0;
}
