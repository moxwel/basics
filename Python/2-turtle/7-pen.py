import turtle
import time

#En turtle, podemos manejar mas de una tortuga a la vez, para eso, tenemos que definir una variable de tipo "Lapiz".
lapiz_1 = turtle.Pen()
#Ahora para manejar "lapiz_1", tenemos que llamarlo junto al metodo que queremos.

#Hagamos que el "lapiz_1" sea de color azul y dibuje un poco...
lapiz_1.color("blue")
lapiz_1.forward(100)
lapiz_1.left(90)
lapiz_1.forward(100)

#Ahora podemos tambien crear otro lapiz...
lapiz_2 = turtle.Pen()
#Ahora para cambiarle el color al "lapiz_2", tenemos que llamarlo.

lapiz_2.color("red")
#El "lapiz_2" sera de color rojo.

lapiz_2.backward(100)
lapiz_2.right(90)
lapiz_2.forward(100)

#Ahora podemos controlar los dos lapices de forma independiente.

for x in range(50):
    lapiz_1.left(90)
    lapiz_2.left(90)

    #El cuadrado del lapiz azul se hara cada vez mas grande.
    lapiz_1.forward(50+x)
    #El cuadrado del lapiz rojo se hara cada vez mas chico.
    lapiz_2.forward(50-x)

while True:
    lapiz_1.forward(0)