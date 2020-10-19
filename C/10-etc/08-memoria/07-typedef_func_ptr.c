#include <stdio.h>

void sumarUno(int* valor) {
    *valor += 1;
}
void restarUno(int* valor) {
    *valor -= 1;
}
void duplicar(int* valor) {
    *valor *= 2;
}

// Se puede hacer un typedef de un puntero a funcion.

// 'fpOperador' es un puntero a funcion (fp) a una funcion de tipo void que recibe un puntero a int.
typedef void (*fpOperador)(int*);


fpOperador operacion(int n) {
    if (n == 1) {
        return &sumarUno;
    } else if (n == 2) {
        return &restarUno;
    } else if (n == 3) {
        return &duplicar;
    }
    return &sumarUno;
}

int main() {
    int numero = 15;
    printf("%d\n", numero); // 15

    // Ahora, la variable 'una_funcion' es un puntero a una funcion de tipo
    // void que recibe un puntero a int.
    fpOperador una_funcion;

    una_funcion = operacion(1); // sumarUno()
    una_funcion(&numero);
    printf("%d\n", numero); // 16

    una_funcion = operacion(3); // duplicar()
    una_funcion(&numero);
    printf("%d\n", numero); // 32

    una_funcion = operacion(2); // restarUno()
    una_funcion(&numero);
    printf("%d\n", numero); // 31


    return 0;
}
