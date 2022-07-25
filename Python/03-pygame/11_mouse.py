import pygame
import time
import random

pygame.init()

blanco = pygame.Color(255,255,255)
negro = pygame.Color(0,0,0)

mi_icono = pygame.image.load("resources\icono_pixel.gif")
pygame.display.set_icon(mi_icono)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 11")

carita = pygame.image.load("resources\carita.png")

posX = 200
posY = 100
velocidad = 5

while True:

    for evento in pygame.event.get():

        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    mi_ventana.fill(negro)

    #Con pygame.mouse.get_pos(), podemos obtener la tula de coordenadas actuales del mouse.
    print(pygame.mouse.get_pos())

    #Una vez que tenemos las coordenadas, podemos definirselas a la imagen de la carita para que tome las mismas coordenadas que nuestro mouse.
    posX,posY = pygame.mouse.get_pos()
    #Recordemos que las coordenadas empiezan desde la esquina superior izquierda de la imagen, entonces con lo siguiente podemos centrar la imagen (ya que la imagen de la carita es de 30x30 px).
    posX -= 15
    posY -= 15
    #Ahora la carita va a usar las coordenadas del mouse.

    mi_ventana.blit(carita, [posX,posY])

    pygame.display.update()