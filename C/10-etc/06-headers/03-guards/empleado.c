#include <stdlib.h>

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
