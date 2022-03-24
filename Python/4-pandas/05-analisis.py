import pandas as pd

# El metodo "head" sobre un dataframe sirve para obtener las primeras 'n' filas.
# Si no se especifica argumento, por defecto retorna las 5 primeras filas..
datos = pd.read_csv("archivo.csv")
print(datos.head(10))

# De la misma forma, el metodo "tail" sobre un dataframe sirve para obtener las utlimas 'n' filas
print(datos.tail(10))

# Para obtener informacion sobre algun objeto de pandas, se puede utilizar el metodo "info"
print(datos.info())



# Se pueden analizar "correlaciones" entre las columnas de la tabla. Es decir, que tan
# relacionados estan uno del otro (se ignoran columnas que posean valores no-numericos).

# --> Si el valor se acerca a 1, significa que los valores son proporcionales
#     (si uno sube, el otro tambien)
# --> Si el valor se acerca a -1, significa que los valores son inversamente proporcionales
#     (si uno sube, el otro baja).
# --> Si el valor esta cerca de 0, significa que los valores no estan relacinados entre si.

# Usemos otro dataframe.
print("Analizar correlaciones...")
datos2 = pd.read_csv("archivo3.csv")
print(datos2)
print(datos2.corr())
# Notemos como las calorias y la duracion estan muy relacionadas entre si.
# Sin embargo, las calorias con el pulso maximo no.
