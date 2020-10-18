#include <stdio.h>


// Esta funcion puede imprimir el valor de un puntero a void.
void printVoid(void* variable, int tipo) {

    // Pero para eso, se necesita saber con anteriorirdad que tipo de dato
    // es en realidad el puntero a void.

    // Esto es necesario para poder resreferenciarlo. Cuando uno desreferencia un
    // puntero de tipo 'int' por ejemplo, el compilador sabe que debe leer 4 bytes
    // de memoria, pero en los punteros a void, no se puede saber. Es necesario
    // decirselo de forma explicita.

    if (tipo == 1) {
        // Si el tipo es 1, se considera como 'int', y el puntero a void se
        // castea como puntero de tipo 'int' (int*), y luego se resreferencia (* de afuera)
        printf("%d\n", *(int*)variable);
    } else if (tipo == 2) {
        // Si el tipo es 2, se considera como 'float'.
        printf("%f\n", *(float*)variable);
    } else if (tipo == 3) {
        // Si el tipo es 3, se considera como 'char'
        printf("%c\n", *(char*)variable);
    }
}



int main() {
    int entero = 10;
    float flotante = 3.1416;
    char caracter = 'a';


    // Cuando se definen punteros, se puede hacer utilizando el tipo.
    // Un puntero de tipo 'int' solo podra apuntar a una direccion de memoria
    // que tenga un tipo 'int' guardado.

    // Esto no va a funcionar...
    // int* ptr = &flotante;

    // Un puntero a void es un puntero sin ningun tipo asociado a el, es decir,
    // puede apuntar a una direccion de memoria de cualquier tipo sin problema.

    void* ptr;

    ptr = &entero;
    printVoid(ptr, 1);

    // Como se puede notar, podemos cambiar la direccion de memoria a cualquier tipo,
    // y aun asi funcionara.
    ptr = &flotante;
    printVoid(ptr, 2);

    ptr = &caracter;
    printVoid(ptr, 3);

    return 0;
}
