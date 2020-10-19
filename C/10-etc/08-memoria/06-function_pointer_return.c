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



// Podemos hacer que una funcion retorne otra funcion.
// Una funcion 'operacion()' que recibe un entero 'n'.

// Esta funcion retornara: un puntero a una funcion de tipo void que
// recibe como parametro un puntero de tipo 'int'

void (*operacion(int n))(int*){
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
    printf("%d\n",numero); // 15

    // Un puntero a una funcion de tipo void que recibe un puntero a int.
    void (*una_funcion)(int*);

    // Este puntero 'una_funcion' va a recibir la funcion que retorne 'oepracion()'
    una_funcion = operacion(2); // restarUno()
    una_funcion(&numero);
    printf("%d\n",numero); // 14

    una_funcion = operacion(3); // duplicar()
    una_funcion(&numero);
    printf("%d\n",numero); // 28

    una_funcion = operacion(1); // sumarUno()
    una_funcion(&numero);
    printf("%d\n",numero); // 29

    return 0;
}
