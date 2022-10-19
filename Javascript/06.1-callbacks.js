// Las funciones pueden recibir otras funciones como parametros.
// Cuando ese parametro se llama dentro de la funcion, se denomina 'callback'.

// Definamos una calculadora.

function calculadora(num1, num2, operacion) {
    console.log("Los numeros ingresados son: " + num1 + " y " + num2);

    let resultado = operacion(num1, num2);

    console.log("El resultado es: " + resultado);
}

// Notese como el parametro 'operacion' se llama como funcion para definir una variable 'resultado'.
// Pero hasta el momento, 'operacion' nisiquiera esta definido como tal.

// Definamos algunas operaciones genericas

function sumar(x,y) {return x+y}
function restar(x,y) {return x-y}




// Llamemos a la calculadora con las operaciones que hemos definido:

calculadora(5,6,sumar);
// Los numeros ingresados son: 5 y 6
// El resultado es: 11

calculadora(7,12,restar);
// Los numeros ingresados son: 7 y 12
// El resultado es: -5

// NOTA: cuando pasamos funciones como parametros, no se deben usar parentesis
