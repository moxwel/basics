# Estructura de ``makefile``

La estructura del archivo ``makefile`` es la siguiente:

```makefile
obj1: dep1 dep2 ... depN
    instr1
    instr2
    ...
    instrN

obj2: dep1 dep2 ... depN
    instr1
    instr2
    ...
    instrN

...

objN: dep1 dep2 ... depN
    instr1
    instr2
    ...
    instrN
```

* ``makefile`` se compone de **Reglas**. Cada **Regla** se compone de:
  * ``obj`` : Un _Objetivo_
    * _¿Que se quiere obtener?_

  * ``dep`` : Dependencias
    * _¿Que se necesita antes para poder realizar el objetivo?_ Pueden ser archivos que necesitan existir, o tambien pueden ser otras **Reglas**.

  * ``instr`` : Instrucciones
    * _¿Que hay que realizar?_ Basicamente son comandos de terminal que ``make`` va a ejecutar automaticamente.

## Automatizacion y eficiencia

``make`` nos va a ayudar a no tener que recompilar todo, solamente lo que es necesario, resolviendo las dependencias necesarias, y ademas, de forma automatica.

Esto es posible ya que, cuando ejecutamos el comando, el programa se va a dar cuenta de los archivos compilados por su **fecha de modificacion**, por esta razon, si ejecutamos ``make`` dos veces seguidas, va a ocurrir esto:

```
$ make

gcc -c main.c
gcc -c empleado.c
gcc -c sueldos.c
gcc main.o empleado.o sueldos.o -o mi_programa

$ make

make: Nothing to be done for 'all'.
```

Notar como make dice que ya no es necesario hacer ningun cambio, ya que todas las dependencias no fueron modificadas desde que se ejecuto ``make`` por primera vez.

Si se modifica una unica dependencia, solamente esa dependencia se va a recompilar, y el resto no. Esto puede ser un gran _boost_ de eficiencia en el tiempo de compilacion del proyecto completo.
