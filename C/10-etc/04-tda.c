#include <stdio.h>
#include <stdlib.h>

// =====================
// CREACION DE TDA
typedef struct {
    int codigo;
    float sueldo;
    char rango;
} emp;
// =====================


// =====================
// CREACION DE INTERFAZ PARA TDA

// Constructor: asignar memoria
emp* crearEmpleado(int c, float s, char r) {
    emp *e = (emp*)malloc(sizeof(emp));
    // Alocar memoria suficiente para el tipo de dato "emp".
    // Es necesario usar malloc para que al salir de la
    // funcion podamos retornarla sin que se elimine.

    e->codigo = c;
    e->sueldo = s;
    e->rango = r;

    return e;
}

// Destructor: librerar memoria
void borrarEmpleado(emp *e) {
    free(e);
}

int codigo(emp *e) {
    return e->codigo;
}
float sueldo(emp *e) {
    return e->sueldo;
}
char rango(emp *e) {
    return e->rango;
}

// ====================


int main() {
    emp *max = crearEmpleado(30661, 10.56, 'A');
    emp *bro = crearEmpleado(30662, 5.56, 'D');

    printf("Sueldo de Max: %f\nSueldo de Bro: %f\n",sueldo(max),sueldo(bro));

    borrarEmpleado((void*)max);
    borrarEmpleado((void*)bro);

    return 0;
}
