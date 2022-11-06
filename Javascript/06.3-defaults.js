// Se pueden definir valores por defecto en los parametros de una funcion.

function saludo(nombre = "Persona") {
    console.log("Saludos " + nombre + ".");
}

// Cuando una funcion se llama y no se le define valores a los parametros,
// los valores por defecto toman su lugar.

saludo("Max"); // Saludos Max
saludo(); // Saludos Persona
