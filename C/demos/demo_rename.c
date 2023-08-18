#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Demostración de rename
    // 'rename' es una función que permite renombrar un archivo o directorio
    // 'rename' es parte de la librería 'stdio.h'

    // La funcion 'rename' recibe dos argumentos: el nombre del archivo o directorio a renombrar y el nuevo nombre.
    // La función devuelve 0 si se pudo renombrar el archivo o directorio, o -1 si no se pudo renombrar

    // A 'renombrar' se refiere a cambiar la direccion del archivo o directorio, eso tambien incluye poder mover
    // archivos o directorios de una carpeta a otra.

    // Ejemplo: cambiar el nombre de 'mi_archivo.txt' a 'mi_archivo_renombrado.txt'
    int resultado = rename("mi_archivo.txt", "mi_archivo_renombrado.txt");
    if (resultado == 0) {
        printf("Se pudo renombrar el archivo\n");
    } else {
        printf("No se pudo renombrar el archivo\n");

        // Un error común es que el archivo o directorio que se quiere renombrar no exista
    }

    // Ejemplo: mover el archivo 'mi_archivo_renombrado.txt' a la carpeta 'carpeta1'
    resultado = rename("mi_archivo_renombrado.txt", "carpeta1/mi_archivo_renombrado.txt");
    if (resultado == 0) {
        printf("Se pudo mover el archivo\n");
    } else {
        printf("No se pudo mover el archivo\n");
    }

    // NOTA: Para ver como crear carpetas, vease el archivo 'demo_mkdir.c'

    return 0;
}
