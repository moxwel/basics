import turtle

lapiz = turtle.Pen()

#Para cambiar el grosor del lapiz, podemos usar la funcion width(), y el valor que hay dentro de los parentesis, es el valor en pixeles del grosor.
lapiz.width(10)
#El grosor cambio a 10 pixeles.
lapiz.fd(100)

lapiz.width(5)
lapiz.fd(100)

lapiz.width(1)
lapiz.fd(100)

while True:
    lapiz.forward(0)