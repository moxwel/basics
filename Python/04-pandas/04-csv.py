import pandas as pd

# Pandas tambien es capaz de importar datos desde archivos externos.
# En este caso, vamos a ver como importar archivos CSV (archivo separado por comas).

# Los archivos CSV son archivos TXT que contienen datos separados por comas. Es muy utilizado
# para almacenar datos ya que es compatible con la mayoria de herramientas de estadistica y datos.

# Para importar un archivo CSV en Pandas, se utiliza la funcion "read_csv", y como argumento, el nombre
# del archivo a abrir.
mi_archivo = pd.read_csv("archivo.csv")

# Cuando las tablas son muy grandes, pandas solo retorna las primeras y ultimas 5 filas.
print(mi_archivo)

# Podemos usar el metodo "to_string" sobre el archivo para poder imprimir toda la tabla por pantalla.
print(mi_archivo.to_string())

# Podemos cambiar cual debe ser el tamaño minimo de la tabla para que pandas automaticamente
# oculte el resto de filas. Cambiando la siguiente variable:
print(pd.options.display.max_rows) # 60 (defecto)
