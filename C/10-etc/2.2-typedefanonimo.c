#include <stdio.h>

typedef struct {
    int codigo;
    float sueldo;
    char rango;
} emp;
// Redefinicion de struct anonimo a "emp"

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
