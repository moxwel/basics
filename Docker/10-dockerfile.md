# Dockerfile

`Dockerfile` es un archivo que contiene instrucciones para construir imágenes.

Este archivo se puede utilizar en un proyecto para crear un imagen que pueda
crear un contenedor que almacene la aplicación que estamos desarrollando.

## Docker build

Para construir la imagen en base a un archivo `Dockerfile`, se debe utilizar el comando:

```
$ docker build -t <nombre_imagen>:<etiqueta> <dirección_dockerfile>
```

> La opción `-t` sirve para ingresar el nombre de la imagen y su respectiva etiqueta.

Una vez hecho esto, podemos usar `docker create` para crear un contenedor con dicha imagen que creamos.

---

# Sintaxis de `Dockerfile`

## FROM

Cada imagen que nosotros creemos debe basarse en otra imagen. La instrucción `FROM` nos dice
**la imagen base que Docker debe usar para comenzar a crear el contenedor**.

```
FROM <nombre_imagen>:<etiqueta>
```

> Equivalente a `docker pull`.

## RUN

Cuando un contenedor se crea, eventualmente quisiéramos ejecutar comandos de terminal antes de ejecutar
la aplicación, por ejemplo crear una carpeta, descargar una librería o dependencia, etc.

La instrucción `RUN` **ejecuta comandos en el terminal del sistema operativo que el contenedor esta corriendo**.
Recodemos que Docker corre en un kernel de Linux, asi que los comandos que ingresemos deben ser compatibles con dicho sistema.

```
RUN <comando>
```

> Podemos tener tantas instrucciones `RUN` como queramos.

## COPY

Cuando el contenedor esta creado, quisiéramos que el código de nuestra aplicación estuviese dentro
del contenedor. Para ello es necesario copiarlo dentro del contenedor.

La instrucción `COPY` permite copiar archivos de una carpeta del sistema operativo anfitrión hacia dentro del contenedor.

```
COPY <dirección_origen> <dirección_destino>
```

La dirección de origen debe ser una dirección del sistema operativo anfitrión (en este caso Windows), y la dirección de destino
debe ser una dirección dentro del sistema operativo del contenedor.

## WORKDIR

Esta instrucción cambia la carpeta actual a otra especificada. Esto afecta a todas las instrucciones que dependan
de la ubicación en donde se ejecutan como `RUN`, `CMD`, `COPY`, etc.

```
WORKDIR <dirección>
```

> Por defecto las direcciones son relativas. Si no existe la carpeta, se creará.

> Se puede utilizar varias veces.

## ENV

Esta instrucción define variables de entorno.

```
ENV <nombre_variable=<valor>
```

> Se puede utilizar varias veces para definir mas de una variable de entorno.

## EXPOSE

Hay casos donde una aplicación debe establecer comunicaciones a traves de un puerto. Por ejemplo, las aplicaciones con NodeJS
normalmente utilizan el puerto 3000 para recibir conexiones entrantes.

Para decirle a Docker que es necesario utilizar dicho puerto, es necesario exponerlo.

```
EXPOSE <puerto>
```

## CMD

A diferencia de `RUN`, la instrucción `CMD` **es única**, y es el ultimo comando que se debe ejecutar en el contenedor.

El proceso que `CMD` ejecuta debe ser perpetuo. En otras palabras: si la aplicación que `CMD` ejecuta se detiene,
entonces el contenedor se detendrá también.

`CMD` utiliza un arreglo donde se separa el comando con sus respectivos argumentos.

```
CMD ["comando", "arg1", "arg2, "arg3" , ...]
```
