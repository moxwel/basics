// Para leer archivos, es necesario utilizar la libreria 'fs'.

const fs = require('fs');

// La libreria 'fs' posee un metodo llamado 'readFile()' y 'writeFile()'




// readFile(<direccion>, <formato>, <funcion(err,dat)>)

fs.readFile('./archivo.txt', 'utf-8', (error, datosLeidos) => {
    if (error) throw error;

    console.log(datosLeidos);
})
// Esto es un archivo de texto.
//
// Hola mundo!

// Si no se menciona formato, entonces se lee como hexadecimal

fs.readFile('./archivo.txt', (error, datosLeidos) => {
    if (error) throw error;

    console.log(datosLeidos);
})

// <Buffer 45 73 74 6f 20 65 73 20 75 6e 20 61 72 63 68 69 76 6f 20 64 65 20 74 65 78 74 6f 2e 0a 0a 48 6f 6c 61 20 6d 75 6e 64 6f 21 0a>




// writeFile(<direccion>, <datos>, <funcion(err)>)

var datosIngresados = "Estoy escribiendo en un archivo.";

fs.writeFile('salida.txt', datosIngresados, (err) => {
    if (err) {
        throw err;
    } else {
        console.log("El archivo se ha escrito correctamente");
    }
});
