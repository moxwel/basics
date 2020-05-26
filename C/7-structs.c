#include <stdio.h>

int main() {

    struct empleado {
        int codigo;
        float sueldo;
        char rango;
    };
    // Declaracion de struct "empleado"

    struct empleado max, bro;
    // Declaracion de variables de tipo "struct empleado"

    max.codigo = 30661;
    max.sueldo = 10.56;
    max.rango = 'A';
    // modificar directamente los valores

    bro.codigo = 30662;
    bro.sueldo = 5.56;
    bro.rango = 'D';
    // modificar directamente los valores

    printf("Sueldo de Max: %f\nSueldo de Bro: %f\n",max.sueldo,bro.sueldo);

    return 0;
}
