// NOTA: Para poder utilizar 'import' con Node.js, es necesario mencionar que el proyecto es de tipo 'module' en el archivo 'package.json'.

// Si deseamos utilizar las variables y funciones definidas en '01-export.js', debemos importarlos.
import { nombreArchivo, mensaje } from "./01-export.js"

// Con esto, estamos importando los elementos 'nombreArchivo' y 'mensaje' desde el archivo '01-export.js'.

// Ahora podemos usarlos en este archivo.

console.log(nombreArchivo); // Archivo de Prueba 1
mensaje(); // Este mensaje se ha impreso gracias a 'archivo1.js'.

//import {otraVariable} from "./archivo1.js" // Esto dará un error pues 'otraVariable' no se ha exportado.




// Podemos usar 'as' para darle un nuevo nombre a los elementos que importamos

import { sumarNumeros as suma } from "./01-export.js"

console.log(suma(5,3)); // 8
