/*
Esto es un archivo cabecera (header).

Aqui, se introducen definiciones de estructuras, y prototipos de funciones, es decir,
declaraciones de funciones, pero sin definicion.

Esto le sera util al compilador ya que con esto, podemos "anticiparle" al compilador como
va a llamarse una funcion, y como va a funcionar, y tambien, que tipos
de datos se definen, y sus campos.
*/

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
