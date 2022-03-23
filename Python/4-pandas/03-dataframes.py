import pandas as pd

# Los DataFrames en pandas, a comparacion de las series, son tablas bidimensionales.
# Las series representan una columna, los dataframes representan la tabla completa.

datos = {
	"metros":   [750, 1500, 3000, 900, 1200],
	"calorias": [420, 700,  960,  500, 640],
	"minutos":  [15,  30,   60,   20,  25]
}
tablaEntrenamiento = pd.DataFrame(datos)
print(tablaEntrenamiento)

# Por defecto, al igual que las series, los indices comienzan desde 0. Cada indice representa
# una fila de la tabla.

# Podemos "localizar" filas especificas de un dataframe, utilizando el metodo "loc" sobre uno.
print(tablaEntrenamiento.loc[0]) # Esto retorna una SERIE, correspondiente a la fila 0

print(tablaEntrenamiento.loc[[2,3,4]]) # Esto retorna un DATAFRAME, correspondiente a una tabla con las filas 2, 3 y 4

# De la misma manera, podemos ingresar nombres a los indices al crear el dataframe.
tablaEntrenamiento_nombres = pd.DataFrame(datos, index = ["dia 1", "dia 2", "dia 3", "dia 4", "dia 5"])
print(tablaEntrenamiento_nombres)

# Y de la misma manera, ahora podemos "localizar" filas utilizando dichos nombres
print(tablaEntrenamiento_nombres.loc["dia 3"])

# Para poder imprimir unicamente una columna especifica, se puede mencionar como arreglo.
print(tablaEntrenamiento_nombres["calorias"])
