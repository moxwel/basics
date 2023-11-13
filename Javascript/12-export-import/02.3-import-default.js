// Para importar el elemento exportado como 'default', simplemente se debe importar sin llaves '{}'.
import miImport from './01-export.js'

miImport(); // Elemento por defecto.

// Notese que podemos darle el nombre que queramos al elemento importado, independiente de como se llame en el archivo exportado.



// Podemos importar el elemento exportado como 'default' y otros elementos nombrados en una misma linea.
import otroImport, {nombreArchivo, mensaje} from './01-export.js'

otroImport(); // Elemento por defecto.
console.log(nombreArchivo); // Archivo de Prueba 1
mensaje(); // Este mensaje se ha impreso gracias a '01-export.js'.



// Al importar todos los elementos de un archivo en un mismo objeto, este va a contener tambien al elemento exportado como 'default'.
// Para acceder a este elemento, se debe usar la palabra 'default' como llave del objeto.
import * as objetoImportado from './01-export.js'

objetoImportado.default(); // Elemento por defecto.
console.log(objetoImportado.nombreArchivo); // Archivo de Prueba 1
