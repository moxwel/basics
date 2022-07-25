import pygame
import time
import random

pygame.init()

negro = pygame.Color(0,0,0)

mi_icono = pygame.image.load("resources\carita_icono.gif")
pygame.display.set_icon(mi_icono)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Carita Screen")

mi_ventana.fill(negro)

carita = pygame.image.load("resources\carita.png")

posX = 0
posY = 120

velocidad = 0.05

esta_en_borde_derecha = False
esta_en_borde_inferior = False

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    mi_ventana.fill(negro)
    mi_ventana.blit(carita, [posX,posY])

    if esta_en_borde_derecha == False:
        posX += velocidad
        if posX > 370:
            esta_en_borde_derecha = True
    else:
        posX -= velocidad
        if posX < 0:
            esta_en_borde_derecha = False

    if esta_en_borde_inferior == False:
        posY += velocidad
        if posY > 270:
            esta_en_borde_inferior = True
    else:
        posY -= velocidad
        if posY < 0:
            esta_en_borde_inferior = False

    pygame.display.update()