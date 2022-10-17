// Como todo lenguaje, Javascript tiene capacidad para realizar operaciones aritmeticas.
// La sintaxis es parecida a C:

console.log(10 + 1) // xd

console.log(12 - 1) // yapo

console.log(25 * 3) // 75

console.log(100 / 2) // 50

console.log(56 % 3) // 2

// Se pueden usar variables para realizar operaciones

var x = 10
var y = 135
var z = (x + y*2)/5
console.log(z) // 56

// Si tenemos una operacion en forma de string, podemos resolverla utilizando la funcion 'eval()'

var operacion = "(10 + 4 + 2)/2 * 4"

console.log(eval(operacion)) // 32
