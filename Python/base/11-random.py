# Podemos usar modulos externos de Python, por ejemplo, hay un modulo que se especializa en generar numeros pseudoaleatorios. Para poder usarlo, primero hay que importarlo:
import random
# Ahora podemos usar comandos de ese modulo.

import math
# Ahora podemos usar comandos del modulo "math".

# Con el metodo randint() del modulo random, podemos generar numeros enteros dentro de un rango.
print(random.randint(0,10))
print("")
# Esto generara un numero aleatorio en [0,10] cada vez que ejecutes el programa.

print("Lista de numeros randint:")
for x in range(10):
    print(random.randint(10,20))
print("")

# Con el comando randrange() podemos generar numeros dentro de un invervalo, pero tambien podemos hacer que busque numeros aleatorios en ciertos multiplos.

# Vamos a generar numeros en el intervalo de [0,11[, solo usando multiplos de 3.
print(random.randrange(0,11,2))
print("Lista de numeros randrange:")
for x in range(10):
    print(random.randrange(0,11,3))
print("")