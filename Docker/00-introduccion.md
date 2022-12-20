# Introducción

Docker es un programa de virtualización que permite ejecutar contenedores.

A diferencia de una maquina virtual clásica que virtualiza todo, Docker se enfoca mas en la
virtualizacion del software. Es decir, a traves de un kernel compartido de Linux, las
aplicaciones que se ejecuten serán virtualizadas en diferentes ámbitos.

Para entender como funciona Docker, hay que tener en cuenta el concepto de contenedor y de imagen.

## ¿Que es un contenedor?

Un contenedor es una manera de "empaquetar" software, pero incluyendo las dependencias y el entorno
en donde se ejecuta dicho software. El contenedor posee los archivos como tal de una "mini maquina virtual".

El ejemplo clásico consiste en diferentes equipos de desarrollo, y cada uno con sus propias maquinas.
Cuando un equipo quiere transportar su software a otro equipo, el otro equipo debe adaptar sus dependencias
y herramientas necesarias para que dicho software pueda correr sin problema.

Con un contenedor, el problema anterior mencionado se resuelve de manera mas sencilla pues el software
y todas sus dependencias y configuraciones se transportan sin problema, y solo es necesario trabajar dentro
del contenedor.

## ¿Que es una imagen?

Una imagen es una "captura" del estado actual de algún software y sus dependencias y configuraciones.

En pocas palabras, una imagen es una maquina virtual "congelada" en el tiempo.

Los contenedores se construyen en base a imágenes. Por ejemplo, una imagen de una version
especifica de Ubuntu, o una imagen de algún software corriendo en cierto sistema operativo especifico
con ciertas configuraciones en especifico.

Incluso, desde una misma imagen se pueden crear multiples contenedores.
