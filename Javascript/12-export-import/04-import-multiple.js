// Como el archivo '03-export-multiple.js' exporta un unico elemento por defecto, se debe importar sin llaves '{}'.

import miImport from "./03-export-multiple.js"

// Recordemos que en '03-export-multiple.js' se exporto un objeto con 3 elementos.

// Por lo tanto, podemos acceder a los elementos de 'miImport' con el operador punto '.'.

miImport.mensaje(); // Este mensaje se ha impreso gracias a 'archivo2.js'.
console.log(miImport.nombreArchivo); // Archivo de Prueba 3
console.log(miImport.multiplicarNumeros(5,3)); // 15
