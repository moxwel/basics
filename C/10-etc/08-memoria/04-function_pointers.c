#include <stdio.h>

void sumarUno(int* valor) {
    *valor += 1;
}

int elevar(int base, int exponente) {
    int result = 1;
    for (int i = 0; i < exponente; i++) {
        result *= base;
    }
    return result;
}

int main() {

    int mi_num = 15;

    printf("mi_num: %d\n", mi_num);
    sumarUno(&mi_num);
    printf("mi_num: %d\n", mi_num);


    // Los punteros a funcion, como su nombre lo indica, son variables punteros que apuntan
    // a la direccion de memoria donde la funcion esta ubicada.

    // El nombre de la funcion de por si ya es un puntero, posee una direccion de memoria.
    printf("Direccion de 'sumarUno()': %p\n", sumarUno);

    // De esta forma se puede ejecutar la funcion a traves de la variable.

    // Como es un puntero, este debe tener asociado el tipo de retorno de la funcion,
    // y el tipo de los parametros.

    // Podemos crear una variable que contenga la direccion de 'sumarUno()'

    // Declaracion de un puntero a funcion 'func_ptr'
    // tipo_retorno (*variable_puntero)(tipo_parametros)
    void (*func_ptr)(int*);
    int (*otra_func)(int, int);

    func_ptr = sumarUno;
    otra_func = elevar;
    // Con esto, asociamos la direccion de memoria de la funcion 'sumarUno()' a
    // la variable 'func_ptr'. Y asociamos la direccion de 'elevar()' a 'otra_func'.

    //Ahora podemos llamar a 'sumarUno()' a traves de la nueva variable.

    func_ptr(&mi_num);

    printf("mi_num: %d\n", mi_num);

    printf("%d\n", otra_func(2,5));

    return 0;
}
