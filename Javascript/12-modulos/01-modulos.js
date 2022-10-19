// Podemos exportar o importar codigo de otros archivos Javascript con los comandos 'export' e 'import'.

// Vease los demas archivos

// Si deseamos utilizar las variables y funciones definidas en 'archivo1.js', debemos importarlos.

// NOTA: Para poder utilizar 'import' con Node.js, es necesario mencionar que el proyecto es
// de tipo 'module'. Vease el archivo 'package.json'.




// Para importar ciertos elementos de un archivo.

import {nombreArchivo, mensaje} from "./archivo1.js"

console.log(nombreArchivo); // Archivo de Prueba 1
console.log(mensaje()); // Este mensaje se ha impreso gracias a 'archivo1.js'.

//import {otraVariable} from "./archivo1.js" // Esto dará un error pues 'otraVariable' no se ha exportado.




//Para cambiar el nombre de algun elemento exportado

import {sumarNumeros as unaFuncion} from "./archivo1.js"

console.log(unaFuncion(5,3)); // 8




// Para importar todos los exports de un archivo como un objeto

import * as unObjeto from "./archivo2.js"

console.log(unObjeto.nombreArchivo); // Archivo de Prueba 2
unObjeto.mensaje(); // Este mensaje se ha impreso gracias a 'archivo2.js'.
console.log(unObjeto.restarNumeros(5,3)); // 2




// Para importar un elemento exportado como default

import elementos from './archivo3.js'

console.log(elementos.nombreArchivo); // Archivo de Prueba 3
elementos.mensaje(); // Este mensaje se ha impreso gracias a 'archivo2.js'.
console.log(elementos.multiplicarNumeros(5,5)); // 25
