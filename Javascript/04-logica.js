// Esiten comparadores logicos que pueden comparar diferentes tipos de datos y retornar un
// valor booleano.

// La gran mayoria tienen la misma sintaxis que C.

5 < 10; // true
5 > 10; // false
5 <= 15; // true
10 >= 10; // true
5 != 5; // false

// Sin embargo, existe una diferencia en iguadlades:

'10' == 10; // true - Igualdad de valor
'10' === 10; // false - Igualdad de valor y tipo

// El operador 'igual a' (==) utiliza correccion de tipo, sin embargo 'identico a' (===) no.

// Se recomienda siempre usar === al comparar diferentes cosas entre si, de esta manera se
// asegura que se estan comparando elementos del mismo tipo.



// Tambien existen operadores logicos que permiten realizar comparaciones entre valores booleanos.

// AND

true && true; // true
true && false; // false
false && false; // false

// OR

true || true; // true
true || false; // true
false || false; // false

// NOT

!true; // false
!false; // true


// Estos comparadores y operadores logicos se pueden usar en bloques de condiciones:

if (cond) {
    // si condicion es true...
}

if (cond) {
    // si condicion es true...
} else {
    // si condicion es false...
}

if (cond1) {
    // si condicion 1 es true...
} else if (cond2) {
    // si condicion 2 es true...
} else {
    // si ninguna condicion anterior se cumple...
}

switch (exp) {
    case value1:
        // si la expresion se evalua en value1...
        break;

    case value2:
        // si la expresion se evalua en value2...
        break;

    default:
        // si ninguno de lo anterior se cumple...
}