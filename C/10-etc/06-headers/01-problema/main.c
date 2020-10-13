#include <stdio.h>
#include <stdlib.h>

// Es necesario incluir el archivo "empleado.c", ya que
// alli se encuentran las definiciones del TDA.
#include "empleado.c"

/*
En ciertos IDE, cuando uno intenta compilar un proyecto. Estos
se compilan de forma independiente. Es decir, se estaria compilando
"main.c" y "empleado.c" de forma separada.

$ gcc -c main.c        ----->    main.o
$ gcc -c empleado.c    ----->    empleado.o

Ambos generan archivos "objeto" (.o), estos contienen lenguaje de maquina.

Para que el programa completo funcione como debe, el compilador "enlaza" todos
estos codigos de maquina, para que al final se genere el ejecutable como tal.

$ gcc main.o empleado.o -o programa

Pero hay un problema... El compilador seguramente, al compilar todos los archivos
separados, y despues, al intentar enlazarlos, el compilador se va a encontrar con
que algunas funciones se vuelven a redefinir, y lanza error.

*Notese como al intentar compilar los archivos por separados, funciona, pero
al intentar enlazarlos, da error de definiciones multiples (esto es a causa del "copypaste"
del "include empleado.c").
*/

int main() {
    emp *max = crearEmpleado(30661, 10.56, 'A');
    emp *bro = crearEmpleado(30662, 5.56, 'D');

    printf("Sueldo de Max: %f\nSueldo de Bro: %f\n",sueldo(max),sueldo(bro));

    borrarEmpleado((void*)max);
    borrarEmpleado((void*)bro);

    return 0;
}
