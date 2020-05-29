import pygame
import time

pygame.init()

rojo = pygame.Color(255,0,0)
verde = pygame.Color(0,255,0)
azul = pygame.Color(0,0,255)
blanco = pygame.Color(255,255,255)
negro = pygame.Color(0,0,0)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 4")

mi_ventana.fill(negro)

#Pygame posee metodos para crear lineas, poligonos y otras figuras. Esto es posible con el siguiente comando:
pygame.draw.line(mi_ventana, blanco, (10,10), (200,200), 5)
#El primer parametro de esta funcion es la superficie en donde se va a crear la linea, en este caso, en "mi_ventana".
#El segundo parametro es el color de la linea.
#El tercer parametro es la coordenada de inicio (tiene que estar en forma de dupla).
#El cuarto parametro es la coordenada de termino. La linea ira desde el inicio hasta el final de forma recta.
#El quinto parametro es el grosor de la linea

pygame.draw.line(mi_ventana, rojo, (10,50), (200,200), 1)
pygame.draw.line(mi_ventana, verde, (50,10), (200,200), 1)

#Podemos tomar los valores RGB de esta forma.
print rojo.r

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()