import turtle

#Podemos poner los nombres de los colores en una lista para despues recorrerlos.
colores = ["black","red","blue","green"]

for x in range(10,50):

    #Cada vez el espiral se hace mas grande.
    turtle.forward(x)

    turtle.left(90)

    #Y en cada giro, va cambiando de color.
    turtle.pencolor(colores[x%4])

while True:
    turtle.forward(0)