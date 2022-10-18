// Podemos crear un objeto escribiendolo literalmente como lo hicimos anteriormente.

var algunAuto = {
    marca: "Kia",
    puertas: 4,
    color: "Celeste",
    cambiarColor: (nuevoColor) => {this.color = nuevoColor}
}

// O de manera alternativa, podemos utilizar una funcion 'constructor' de objetos.

function Auto(m, p, c) {
    this.marca = m;
    this.puertas = p;
    this.color = c;
    this.cambiarColor = (nuevoColor) => {this.color = nuevoColor};
    // 'this' hace mencion a las propieades que tendran los objetos creados por 'Auto()'.
}

// Tener una funcion constructor nos facilita la tarea de crar varios objetos del mismo tipo.

// Por convencion, las funciones constructores de objetos comienzan con mayusculas.

// Para crear un objeto con este constructor, es necesario utilizar la palabra clave 'new'

var auto1 = new Auto("Citroen", 4, "Gris");
var auto2 = new Auto("Hyundai", 4, "Blanco");
var auto3 = new Auto("BMW", 2, "Negro");

// Ahora auto1, auto2 y auto3 son objetos de tipo 'Auto', y posee las propiedades 'marca', 'puertas', 'color', y el metodo 'cambiarColor.

console.log(auto1);
// Auto {
//     marca: 'Citroen',
//     puertas: 4,
//     color: 'Gris',
//     cambiarColor: [Function]
// }

// Como cualquier objeto, podemos acceder a sus propiedades:

console.log(auto1.marca); // Citroen

console.log(auto1.color); // Gris

auto1.cambiarColor("Celeste");

console.log(auto1.color); // Celeste
