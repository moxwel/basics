import pandas as pd

# Notemos como en algunas filas de la columna "Date" algunas fechas estan erroneas.
# Y la mayoria son strings (fijarse en las comillas)
datos = pd.read_csv("archivo2.csv")
print(datos.to_string())

# Podemos convertir esos datos para corregirlo. En este caso, podemos usar el metodo
# "to_datetime()" de pandas
print(pd.to_datetime(datos["Date"]))
# Notese como ahora todos los datos estan estandarizados, y el dato vacio 'NaN' (not a number)
# ahora es 'NaT' (not a time).

# Podemos ingresar esa columna en el dataframe original
datos["Date"] = pd.to_datetime(datos["Date"])
print(datos.to_string())
