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

while True:

    posX = random.randrange(10,390)
    posY = random.randrange(10,290)

    red = random.randrange(0,255)
    blue = random.randrange(0,255)
    green = random.randrange(0,255)
    
    pygame.draw.rect(mi_ventana, pygame.Color(red,green,blue), [(posX,posY),(1,1)])

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()