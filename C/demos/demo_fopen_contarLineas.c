#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Demostración de leer archivo para contar lineas
    // 'fopen' es una función que permite abrir un archivo
    // 'fopen' es parte de la librería 'stdio.h'

    // 'fopen' recibe dos argumentos: el nombre del archivo a abrir y el modo de apertura.
    // El modo de apertura puede ser 'r' (lectura), 'w' (escritura) o 'a' (agregar).
    // 'fopen' devuelve un puntero a un archivo (FILE*) si se pudo abrir el archivo, o NULL si no se pudo abrir.

    // 'FILE' es una estructura que representa un stream de archivo. Contiene información como el nombre del archivo,
    // el modo de apertura, el puntero a la posición actual del archivo, etc.

    FILE* archivo = fopen("mi_archivo.txt", "r");

    // La variable 'archivo' ahora contiene un puntero al archivo 'mi_archivo.txt'.

    // Verificamos que 'fopen' haya retornado un puntero válido

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }



    // Para leer un archivo, utilizamos la función 'fread', o 'fgets' si queremos leer linea por linea.
    // En este caso, vamos a leer linea por linea.

    // 'fgets' recibe 3 argumentos: un puntero a un string donde se va a guardar la linea leida,
    // un entero con la cantidad máxima de caracteres a leer, y un puntero al archivo a leer.
    // 'fgets' devuelve un puntero al string donde se guardó la linea leida, o NULL si no se pudo leer.

    // Creamos un string (char*) de 450 caracteres para guardar la linea leida (450 es un número arbitrario)
    char buffer[450];

    // Creamos un contador para contar la cantidad de lineas leidas
    int contador = 0;

    // La estructura 'FILE' posee un puntero a la posición actual del archivo. Este puntero se actualiza
    // cada vez que se lee o escribe en el archivo. Para leer la siguiente linea del archivo, podemos
    // simplemente llamar a 'fgets' de nuevo.

    while(fgets(buffer, sizeof(buffer), archivo) != NULL) {
        printf("Linea %d:\t%s", contador+1, buffer);
        contador++;
    }

    printf("\nCantidad de lineas leidas: %d\n", contador);






    // Luego de leer el archivo, debemos cerrarlo. Para esto, utilizamos la función 'fclose'.

    // 'fclose' recibe un puntero a un archivo (FILE*) y cierra el archivo.
    // 'fclose' devuelve 0 si pudo cerrar el archivo, o un número distinto de 0 si no pudo cerrar el archivo.

    fclose(archivo);

    return 0;
}
