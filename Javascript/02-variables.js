// Javscript es un lenguaje debilmente tipado, es decir, las varibales en este lenguaje no tienen tipo
// definido a priori, pueden tomar cualquier tipo de dato, y cambiarse por otro arbitrario cuando se desee.
// De la misma manera que en Python.

// Para definir una variable, se usa la palabra clave 'var', seguido del nombre, luego el signo
// de asignacion (=) y finalmente el valor.

var miVariable = 100;

// Antes de utilizar una variable, debe estar definida antes, si no, un error ocurrira.

// Para obtener la variable, podemos llamarla directamente en consola (nos retorna su valor), o podemos
// utilizarlo en algun otro lugar.

miVariable; // 100

console.log(miVariable); // 100

// Teniendo una variable ya definida, podemos cambiar su valor cuando queramos:

miVariable = 'Hola mundo';

console.log(miVariable); // Hola mundo

// Las variables en Javascript son case-sensitives, es decir, son sensibles a mayusculas.

miVariable = 'Max';

var MiVariable = 'Bob'; // Se define como nueva variable, pues 'MiVariable' no existe, sino 'miVariable'

console.log(miVariable); // Max
console.log(MiVariable); // Bob

// Las variables pueden almacenar practicamente cualquier tipo de dato, desde numeros, floats, strings,
// booleanos, hasta objetos y funciones.

var booleano = true;
booleano = false;

var decimal = 3.14;

var nombre = "Max";
