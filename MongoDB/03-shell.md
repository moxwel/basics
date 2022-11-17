# 03 - Shell

Una vez abierto el servidor de Mongo, debemos conectarnos a este para poder realizar consultas.

El shell de Mongo es un interprete que nos permite ejecutar comandos directamente en la
base de datos, y realizar cambios y consultas.

Para ejecutar el shell de Mongo, hay que ejecutar en terminal:

```
> mongosh
```

Para saber si se conectó correctamente a la base de datos, nota la entrada del terminal, deberia decir:

```
Current Mongosh Log ID: <numero>
Connecting to: mongodb: <direccion>
Using MongoDB:          x.x.x
Using Mongosh:          x.x.x

<mas informacion>

test> _
```

**¡Has accedido a la base de datos!**
