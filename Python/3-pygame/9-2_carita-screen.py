import pygame
import time
import random

pygame.init()

mi_icono = pygame.image.load("resources\carita_icono.gif")
pygame.display.set_icon(mi_icono)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Carita Screen")

carita = pygame.image.load("resources\carita.png")

posX = 0
posY = 120

velocidad = 0.05

esta_en_borde_derecha = False
esta_en_borde_inferior = False

r = 0
g = 0
b = 0
brillo = 70

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    mi_ventana.fill(pygame.Color(r,g,b))
    mi_ventana.blit(carita, [posX,posY])

    if esta_en_borde_derecha == False:
        posX += velocidad
        if posX > 370:
            esta_en_borde_derecha = True
            r = random.randrange(0,brillo)
            g = random.randrange(0,brillo)
            b = random.randrange(0,brillo)
    else:
        posX -= velocidad
        if posX < 0:
            esta_en_borde_derecha = False
            r = random.randrange(0,brillo)
            g = random.randrange(0,brillo)
            b = random.randrange(0,brillo)

    if esta_en_borde_inferior == False:
        posY += velocidad
        if posY > 270:
            esta_en_borde_inferior = True
            r = random.randrange(0,brillo)
            g = random.randrange(0,brillo)
            b = random.randrange(0,brillo)
    else:
        posY -= velocidad
        if posY < 0:
            esta_en_borde_inferior = False
            r = random.randrange(0,brillo)
            g = random.randrange(0,brillo)
            b = random.randrange(0,brillo)

    pygame.display.update()