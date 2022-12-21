# Redes de Docker

Normalmente, cada contenedor esta aislada de todos los demás contenedores, es decir, no se
pueden comunicar entre sí.

Eventualmente podemos llegar a una situación en donde tenemos varios contenedores que quisiéramos
conectar entre sí, por ejemplo un contenedor de NodeJS y otro de MongoDB.

Para poder conectar diferentes contenedores entre sí, debemos **crear una red** interna de Docker, y que
dichos contenedores se creen en dicha red.

Para ver una **lista de las redes de Docker** actuales, se usa el comando:

```
$ docker network ls
```

Para **crear una red de Docker**, se usa el comando:

```
$ docker network create <nombre_red>
```

Para **borrar una red de Docker**, se usa el comando:

```
$ docker network rm <nombre_red|id>
```

## Creando contenedores en redes

Para crear un contenedor que es parte de una red de Docker, es necesario mencionarlo usando la opción
`--network <nombre_red>`. Por ejemplo:

```
$ docker network create mi_red_mongo

$ docker create -p 27017:27017 --name amongo --network mi_red_mongo -e MONGO_INITDB_ROOT_USERNAME=maxim -e MONGO_INITDB_ROOT_PASSWORD=password mongo
```

## Conexiones internas

Cuando creamos conexiones en nuestro PC y queremos conectarnos a "nosotros mismos", usamos el dominio `localhost`;
o en otro caso usamos una dirección IP.

En una red de Docker, las direcciones para conectarse a contenedores utilizan como nombre de dominio **el mismo
nombre del contenedor**.

En el caso anterior, si otro contenedor dentro de la misma red de Docker quisiera conectase a la base de datos de MongoDB
que se encuentra en el contenedor llamado `amongo`, entonces la dirección en vez de ser `mongodb://maxim:password@localhost:27017`
debiese ser `mongodb://maxim:password@amongo:27017`.
