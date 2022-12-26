# Puertos

Anteriormente creamos un contenedor corriendo MongoDB, y aunque funciona, no podemos conectarnos desde
"fuera" del contenedor, porque no tiene expuesto ningún puerto hacia el sistema anfitrión.

En este caso, el sistema anfitrion es nuestro PC con Windows, y el kernel Linux que utiliza Docker es el
sistema invitado. Los contenedores corren en Docker, y sus conexiones internas funcionan de
manera independiente a las del sistema anfitrión Windows.

Eventualmente quisieramos poder acceder a las conexiones internas de los contenedores, y para ello es
necesario exponer ciertos puertos hacia Windows, y ademas decirles como "mapearlos".

Crearemos un contenedor de la misma manera que antes, pero mapeando puertos. Para ello se añade la
opcion `-p <puerto_anfitrión>:<puerto_contenedor>`. Como ejemplo:

```
$ docker create -p 6000:27017 --name amongo mongo
```

En este ejemplo, 6000 es el puerto de nuestro sistema anfitrión (Windows), y 27017 el puerto de
nuestro sistema invitado (Contenedor).

Lo que quiere decir esto es: **si desde Windows se intenta conectar al puerto 6000, Docker va a
redirigir esa conexión al puerto 27017 de este contenedor**

> La opción `-p` se puede usar mas de una vez.
