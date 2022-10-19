// Cuando solicitas un viaje en Uber, un conductor crea una promesa para ir a buscarte.
// Mientras esperas la respuesta del conductor, la promesa esta pendiente.
// Luedo de un rato, si el conductor acepta el viaje, entonces la promesa se ha cumplido.
// En otro caso, si el conductor decide no aceptar el viaje, entonces la promesa ha fracasado.
// De todas maneras, al recibir la respuesta del conductor, la promesa se ha resuelto.



let viaje = new Promise((exito, fracaso) => {

    let tiempoEspera = Math.floor(Math.random()*6000); // Numero aleatorio entre 0 y 6000

    setTimeout(() => {

        let aceptarViaje = Math.round(Math.random()); // Numero aleatorio, puede ser 0 o 1.

        // Si el conductor acepta el viaje, se ejecutará la funcion de exito, en caso contrario
        // se ejecutara la funcion de fracaso.
        if (aceptarViaje) {

            let idViaje = Math.floor(Math.random()*10000); // Numero aleatorio entre 0 y 10000.
            let mensajeConductor = "Voy en camino!!";

            exito( [mensajeConductor, tiempoEspera, idViaje] );

        } else {
            fracaso(tiempoEspera);
        }

    }, tiempoEspera);

});



viaje
    .then((respuesta) => {
        console.log(`Tu conductor ha aceptado el viaje!\n\nMensaje del conductor: \"${respuesta[0]}\"\nTiempo de espera: ${respuesta[1]} ms\nID de viaje: #${respuesta[2]}`)
    })
    .catch((respuesta) => {
        console.log(`Tu conductor ha rechazado el viaje...\n\nTiempo de espera: ${respuesta} ms`)
    })
