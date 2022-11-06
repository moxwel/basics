import turtle

#Tamano del poligono.
tam = 100

#Numero de vertices.
vertices = 5

#Calculo de los angulos interiores del poligono (geometria).
angulos = (180 * (vertices - 2))/vertices

#Repetir segun la cantidad de vertices.
for x in range(vertices):

    #Avanzar segun el tamano del poligono que pusimos.
    turtle.forward(tam)

    #Girar hacia la derecha el suplemento del angulo.
    turtle.left(180 - angulos)

while True:
    turtle.forward(0)