// Las palabras clave 'async' y 'await' nos ayudan a manipular promesas y sus valores de manera mas sencilla.




// Si aplicamos 'async' a una funcion, esta se volverá una 'funcion asincronica'.
// El valor que retorna este tipo de funciones es como si fuese un valor pasado a la funcion de exito de una promesa.

async function miFuncion() {
    let unValor = "Esto es un resultado."

    return unValor; // Equivalente a 'return Promise.resolve(unValor)'
}

console.log(miFuncion); // [asyncFunction: miFuncionA]
console.log(miFuncion()); // Promise { 'Esto es un resultado.' }
miFuncion().then((resultado) => {console.log(resultado);}); // Esto es un resultado.

// Notese como no es necesario definir una funcion de rechazo en el capturador de promesa, ya que
// la funcion al retornar, siempre ejecuta la funcion de exito.




// 'await' detiene la ejecucion de un codigo sincronico, y espera a que una promesa termine de ejecutarse.
// El valor que retorna await es el resultado mismo de la promesa.
// (Solo se puede utilizar dentro de una funcion asincronica)

async function otraFuncion(){
    console.log(miFuncion()); // Promise { 'Esto es un resultado.' }
    console.log(await miFuncion()); // Esto es un resultado.
}

otraFuncion();







// Las funciones asincronicas nos permiten poder ejecutar codigo asincronico, y con 'await',
// nos permite poder esperar los resultados de las promesas.

// Por ejemplo, podemos tener una funcion asincronica que retorne una promesa, y que demore en ejecutar.

async function miPromesaFuncion() {
    return new Promise((result)=>{
        setTimeout(() => {
            result("Este resultado demora en obtenerse.");
        },2000);
    });
}

// Esta promesa será ejecutada en el momento que la funcion es llamada.





// Tengamos otra funcion que utilice el valor retornado por la funcion anterior.

async function ejecutarFuncionSinEsperar() {

    let resultado = miPromesaFuncion();

    console.log(resultado);
}

ejecutarFuncionSinEsperar(); // Promise { <pending> }

// Sin embargo, notemos como al intentar imprimir el resultado, la promesa aun esta ejecutandose.
// Esto sucede porque la variable resultado esta 'sincrono'. En otras palabras, se ejecuta inmeditamente
// sin esperar a que la promesa en 'miPromesaFuncion()' termine de dar la respuesta.





// Para evitar esto podemos utilizar 'await', para decirle a la funcion que detenga la ejecucion
// hasta que la promesa sea resuelta y su valor sea obtenido.

async function ejecutarFuncionConEspera() {

    let resultado = await miPromesaFuncion();

    console.log(resultado);
}

ejecutarFuncionConEspera(); // Este resultado demora en obtenerse.
