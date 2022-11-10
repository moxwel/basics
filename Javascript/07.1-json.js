// JSON es el lenguaje de notacion de objetos de Javascript. Se utiliza para poder transportar
// informacion a diferentes sistemas en forma de objetos Javascript.

/*
JSON:

{
    "empleados":[
        {
            "nombre":"John",
            "apellido":"Doe"
        },
        {
            "nombre":"Anna",
            "apellido":"Smith"
        },
        {
            "nombre":"Peter",
            "apellido":"Jones"
        }
    ]
}
*/

// Por ejemplo, teniendo un string en formato JSON (obtenido de algun archivo o respuesta web),
// podemos guardarlo en una variable y luego poder manipularlo como un objeto Javascript.

var string = '{"empleados":[{"nombre":"John","apellido":"Doe"},{"nombre":"Anna","apellido":"Smith"},{"nombre":"Peter","apellido":"Jones"}]}';

// Le decimos a Javascript que transforme este string de texto en un objeto Javascript.

var objeto = JSON.parse(string);

console.log(objeto);
// {
//   empleados: [
//     { nombre: 'John', apellido: 'Doe' },
//     { nombre: 'Anna', apellido: 'Smith' },
//     { nombre: 'Peter', apellido: 'Jones' }
//   ]
// }



// Ahora que tenemos un objeto, podemos tratarlo como normalmente se haria en Javascript.

console.log(objeto.empleados[1].apellido); // Smith




// Tambien podemos hacerlo "al reves": tener un objeto Javascript, y transformarlo a string.

var mis_juegos = {
    juegos: [
        {
            nombre: "MarioBros",
            genero: "plataformas",
            tiempo: 90
        },
        {
            nombre: "Tetris",
            genero: "puzzle",
            tiempo: 70
        }
    ]
}

var mis_juegos_string = JSON.stringify(mis_juegos)
// '{"juegos":[{"nombre":"MarioBros","genero":"plataformas","tiempo":90},{"nombre":"Tetris","genero":"puzzle","tiempo":70}]}'

// NOTA: Los metodos de un objeto Javascript no se conservaran al momento de convertir a string!!
