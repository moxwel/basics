# Makefile

## ¿Que es makefile?

Makefile es un tipo de archivo especial que se utiliza con el programa ``make``.

``make`` es una herramienta que nos ayuda a automatizar la compilacion de varios archivos
en proyectos muy grandes.

## ¿Por que usar makefile?

En la seccion **_06-header_**, nos dimos cuenta que es posible hacer "compilacion separada" de archivos.

Esto viene util en los casos que se tenga un proyecto muy grande, con mucho codigo, en donde la
compilacion de cada archivo cuesta muchos minutos.

Cuando usamos ``gcc``, lo que hace el compilador es:

```bash
$ gcc main.c prog1.c prog2.c -o mi_programa
```

* Toma todos los archivos ``.c``
* Transforma todos ese codigo a archivo de objeto ``.o``
* Finalmente los enlaza todos y los une en un ejecutable llamado ``mi_programa``

En los casos de el proyecto sea muy pesado, y se necesite tiempo para compilar, al modificar solo un archivo, seria muy ineficiente tener que recompilar todos los archivos nuevamente.

Por eso tambien se decide hacer compilacion separada:

```bash
$ gcc -c main.c
$ gcc -c prog1.c
$ gcc -c prog2.c
$ gcc main.o prog1.o prog2.o -o mi_programa
```

Pero escribir esto todo el tiempo puede ser tedioso tambien. Ademas, cada comando necesita del anterior para poder funcionar (ej: para generar los archivos .o se debe primero compilar el archivo .c). Se puede notar que hay una cierta **dependencia** entre los comandos y los archivos.

---

## Usando ``make``

Utilizando alguna distribucion de Linux, se pude ver si se tiene ``make`` instalado con solamente escribir esto en el terminal:

```bash
$ make

make: *** No targets specified and no makefile found.  Stop.
```

Un mensaje como ese deberia aparecer. Significa que si esta instalado.

Cuando se llama a ``make``, el programa busca un archivo llamado ``makefile``.
