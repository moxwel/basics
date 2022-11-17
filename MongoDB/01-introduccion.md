# 01 - Introducción

## Sobre MongoDB

MongoDB es una base de datos no relacional NoSQL, es decir, no utiliza el estandar SQL para manejar
peticiones, sino que utiliza su propio lenguaje basado en Javascript.

MongoDB tambien es de tipo documental, es decir: a diferencia de, por ejemplo, MySQL, en Mongo no
existen datos en tablas, sino que existen "documentos" en colecciones.

Ademmas, por diseño, este tipo de base de datos **no están estructuradas**, es decir: pueden existir
datos con diferentes atributos y tipos de datos a comparacion de otro
base de datos muy flexible y moldeable.

Cada **"Documento"** en MongoDB en realidad es un __objeto JSON_, y una **"Coleccion"** es un conjunto de
**"Documentos"**.

Una Coleccion en Mongo puede ser el equivalente a una tabla en SQL, y un **documento** el equivalente
a una fila de la tabla.

Como esta base de datos es no relacional y no estrucutrada, no es necesario definir un modelo inicial,
se puede directamente ingresar datos como uno desee.

## Instalación

Para descargar MongoDB, se debe hacer desde su pagina. Recomiendo descargar ambos programas:

* MongoDB: https://www.mongodb.com/try/download/community

* MongoDB Shell: https://www.mongodb.com/try/download/shell

> **RECOMENDACION**: No marcar 'instalar como servicio' en Windows.

> **NOTA**: MongoDB Compass es una interfaz grafica para poder manipular la base de datos. Recomendado instalar.

Una vez descargado, añadir `C:/Program Files/MongoDB/Server/x.x/bin` (la ubicacion de instalacion) al PATH de Windows.

Al descargar MongoDB Shell, copiar los archivos a `MongoDB/Server/x.x/bin` tambien.

Deberian haber 3 ejecutables en esa carpeta `bin`:

* `mongod.exe` (servidor)

* `mongosh.exe` (shell de MongoDB)

* `mongos.exe` (proxy, no lo necesitaras, pero debe estar alli)

## Probar

Para ver si todo esta correcto, ejecutar los comandos en consola:

```
> mongod --version
```
```
> mongosh --version
```

Si ambos retornan datos, entonces esta todo listo.
