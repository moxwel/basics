#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int num;
    pid_t pid;

    for (num = 0; num < 2; num++) {
        printf("\033[%dm[%d]\033[0m Voy a crear un hijo... (num=%d)\n", 30+getpid()%20, getpid(), num);
        pid = fork();
        if (pid == 0) {
            printf("\033[%dm[%d]\033[0m Soy el hijo de \033[%dm%d\033[0m\n", 30+getpid()%20, getpid(), 30+getppid()%20, getppid());
        }else{
            printf("\033[%dm[%d]\033[0m Mi hijo tiene el PID \033[%dm%d\033[0m\n", 30+getpid()%20, getpid(), 30+pid%20, pid);
        }

        if (pid != 0) {
            printf("\033[%dm[%d]\033[0m Voy a salir del ciclo for\n", 30+getpid()%20, getpid());
            break;
        }

        srandom(getpid());
        int r = random() % 5;

        printf("\033[%dm[%d]\033[0m Voy a dormir %d segundos\n", 30+getpid()%20, getpid(), r);

        // sleep(r);

        printf("\033[%dm[%d]\033[0m Ya desperte. Volvere al for\n", 30+getpid()%20, getpid());
    }
    printf("\033[%dm[%d]\033[0m Sali del for.\n", 30+getpid()%20, getpid());

    if (pid != 0) {
        printf("\033[%dm[%d]\033[0m Esperando a algun hijo...\n", 30+getpid()%20, getpid());
        pid_t pid_hijo = wait(NULL);
        printf("\033[%dm[%d]\033[0m Mi hijo \033[%dm%d\033[0m termino.\n", 30+getpid()%20, getpid(), 30+pid_hijo%20, pid_hijo);
    }

    printf("\033[%dm[%d]\033[0m Terminando...\n", 30+getpid()%20, getpid());
    return 0;
}
