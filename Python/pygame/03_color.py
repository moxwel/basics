import pygame
import time

pygame.init()

#Pygame trabaja con el formato de color RGB (Red Green Blue). Para establecer un triplete de color (3 datos) hay que usar parentesis y poner los 3 valores de RGB separados por comas, desde 0 hasta 255.
rojo = (255,0,0)
verde = (0,255,0)
azul = (0,0,255)
blanco = (255,255,255)
negro = (0,0,0)

#Tambien se puede crear un color con Pygame.
color2 = pygame.Color(0,150,60)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 3")

#Con este comando, se rellena la superficie ("mi_ventana") con un color solido, el color es el que estara dentro de los parentesis.
mi_ventana.fill(color2)

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()