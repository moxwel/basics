import pygame
import time

#Esta libreria nos ayudara a generar numeros pseudoaleatorios.
import random

pygame.init()

rojo = pygame.Color(255,0,0)
verde = pygame.Color(0,255,0)
azul = pygame.Color(0,100,255)
blanco = pygame.Color(255,255,255)
negro = pygame.Color(0,0,0)

mi_icono = pygame.image.load("resources\icono_pixel.gif")
pygame.display.set_icon(mi_icono)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 8")

mi_ventana.fill(negro)

#Ya sabemos cargar imagenes, carguemos la imagen de una carita.
carita = pygame.image.load("resources\carita.png")

#Vamos a crear unas variables que tengan un numero aleatorio en un rango.
posX = random.randrange(0,370)
posY = random.randrange(0,270)
#Vamos a imprimir la coordenada en la consola.
print("La posicion de la carita es: " + str(posX) + "," + str(posY))
#Estas variables juntas, conforman una coordenada aleatoria en la ventana.

#Ahora le vamos a decir que ponga la imagen "carita" en la coordenada aleatoria que generamos antes.
mi_ventana.blit(carita, [posX,posY])
#Ahora cada vez que ejecutemos el programa, la carita va a estar en otra posicion aleatoria.

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()