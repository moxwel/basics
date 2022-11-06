import turtle

#Esta libreria lo usaremos para detener el codigo por un momento, con el comando time.sleep()
import time

#El formato RGB se puede usar en turtle, pero es algo diferente. En vez de valores entre 0-255, son entre 0-1, entonces, para usar valores intermedios, hay que usar puntos flotantes.
turtle.bgcolor(1, 0.5, 0)
time.sleep(1)

turtle.bgcolor(0, 0.5, 1)
time.sleep(1)

turtle.bgcolor(0.5, 0.5, 0.5)
time.sleep(1)

#Para cambiar el modo a RGB normal, se debe usar la funcion colormode(), y dentro de los parentesis, poner 255.
turtle.colormode(255)
#Ahora podemos usar el formato RGB normal.

turtle.bgcolor(0, 150, 200)
time.sleep(1)

turtle.bgcolor(150, 255, 0)
time.sleep(1)

turtle.bgcolor(255,255,255)

while True:
    turtle.forward(0)