import pandas as pd

# Esta vez vamos a cargar un archivo que posee datos malos.
datos = pd.read_csv("archivo2.csv")
print(datos.to_string())

# Notese las columnas que dicen 'NaN', quiere decir que son datos vacios
# Para eliminar los datos vacios, se debe usar el metodo 'dropna()'
datos_limpio = datos.dropna()
print("Limpiando datos...")
print(datos_limpio.to_string())
# Todas las filas que posean al menos un 'NaN' seran descartados, notese como
# algunas filas ya no estan (fijarse en el numero de fila).

# En vez de considerar todas las filas, podemos considerar las filas de una unica
# columna solamente. Para ello debemos mencionar el "subset".
datos_limpio_2 = datos.dropna(subset=["Calories"])
print("Limpiando datos de la columna Calories...")
print(datos_limpio_2.to_string())
# Ahora la columna Calories no tiene datos vacios.

# Para reemplazar directamente la tabla limpia a la misma variable, se puede usar
# el argumento 'inplace = True' dentro del metodo sobre la variable.
# datos.dropna(inplace = True)
# print(datos.to_string())




# Para poder 'rellenar' celdas vacias con algun dato, podemos usar el metodo 'fillna',
# este recibe un valor y lo reemplaza en todas las celdas vacias.
datos_relleno = datos.fillna("algo")
print("Rellenando celdas vacias...")
print(datos_relleno.to_string())
# Tambien se puede usar 'inplace = True' para reemplazar directamente en la variable.

# Para poder rellenar celdas vacias unicamente en una columna especifica, se debe
# mencionar la columna antes.
datos_relleno_col = datos["Date"].fillna("Sin Fecha")
print("Rellenando unicamente la columna Date...")
print(datos_relleno_col.to_string())
# Notese que solo se imprime una columna, si quieremos reemplazarlo pero conservando toda
# la tabla, debemos reemplazarlo inplace.
datos["Date"].fillna("Sin fecha", inplace=True)
print(datos.to_string())
