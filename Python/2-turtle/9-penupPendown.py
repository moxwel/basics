import turtle

l = turtle.Pen()
l.width(3)

#En turtle, podemos manejar el lapiz de tal forma que no dibuje mientras nos movamos, esto es util para mover la tortuga a un lugar evitando dibujar su trayectoria.

l.forward(100)
l.left(90)

#Para levantar el lapiz, usaremos la funcion penup() , esto hara que la tortuga ya no dibuje mientras se mueve.
l.penup()

l.forward(100)
l.left(90)

#Para bajar nuevamente el lapiz, usaremos la funcion pendown() , ahora la tortuga volvera a dibujar mientras se mueve.
l.pendown()
l.forward(100)
l.left(90)

l.penup()

l.forward(200)
l.left(90)

l.pendown()

l.forward(100)


while True:
    l.forward(0)