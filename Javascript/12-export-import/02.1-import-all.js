// Podemos importar todos los elementos de un archivo con '*'.
// Para hacer esto, debemos usar 'as' para darle un nombre al objeto que se creará con todos los elementos importados.

import * as objetoImportado from "./01-export.js"

// Ahora 'objetoImportado' es un objeto que contiene todos los elementos exportados en '01-export.js'.

// Podemos acceder a los elementos de 'objetoImportado' con el operador punto '.'.

console.log(objetoImportado.nombreArchivo); // Archivo de Prueba 1
objetoImportado.mensaje(); // Este mensaje se ha impreso gracias a '01-export.js'.
console.log(objetoImportado.restarNumeros(5,3)); // 2
