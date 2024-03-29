// Las variables declaradas con 'var' solo tienen dos contextos: global y funcion.
// Las variables declaradas dentro de una funcion no afectan hacia afuera.

function funcion() {
    console.log(x); // undefined
    var x = 2;
    console.log(x); // 2
}

var x = 10;

console.log(x); // 10

funcion();

console.log(x); // 10

// Sin embargo, con 'let' y 'const' tenemos otro contexto mas: bloque

// Dependiendo de como declaremos variables, podemos restringir su uso por contextos (o bloques)
// como por ejemplo un bloque 'if', 'while', 'for', etc.
// En otras palabras, utilizar variables dentro de un bloque de codigo, pero que fuera de dicho
// bloque, no pueda ser accesado (o no afecte a otras variables fuera).




var x = 5;

console.log(x); // 5

{
    var x = 2;
    console.log(x); // 2
}

console.log(x); // 2
// La variable definida dentro del bloque ha modificado a la variable definida fuera del bloque.




// Utilizar 'let' tiene efecto.

let y = 50;

console.log(y); // 50

{
    // Aqui, la variable 'y' no existe (dentro de este bloque), hay que declararla.
    let y = 20;
    console.log(y); // 20
}

console.log(y) // 50
// La variable definida dentro del bloque NO ha modificado a la variable definida fuera del bloque.
