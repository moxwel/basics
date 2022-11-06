import turtle

lapiz = turtle.Pen()
lapiz.speed(0)
lapiz.width(2)

turtle.bgcolor("black")
colores = ["red", "yellow", "blue", "green"]

for x in range(20,100):
    lapiz.pencolor(colores[x%4])
    lapiz.circle(x)
    lapiz.left(45)

while True:
    lapiz.forward(0)