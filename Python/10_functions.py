# Las funciones son utiles para empaquetar codigo, y evitar tener que repetir codigo una y otra vez. Funciones como print(), str(), y cosas asi son funciones; uno le puede entregar un dato, y las funciones te devuelven otro dato. Utilizan la misma idea de las funciones matematicas, pero en este caso, en programacion, se pueden hacer mas cosas.

# Para definir una funcion, se debe usar el comando "def".
def mi_funcion():
    print("Hola mundo")
    print("Esta es una funcion")
    print("AAAAA")
    print("")

# Para ejecutar lo que hay dentro de una funcion, hay que llamar a la funcion, de la siguiente forma:
mi_funcion()

# Las funciones pueden contener argumentos. Los argumentos son valores que uno puede ingresar a la funcion, y manipularlas dentro de esta. Los argumentos van dentro de los parentesis, y van separados por coma.
def print_suma(num1, num2):
    # Las variables que se definan dentro de una funcion no pueden accederse fuera de ella.
    resultado = num1 + num2
    print(resultado)

print_suma(5,2) # 7

# Existen funciones que retornan valores para usarse despues, por ejemplo str(), esa funcion devuelve un string. En esos casos, se usa el comando return. Con return, la variable se transforma en el valor que se le asigna.
def mayor(x, y):
    if x > y:
        return x
    else:
        return y

mayor(6,2)
# No imprime nada, ya que la funcion solo toma el valor del numero mayor, si quisieramos saber cuanto vale la funcion, tendriamos que usar print().
print(mayor(4,105)) # 105
print(mayor(42,12)) # 42

# NOTA: un return actua de forma parecida a un break. Cuando se ejecuta, la funcion deja de ejecutarse, todo lo que venga despues no ocurrira.

# Los DOCSTRINGS sirven para explicar el funcionamiento de alguna funcion. Esa informacion puede mostrarse al escribir codigo y puede resultar muy util, por ejemplo en Visual Studio Code.
def mi_otra_funcion():
    """
    Aqui se puede explicar el funcionamiento de la funcion, si puedes leer esto mientras escribes codigo, significa que tu editor de codigo si es compatible.
    """

# Cuando uno define una funcion, para que la funcion no tenga errores, se le deben entregar todos los parametros correspondientes. Para evitar eso, podemos hacer que ciertos parametros tengan valores predeterminados, y de esa forma evitar escribirlos.

# Definiremos una funcion que escriba un nombre.
def escribir_nombre(nombre="Predeterminado"):
    print("Mi nombre es: " + nombre)

# La funcion imprimira el valor que le pongamos como parametro.
escribir_nombre("Max") # Mi nombre es: Max
escribir_nombre("Juan") # Mi nombre es: Juan
escribir_nombre("Josh") # Mi nombre es: Josh

# Pero si no le ponemos ningun valor al parametro, utilizara el valor predeterminado que pusimos antes.
escribir_nombre() # Mi nombre es: Predeterminado