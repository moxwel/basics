// De la misma manera que en Python, podemos utilizar un loop 'for' para recorrer un objeto "iterable".

// Recordemos que un objeto consiste en pares 'nombre: valor'.

var unObjeto = {nombre:'Max', edad:22, color:'Azul'};

var unArreglo = ["Un arreglo", 3.1415, "Texto", 11];




// NOTA: Se usa 'let' para que la variable no pueda ser usada fuera del 'for'.}

// 'for-in' se usa para que la variable que ira recorriendo el iterable tome los
// nombres de las propiedades del objeto.

for (let variable in unObjeto) {
    console.log(variable);
}
// nombre
// edad
// color

for (let variable in unArreglo) {
    console.log(variable);
}
// 0
// 1
// 2
// 3

// NOTA: En Javascript no es buena practica utilizar 'for-in' en arreglos, menos aun si el orden
// de los elementos es importante. En vez de eso, se recomienda el uso del metodo 'Array.forEach()'
// o un for loop clasico.




// 'for-of' se usa para que la variable que ira recorriendo el iterable tome los
// valores del iterable. (No sirve en objetos, porque los objetos no son iterables)

for (let variable of unArreglo) {
    console.log(variable);
}
// Un arreglo
// 3.1415
// Texto
// 11
