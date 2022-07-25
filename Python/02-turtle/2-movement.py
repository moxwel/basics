import turtle

#Para mover la tortuga, hay que hacer referencia al modulo turtle primero.
turtle.forward(100)
#El metodo forward() o fd() hara que la tortuga se mueva hacia adelante una cierta cantidad de pixeles (lo que hay dentro de los parentesis, en este caso: 100 pixeles).
turtle.left(90)
#El metodo left() o lt() hara que la tortuga gire hacia la izquierda una cierta cantidad de grados (lo que hay dentro de los parentesis, en este caso: 90 grados).
turtle.backward(50)
#El metodo backward() o bk() hara que la tortuga se mueva hacia atras una cierta cantidad de pixeles (lo que hay dentro de los parentesis, en este caso: 50 pixeles).
turtle.right(135)
#El metodo right() o rt() hara que la tortuga gire hacia la derecha una cierta cantidad de grados (lo que hay dentro de los parentesis, en este caso: 135 grados).
turtle.forward(100)
turtle.right(90)
turtle.forward(100)

while True:
    turtle.forward(0)