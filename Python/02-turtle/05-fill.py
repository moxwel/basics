import turtle
import time

#Para rellenar una figura, podemos usar el comando begin_fill() y end_fill().

#Establecemos el color de lapiz y relleno a rojo.
turtle.color("red")

#Comenzamos a rellenar con begin_fill().
turtle.begin_fill()

#Dibujamos un cuadrado simple.
turtle.forward(50)
turtle.left(90)
turtle.forward(50)
turtle.left(90)
turtle.forward(50)
turtle.left(90)
turtle.forward(50)
turtle.left(90)

#Y al poner end_fill(), la figura que hayamos hecho se va a rellenar de rojo.
turtle.end_fill()

time.sleep(1)

#Tambien podemos cambiar el color del lapiz y el color de relleno de forma independiente.

#Establecemos el fondo de color negro.
turtle.bgcolor("black")
#Establecemos el color del lazpiz a amarillo y el color de relleno a verde.
turtle.color("yellow","green")
#Comenzamos a rellenar.
turtle.begin_fill()
#Dibjamos el mismo cuadrado.
turtle.forward(50)
turtle.left(90)
turtle.forward(50)
turtle.left(90)
turtle.forward(50)
turtle.left(90)
turtle.forward(50)
turtle.left(90)
#Terminamos de rellenar.
turtle.end_fill()

while True:
    turtle.forward(0)