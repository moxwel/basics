#include <stdio.h>

struct empleado {
    int codigo;
    float sueldo;
    char rango;
};
// Declaracion de sturct "empleado"

typedef struct empleado emp;
// Redefinicion del tipo "struct empleado" a "emp"

int main() {

    emp max, bro;
    // Ahora se pueden definir variables de tipo "strct empleado" solo con "emp"

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
