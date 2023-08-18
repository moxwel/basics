#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    // Demostración de strstr
    // 'strstr' es una funcion que busca un string dentro de otro string.
    // 'strstr' es parte de la librería 'string.h'


    // 'strstr' recibe dos parámetros: el string donde se va a buscar y el string que se quiere buscar
    // 'strstr' devuelve un puntero a un caracter (char*) al primer caracter del string encontrado
    // Si no se encuentra el string, 'strstr' devuelve NULL

    char* texto = "Holamundocomoestaslenguajesdeprogramacion";
    char* string_mundo = "mundo";
    char* string_lengua = "lengua";
    char* string_max = "max";
    char* string_lenguajes = "lenguajes";




    // Busquemos la palabra "mundo" en el string 'texto'

    char* resultado = strstr(texto, string_mundo);
    // Ahora la variable 'resultado' apunta al caracter 'm' de 'mundo'

    printf("Resultado: %p\n", resultado);
    printf("Direccion de la letra 'm' de 'mundo': %p\n", &texto[4]);
    // Notar que el resultado es el mismo




    // Busquemos la palabra "lengua" en el string 'texto'

    resultado = strstr(texto, string_lengua);
    // Ahora la variable 'resultado' apunta al caracter 'l' de 'lengua'

    printf("\nResultado: %p\n", resultado);
    printf("Direccion de la letra 'l' de 'lengua': %p\n", &texto[18]);





    // Busquemos la palabra "max" en el string 'texto'

    resultado = strstr(texto, string_max);
    // Ahora la variable 'resultado' apunta a NULL

    printf("\nResultado: %p\n", resultado);





    // Si conocemos el lago de la palabra que queremos buscar, podemos hacer que el print del string
    // comience en el caracter que queremos y termine en el caracter segun el largo de la palabra.

    // Largo de la palabra "lenguajes" (podemos usar 'strlen' para esto)

    int largo_palabra = strlen(string_lenguajes);
    // Ahora la variable 'largo_palabra' tiene el valor 9

    // Busquemos la palabra "lenguajes" en el string 'texto'

    resultado = strstr(texto, string_lenguajes);
    // Ahora la variable 'resultado' apunta al caracter 'l' de 'lenguajes'

    // Desde el string 'texto' vamos a imprimir el string que comienza en 'resultado' y termina en
    // 'largo_palabra' caracteres despues.


    printf("\nLargo de la palabra 'lenguajes': %d\n", largo_palabra);
    printf("Resultado: %p\n", resultado);
    printf("Direccion de la letra 'l' de 'lenguajes': %p\n", &texto[18]);
    printf("String: %.*s\n", largo_palabra, resultado);


    return 0;
}
