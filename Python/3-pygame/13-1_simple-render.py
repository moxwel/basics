import pygame
import time

pygame.init()

azul = pygame.Color(0,100,255)
rojo = pygame.Color(150,0,0)
verde = pygame.Color(0,150,50)
negro = pygame.Color(0,0,0)
blanco = pygame.Color(255,255,255)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 13")

#En vez de copiar el mismo comando una y otra vez, empaquetemos el codigo en una funcion, ahora se hara mas simple renderizar texto en la pantalla.
def render_text(texto, color, posX, posY):
    mi_fuente = pygame.font.Font("resources/determination.ttf", 30)
    mi_texto = mi_fuente.render(texto, True, color, None)
    mi_ventana.blit(mi_texto,(posX, posY))

mi_ventana.fill(negro)

#Ahora con una sola funcion podemos renderizar texto.
render_text("Prueba de la funcion", blanco, 10,10)
render_text("Prueba de la funcion", rojo, 10,40)
render_text("Prueba de la funcion", azul, 10,70)
render_text("Prueba de la funcion", verde, 10,100)

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()