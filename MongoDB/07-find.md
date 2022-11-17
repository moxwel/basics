# 07 - Buscar documentos

## Mostrar en pantalla

Para mostrar los documentos de una coleccion, debemos usar el metodo `find()`.

Este metodo en realidad sirve para buscar, pero si lo utilizamos sin ingresarle
ningun parametro, entonces nos retorna todos los elementos de la coleccion.

```
miTienda> db.productos.find()

[
  {
    _id: ObjectId("637599748e7de5cc2caac5e6"),
    nombre: 'PC',
    marca: 'Lenovo',
    tags: [ 'gaming', 'oficina' ],
    precio: 400000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e7"),
    nombre: 'Mouse',
    marca: 'Razer',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 80000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e8"),
    nombre: 'Teclado',
    marca: 'Logitech',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 50000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e9"),
    nombre: 'Monitor',
    marca: 'LG',
    tags: [ 'perifericos' ],
    precio: 50000
  }
]
```

> **NOTA**: Notese la propiedad `_id` que se creó en cada objeto que insertamos anteriormente.
Esta propiedad lo crea MongoDB para registrar un identificador unico a cada elemento.

## Buscar elementos

Para buscar elementos usando `find(<object>)`, el parametro que le damos sera el criterio de
coincidencia. Si algun elemento posee las propiedades que ingresamos, entonces las muestra por pantalla.

Por ejemplo:

```
miTienda> db.productos.find({nombre:"Teclado"})

[
  {
    _id: ObjectId("637599748e7de5cc2caac5e8"),
    nombre: 'Teclado',
    marca: 'Logitech',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 50000
  }
]
```

```
miTienda> db.productos.find({tags: "perifericos"})

[
  {
    _id: ObjectId("637599748e7de5cc2caac5e7"),
    nombre: 'Mouse',
    marca: 'Razer',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 80000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e8"),
    nombre: 'Teclado',
    marca: 'Logitech',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 50000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e9"),
    nombre: 'Monitor',
    marca: 'LG',
    tags: [ 'perifericos' ],
    precio: 50000
  }
]
```

```
miTienda> db.productos.find({tags: {$all: ["gaming", "perifericos"]}})

[
  {
    _id: ObjectId("637599748e7de5cc2caac5e7"),
    nombre: 'Mouse',
    marca: 'Razer',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 80000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e8"),
    nombre: 'Teclado',
    marca: 'Logitech',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 50000
  }
]
```

## Seleccionar datos

Al encontrar datos, podemos decir que datos queremos obtener como segundo parametro
de `find(<object>,<object>)`. El segundo parametro se trata de un objeto en
donde podemos tomar el nombre de alguna propiedad y usando 1 (true) o 0 (false),
decirle a MongoDB que lo considere o no.

```
miTienda> db.productos.find({tags: "perifericos"},{nombre:1,precio:1})

[
  {
    _id: ObjectId("637599748e7de5cc2caac5e7"),
    nombre: 'Mouse',
    precio: 80000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e8"),
    nombre: 'Teclado',
    precio: 50000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e9"),
    nombre: 'Monitor',
    precio: 50000
  }
]
```

## Ordenar datos

Usando el metodo `sort(<object>)` podemos especificar respecto a que propiedades deseamos
ordenar los datos retornados.

```
miTienda> db.productos.find().sort({nombre:1})

[
  {
    _id: ObjectId("637599748e7de5cc2caac5e9"),
    nombre: 'Monitor',
    marca: 'LG',
    tags: [ 'perifericos' ],
    precio: 50000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e7"),
    nombre: 'Mouse',
    marca: 'Razer',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 80000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e6"),
    nombre: 'PC',
    marca: 'Lenovo',
    tags: [ 'gaming', 'oficina' ],
    precio: 400000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e8"),
    nombre: 'Teclado',
    marca: 'Logitech',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 50000
  }
]
```

## Límites

Podemos establecer una cantidad maxima de elementos a mostrar con el metodo `limit(<int>)`.

```
miTienda> db.productos.find().limit(2)

[
  {
    _id: ObjectId("637599748e7de5cc2caac5e6"),
    nombre: 'PC',
    marca: 'Lenovo',
    tags: [ 'gaming', 'oficina' ],
    precio: 400000
  },
  {
    _id: ObjectId("637599748e7de5cc2caac5e7"),
    nombre: 'Mouse',
    marca: 'Razer',
    tags: [ 'gaming', 'oficina', 'perifericos' ],
    precio: 80000
  }
]
```

## Contar

Podemos obtener la cantidad de datos que hay en una consulta usando el metodo `count()`.

```
miTienda> db.productos.find().count()

4
```

## forEach

Incluso podemos crear una funcion de Javascript que recorra todos los elementos de una consulta, gracias al comando `forEach(<function>)`.

```
miTienda> db.productos.find().forEach((producto)=>{print("Producto: " + producto.nombre + " --- Precio: " + producto.precio)})

Producto: PC --- Precio: 400000
Producto: Mouse --- Precio: 80000
Producto: Teclado --- Precio: 50000
Producto: Monitor --- Precio: 50000
```

> **NOTA**: En Mongosh no existe `console.log()`, en cambio existe `print()` que
cumple la misma función.

> **NOTA**: El parametro que recibe `forEach()` es una _funcion_. En este ejemplo
se le ingresó una función anonima de Javascript. Recomiendo revisar su sintaxis.
