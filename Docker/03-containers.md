# Contenedores

Una vez tenemos imágenes descargadas, podemos crear contenedores a partir de estas.

Para **crear un contenedor** a partir de una imagen, se debe usar el comando:

```
$ docker create <nombre_imagen>:<etiqueta>
```

> También sirve `docker container create`

> Si no se especifica etiqueta, se usa "latest"

> Si la imagen no existe localmente, se descargará primero.

Para ver una **lista de contenedores** se utiliza el siguiente comando:

```
$ docker ps -a
```

> El comando `docker ps` solo lista los contenedores que están corriendo actualmente. La opción
> `-a` permite listar todos los contenedores, incluso aquellos que no están en ejecución.

Cuando se crea un contenedor, Docker imprimirá el ID del contenedor, este se puede utilizar para
poder hacerle referencias y manipularlo en consola.

O también como alternativa, nosotros podemos **definir un nombre** usando la opción `--name`:

```
$ docker create --name <nombre_contenedor> <nombre_imagen>:<etiqueta>
```

> Si no se especifica un nombre, Docker eligirá uno de manera aleatoria.

> El nombre debe ser único para cada contenedor.

Para **iniciar un contenedor**, se utiliza el siguiente comando:

```
$ docker start <nombre|id>
```

Para **detener un contenedor**, se utiliza el siguiente comando:

```
$ docker stop <nombre|id>
```

Para **borrar un contenedor**, se utiliza el siguiente comando:

```
$ docker rm <nombre|id>
```

> Para borrar un contenedor, este debe estar detenido.

---

## Por ejemplo...

```
$ docker create --name amongo mongo
9c9f1fc5f35628ea4ebb2148dbff1ad0e85a8462ba1c4628c7fbb2e7d402585b

$ docker start amongo
amongo

$ docker ps
CONTAINER ID  IMAGE  COMMAND            CREATED        STATUS        PORTS      NAMES
9c9f1fc5f356  mongo  "docker-entry..."  4 minutes ago  Up 4 minutes  27017/tcp  amongo
```

Nótese la columna `NAME`. Este nombre es un segundo identificador para poder hacer
referencia a nuestro contenedor.

La columna `PORT` nos dice que actualmente el contenedor esta utilizando el puerto 27017, sin
embargo no nos sirve de nada porque desde nuestra maquina anfitrión no podemos acceder a los puertos de dichos
contenedores (recordemos que los contenedores son pequeñas maquinas virtuales).

A continuación veremos como conectarnos a un contenedor.

---

## Logs

Cuando un contenedor se ejecuta, Docker tendrá un registro de lo que esta sucediendo en su terminal.
Para acceder a los registros (logs) de un contenedor, se puede usar el comando:

```
$ docker logs <nombre_contenedor|id>
```

> Si se añade la opción `--follow`, la consola se mantendrá en los registros y se actualizará cuando
> ocurran cambios.

## Docker Run

Existe un comando que combina la creación de imágenes y de contenedores de manera automática.

```
$ docker run <nombre_imagen>
```

Este comando buscara la imagen, la descargará de ser necesario, **creará un contenedor nuevo** y
la ejecutara, mostrando y siguiendo los logs de este.

Si se intenta salir de la consola en ese estado, el contenedor se detendrá. Para evitar mostrar
los logs y poder seguir utilizando el terminal, se debe usar con la opcion `-d` o `--detach`.

> Las opciones `--name`, `-p` tambien se pueden usar con este comando. 
