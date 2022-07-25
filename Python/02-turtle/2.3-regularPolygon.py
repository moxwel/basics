import turtle

#Podemos empaquetar el codigo anterior y transformarlo en funcion.
def poligono(vertices,tam):
    angulos = (180 * (vertices - 2))/vertices
    for x in range(vertices):
        turtle.forward(tam)
        turtle.left(180 - angulos)

#Ahora sera mas facil dibujar poligonos.
poligono(3,100)
poligono(4,100)
poligono(5,100)
poligono(6,100)
poligono(7,100)
poligono(8,100)

while True:
    turtle.forward(0)