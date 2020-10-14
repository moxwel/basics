# Agregar variables puede ayudar a la "flexibildiad" del makefile
# Por ejemplo, cambiar el nombre de los programas sin necesidad de cambiar
# todo el archivo.

# A continuacion se tienen algunos nombres de variables por estandar para C:

# Nombre del compilador
CC = gcc

# Una lista de los archivos objetos que van a enlazarse
OBJS = main.o empleado.o sueldos.o

# El nombre del ejecutable
EXEC = mi_programa

# Opciones de compilacion
CFLAGS = -Wall -g

# Opciones de enlazador
LDFLAGS = -Wall -g


# Ahora si necesitamos agregar mas archivos objeto, ya solo bastara con
# cambiar las variables y no todo el archivo.

# Si una linea queda muy larga, se puede usar el backslash \
para seguir en una linea siguiente

# =============


all: programa

programa: $(OBJS)
	gcc $(LDFLAGS) $(OBJS) -o $(EXEC)
	make clean

main.o: main.c empleado.h sueldos.h
	gcc $(CFLAGS) -c main.c

empleado.o: empleado.c empleado.h
	gcc $(CFLAGS) -c empleado.c

sueldos.o: sueldos.c sueldos.h empleado.h
	gcc $(CFLAGS) -c sueldos.c

clean:
	rm -f $(OBJS)
