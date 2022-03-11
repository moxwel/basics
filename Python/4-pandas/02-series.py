from operator import index
import pandas as pd

# Una serie en pandas, se considera como una columna en una tabla.
# Es un arreglo unidimensional que contiene datos de cualquier tipo

# Podemos crear una serie con una lista en python
datos = [392, 700, 400, 3.1415, "Max"]
mi_serie = pd.Series(datos)
print(mi_serie)

# Cada elemento de la serie estara listado con los indices de la lista, comenzando con 0
# Podemos acceder a un elemento especifico de la lista de la siguiente forma
print(mi_serie[0]) # 392

# Podemos ponerle un nombre a cada indice, utlizando el argumento 'index' al momento de crear
# la serie. Debemos ingresarle una lista con los nombres de cada elemento de la serie.
mi_serie_titulos = pd.Series(datos, index = ["indice 1", "indice 2", "indice 3", "decimal", "nombre"])
print(mi_serie_titulos)

# Al hacer esto, tambien podremos acceder a los elementos de la serie utilizando el nombre que le dimos
print(mi_serie_titulos["nombre"]) # Max

# Tambien podemos crear series utilizando un diccionario en python. De esta manera, los indices
# ya tendran el nombre correspondiente a cada dato.
datos2 = {
	"lunes": 25,
	"martes": 20,
	"miercoles": 29,
	"jueves": 32,
	"viernes": 30,
	"sabado": 28,
	"domingo": 20
}
temps = pd.Series(datos2)
print(temps)

# Desde un diccionario, podemos crear una serie utilizando solo ciertos datos
temps2 = pd.Series(datos2, index=["lunes", "jueves", "domingo"])
print(temps2)
