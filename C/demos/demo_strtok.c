#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Demostración de strtok
    // 'strtok' es una función que permite tokenizar una cadena de caracteres
    // 'tokenizar' significa dividir una cadena de caracteres de acuerdo
    // a un delimitador (un caracter que separa los tokens)
    // 'stkrtok' es parte de la librería 'string.h'

    // Palabra a tokenizar:
    char palabra[] = "hola,como,estas";

    // Recordemos que un string es un arreglo de caracteres,
    // y en C, un arreglo de caracteres es un puntero a un caracter (char*).

    // 'strkrtok' recibe dos parámetros: el string a tokenizar (char*) y el delimitador (char)
    // y retorna un puntero a un caracter (char*) que apunta al primer token.
    // 'strtok' retorna NULL cuando no hay más tokens

    char* token = strtok(palabra, ",");

    // 'strtok' modifica el string original, reemplazando el delimitador por un caracter nulo ('\0')
    // por lo que el string original queda de la siguiente forma:
    // "hola\0como\0estas"

    // La variable 'token' ahora posee la dirección de memoria del primer token, es decir 'hola'

    // Mientras 'strtok' no retorne NULL, imprimir el token
    while (token != NULL) {
        printf("%s\n", token);

        token = strtok(NULL, ",");

        // Llamar a 'strtok' con NULL como primer parámetro permite continuar
        // con la tokenización del string original. Por lo tanto, la variable
        // 'token' ahora posee la dirección de memoria del siguiente token, es decir 'como'.
    }

    // Cuando no hay más tokens, 'strtok' retorna NULL, por lo que el ciclo termina.
    return 0;
}
