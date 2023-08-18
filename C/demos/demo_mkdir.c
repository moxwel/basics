#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Demostración de mkdir
    // 'mkdir' es una función que permite crear un directorio
    // 'mkdir' es parte de la librería 'sys/stat.h'
    // 'sys/types.h' también es necesario para utilizar 'mkdir'

    // ==========
    // RECORDATORIO: Los permisos en Unix se dividen en 3 grupos: usuario (quien creó el archivo),
    // grupo (grupo al que pertenece el usuario) y otros (todos los demás usuarios).

    // Cada grupo puede tener permisos de lectura (r), escritura (w) y ejecución (x).
    // Los permisos de lectura, escritura y ejecución se representan con un 1
    // si el permiso está activo y un 0 si no lo está.

    // Al usar 'ls' en la terminal, los permisos se muestran como una secuencia de 9 caracteres:
    // 3 caracteres para el usuario, 3 para el grupo y 3 para otros.

    // Por ejemplo: 'rwx r-x r-x' significa que el usuario tiene permisos de lectura, escritura y ejecución,
    // mientras que el grupo y otros tienen permisos de lectura y ejecución. En binario, esto es 111 101 101.
    // Este ultimo corresponde a los permisos por defecto de un archivo o directorio creado con 'mkdir'.
    // ==========

    // 'mkdir' tiene dos parametros: un string con la direccion del directorio a crear, y un entero con
    // los permisos del directorio. Retorna 0 en caso de éxito, -1 en caso de error.

    // Creamos un directorio llamado 'nuevo_dir' dentro del directorio raiz del programa
    // con permisos de lectura, escritura y ejecución para el usuario.

    int resultado = mkdir("./nuevo_dir", 0755);

    // '0755' es un número octal que representa los permisos del directorio.
    // 0755 en octal es 111 101 101 en binario, equivalente a 'rwx r-x r-x'.

    // Verificamos que 'mkdir' haya retornado 0 (es decir, que el directorio se haya creado con éxito)
    if (resultado == 0) {
        printf("Directorio creado con éxito\n");
    } else {
        printf("Error al crear directorio\n");

        // Un error puede ocurrir cuando el directorio que se quiere crear ya existe.
    }


    // Para crear un directorio dentro de otro directorio, se debe especificar la ruta completa
    // del directorio a crear. Por ejemplo, para crear un directorio llamado 'otros_dir' dentro
    // del directorio 'nuevo_dir' que creamos anteriormente, se debe especificar la ruta completa
    // del directorio a crear: './nuevo_dir/otros_dir'

    int resultado2 = mkdir("./nuevo_dir/otros_dir", 0755);

    if (resultado2 == 0) {
        printf("Directorio creado con éxito\n");
    } else {
        printf("Error al crear directorio\n");
    }

    // Sin embargo, si el directorio 'nuevo_dir' no existe, 'mkdir' fallará.
    // Siempre se debe crear el directorio padre antes de crear un directorio hijo. 

    return 0;
}
