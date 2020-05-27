# Podemos hacer comparaciones logicas con los operadores logicos.

# Para comparar si dos objetos son iguales, se usa el operador == (que es diferente al de asignacion: = )
print(5 == 5)
# Aqui le estamos preguntando al programa "el numero 5 es igual al numero 5?". Los dos numeros son iguales, por ende, esa sentencia es VERDADERA, y la consola imprimira "True".

print(5 == 3)
# Aqui le estamos preguntando al programa "el numero 5 es igual al numero 3?". Los dos numeros NO son iguales, por ende, esa sentencia es FALSA, y la consola imprimira "False".

print(5 > 3)
# "El numero 5 es MAYOR que 3?". Si, es verdadero.

print(5 > 5)
# "El numero 5 es MAYOR que 5?". No, es falso.

print(5 >= 5)
# "El numero 5 es MAYOR O IGUAL que 5?". Si, es verdadero.

print(5 != 5)
# "El numero 5 es DIFERENTE que 5?". No, es falso.

print(5 != 3)
# "El numero 5 es DIFERENTE que 3?". Si, es verdadero.

print()
# Para comparaciones mas complejas, existen los comparadores logicos. Estos pueden comparar los resultados que pueden entregar los operadores logicos (valores booleanos).

# El comparador "and" se evalua verdadera SI Y SOLO SI ambos argumentos SON VERDADEROS.
print(True and True)
# Los dos argumentos son verdaderos, entonces el resultado es verdadero.

print(False and True)
# Ambos argumentos no son verdaderos, entonces el resultado es falso.

print(False and False)
# Los dos argumentos son falsos, entonces el resultado es falso.

# El comparador "or" se evalua verdadera si AL MENOS un argumento ES VERDADERO.
print(True or True)
# Los dos argumentos son verdaderos, entonces el resultado es verdadero.

print(False or True)
# Uno de los argumentos es verdadero, entonces el resultado es verdadero.

print(False or False)
# Ambos argumentos son falsos, entonces el resultado es falso.


# El operador "not" solo recibe un argumento. La funcion de "not" es invertir el valor del booleano, es decir, si antes era falso, el inverso es verdadero, y viceversa.
print(not True)
# El argumento es verdadero, se invierte, entonces el resultado es falso.
print(not False)
# El argumento es falso, se invierte, entonces el resultado es verdadero.