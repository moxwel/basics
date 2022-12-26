# Composición de contenedores

Imaginemos que debemos crear diferentes contenedores para diferentes servicios, y que ademas estas deben estar
conectadas entre sí.

Una alternativa es crear los diferentes contenedores de manera manual, con cada comando y `Dockerfile` necesario,
pero como se puede intuir, esto es muy tedioso.

**Docker compose** es una manera de crear diferentes contenedores con diferentes configuraciones y conectadas entre
si al mismo tiempo. A esto se le llama una **composicion de contenedores**. Para poder realizar esto debemos crear
un archivo llamado `docker-compose.yaml` que conteiene indicaciones de como deben construirse los contenedores
dentro de la composición.

## Sintaxis

La sintaxis del archivo YAML debe ser de este estilo:

```yaml
services:
  contenedor1:
    image: imagen/etiqueta
    ports:
      - "3000:3000"
      - "8080:8080"
      - ...
    networks:
      - mired1
      - mired2
      - ...
    links:
      - contenedor2
      - ...
    environment:
      - variable1=valor
      - variable2=valor
      - ...
  contenedor2:
    build: .
    ports:
      - ...
    networks:
      - ...
    ...
  ...
```

* **Services**: Contiene una lista de todos los contenedores que se crearán en la composición.
  * **Nombre del contenedor**
    * **Image**: Nombre de la imagen con el cual se construirá el contenedor. Equivalente a `docker pull`.
    * **Build**: Ubicación del archivo `Dockerfile` en el caso de que la imagen se deba construir a traves de dicho archivo. Equivalente a `docker build`
    * **Ports**: Lista de puertos que se van a mapear entre el sistema host y el anfitrión. Equivalente a la opcion `-p <puerto_anfitrión>:<puerto_contenedor>`.
    * **Networks**: Lista de redes Docker que el contenedor será parte. Equivalente a la opción `--network <nombre_red>`.
    * **Links**: Lista de contenedores las cuales el contenedor actual debe poder conectarse. Esto es util en vez de definir redes Docker.
    * **Environment**: Lista de variables de entorno que se deben definir en el contenedor. Equivalente a la opción `-e <nombre_variable=<valor>`.

## Crear composiciones

Para construir la composición, se debe utilizar el comando:

```
$ docker compose up
```

El comando buscará en la carpeta actual el archivo `docker-compose.yaml` y comenzará a construir las imágenes y los contenedores.

> El nombre de la composición sera el mismo nombre de la carpeta donde se ubica el proyecto.

> El nombre de las imágenes construidas con `build` tendrá el nombre de la carpeta donde se ubica el proyecto seguido del nombre del contenedor que lo utiliza.

> Luego de ejecutar, aparecerán los logs de todos los contenedores. Para evitar esto se puede usar la opcion `-d`.

Una vez creado todo, se puede volver a utilizar el mismo comando para volver a ejecutar los contenedores que ya se crearon.

## Eliminar composiciones

En vez de borrar todo manualmente, se puede usar el siguiente comando para borrar todo lo referente a una composición (sus contenedores, imágenes creadas y redes Docker).

```
$ docker compose down
```

> El comando se debe ejecutar dentro de la carpeta del proyecto.
