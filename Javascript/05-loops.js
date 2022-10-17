// De la misma manera que en C, existen loops para realizar iteraciones.

while (cond) {
    // mientras la condicion sea verdadera, se repite...
}

do {
    // primero se ejecuta este bloque, y luego evalua la condicion. Si es verdadera, se repite...
} while (cond);

for (init; cond; incr) {
    // Inicializa variables, evalua condicion, ejecuta este bloque de codigo, y luego evalua incremento.
}

// Como siempre, el uso mas comun de for-loop

for (i = 0; i < 10; i++) {
    // codigo
}

// Se puede usar 'break' para salir de un loop, o 'continue' para saltar inmediatamente a una nueva iteracion

var x = 0;

while (x < 10) {     
    console.log(x);

    if (x == 5) {
        break;
    }

    x++;
}

while (x < 10) {
    console.log(x);

    if (x == 5) {
        continue;
    }

    x++;
}