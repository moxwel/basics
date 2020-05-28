import turtle

l = turtle.Pen()
l.width(3)

#La tortuga es muy lenta para dibujos demasiado grandes? Con la funcion speed() puedes cambiar la velocidad de la tortuga. Los valores pueden ser desde 10 (rapido) hasta 1 (lento), y 0 (instantaneo).

#Vamos a crear un cuadrado negro de la forma mas lenta posible.
l.speed(1)
for x in range(4):
    l.forward(100)
    l.left(90)

#Cambiemos el color a verde y dibujemos otro cuadrado pero mas rapido.
l.color("green")
l.speed(10)
for x in range(4):
    l.forward(150)
    l.left(90)

#Cambiemos el color a rojo y dibujemos otro cuadrado de forma casi instantanea.
l.color("red")
l.speed(0)
for x in range(4):
    l.forward(200)
    l.left(90)

while True:
    l.forward(0)