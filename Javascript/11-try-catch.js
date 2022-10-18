// Si tenemos la certeza de que un codigo podra fallar, una buena idea es "manejar el error",
// es decir, decirle al programa "que hacer en caso de que un error ocurra".

// Si no le decimos al programa que hacer en caso de encontrar un error, el programa se detendra
// por completo. Podemos evitar esto gracias a los bloques 'try-catch'.

// Por ejemplo, intentemos usar una variable que no esta declarada. Si intentamos hacer esto, el
// programa retornará una "excepcion" y se detendra inmediatamente.

//console.log(x); // Uncaught ReferenceError: x is not defined




// Podemos capturar el error que obtuvimos y hacer algo al respecto, evitando que el programa
// se detenga.

try {
    console.log(x);
} catch (errorCapturado) {
    console.log("Hubo un error. El contenido capturado es: " + errorCapturado);
}
// Hubo un error. El contenido capturado es: ReferenceError: x is not defined




// El objeto 'errorCapturado' es obtenido segun lo que el bloque 'try' retorne.

// 'throw' sirve para retornar una excepcion, que eventualmente debe ser capturado por un bloque 'catch'.

// Programa lanza (throw) una excepcion. La excepcion es atrapada (catch) para realizar una accion.

var variable = "";

try {
    if (variable == "") {
        throw "El string esta vacio.";
    }
} catch (err) {
    console.log("Ocurrio un error!!! Excepcion: " + err);
}
// Ocurrio un error!!! Excepcion: El string esta vacio.



// Ademas, se puede añadir un bloque adicional llamado 'finally', la cual siempre ejecutara codigo
// sin importar el resutado del bloque 'try'.
var variable = "Hola";

try {
    if (variable == "") {
        throw "El string esta vacio.";
    }
} catch (err) {
    console.log("Ocurrio un error!!! Excepcion: " + err);
} finally {
    console.log("Continuando....")
}
// Continuando....
