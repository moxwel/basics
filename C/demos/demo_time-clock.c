#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    // Demostracion de 'time' y 'clock'.
    // 'time' es una funcion que devuelve el tiempo actual en formato UNIX.
    // 'clock' es una funcion que devuelve el tiempo de ejecucion de un programa o algoritmo.
    // Ambos son parte de la libreria 'time.h'


    // 'time' retorna el tiempo actual en formato UNIX cuando se le pasa un puntero a NULL.
    // El retorno es de tipo 'time_t'.

    time_t tiempo_actual_unix = time(NULL);
    // La variable 'tiempo_actual' ahora contiene el tiempo actual en formato UNIX.

    printf("Tiempo actual: %ld\n", tiempo_actual_unix);

    // La resolucion de 'time' es de 1 segundo, por lo que es bastante impreciso si se quiere
    // medir el tiempo de ejecucion de un programa o algoritmo.

    // Para medir el tiempo de ejecucion de un programa o algoritmo se puede usar la funcion 'clock'.





    // 'clock' retorna el numero de ticks de reloj de la CPU desde que el programa se ha iniciado.
    // El retorno es de tipo 'clock_t'.

    clock_t ticks_inicio = clock();
    // La variable 'ticks_inicio' ahora contiene el numero de ticks de reloj de la CPU desde que
    // el programa se ha iniciado.

    printf("\nTicks en inicio: %ld [ticks]\n", ticks_inicio);

    // Podemos usar la funcion 'clock' para medir el tiempo de ejecucion de un programa o algoritmo.
    // Para ello, se debe llamar a 'clock' al inicio y al final del programa o algoritmo y luego
    // calcular la diferencia entre ambos valores.

    // Ejemplo: Calcular el tiempo de ejecucion de un programa que imprime los numeros del 1 al 1000000.
    for (int i = 1; i <= 1000000; i++) {
        // Algoritmo
    }

    clock_t ticks_final = clock();

    printf("Ticks en final: %ld [ticks]\n", ticks_final);
    // La variable 'ticks_final' ahora contiene el numero de ticks de reloj de la CPU desde que
    // el programa se ha iniciado. Que es mayor que 'ticks_inicio' porque el programa ha estado ejecutandose.




    // Para calcular el tiempo de ejecucion del programa, se debe calcular la diferencia entre
    // 'ticks_final' y 'ticks_inicio'.
    // La diferencia entre ambos valores es el tiempo de ejecucion del programa en ticks de reloj de la CPU.

    clock_t diff_ticks = ticks_final - ticks_inicio;

    printf("Diferencia de ticks: %ld [ticks]\n", diff_ticks);
    // Tenemos la diferencia en ticks de reloj de la CPU, pero no sabemos cuanto tiempo representa eso en segundos.






    // 'time.h' tiene una constante llamada 'CLOCKS_PER_SEC' que representa
    // el numero de ticks de reloj de la CPU por segundo. Es de tipo 'clock_t'.

    printf("\nNumero de ticks por segundo: %ld [ticks/s]\n", CLOCKS_PER_SEC);

    // Para calcular el tiempo de ejecucion del programa en segundos, se debe dividir
    // 'tiempo_ejecucion' por 'CLOCKS_PER_SEC'.

    double tiempo_ejecucion = (double)diff_ticks / CLOCKS_PER_SEC;
    // Se debe convertir 'diff_ticks' a 'double' para que la division sea en punto flotante y con mayor precision.

    printf("Tiempo de ejecucion: %lf [s]\n", tiempo_ejecucion);
    // Ahora tenemos el tiempo de ejecucion del programa en segundos.


    return 0;
}
