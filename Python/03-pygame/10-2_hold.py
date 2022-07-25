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
velocidad = 0.1

#Para ver si las teclas se presionan
left = False
right = False
up = False
down = False

while True:

    for evento in pygame.event.get():

        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()
        
        #Mientras se presionen, el boolean sera True
        if evento.type == pygame.KEYDOWN:
            if evento.key == pygame.K_LEFT:
                left = True
            elif evento.key == pygame.K_RIGHT:
                right = True
            elif evento.key == pygame.K_UP:
                up = True
            elif evento.key == pygame.K_DOWN:
                down = True

        #Si se sueltan, volveran a False
        if evento.type == pygame.KEYUP:
            if evento.key == pygame.K_LEFT:
                left = False
            elif evento.key == pygame.K_RIGHT:
                right = False
            elif evento.key == pygame.K_UP:
                up = False
            elif evento.key == pygame.K_DOWN:
                down = False

    if left == True:
        if up == True:
            posX -= velocidad
            posY -= velocidad
        elif down == True:
            posX -= velocidad
            posY += velocidad
        else:
            posX -= velocidad
    elif right == True:
        if up == True:
            posX += velocidad
            posY -= velocidad
        elif down == True:
            posX += velocidad
            posY += velocidad
        else:
            posX += velocidad
    elif up == True:
        if left == True:
            posY -= velocidad
            posX -= velocidad
        elif right == True:
            posY -= velocidad
            posX += velocidad
        else:
            posY -= velocidad
    elif down == True:
        if left == True:
            posY += velocidad
            posX -= velocidad
        elif right == True:
            posY += velocidad
            posX += velocidad
        else:
            posY += velocidad

    #Limites de ventana
    if posX < 0:
        posX += 1
        if posY < 0:
            posY += 1
        elif posY >= 270:
            posY -= 1
    elif posX >= 370:
        posX -= 1
        if posY < 0:
            posY += 1
        elif posY >= 270:
            posY -= 1
    elif posY < 0:
        posY += 1
    elif posY >= 270:
        posY -= 1

    mi_ventana.fill(negro)
    mi_ventana.blit(carita, [posX,posY])

    pygame.display.update()