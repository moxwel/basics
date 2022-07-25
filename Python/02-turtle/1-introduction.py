#Turtle es un modulo de Python que permite dibujar de la forma tortuga, es decir, uno maneja un lapiz que puede controlar con distintos comandos.

#Para poder usar el modulo de turtle, es necesario importarlo. No es necesario usar "pip" para instalar el modulo, turtle ya viene preinstalado en Python.
import turtle
#Ahora podemos usar los metodos del modulo turtle.

#La tortuga se representa con una flecha. Para manejar la direccion de la flecha, hay que usar distintas funciones que nos ayudaran. Mas adelante veremos mas a fondo como se hace. Por ahora, veamos este ejemplo.
turtle.forward(100)
turtle.right(90)
turtle.forward(100)
turtle.right(90)
turtle.forward(100)
turtle.right(90)
turtle.forward(100)
#Por el nombre en ingles, uno ya se puede dar cuenta de como funciona esto. Cada instruccion se sigue en orden, y a medida que la flecha se mueve, va dibujando lineas. En este caso, la tortuga dibujara un simple cuadrado.

#Este loop infinito ayudara a que no se cierre el programa una vez terminado el dibujo del cuadrado. El loop hace que la tortuga se mueva "0" pixeles para siempre; en ortras palabras, quedarse inmovil.
while True:
    turtle.forward(0)