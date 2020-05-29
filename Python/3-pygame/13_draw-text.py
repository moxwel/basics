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

mi_ventana.fill(negro)

#Para poder imprimir texto en pantalla, primero es necesario definir una fuente para usar. Para eso, debemos crear una variable de tipo Font, con pygame.font.Font() .
mi_fuente = pygame.font.Font(None, 50)
#El primer parametro de Font() es el archivo de fuente ".ttf" (para usar la fuente predeterminada se usa "None"), el segundo parametro es el tamaño de la fuente.

#Si se quiere usar una fuente propia, se debe dejar la direccion relativa del archivo ".ttf" que se quiere usar.
determination_font = pygame.font.Font("resources/determination.ttf", 50)

#NOTA: Para usar fuentes que sean partes del sistema, hay que usar la funcion SysFont() en vez de Font().

#Para poner texto en la ventana, no se puede directamente poner un texto y ya... primero hay que renderizar el texto que queremos poner. Esto creara una especie de imagen, que despues con la funcion blit() podemos poner en la ventana.

#Utilizando "mi_fuente" como fuente, vamos a renderizar el texto en la variable "mi_texto".
mi_texto = mi_fuente.render("Prueba de texto 1", True, azul, None)
#El primer parametro de render() es el texto que queremos poner, el segundo es el antialias (True o False), el tercero es el color del texto, y el cuarto es el color del fondo (None para transparente).

#Ahora, como lo haciamos con las imagenes, usaremos la funcion blit() para poner el texto en la ventana.
mi_ventana.blit(mi_texto,(10,10))

#Vamos a cambiar un poco el texto y el color, y vamos a volver a renderizar otro texto.
mi_texto = mi_fuente.render("Prueba de texto 2", False, rojo, None)
mi_ventana.blit(mi_texto,(10,50))

mi_texto = mi_fuente.render("Prueba de texto 3", True, verde, azul)
mi_ventana.blit(mi_texto,(10,90))

#Aqui en vez de ponerle "mi_fuente" le ponemos "determination_font".
mi_texto = determination_font.render("Prueba de texto 4", True, blanco, None)
mi_ventana.blit(mi_texto,(10,130))

mi_texto = determination_font.render("Prueba de texto 5", True, azul, None)
mi_ventana.blit(mi_texto,(10,170))

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()