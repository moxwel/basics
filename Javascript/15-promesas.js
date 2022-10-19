// En todos los procesos que toman tiempo nos encontraremos con dos elementos:
// - Aquel que produce (quien se DEMORA en terminar una tarea)
// - Aquel que consume (quien debe ESPERAR a que la tarea termine para poder usar su resultado)

// Las 'Promesas' en Javascript son objetos que vinculan un codigo que 'produce' con el codigo que 'lo consume'.
// Representan el eventual exito (o fallo) de algun codigo que "se demora" en completarse.

// Una promesa puede estar en 3 estados:
// - pendiente (pending)  : aun no se sabe el resultado
// - cumplido (fulfilled) : la promesa ha sido un exito
// - rechazado (rejected) : la promesa fracasó

// Cuando una promesa recien se inicia, siempre comienza como pendiente. Una vez haya
// terminado (ya sea con exito o fracaso), se dice que la promesa esta resuelta o establecida (settled).




// Aquel que produce:

let miPromesa = new Promise((funcionExito, funcionFracaso) => {

    // Codigo asincrono (que puede demorarse)...


    // Ejecutores de promesa.
    // Estas funciones causaran que la promesa se resuelva en un exito (o fracaso).
    // Aqui, uno decide CUANDO 'aceptar' o 'rechazar' la promesa.
    funcionExito(unValor);
    funcionFracaso(unError);
})



// Aquel que consume:
// Aqui se decide QUE HACER una vez la promesa se haya resuelto
miPromesa
    .then((valor) => {
        // Codigo que se ejecuta cuando la promesa se haya cumplido.
        // La variable 'unValor' se recibe aqui.
    })
    .catch((error) => {
        // Codigo que se ejecuta cuando la promesa haya fracasado.
        // La variable 'unError' se recibe aqui.
    })
    .finally(() => {
        // Opcional.
        // Este bloque siempre se ejecutara no importa el resultado.
    })
