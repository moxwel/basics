import turtle

#Para poder estampar texto, podemos usar la funcion write(). Esta funcion tiene 4 parametros:

#El texto que queremos que imprima.
texto = "Mi texto"
#Si la tortuga debe moverse al escribir el texto.
moverse = False
#El centrado del texto.
centrado = "center"
#Y la fuente del texto: nombre, tamaño, y forma.
fuente = ("Arial", 20, "normal")

turtle.write(texto, moverse, centrado, fuente)

for x in range(3):
    turtle.forward(300)
    turtle.write(texto, moverse, centrado, fuente)
    turtle.left(90)

turtle.forward(300)

while True:
    turtle.forward(0)