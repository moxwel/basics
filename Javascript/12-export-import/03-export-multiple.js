// Podemos exportar multiples elementos en un mismo archivo con un solo 'export'.

// En este caso, se exporta el objeto 'elementos' que contiene 3 cosas.

let elementos = {
    nombreArchivo: "Archivo de Prueba 3",
    mensaje: () => {console.log("Este mensaje se ha impreso gracias a 'archivo2.js'.")},
    multiplicarNumeros: (x,y) => {return x*y}
}

// Cuando se exporta un unico elemento, se puede usar la palabra 'default'.

export default elementos;

// Para poder importarlo en otro archivo, se debe usar sin llaves '{}'.
