# Una nota: Cuando se ejecuta el comando "make" sin argumentos, lo que hara sera
# ejecutar la primera regla que se encuentre en este archivo.
# Es una buena practiva tener una regla principal llamada "all" para definir
# por asi decirse "las reglas principales" para la construccion del programa.
all: mi_programa

# Vamos a crear una regla para poder crear el programa principal
mi_programa: main.o empleado.o sueldos.o
	gcc main.o empleado.o sueldos.o -o mi_programa

# Como vemos, para el objetivo "mi_programa", se tienen 3 dependencias, si las
# 3 dependencias se satisfacen, entonces se ejecuta la instruccion dada, que es
# enlazar todos los archivos de objeto generados en un ejecutable.

# Para poder resolver las dependencias que siguen, se pueden crear mas reglas.

main.o: main.c empleado.h sueldos.h
	gcc -c main.c

empleado.o: empleado.c empleado.h
	gcc -c empleado.c

sueldos.o: sueldos.c sueldos.h empleado.h
	gcc -c sueldos.c

# Ahora si ejecutamos "make", se ejecutara "mi_programa", y todos los comandos se van a ejecutar
# y el programa va a estar compilado.

# Aunque, al final, va a quedar lleno de archivos .o basura, podemos crear una nueva
# regla para limpiar los restos. Es buena practica llamar a esta regla "clean".

# Borrar todos los archivos que tengan extension .o
clean:
	rm -f *.o
