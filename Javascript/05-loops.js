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

    if (x == 5) {
        break;
    }

    console.log(x);
    x++;
}

// 0
// 1
// 2
// 3
// 4

x = 0;
while (x < 10) {

    if (x == 5) {
        x++;
        continue;
    }

    console.log(x);
    x++;
}

// 0
// 1
// 2
// 3
// 4
// 6
// 7
// 8
// 9