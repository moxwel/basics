// Una funcion sin nombre se llama 'funcion anomina'. Estos generan una funcion normal como cualquier otro, sin embargo, no se pueden llamar directamente.
// Esto es bastante util cuando se desea realizar operaciones funcionales, o definir una funcion en la misma linea.

/*
function(argumentos) {
    //Definicion de funcion
}
*/

function ejecutarFuncion(valor, funcion) {
    return funcion(valor);
}

// Notese que la funcion 'ejecutarFuncion()' recibe como parametros un valor y otra funcion.

console.log(ejecutarFuncion(25, function(arg){return arg*arg} )); // 625

// Al llamar 'ejecutarFuncion()', se define alli mismo una funcion anonima que eleva al cuadrado, donde su definicion es utilizada junto al valor ingresado (24).



// Las funciones anonimas tambien se pueden definir usando la notacion de flechas.
// (argumentos) => {Definicion de funcion}

console.log(ejecutarFuncion(6, (arg) => {return arg*arg} )); // 36



// Podemos guardar funciones en variables tambien.

var saludo = function(nombre) {
    console.log("Hola " + nombre);
}

saludo("Max"); // Hola Max

var despedida = (nombre) => {console.log("Adios " + nombre)};

despedida("Bob"); // Adios Bob