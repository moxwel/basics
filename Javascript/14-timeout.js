function saludo() {
    console.log("Hola soy una funcion");
}

function mensaje() {
    console.log("Estoy ejecutandome de forma asincrona");
}

function despedida() {
    console.log("Adios!!");
}

function mensaje2() {
    console.log("Ha pasado 1 segundo");
}

// Uno de los primeros acercamientos para hacer funciones asincronicas es usar los funciones
// 'setTimeout()' y 'setInterval()'.

// 'setTimeout(<funcion>, <milisegundos>, <params>, ...)'
// Recibe la funcion que se va a ejecutar, luego de haber pasado cierta cantidad de milisegundos.

// 'setInterval(<funcion>, <milisegundos>, <params>, ...)'
// Recibe la funcion que se va a ejecutar cada cierta cantidad de milisegundos.

setTimeout(despedida, 6000);

setTimeout(saludo, 2000);

setTimeout(mensaje, 4000);

setInterval(mensaje2, 1000);

// Notese que primero se ejecuta la segunda funcion, luego la tercera, y al final la primera; todo
// esto mientras la ultima funcion se repite cada segundo.
