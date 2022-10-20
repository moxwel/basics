// Cuando solicitas un viaje en Uber, un conductor crea una promesa para ir a buscarte.
// Mientras esperas la respuesta del conductor, la promesa esta pendiente.
// Luedo de un rato, si el conductor acepta el viaje, entonces la promesa se ha cumplido.
// En otro caso, si el conductor decide no aceptar el viaje, entonces la promesa ha fracasado.
// De todas maneras, al recibir la respuesta del conductor, la promesa se ha resuelto.



var viaje = new Promise((resolve, reject) => {

    let tiempoEspera = Math.floor(Math.random()*6000); // Numero aleatorio entre 0 y 6000

    // Esta funcion se demorará en ejecutarse (simulando codigo asincrono)
    setTimeout(() => {

        let aceptarViaje = Math.round(Math.random()); // Numero aleatorio, puede ser 0 o 1.

        // Si el conductor acepta el viaje, se ejecutará la funcion de exito, en caso contrario
        // se ejecutara la funcion de fracaso.
        if (aceptarViaje) {

            let idViaje = Math.floor(Math.random()*10000); // Numero aleatorio entre 0 y 10000.
            let mensajeConductor = "Voy en camino!!";

            resolve({
                mensaje: mensajeConductor,
                tiempo: tiempoEspera,
                id: idViaje
            });

        } else {

            let mensajeConductor = "Estas muy lejos.";

            reject({
                mensaje: mensajeConductor,
                tiempo: tiempoEspera
            });
        }

    }, tiempoEspera);

});



viaje
    .then(
    (result) => {
        console.log(`Tu conductor ha aceptado el viaje!\n\nMensaje del conductor: \"${result.mensaje}\"\nTiempo de espera: ${result.tiempo} ms\nID de viaje: #${result.id}`)
    },
    (error) => {
        console.log(`Tu conductor ha rechazado el viaje...\n\nMensaje del conductor: \"${error.mensaje}\"\nTiempo de espera: ${error.tiempo} ms`)
    })