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

#Ahora nuestro objetivo es hacer que la carita se mueva si NOSOTROS presionamos el teclado. Hay que recordar que en Pygame se trabajan con eventos, y uno de esos eventos es efectivamente "presonar una tecla".

#Pongamos unas variables para las coordenadas y la velocidad:
posX = 200
posY = 100
velocidad = 5

while True:

    #Aqui es donde censamos los eventos que ocurren en el juego.
    for evento in pygame.event.get():

        #Si se toca la "X" de la ventana.
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()
        
        #Si se PRESIONA alguna tecla del teclado. Esta nos va a servir.
        if evento.type == pygame.KEYDOWN:
            #Cuando el programa detecte que se ha presionado una tecla, va a ejecutar lo que esta en este if, pero lo que nosotros queremos es hacer acciones especificas por CADA TECLA. Para esto, necesitaremos comparar para hacer que el programa ejecute las acciones SOLAMENTE CUANDO PRESIONAMOS UNA TECLA DEFINIDA.

            #En este caso, si se presiona la tecla direccional izquierda...
            if evento.key == pygame.K_LEFT:
                #...la imagen se va a mover a la izquierda.
                posX -= velocidad
                #Y nos va a avisar que tocamos la tecla en la consola.
                print("[ IN >] Tecla izquierda presionada")

            #Si se presiona la tecla direccional derecha...
            elif evento.key == pygame.K_RIGHT:
                #...la imagen se va a mover a la derecha.
                posX += velocidad
                print("[ IN >] Tecla derecha presionada")

            elif evento.key == pygame.K_UP:
                posY -= velocidad
                print("[ IN >] Tecla arriba presionada")
            elif evento.key == pygame.K_DOWN:
                posY += velocidad
                print("[ IN >] Tecla abajo presionada")

        #Si se suelta alguna tecla del teclado.
        if evento.type == pygame.KEYUP:
            if evento.key == pygame.K_LEFT:
                print("[OUT <] Tecla izquierda suelta")
            elif evento.key == pygame.K_RIGHT:
                print("[OUT <] Tecla derecha suelta")
            elif evento.key == pygame.K_UP:
                print("[OUT <] Tecla arriba suelta")
            elif evento.key == pygame.K_DOWN:
                print("[OUT <] Tecla abajo suelta")

    mi_ventana.fill(negro)
    mi_ventana.blit(carita, [posX,posY])

    pygame.display.update()