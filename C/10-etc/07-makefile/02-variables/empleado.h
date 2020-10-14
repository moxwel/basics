/*
Un guard nos va a servir para evitar que los prototipos y las definiciones de tipos de datos
se vuelvan a definir dos veces.
*/

// Para esto, podemos usar el siguiente preprocesador
#ifndef __EMPLEADO__
// Aqui lo que estamos diciendo es "si no esta definido el identificador "__EMPLEADO__"
// entonces, va a continuar con todo lo que sigue hasta el "endif".


// Si no esta definido el identificador, pues, comenzemos definiendolo entonces.
#define __EMPLEADO__
// Como ya esta definido, la proxima vez que se intente importar este header, ya va a estar definido
// por lo tanto, el "ifndef" lo va a saltar.

typedef struct {
    int codigo;
    float sueldo;
    char rango;
} emp;

emp* crearEmpleado(int c, float s, char r);
void borrarEmpleado(emp *e);

int codigo(emp *e);
float sueldo(emp *e);
char rango(emp *e);


// Hasta aqui llegan todas nuestras definiciones, por lo tanto, temrinamos el "if" que
// habiamos puesto al inicio.
#endif // __EMPLEADOS__

// Esto es una buena practica para evitar conflictos en proyectos mas grandes.
// Todos los headers deberian tener un "guard".
