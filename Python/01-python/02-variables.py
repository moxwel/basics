# Para crear variables, debemos poner el nombre de la variable y luego un signo de = (definir).
mi_variable = 5
# Se define la variable "mi_variable" con valor 5.

# Una vez definido una variable, podemos imprimirla en consola con la funcion print().
print(mi_variable) # 5

# De la misma forma, podemos manipular variables.
mi_variable = mi_variable + 5
# Le agregamos 5 al valor de "mi_variable" (5 + 5).

# NOTA: eso mismo es posible con el operador += (sumar a si mismo).

print(mi_variable) # 10

# Las variables tambien pueden contener cadenas.
mi_variable = "Hola mundo"
print(mi_variable) # Hola mundo

# Tambien pueden contener valores booleanos (verdadero o falso).
mi_variable = True
print(mi_variable) # True

# Variables tambien pueden llamar a otras variables.
var1 = 100
var2 = var1
print(var2) # 100

# Variables tambien pueden tener fomas de tuplas, en vez de definir 2 variables en lineas diferentes, podemos hacerlo en la misma linea.
tupla1,tupla2 = 50,32
print(tupla2) # 32

# Tambien podemos definir una tupla en una sola variable
tupla3 = 34,56
print(tupla3) # (34, 56)