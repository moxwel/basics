from http.client import TOO_MANY_REQUESTS
import pandas as pd

# Notemos como en la fila 7, hay un dato extraño, 450 minutos de entrenamiento
# parece ser un error, y quisieramos reemplazarlo.
datos = pd.read_csv("archivo2.csv")
print(datos.to_string())

# Para cambiar el valor de una celda en especifica primero debemos localizarla.
# Recordemos como usar el metodo "loc" sobre un dataframe
print("Fila 7:\n" + str(datos.loc[7]))
# Esto nos dara la informacion de la fila 7

# Al usar dos argumentos, ubicaremos tanto la fila como la columna.
print("Fila 7, columna Duration: " + str(datos.loc[7, "Duration"]))
# Encontramos el valor erroeno, debemos cambiarlo.

# Reemplazar el valor que esta en la fila 7 en la columna Duration a 45
print("Reemplazando datos...")
datos.loc[7, "Duration"] = 45
print(datos.to_string())

# Notemos tambien que las filas 11 y 12 son exactamente iguales, es decir, hay un
# duplicado, y queremos quitarlo. Para saber si el dataframe tiene duplicados, debemos
# usar el metodo "duplicated" sobre el dataframe.
print("Buscando duplicados..-")
print(dict(datos.duplicated()))
# Esto retornara una lista (iterable) con un booleano por cada fila, sera True si detecta que
# dicha fila esta duplicada. En este caso, la fila 12 si se detecta como duplicada.
# Podemos quitarla si usamos un for-loop:
for x in list((datos.duplicated()).items()): # TODO: Terminar esto
	print(str(x[0]) + " es " + str(x[1]))


# Reemplazar muchos valores en el mismo dataset sera un trabajo mas o menos dificil,
# habra que crear ciclos para ello.

# Para esto, podemos usar el atributo "index" que poseen los dataframes.
print(list(datos.index))
# Esto es una lista con todos los indices de las filas (iterable).
# Usarlo en un for-loop ayudara para reemplazar los datos en diferentes filas.

print("Quitando gente que ha quemado menos de 250 calorias...")
for x in datos.index:
	if (datos.loc[x, "Calories"] < 250):
		datos.drop(x, inplace=True)
		# El metodo "drop" sirve para poder eliminar una fila especifica, y al usar
		# "inpalce=True" se esta sobreescribiendo el dataframe original.
print(datos.to_string())
