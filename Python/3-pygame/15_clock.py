import pygame
import time
import random

pygame.init()

rojo = pygame.Color(100,0,50)
negro = pygame.Color(0,0,0)

mi_icono = pygame.image.load("resources\icono_pixel.gif")
pygame.display.set_icon(mi_icono)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 15")

carita = pygame.image.load("resources\carita.png")

bg_color = negro
mi_ventana.fill(bg_color)

posX = 0
posY = 120
velocidad = 1
esta_en_borde_derecha = False

#En Pygame podemos cambiar el valor de los fotogramas por segundo. Por defecto, son muchos fotogramas por segundo, pero podemos cabiarlo. Para eso, tenemos que modificar el "reloj" del programa.

#Primero, tenemos que crear un objeto que sea de tipo "Clock", podemos usar el siguiente comando:
mi_reloj = pygame.time.Clock()
#Ahora para referirnos a nuestro reloj, usaremos "mi_reloj"

#Establescamos una variable "bg" al color negro, lo usaremos despues.
bg = negro

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    #Vamos a establecer la variable "bg" como el color de fondo
    mi_ventana.fill(bg)
    mi_ventana.blit(carita, [posX,posY])

    #La animacion de la carita
    if esta_en_borde_derecha == False:
        posX += velocidad
        if posX > 370:
            esta_en_borde_derecha = True
    else:
        posX -= velocidad
        if posX < 0:
            esta_en_borde_derecha = False

    #Si la posicion de la carita en X es una coordenada par...
    if posX%2 == 0:
        #Entonces el fondo cambia a rojo
        bg = rojo
    else:
        #Si no, entonces cambia a negro
        bg = negro

    #Lo anterior causara que el fondo cambie muy rapidamente entre negro y rojo, de esta forma podemos ver las actualizaciones por segundo que tiene el programa.

    #Recordemos que creamos una variable llamada "mi_reloj" que contiene el reloj interno del programa, de este depende los FPS del juego. Para manipular ese valor, podemos usar la funcion tick(). Los valores dentro de los parentesis seran los FPS que tendra el juego.
    mi_reloj.tick(15)
    #Mientras mas alto sea el valor, mas rapido sera la animacion de la carita, y tambien el parpadeo del fondo.

    #Notese la consola y los cambios en los FPS.
    print(mi_reloj)

    pygame.display.update()
