// Podemos crear un objeto escribiendolo literalmente como lo hicimos anteriormente.

var unAuto = {
    marca: "Kia",
    puertas: 4,
    color: "Celeste",
    cambiarColor: (nuevoColor) => {this.color = nuevoColor}
}

// O de manera alternativa, podemos utilizar una 'funcion constructor' de objetos.

function Auto(m, p, c) {
    this.marca = m;
    this.puertas = p;
    this.color = c;
    this.cambiarColor = (nuevoColor) => {this.color = nuevoColor};
    // 'this.color' hace mencion a la propedad 'color' del objeto creado por 'Auto()'.
}

// La funcion 'Auto()' es un constructor que nos permitirá crear objetos de tipo 'Auto'. Por convencion, las funciones constructores
// de objetos comienzan con mayusculas. Para crear un objeto con este constructor, es necesario utilizar la palabra clave 'new', asignemoslo
// a una variable.

var miAuto = new Auto("Citroen", 4, "Gris");

// Ahora miAuto es un objeto de tipo 'Auto', y posee las propiedades 'marca', 'puertas' y 'color'.

console.log(miAuto.marca); // Citroen

console.log(miAuto.color); // Gris

miAuto.cambiarColor("Celeste");

console.log(miAuto.color); // Celeste
