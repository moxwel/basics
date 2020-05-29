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
pygame.display.set_caption("Ventana de Pygame 9")

mi_ventana.fill(negro)

carita = pygame.image.load("resources\carita.png")

#Ahora vamos a usar la carita, y vamos a hacer que se mueva, pero antes, vamos a establecer unas variables...

#Estas variables contendran unas coordenadas de la ventana.
posX = 0
posY = 120

#Vamos a definir esta variable como la "velocidad" del objeto, luego veremos para que servira.
velocidad = 0.05

#Y esta variable booleana nos dira si el objeto esta tocando el borde derecho de la ventana, luego veremos para que servira.
esta_en_borde_derecha = False

#Ahora nos meteremos al loop infinito, recordemos que es aqui en donde ocurren cosas que producen que hayan cambios, ya que aqui se queda atascado el programa.
while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    #Volvemos a rellenar la pantalla en negro, despues de cada frame, ya que si no lo hacemos, los sprites anteriores de la carita no se van a borrar, y se vera muy mal.
    mi_ventana.fill(negro)
    mi_ventana.blit(carita, [posX,posY])

    #Basicamente aqui ocurre la animacion.

    #Aqui le preguntamos al programa si el objeto (la carita) esta en el borde derecho de la ventana. Si este es "False" (se encuentra a la izquierda), entonces que la carita avance hacia la derecha.
    if esta_en_borde_derecha == False:

        #Aqui usamos la variable velocidad, estamos aumentando el valor de la coordenada de X (hacia la derecha). La variable velocidad sera responsable de "cuantos pixeles aumenta en cada frame", mientras mas sea el numero, mas rapido se movera.
        posX += velocidad

        #Aqui volvemos a preguntarle al programa sobre la posicion de la carita. Esta vez, si la carita se encuentra en una coordenada mayor a la coordenada X = 370, entonces significa que ya esta en el borde derecho de la ventana, por ende, el valor de la variable "esta_en_borde_derecha" cambia a "True".
        if posX > 370:
            esta_en_borde_derecha = True

    #El else se ejecuta cuando la condicion anterior no se cumple. En otras palabras, si el objeto ya esta en el borde derecho (es decir, la variable "esta_en_borde_derecha" es "True"), entonces hay que hacer que se mueva a la izquierda.
    else:

        #Al igual que la anterior, estamos cambiando la posicion de la coordenada X, pero esta vez la estamos disminuyendo (hacia la izquierda).
        posX -= velocidad

        #Tambien, si el objeto ya llega a la coordenada X = 0, significa que la carita ya esta en el borde izquierdo de la ventana, entonces el valor de "esta_en_borde_derecha" cambia denuevo a "False", y el ciclo se repite.
        if posX < 0:
            esta_en_borde_derecha = False

    pygame.display.update()
