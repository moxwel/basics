import pygame
import time
import random

pygame.init()

azul = pygame.Color(0,100,255)
rojo = pygame.Color(150,0,0)
verde = pygame.Color(0,150,50)
negro = pygame.Color(0,0,0)

mi_icono = pygame.image.load("resources\icono_pixel.gif")
pygame.display.set_icon(mi_icono)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 12")

posX = 0
posY = 200
velocidad = 0.1
esta_en_borde_derecha = False

#Vamos a establecer el valor de la variable "color_rectangulo1" al rojo (que es el color rojo).
color_rectangulo1 = verde

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    mi_ventana.fill(negro)

    #Vamos a hacer que dos rectangulos colisionen, y al colisionar, estos reaccionen y hagan algo. Esto es importante en el desarrollo de juegos.

    #Comenzamos creando un cuadrado rojo ("color_rectangulo1" es rojo) pequeño.
    rectangulo1 = pygame.draw.rect(mi_ventana,color_rectangulo1,[posX,posY,100,300])

    #Tomamos la posicion del mouse y lo guardamos en la variable "mouse_pos".
    mouse_pos = pygame.mouse.get_pos()
    #Y creamos otro rectangulo de color azul y un poco mas pequeño, que va a tener la posicion de nuestro mouse.
    rectangulo2 = pygame.draw.rect(mi_ventana,azul,[mouse_pos,(50,50)])

    #La funcion colliderect() devuelve un booleano: True si los dos rectangulos "rectangulo1" y "rectangulo2" se sobreponen, False si no se sobreponen.
    if rectangulo1.colliderect(rectangulo2):
        #Mientras se sobreponen, esta parte del codigo se ejecuatra.

        #Cambia el color del rectangulo a verde.
        color_rectangulo1 = verde

        #Y hara que el cuadrado se mueva de izquierda a derecha (extraido del tutorial numero 9).
        if esta_en_borde_derecha == False:
            posX += velocidad
            if posX > 300:
                esta_en_borde_derecha = True
        else:
            posX -= velocidad
            if posX < 0:
                esta_en_borde_derecha = False
    else:
        #Mienrtas no se sobrepongan, esta parte del codigo se ejecutara.
        color_rectangulo1 = rojo

    pygame.display.update()
