import pandas as pd

# Para poder crear graficos con los datos que tenemos en Pandas, debemos usar
# el modulo "pyplot" de la libreria "matplotlib". Primero debemos instalarlo usando pip:

# $ pip install matplotlib

# Y luego lo importamos
import matplotlib.pyplot as plt

# Tal vez sea necesario instalar todos los paquetes de Python para que el grafico
# pueda mostrarse en una interfaz grafica. Para ello:

# $ sudo apt install python3.8-full

datos=pd.read_csv("archivo3.csv")

# Usar el metodo "plot" sobre el dataframe creara un "grafico" en memoria, que pyplot
# podra usar para mostrar por pantalla
datos.plot() # Crear grafico
plt.show()   # Mostrar grafico

# Podemos cambiar el tipo de grafico usando el argumento "kind"
datos.plot(kind='scatter', x='Duration', y='Calories')
# Esto creara un grafico de puntos, donde la coordenada 'x' es la duracion y la 'y' son las
# calorias.
plt.show()
# Notese que habiamos dicho que estas dos columnas en la tabla tenian una correlacion alta,
# y por lo tanto se ordenan de manera lineal.

datos.plot(kind='scatter', x='Duration', y='Maxpulse')
plt.show()
# Notese como en este grafico los datos estan mas dispersos, pues los datos no estan
# correlacionados.

# Para crear un histograma, debemos usar el kind "hist", y seleccionar una columna.
# De esta forma podemos contar la frecuencia con la que aparecen los datos.
datos['Duration'].plot(kind='hist')
plt.show()
