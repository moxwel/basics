import pygame
import time

pygame.init()

rojo = pygame.Color(255,0,0)
verde = pygame.Color(0,255,0)
azul = pygame.Color(0,100,255)
blanco = pygame.Color(255,255,255)
negro = pygame.Color(0,0,0)

#Ahora que ya sabemos cargar imagenes al programa, tambien podemos cargar imagenes para usarlos como iconos para nuestro prorgama. Tenemos que tener una imagen cuadrada, escalarla a 16x16 px, luego a 32x32 px y finalmente guardarlo como .gif. Una vez hecho eso, cargamos la imagen en algun objeto, en este caso "mi_icono".
mi_icono = pygame.image.load('resources/icono_pixel.gif')
#La imagen ya esta cargada, ahora hay que decirle al programa que queremos esa imagen como icono del programa.

#Con este comando podemos hacerlo:
pygame.display.set_icon(mi_icono)
#Es importante hacer esto antes de pygame.display.set_mode()

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("<-- Mira el icono | Ventana de Pygame 7")

mi_ventana.fill(negro)

pygame.draw.polygon(mi_ventana, blanco, [(12,5),(17,15),(7,15)])
pygame.draw.rect(mi_ventana, blanco, [(11,15),(3,50)])

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()
