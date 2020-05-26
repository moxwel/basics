#include <stdio.h>



typedef struct {
    int encendido;
    int gasolina;
    float direccion;
    int velocidad;
    int engranaje;
} automovil;

void iniciarAuto(automovil *a) {
    a->encendido = 0;
    a->gasolina = 100;
    a->direccion = 0.0;
    a->velocidad = 0;
    a->engranaje = 0;
}
void encenderAuto(automovil *a) {
    a->encendido = 1;
}
int obtenerGasolina(automovil *a) {
    return a->gasolina;
}
void virar(automovil *a, float angulo) {
    a->direccion += angulo;
}
void acelerar(automovil *a, int cantidad) {
    a->velocidad += cantidad;
}
void cambiarMarcha(automovil *a, int cambio) {
    a->engranaje = cambio;
}

int main()
{
    automovil kia;

    iniciarAuto(&kia);
    encenderAuto(&kia);
    acelerar(&kia,10);
    printf("Gasolina: %i\n",obtenerGasolina(&kia));

    return 0;
}
