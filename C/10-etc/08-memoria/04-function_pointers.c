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

    printf("Direccion de 'sumarUno()': %p\n", &sumarUno);

    // De esta forma se puede ejecutar la funcion a traves de la variable.

    // Como es un puntero, este debe tener asociado el tipo de retorno de la funcion,
    // y el tipo de los parametros.

    // Podemos crear una variable que contenga la direccion de 'sumarUno()'
    void (*func_ptr)(int*);
    // tipo de retorno  --- variable puntero  ---  tipo de parametros

    func_ptr = &sumarUno;
    // Con esto, asociamos la direccion de memoria de la funcion 'sumarUno()' a
    // la variable 'func_ptr'. Ahora podemos llamar a 'sumarUno()' a traves de la
    // nueva variable.

    func_ptr(&mi_num);

    printf("mi_num: %d\n", mi_num);




    int (*otra_func)(int, int);
    otra_func = &elevar;

    printf("%d\n", otra_func(2,5));

    return 0;
}
