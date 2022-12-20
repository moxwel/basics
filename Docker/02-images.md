# Imágenes

Como se mencionó en la introducción, los contenedores nacen desde una imagen (o un conjunto de estas).

Para conocer la lista de imágenes que tenemos disponibles de manera local (descargadas), usamos el comando:

```
$ docker images
```

> Tambien sirve `docker image ls`

Para descargar imágenes se utiliza el comando:


```
$ docker pull <nombre_repositorio>:<etiqueta>
```

> Tambien sirve `docker image pull`

Las imágenes se descargan desde un repositorio de imágenes, en este caso es
[Docker Hub](https://hub.docker.com/). El nombre de los repositorios y de sus
correspondientes etiquetas se obtiene desde allí.

Por ejemplo, instalemos una versión de NodeJS: podemos encontrar su
repositorio [aquí](https://hub.docker.com/_/node).

Podemos decirle a Docker que descargue la ultima version o una version especifica.

Para descargar la ultima version, se ingresa el nombre sin etiquetas:

```
$ docker pull node
```

Esto ultimo descargará la imagen que tenga la etiqueta "latest".

> Equivalente a decir `docker pull node:latest`

Para descargar una version especifica, se debe mencionar alguna etiqueta:

```
$ docker pull node:18
```

## Etiquetas

Las etiquetas en las imágenes son una forma de identificarlos entre si, incluso si se trata de
exactamente la misma imagen. En Docker Hub las etiquetas se utilizan para diferenciar diferentes
versiones de una imagen.

Por ejemplo, si quisiéramos descargar la imagen de Ubuntu 20.04, podemos utilizar el comando

```
$ docker pull ubuntu:20.04
```

Pero también podemos utilizar el comando:

```
$ docker pull ubuntu:focal
```

> NOTA: El nombre de la version de Ubuntu 20.04 es "Focal Fossa"

Y si vemos la información de las imágenes con `docker images`...

```
$ docker images

REPOSITORY   TAG       IMAGE ID       CREATED       SIZE
ubuntu       20.04     d5447fc01ae6   11 days ago   72.8MB
ubuntu       focal     d5447fc01ae6   11 days ago   72.8MB
```

Nótese que la ID de ambas imágenes es la misma, pero la etiqueta es la que cambia.

## Borrando imágenes

Para borrar una imagen, se utiliza el comando:

```
$ docker image rm <nombre_imagen>:<etiqueta>
```

> Si no se especifica etiqueta, buscará la etiqueta "latest".
