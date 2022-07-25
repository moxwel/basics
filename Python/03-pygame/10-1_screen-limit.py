import pygame
import time
import random

pygame.init()

blanco = pygame.Color(255,255,255)
negro = pygame.Color(0,0,0)

mi_icono = pygame.image.load("resources\icono_pixel.gif")
pygame.display.set_icon(mi_icono)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 10")

carita = pygame.image.load("resources\carita.png")

posX = 200
posY = 100
velocidad = 5

while True:

    for evento in pygame.event.get():

        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()
        
        if evento.type == pygame.KEYDOWN:
            if evento.key == pygame.K_LEFT:
                posX -= velocidad
                print("[ IN >] Tecla izquierda presionada")
            elif evento.key == pygame.K_RIGHT:
                posX += velocidad
                print("[ IN >] Tecla derecha presionada")
            elif evento.key == pygame.K_UP:
                posY -= velocidad
                print("[ IN >] Tecla arriba presionada")
            elif evento.key == pygame.K_DOWN:
                posY += velocidad
                print("[ IN >] Tecla abajo presionada")

        if evento.type == pygame.KEYUP:
            if evento.key == pygame.K_LEFT:
                print("[OUT <] Tecla izquierda suelta")
            elif evento.key == pygame.K_RIGHT:
                print("[OUT <] Tecla derecha suelta")
            elif evento.key == pygame.K_UP:
                print("[OUT <] Tecla arriba suelta")
            elif evento.key == pygame.K_DOWN:
                print("[OUT <] Tecla abajo suelta")

    if posX < 0:
        posX += velocidad
        print("!!!!!!! Cara al limite")
    elif posY < 0:
        posY += velocidad
        print("!!!!!!! Cara al limite")
    elif posX > 370:
        posX -= velocidad
        print("!!!!!!! Cara al limite")
    elif posY > 270:
        posY -= velocidad
        print("!!!!!!! Cara al limite")

    mi_ventana.fill(negro)
    mi_ventana.blit(carita, [posX,posY])

    pygame.display.update()