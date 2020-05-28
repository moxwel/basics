import turtle

def dibujar_flor(petalos,tam):
    for n in range(petalos):
        turtle.circle(tam)
        turtle.right(360 / petalos)

dibujar_flor(5,50)

while True:
    turtle.forward(0)