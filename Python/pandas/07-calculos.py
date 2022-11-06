import pandas as pd

datos = pd.read_csv("archivo2.csv")
print(datos.to_string())

# Podemos calcular diferentes valores estadisticos directamente de los datos de la tabla
# por ejemplo el promedio, la mediana, o la moda.

prom = datos["Calories"].mean()    # Promedio
medi = datos["Calories"].median()  # Mediana
moda = datos["Calories"].mode()[0] # Moda de la primera columna

print("--> El promedio de las Calorias es: " + str(prom))
print("--> La mediana de las Calorias es: " + str(medi))
print("--> La moda de las Calorias es: " + str(moda))

# Calcular la moda usando 'mode()' causara que se calule la moda para cada columna.
modas = datos.mode()
print("--> La moda de cada columna son: ")
print(modas.to_string())
