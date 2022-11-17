# 06 - Insertar documentos

Recordemos que un **documento** para MongoDB son los datos que queremos guardar, y
que estan en formato JSON.

Para poder insertar datos a nuestra base de datos, debemos usar el metodo `insert(<object>)` o `insertOne(<object>)`.

Y se utiliza de la siguiente manera:

```
miTienda> db.productos.insertOne({"nombre":"PC","marca":"Lenovo","precio":400000})

{
  acknowledged: true,
  insertedId: ObjectId("63758f188e7de5cc2caac5db")
}
```

Descomponiendo el codigo:

* `db` : Utilizando la base de datos actual...
  * `productos` : ...en la coleccion llamada "productos"...
    * `insertOne()` : ...insertar un documento allí.
      * El documento en cuestion:
      ```json
      {
        "nombre" : "PC",
        "marca"  : "Lenovo",
        "tags"   : ["gaming", "oficina"],
        "precio" : 400000
      }
      ```

> **NOTA**: Los documentos _siempre_ van dentro de una coleccion. Las colecciones
se crean al momento de insertar elementos. Y de la misma manera que con las
bases de datos: si la colección esta vacia, MongoDB lo ignora.

## Creacion de colecciones

Vimos que utilizando `insertOne()`, si la coleccion a la que queremos insertar
no existe, entonces MongoDB lo crea automaticamente.

De manera alternativa, podemos crear manualmente una coleccion utilizando el metodo
`createCollection()`.

## Insertando mas elementos

Podemos insertar mas documentos en un mismo comando usando `insertMany(<array>)`.

Los objetos que queremos ingresar debemos agruparlos en un arreglo.

Por ejemplo:

```json
[
  {
    "nombre" : "Mouse",
    "marca"  : "Razer",
    "tags"   : ["gaming", "oficina", "perifericos"],
    "precio" : 80000
  },
  {
    "nombre" : "Teclado",
    "marca"  : "Logitech",
    "tags"   : ["gaming", "oficina", "perifericos"],
    "precio" : 50000
  },
  {
    "nombre" : "Monitor",
    "marca"  : "LG",
    "tags"   : ["perifericos"],
    "precio" : 50000
  }
]
```

Y eso ingresarlo en consola:

```
miTienda> db.productos.insertMany([{"nombre" : "Mouse","marca"  : "Razer","tags"   : ["gaming", "oficina", "perifericos"],"precio" : 80000},{"nombre" : "Teclado","marca"  : "Logitech","tags"   : ["gaming", "oficina", "perifericos"],"precio" : 50000},{"nombre" : "Monitor","marca"  : "LG","tags"   : ["perifericos"],"precio" : 50000}])

{
  acknowledged: true,
  insertedIds: {
    '0': ObjectId("637597e98e7de5cc2caac5df"),
    '1': ObjectId("637597e98e7de5cc2caac5e0"),
    '2': ObjectId("637597e98e7de5cc2caac5e1")
  }
}
```
