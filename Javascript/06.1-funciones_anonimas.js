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

ejecutarFuncion(25, function(arg){return arg*arg;} ) // 625

// Al llamar 'ejecutarFuncion()', se define alli mismo una funcion anonima que eleva al cuadrado, donde su definicion es utilizada junto al valor ingresado (24).



// Las funciones anonimas tambien se pueden definir usando la notacion de flechas.
// (argumentos) => {Definicion de funcion}

ejecutarFuncion(25, (arg) => {return arg*arg} ) // 625