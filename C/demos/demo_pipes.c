#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    // Ejemplo de uso de pipes
    // Las pipes son una forma de comunicacion entre procesos.
    // Son unidireccionales, es decir, si queremos comunicar dos procesos
    // en ambos sentidos, necesitamos dos pipes.

    // Crear pipes
    // [0]: Lectura (entrada)
    // [1]: Escritura (salida)

    int pipe_ph[2]; // Pipe del padre al hijo
    int pipe_hp[2]; // Pipe del hijo al padre

    // Inicializar pipes
    pipe(pipe_ph);
    pipe(pipe_hp);

    // Crear proceso hijo
    int pid_hijo = fork();

    if (pid_hijo > 0) { // Esto sera ejecutado por el padre

        printf("[%d] Soy el padre con PID: %d \n", getpid(), getpid());

        // Pipe del padre al hijo (padre -> hijo)
        // El padre escribe y el hijo lee, por lo tanto, cerramos el modo de
        // lectura del padre al hijo y el modo de escritura del hijo al padre.

        close(pipe_ph[0]); // Cerrar el modo de lectura del padre al hijo
        close(pipe_hp[1]); // Cerrar el modo de escritura del hijo al padre




        int mensaje = 50;
        printf("[%d] el mensaje que envio es: %d \n", getpid(), mensaje);

        // Enviamos el mensaje desde el padre al hijo, por lo tanto, escribimos
        // en el pipe del padre al hijo en modo escritura (pipe_ph[1]).
        write(pipe_ph[1], &mensaje, sizeof(int));




        printf("[%d] mensaje enviado...\n", getpid());
        printf("[%d] esperando respuesta...\n", getpid());




        // Esperamos la respuesta del hijo, por lo tanto, leemos del pipe del
        // hijo al padre en modo lectura (pipe_hp[0]).
        read(pipe_hp[0], &mensaje, sizeof(int));
        // Mientras el hijo no haya escrito en el pipe, el padre se queda
        // bloqueado en esta linea de codigo.




        // Cuando el hijo escribe en el pipe, el padre continua la ejecucion y
        // lee el mensaje del pipe.
        printf("[%d] la respuesta de mi hijo es: %d \n", getpid(), mensaje);
        printf("[%d] terminando proceso...\n", getpid());





    } else if (pid_hijo == 0) { // Esto sera ejecutado por el hijo

        printf("    [%d] Soy el hijo con PID: %d, mi padre es: %d \n", getpid(), getpid(), getppid());

        // Pipe del hijo al padre (padre <- hijo)
        // El padre lee y el hijo escribe, por lo tanto, cerramos el modo de
        // escritura del padre al hijo y el modo de lectura del hijo al padre.

        close(pipe_ph[1]); // Cerrar el modo de escritura del padre al hijo
        close(pipe_hp[0]); // Cerrar el modo de lectura del hijo al padre




        int mensaje;
        printf("    [%d] esperando mensaje de mi padre...\n", getpid());

        // Esperamos el mensaje del padre, por lo tanto, leemos del pipe del
        // padre al hijo en modo lectura (pipe_ph[0]).
        read(pipe_ph[0], &mensaje, sizeof(int));
        // Mientras el padre no haya escrito en el pipe, el hijo se queda
        // bloqueado en esta linea de codigo.




        printf("    [%d] el mensaje que recibi es: %d \n", getpid(), mensaje);

        printf("    [%d] procesando una suma...\n", getpid());
        for (int i = 0; i < 1000000000; i++) {
            mensaje = mensaje + 1;
        }




        printf("    [%d] el mensaje que envio es: %d \n", getpid(), mensaje);

        // Enviamos el mensaje desde el hijo al padre, por lo tanto, escribimos
        // en el pipe del hijo al padre en modo escritura (pipe_hp[1]).
        write(pipe_hp[1], &mensaje, sizeof(int));




        printf("    [%d] mensaje enviado...\n", getpid());
        printf("    [%d] terminando proceso...\n", getpid());
    }
    return 0;
}
