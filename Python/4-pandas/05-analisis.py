import pandas as pd

# El metodo "head" sobre un dataframe sirve para obtener las primeras 'n' filas.
# Si no se especifica argumento, por defecto retorna las 5 primeras filas..
datos = pd.read_csv("archivo.csv")
print(datos.head(10))

# De la misma forma, el metodo "tail" sobre un dataframe sirve para obtener las utlimas 'n' filas
print(datos.tail(10))

# Para obtener informacion sobre algun objeto de pandas, se puede utilizar el metodo "info"
print(datos.info())
