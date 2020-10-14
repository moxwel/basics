/*
Ahora, tendremos este archivo .c solamente para definir las funciones como tal.

En .h estaran los prototipos, que incluso seran utiles para otros programas que necesiten
utilizar los mismos tipos de datos y funciones, y en el archivo .c es donde se definen que hacen.
*/

#include <stdlib.h>

// Tambien incluimos el header aqui, ya que en el header se encuentran
// las definicion del typedef "emp".
#include "empleado.h"

emp* crearEmpleado(int c, float s, char r) {
    emp *e = (emp*)malloc(sizeof(emp));

    e->codigo = c;
    e->sueldo = s;
    e->rango = r;

    return e;
}

void borrarEmpleado(emp *e) {
    free(e);
}

int codigo(emp *e) {
    return e->codigo;
}
float sueldo(emp *e) {
    return e->sueldo;
}
char rango(emp *e) {
    return e->rango;
}
