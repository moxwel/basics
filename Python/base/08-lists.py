# Las listas en Python es como el equivalente a los arreglos en C++. Son un conjunto ordenado de objetos en una misma variable, y se definen con corchetes, y los objetos dentro de este separados por comas.

mi_lista = ["Hola","mundo","!"]
print(mi_lista)

# Cada objeto dentro de una lista tiene su indice, comenzando por 0, es decir, el indice del primer elemento es 0, del segundo 2, y asi. Para acceder a un elemento especifico de una lista, es necesario mencionar el indice de tal objeto.

# Imprime el objeto que esta en el indice 0.
print(mi_lista[0])
# Imprime el objeto que esta en el indice 1.
print(mi_lista[1])
# Imprime el objeto que esta en el indice 2.
print(mi_lista[2])

mi_otra_lista = ["Mi","nombre","es","Max"]
# Lista = ["Mi","nombre","es","Max"]
# Indice:   0      1      2     3

print(mi_otra_lista[3]) # Max

# Una lista puede tener distintos elementos de distinto tipo, e incluso otras listas.
mi_lista2 = ["Hola ", 4, True, ["Max ","dragon "]]
print(mi_lista2[0] + mi_lista2[3][1] + mi_lista2[3][0]) # Hola dragon Max

# Los string tambien pueden actuar como listas.
mi_texto = "Hola mundo"
print(mi_texto[6]) # u

# Tambien se pueden reasignar valores a una lista.
mi_lista3 = [7,7,7,7,7]
print(mi_lista3) # [7,7,7,7,7]
mi_lista3[2] = 2
print(mi_lista3) # [7,7,2,7,7]

# Con el comando del podemos eliminar un valor de una lista.
mi_lista_del = [3,4,5,6,7,8,9]
print(mi_lista_del) # [3,4,5,6,7,8,9]
del mi_lista_del[3]
print(mi_lista_del) # [3,4,5,7,8,9]

# Tambien podemos usar el operador logico "in", que revisa si el argumento esta dentro de una lista.
mi_lista4 = ["Ninten","Lloyd","Teddy","Anna"]
print("Anna" in mi_lista4) # "Ana" si esta en la lista, entonces es verdadero.
print("Ness" in mi_lista4) # "Ness" no esta en la lista, entonces es falso.
print(not "Ness" in mi_lista4) # "Ness" no esta en la lista, pero el "not" lo vuelve verdadero.

# Con la funcion len() podemos tomar el numero de elementos que hay en una lista.
print(len(mi_lista4)) # 4

# Con la funcion append() podemos agregar valores al final de una lista.
mi_lista5 = ["Hola"]
print(mi_lista5) # ["Hola"]
mi_lista5.append("mundo")
print(mi_lista5) # ["Hola", "mundo"]
mi_lista5.append(":D")
print(mi_lista5) # ["Hola", "mundo", ":D"]

# Con la funcion insert() podemos agregar valores en cualquier posicion de una lista. Primero va el numero del indice en donde se quiere agregar el valor, luego viene el valor como tal.
mi_lista6 = ["Aprender", "es", "divertido"]
print(mi_lista6) # ["Aprender", "es", "divertido"]
mi_lista6.insert(1, "Python")
print(mi_lista6) # ["Aprender", "Python", "es", "divertido"]
mi_lista6.insert(3, "muy")
print(mi_lista6) # ["Aprender", "Python", "es", "muy", "divertido"]

# La funcion index() nos devuelve el numero del indice en donde se encuentra un valor en una lista.
letras = ["A","B","C","D","E"]
print(letras.index("D")) # 3 (la letra D se encuentra en el indice 3)

# La funcion range() crea un objeto de lista con tamaño: el valor que le entreguemos. Tambien, la funcion list(), al igual que str() e int(), transforma lo que tiene dentro en una lista.
mi_rango = list(range(10))
print(mi_rango) # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
mi_rango = list(range(5,10))
print(mi_rango) # [5, 6, 7, 8, 9]
mi_rango = list(range(0,20,5))
print(mi_rango) # [0, 5, 10, 15]

dias = ["Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"]
peliculas = [["Titanic", 1997], ["Depredador", 1987]]
print(dias)
print(peliculas[1])