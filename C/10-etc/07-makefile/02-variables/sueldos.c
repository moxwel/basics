/*
Supongamos que quisieramos hacer otro modulo para "main.c"

En este caso, hacer un modulo que posea instrucciones para pagar a los empleados.

En este caso, podemos hacer un archivo ".h" para los prototipos, y este ".c"
para definir que hace
*/

#include "sueldos.h"

void pagarEmpleado(emp *e, int pago){
    e->sueldo = e->sueldo + pago;
}
