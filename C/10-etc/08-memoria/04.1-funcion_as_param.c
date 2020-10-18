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




// Aqui creamos una funcion que tiene dos parametros:
// 1. Un puntero a una funcion.
// 2. Un puntero a un numero.

// Esta funcion va a ejecutar la funcion a la que esta apuntando la variable 'func'
void ejecutarFunc(void (*func)(int*), int* num) {
    func(num);
}
// Nos permiten crear funciones genericas que puedan utilizar otras funciones para realizar acciones.

// Por ejemplo, una funcion para ordenar cosas.
// Podria recibir un arreglo, el tamaño del arreglo, y una funcion de comparacion.
// Ahora solamente supondremos que esa funcion de comparacion hara cosas mas simples
// y retornara true si es que un elemento es mas pequeño que otro.

// La funcion de comparacion se puede programar aparte.




int main() {

    int mi_num = 15;
    printf("%d\n",mi_num); // 15

    void (*funcion1)(int*) = &sumarUno; // 'funcion1' sera sumar
    void (*funcion2)(int*) = &restarUno;
    void (*funcion3)(int*) = &duplicar;


    ejecutarFunc(funcion1, &mi_num); // Estamos ejecutando 'funcion1' a traves de la funcion 'ejecutarFunc()'
    printf("%d\n",mi_num); // 16

    ejecutarFunc(funcion2, &mi_num);
    ejecutarFunc(funcion2, &mi_num);
    ejecutarFunc(funcion2, &mi_num);
    printf("%d\n",mi_num); // 13

    ejecutarFunc(funcion3, &mi_num);
    printf("%d\n",mi_num); // 26



    return 0;
}
