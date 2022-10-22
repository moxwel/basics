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
    // Aqui se decide CUANDO 'aceptar' o 'rechazar' la promesa.
    if (exito) {
        funcionExito(unValor); // La promesa retorna el valor 'unValor'
    } else {
        funcionFracaso(unError); // La promesa lanza una excepcion con el valor 'unError'
    }
});

// Apenas se crea la promesa, el codigo asincrono comenzara a ejecutarse "en segundo plano", y eventualmente obtendrá un resultado.




// Aquel que consume: (capturadores de promesa)
// Aqui se decide QUE HACER una vez la promesa se haya resuelto
miPromesa
    .then((resultado) => {
        // Codigo que se ejecuta cuando la promesa se haya cumplido.
        // La variable 'unValor' (de la promesa) se recibe en el parametro 'resultado'.
    })
    .catch((error) => {
        // Codigo que se ejecuta cuando la promesa haya fracasado.
        // La variable 'unError' (de la promesa) se recibe en el parametro 'error'.
    })
    .finally(() => {
        // Opcional.
        // Este bloque siempre se ejecutara no importa el resultado.
    });




// El metodo 'then()' tambien puede recibir dos argumentos: la funcion a ejecutar cuadno la promesa se cumple,
// y la funcion a ejecutar cuando la promesa fracasa.

miPromesa
    .then(
    (resultado) => {
        // Codigo que se ejecuta cuando la promesa se haya cumplido.
        // La variable 'unValor' (de la promesa) se recibe en el parametro 'resultado'.
    },
    (error) => {
        // Codigo que se ejecuta cuando la promesa haya fracasado.
        // La variable 'unError' (de la promesa) se recibe en el parametro 'error'.
    });



// En resumen:
// - Una Promesa es un objeto en Javascript que ejecuta un codigo (que puede demorarse) y que obtendra un
//   resultado en un futuro.
// - Una Promesa es ejecutada inmeditamente despues de instanciarse (en el momento que se crea con 'new').
// - La Promesa se ejecuta en "segundo plano" mientras el resto del codigo sigue funcionando.
// - El metodo 'then()' de una promesa ejecuta codigo dependiendo del resultado que se haya obtenido de la promesa.
