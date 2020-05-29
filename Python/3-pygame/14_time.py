import pygame
import time

pygame.init()

negro = pygame.Color(0,0,0)
blanco = pygame.Color(255,255,255)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 14")

mi_ventana.fill(negro)

#Variable auxiliar, luego veremos para que sirve.
auxiliar = 1

#Funcion de fuente que usamos en 13-1.
def render_text(texto, color, posX, posY):
    mi_fuente = pygame.font.Font("resources/determination.ttf", 30)
    mi_texto = mi_fuente.render(texto, True, color, None)
    mi_ventana.blit(mi_texto,(posX, posY))

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    mi_ventana.fill(negro)

    #Pygame se ejecuta por ticks. Cada tick cuenta como la "velocidad" a la que corre el programa, mientras menos ticks sean, significa que el programa se ejecuta mas lento. La funcion get_ticks() nos devuelve el valor entero en milisegundos de cuanto tiempo ha pasado desde que pygame.init() se ejecuto.
    tiempo = pygame.time.get_ticks()//1000
    #Dividir ese valor por 1000 nos estaria dando solo el valor de los segundos.
    
    #Si usamos estos comandos de esta forma, podemos hacer que se imprima el tiempo en segundos desde que se abrio el programa.
    if auxiliar == tiempo:
        auxiliar += 1
        print(tiempo) #Notese consola.

    #Ahora si usamos la funcion para renderizar texto como lo vimos en 13-1, podemos hacer que el texto se imprima en pantalla
    render_text("Tiempo: " + str(tiempo), blanco, 10, 10)

    pygame.display.update()