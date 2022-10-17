// Para definir funciones, se debe usar la palabra reservada 'function', luego del nombre de la funcion,
// seguido de sus parametros y luego el codigo.

function saludo(nombre) {
    console.log('Hola ' + nombre);
}

// Para llamar a una funcion, es necesario 'llamarlo':

saludo('Max');

// Todas las funciones retornan algo, si no hay un 'return' definido, retornan 'undefined'

function suma(x, y) {
    return x + y;
}

console.log( suma(4,7) );

// Return causa que la funcion retorne un valor y se detenga su ejecucion.

// Toda funcion posee un arreglo especial llamado 'arguments' que contiene los argumentos pasados a una funcion.
// Una funcion se ejecutara incluso si el numero de argumentos no coincide con los parametros definidos.
// Si no hay valores asignados, o en otro caso, los argumentos se pasan de largo, el resto de argumentos se definen como 'undefined'.

function miFuncion(arg1, arg2, arg3) {
    console.log(arguments[0]);
    console.log(arguments[1]);
    console.log(arguments[2]);
    console.log(arguments[3]);
    console.log(arguments[4]);
}

miFuncion('Max', 4, 22/7);
miFuncion('Bob');
miFuncion('Pip', 'String', 'Otro string', 'Hola');