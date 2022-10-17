// Los objetos en Javascript son parecidos a un diccionario en Python.

// Un objeto consiste en una coleccion de pares de datos nombre:valor llamados 'Propeidades'.

var miObjeto = {nombre:'Max', edad:22, color:'Azul'};

// Para obtener los datos de una propiedad, se puede hacer de dos maneras:

miObjeto.nombre; // Max

miObjeto['nombre']; // Max

// Algunos tipos de datos poseen propiedades nativas, por ejemplo, la propiedad 'length' sirve para obtener el
// tamaño de un string (el numero de caracteres)

var unString = "Esto es un string";

console.log(unString.length); // 17

// Una propiedad puede contener cualquier tipo de dato, desde numeros, strings, hasta funciones.

// Cuando una propiedad contiene una funcion, este se llama 'Metodo'. Por ejemplo, la funcion 'log()' del objeto 'console'

console.log("Estoy usando un metodo");

// Por ejemplo:

var persona = {
    nombre: "Bob",
    edad: 25,
    color: "Rojo",
    cambiarNombre: function(nuevoNombre) { // Funcion anonima asignado a propiedad 'cambiarNombre'
        this.nombre = nuevoNombre; // La palabra clave 'this' hace mencion a las propiedades del objeto mismo,
    }                              // en este caso 'this.nombre' hace mencion a la propiedad 'nombre' que se definio antes.
}

// Ahora el objeto persona puede cambiar su nombre.

console.log(persona.nombre); // Bob

persona.cambiarNombre("Pip");

console.log(persona.nombre); // Pip
