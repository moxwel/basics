# Variables de entorno

Cada contenedor es un entorno diferente e independiente de otros. Cuando descargamos una imagen
creada por un tercero es muy probable que debamos configurarlo primero, y para eso debemos hacer
uso de **variables de entorno**.

Las variables de entorno son variables que se definen y están disponibles en todo el sistema (entorno)
que se está ejecutando.

> TIP: Busca "variables de entorno" en el buscador de Windows y podrás ver una ventana con todas las
> variables definidas para tu sistema.

En el kernel Linux que Docker utiliza también existen variables de entorno, y en este caso
se utiliza para poder configurar ciertos parámetros de la aplicación que se tiene contenida en los
containers.

Las variables de entorno **se definen al momento de crear un contenedor**. Para poder definir variables
de entorno se debe utilizar la opción `-e <nombre_variable=<valor>` **por cada una** que queramos definir.

> Cada imagen tiene diferentes variables de entorno que se pueden utilizar. **Lee la documentación.**

---

## Por ejemplo...

En la [documentación de la imagen de MongoDB](https://hub.docker.com/_/mongo), se hace mención de
las variables de entorno que se pueden definir, que son `MONGO_INITDB_ROOT_USERNAME` y `MONGO_INITDB_ROOT_PASSWORD`.
Estas variables de entorno permiten crear un usuario y contraseña de administrador para MongoDB en el container.

Para poder crear un contenedor definiendo dichas variables de entorno se puede usar el comando:

```
$ docker create -p 27017:27017 --name amongo -e MONGO_INITDB_ROOT_USERNAME=maxim -e MONGO_INITDB_ROOT_PASSWORD=password mongo
```

Si ahora corremos el contenedor, podremos conectarnos a la base de datos usando la dirección `mongodb://maxim:password@localhost:27017`.
