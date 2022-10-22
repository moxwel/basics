// Una funcion sin nombre se llama 'funcion anomina'. Estos generan una funcion normal como cualquier otro, sin embargo, no se pueden llamar directamente.
// Esto es bastante util cuando se desea realizar operaciones funcionales, o definir una funcion en la misma linea.

/*
function(parametros) {
    //Definicion de funcion
}
*/

function ejecutarFuncion(valor, funcion) {
    return funcion(valor);
}

// Notese que la funcion 'ejecutarFuncion()' recibe como argumento un valor y otra funcion.

console.log(ejecutarFuncion(25, function(arg){return arg*arg} )); // 625

// Al llamar 'ejecutarFuncion()', se define alli mismo una funcion anonima que eleva al cuadrado, donde su definicion es utilizada junto al valor ingresado (24).





// Las funciones anonimas tambien se pueden definir usando la notacion de flechas.
// (parametros) => {Definicion de funcion}

console.log(ejecutarFuncion(6, (arg) => {return arg*arg} )); // 36




// Podemos guardar funciones en variables tambien.

var saludo = function(nombre) {
    console.log("Hola " + nombre);
}

saludo("Max"); // Hola Max

var despedida = (nombre) => {console.log("Adios " + nombre)};

despedida("Bob"); // Adios Bob





// Las funciones anonimas pueden retornar valores.

var retornarValor1 = (valor) => {return valor};

console.log(retornarValor1(32)) // 32

// Si solo es una unica expresion la que se quiere retornar, entonces se puede prescindir de los corchetes.

var retornarValor2 = (valor) => valor;

console.log(retornarValor2(32)) // 32

// Si se ingresan corchetes, se debe explicitar 'return' para poder retornar.

var retornarValor3 = (valor) => {valor};

console.log(retornarValor3(32)) // undefined

// Si solo se tiene un unico parametro, se puede prescindir de los parentesis.

var unaFuncion1 = param => param+45;

console.log(unaFuncion1(32)); // 77
