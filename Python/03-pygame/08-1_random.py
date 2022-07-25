import pygame
import time
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

carita = pygame.image.load("resources\carita.png")

while True:

    mi_ventana.fill(negro)
    posX = random.randrange(0,370)
    posY = random.randrange(0,270)
    mi_ventana.blit(carita, [posX,posY])

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()