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

    // Podemos almacenar los tokens en un arreglo de strings. Para esto, debemos
    // crear un arreglo de strings (char**) y luego ir almacenando cada token en
    // una posición del arreglo.

    // Sin embargo, no sabemos cuántos tokens tendrá el string original. Podriamos
    // crear un arreglo de strings con un tamaño fijo si sabemos que el string
    // original no tendrá más de cierta cantidad de tokens. Pero esto no es muy
    // eficiente, ya que si el string original tiene menos tokens que el tamaño
    // del arreglo, estaremos desperdiciando memoria.

    // Para efectos de este ejemplo, crearemos un arreglo de strings con un tamaño
    // fijo de 10. Esto significa que el string original no puede tener más de 10
    // tokens. Si el string original tiene más de 10 tokens, el programa fallará.

    char* palabras[10];

    // Para almacenar los tokens en el arreglo, debemos ir recorriendo el arreglo
    // y almacenando cada token en una posición del arreglo. Para saber cuál es
    // la siguiente posición del arreglo que debemos utilizar, podemos utilizar
    // una variable que vaya almacenando la posición actual del arreglo.

    int i = 0;

    // Mientras 'strtok' no retorne NULL, imprimir el token y almacenar el token en el arreglo
    // en el índice 'i'
    while (token != NULL) {
        printf("%s\n", token);

        palabras[i] = token;
        i++;

        token = strtok(NULL, ",");

        // Llamar a 'strtok' con NULL como primer parámetro permite continuar
        // con la tokenización del string original. Por lo tanto, la variable
        // 'token' ahora posee la dirección de memoria del siguiente token, es decir 'como'.
    }

    // Cuando no hay más tokens, 'strtok' retorna NULL, por lo que el ciclo termina.

    // Ahora podemos imprimir los tokens almacenados en el arreglo

    printf("Tokens almacenados en el arreglo: \n");
    for (int j = 0; j < i; j++) {
        printf("Indice %i : %s\n", j, palabras[j]);
    }

    return 0;
}
