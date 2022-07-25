import turtle

#Para cambiar el color del lapiz, hay que usar la funcion color(). El primer argumento es el color del lapiz, el segundo argumento es el color de relleno, lo veremos mas adelante. Si solo hay un argumento, ese color se establecera como color de lapiz y de relleno tambien.
turtle.forward(100)
turtle.left(90)

#Se puede usar el nombre del color como una cadena.
turtle.color("red")
turtle.forward(100)
turtle.left(90)

turtle.color("blue")
turtle.forward(100)
turtle.left(90)

turtle.color("green")
turtle.forward(100)
turtle.left(90)

#Con la funcion bgcolor() podemos cambiar el color del fondo.
turtle.bgcolor("gray")

while True:
    turtle.forward(0)