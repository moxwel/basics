#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Demostración de opendir y readdir
    // 'opendir' es una función que permite abrir un directorio y obtener un puntero a un 'stream de directorio'
    // 'readdir' es una función que permite leer un directorio a través de un 'stream de directorio'
    // 'opendir' y 'readdir' son parte de la librería 'dirent.h'




    // Un 'stream de directorio' (DIR) es una estructura de datos que contiene información sobre un directorio
    // y los archivos que contiene este. (Formalmente definido como 'struct __dirstream' en 'dirent.h')

    // 'opendir' recibe un string con la direccion del directorio a abrir
    // y retorna un puntero a un stream de directorio (DIR*). NULL en caso de error.

    DIR* open_dir_stream = opendir("../archivos");

    // La variable 'open_dir_stream' ahora posee la dirección de memoria del stream de directorio abierto.




    // Si bien DIR es la estructura de datos que contiene información sobre un directorio,
    // la estructura de datos 'struct dirent' (DIRectory ENTry) contiene información sobre un ARCHIVO dentro de un directorio.

    // 'readdir' recibe un puntero a un stream de directorio (DIR*) y retorna un puntero a un 'struct dirent' (struct dirent*)
    // que contiene información sobre el siguiente archivo dentro del directorio. NULL en caso de error o cuando no hay más archivos.

    // Cada vez que se llama a 'readdir' se obtiene información sobre el siguiente archivo dentro del directorio. Esto es asi
    // porque 'readdir' mantiene un puntero interno que apunta al archivo actual dentro del directorio. Con esto en mente,
    // podemos recorrer el directorio completo llamando a 'readdir' hasta que retorne NULL.



    // Creamos un puntero a un 'struct dirent' para almacenar la información de cada archivo.
    struct dirent* dir_entry;




    // Creamos un arreglo de strings para almacenar los nombres de los archivos
    char* nombres_archivos[15];
    // Suponemos que el directorio no tendrá más de 15 archivos. Si el directorio tiene más de 15 archivos, el programa fallará.

    // Creamos un contador para almacenar la cantidad de archivos
    int n_archivos = 0;

    // Se verifica que el stream de directorio no sea NULL (es decir, que no haya ocurrido un error al abrir el directorio)
    if (open_dir_stream) {

        // Mientras 'readdir' no retorne NULL, imprimir el nombre del archivo.
        while ((dir_entry = readdir(open_dir_stream)) != NULL) {
            // Notar que la funcion 'readdir' se llama dentro de la condicion del while.
            // Cada vez que el programa entre al while se evalua la condicion, causando que 'readdir' se llame.

            // La variable 'dir_entry' ahora posee la dirección de memoria del siguiente archivo dentro del directorio.

            // La estructura de datos 'struct dirent' posee un campo llamado 'd_name' que contiene
            // un string (char*) con el nombre del archivo.

            // Recordemos que para acceder a un campo de una estructura de datos se utiliza el operador '->' en el
            // caso de que la variable sea un puntero a la estructura de datos, o el operador '.' en el caso de que
            // la variable sea la estructura de datos en si.

            // En este caso, 'dir_entry' es un puntero a un 'struct dirent', por lo que se utiliza el operador '->'
            // para desreferenciar el puntero y acceder al campo 'd_name' de la estructura de datos.

            // Hay que considerar que en el stream de directorio existen dos archivos especiales: '.' y '..'
            // '.' representa el directorio actual, y '..' representa el directorio padre.
            // Estos archivos son retornados por 'readdir' junto con los archivos normales, por lo que hay que
            // filtrarlos para que no sean impresos.

            // La función 'strcmp' compara dos strings y retorna 0 si son iguales.
            // En este caso, se compara el nombre del archivo con '.' y '..' para filtrarlos.

            if (strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
                // Almacenamos el nombre del archivo en el arreglo de strings
                nombres_archivos[n_archivos] = dir_entry->d_name;
                n_archivos++;
            }
        }
        // Cuando no hay más archivos, 'readdir' retorna NULL, por lo que el ciclo termina.

    }

    // Imprimimos los nombres de los archivos almacenados en el arreglo
    printf("Nombres de los archivos:\n");
    for (int i = 0; i < n_archivos; i++) {
        printf("Indice %d:\t%s\n", i, nombres_archivos[i]);
    }

    // Cerramos el stream de directorio
    closedir(open_dir_stream);

    return 0;
}
