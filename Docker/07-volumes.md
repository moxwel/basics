# Volúmenes

Un contenedor Docker tiene su propio sistema de archivos, y cuando eliminamos
dicho contenedor, todo su sistema de archivos también se elimina. En otras
palabras, cuando eliminamos un contenedor, los datos que posee también se
eliminan.

Puede existir el caso en el que no queremos que esto suceda, es decir, tener
datos persistentes entre contenedores.

Los volúmenes nos permiten realizar esto. Un volumen es una "carpeta" que existe
fuera de un contenedor, pero que esta montado en una dirección especifica dentro
del contenedor.

Para **listar los volúmenes** disponibles se usa el comando:

```
$ docker volume ls
```

Para **crear un volumen** debemos usar el comando:

```
$ docker volume create <nombre_volumen>
```

Para **borrar un volumen** se debe usar el comando:

```
$ docker volume rm <nombre_volumen>
```

## Crear contenedores con volumen

Para crear un contenedor usando un volumen, se debe mencionar usando la opción
`-v <nombre_volumen>:<dirección_destino>`. Donde la dirección de destino es una
ubicación dentro del sistema de archivos del contenedor.

```
$ docker volume create mongo_db_data

$ docker create -p 27017:27017 --name amongo --network mi_red_mongo -e MONGO_INITDB_ROOT_USERNAME=maxim -e MONGO_INITDB_ROOT_PASSWORD=password -v mongo_db_data:/data/db/ mongo
```

> Podemos utilizar la opción `-v` tantas veces como volúmenes queremos montar.

En este caso: dentro del contenedor, los archivos ubicados en `/data/db/`
estarán siendo guardados en el volumen `mongo_db_data`.

Si borramos el contenedor, los datos dentro de ese volumen no se borrarán.
Incluso podemos crear otro contenedor y montar el mismo volumen, y de esta forma
los datos seguirán funcionando.

## Montar carpetas del sistema anfitrión

Los volúmenes son **sistemas de archivos internos de Docker** que permiten mantener
datos persistentes luego de eliminar contenedores.

Puede que exista la necesidad de poder acceder a los archivos del sistema
anfitrión desde el contenedor. Podemos crear un volumen que tenga como origen
una carpeta dentro del sistema anfitrión; a esto le llamamos **montajes de unión**.

Esto permite que una carpeta del sistema anfitrión actúe como volumen en un
contenedor. Para poder definir un montaje de unión debemos darle como "nombre de
volumen" una **dirección de alguna carpeta de nuestro sistema anfitrión**.

```
$ docker create -p 27017:27017 --name amongo --network mi_red_mongo -e MONGO_INITDB_ROOT_USERNAME=maxim -e MONGO_INITDB_ROOT_PASSWORD=password -v C:\montaje\data\db\:/data/db/ mongo
```

En este caso, la ubicación dentro de Windows `C:\montaje\data\db\` va a empezar
a almacenar todos los archivos que se generen dentro del contenedor en la
ubicación `/data/db/`.
