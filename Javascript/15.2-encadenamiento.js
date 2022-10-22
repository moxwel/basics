// Cuando una promesa se resuelve, se obtiene un valor de respuesta. Pero es posible que
// un problema requiera de esa respuesta para resolverse.

// El problema no se puede resolver si aun no obtenemos respuesta de la promesa inicial mencionada.

// Podemos encadenar 'then()' para realizar eso: podemos tener una funcion, pero que antes de
// poder ejecutarse, debe esperar a que la promesa responda con una solucion.

var miPromesa = new Promise((resolve) => {

    console.log("[miPromesa] Ejecutando promesa...")

    setTimeout(()=>{

        resolve(10);

        console.log("[miPromesa] Promesa ejecutada.");

    }, 3000);

})



console.log("Esperando respuesta...")

miPromesa
    .then((result)=>{
        console.log("La respuesta es: " + result);
        return result;
    })
    .then((valor)=>{
        console.log("Miltiplicando valor recibido por 25...");
        let result = valor*25;
        return result;
    })
    .then((arg)=>{
        console.log("Dividiendo valor recibido por 7...");
        let result = arg/7;
        return result;
    })
    .then((valorFinal)=>{
        console.log("El valor final recibido es: " + valorFinal);
    })



// La gracia de usar esto, es que las funciones dentro del 'then()' podrian retornar otras
// promesas, y realizar otras cosas.
