// Un arreglo en Javascript podria considerarse como un objeto tambien.

// Para crear un arreglo se puede hacer de dos maneras:

var miArreglo = new Array("elemento1", "elemento2", 3.14, "etc");

var miArreglo = ["elemento1", "elemento2", 3.14, "etc"];

// Un arreglo puede contener diferentes tipos de datos.

// Los elementos en un arreglo poseen un indice, siendo el 0 el primer elemento.

console.log(miArreglo[0]); // elemento1
console.log(miArreglo[1]); // elemento2
console.log(miArreglo[2]); // 3.14
console.log(miArreglo[3]); // etc
console.log(miArreglo[4]); // undefined




// Tambien podemos cambiar un elemento de un arreglo:

console.log(miArreglo[1]); // elemento2

miArreglo[1] = "Nuevo string";

console.log(miArreglo[1]); // Nuevo string



// Podemos crear un arreglo vacio:

var arregloVacio = new Array();

var arregloVacio = []; // Forma equivalente

console.log(arregloVacio); // []




// Tambien se pueden crear arreglos asociativos

miArreglo["nombre"] = "Max";

console.log(miArreglo); // [ 'elemento1', 'Nuevo string', 3.14, 'etc', nombre: 'Max' ]

// Pero en estos casos, es mejor usar un objeto.