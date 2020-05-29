import pygame
import time

pygame.init()

rojo = pygame.Color(255,0,0)
verde = pygame.Color(0,255,0)
azul = pygame.Color(0,100,255)
blanco = pygame.Color(255,255,255)
negro = pygame.Color(0,0,0)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 5")

mi_ventana.fill(negro)

#Este comando nos servira para crear circulos.
pygame.draw.circle(mi_ventana, verde, (50,50), 30)
#El primer parametro de esta funcion es la superficie en donde se va a crear el circulo, en este caso, en "mi_ventana".
#El segundo parametro es el color del circulo.
#El tercer parametro es la coordenada del centro.
#El cuarto parametro es el radio del circulo.

#Este comando nos servira para crear rectangulos.
pygame.draw.rect(mi_ventana, rojo, [(30,100),(100,100)])
pygame.draw.rect(mi_ventana, azul, [(30,100),(10,10)])
#El primer parametro de esta funcion es la superficie en donde se va a crear el rectangulo, en este caso, en "mi_ventana".
#El segundo parametro es el color del rectangulo.
#El tercer parametro se compone de 4 numeros:
    #Los dos primeros numeros se refieren a la coordenada de la esquina superior-izquierda del rectangulo.
    #Los ultimos dos numeros se refieren al ancho y al alto del rectangulo respectivamente.

#Este comando nos servira para crear poligonos.
pygame.draw.polygon(mi_ventana, azul, [(100,10),(200,10),(150,80)])
#El primer parametro de esta funcion es la superficie en donde se va a crear el poligono, en este caso, en "mi_ventana".
#El segundo parametro es el color del poligono.
#El tercer parametro se compone de una lista de coordenadas, luego, Pygame unira las coordenadas y creara el poligono.

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()