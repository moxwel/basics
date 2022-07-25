import turtle

#Para ahorrar codigo, podemos hacer un loop que repita movimientos, de esta forma podemos crear patrones.
for i in range(4):

    for x in range(5):
        turtle.forward(100)
        turtle.right(90)
        turtle.forward(10)
        turtle.right(90)
        turtle.forward(110)
        turtle.left(90)
        turtle.forward(10)
        turtle.left(90)

    turtle.forward(95)
    turtle.left(90)

while True:
    turtle.forward(0)