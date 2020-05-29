import pygame
import time

pygame.init()

negro = pygame.Color(0,0,0)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 6")

mi_ventana.fill(negro)

#Antes de poder usar imagenes en el prorgama, primero se deben cargar a este. Se debe usar el siguiente comando:
mi_imagen = pygame.image.load("resources/imagen_pixel.png")
#Dentro de los parentesis debe ir una cadena de texto con la direccion relativa al archivo de imagen que se quiere cargar. La variable "mi_imagen" se vuelve un objeto de imagen, y se podra usar a continuacion, ya esta cargada.

#Blit es un metodo para poder cargar la imagen a la superficie ("mi_ventana"). Con esto podemos mostrar imagenes en la ventana.
mi_ventana.blit(mi_imagen, (10,10))
#El primer parametro es el objeto de imagen que se va a usar ("mi_imagen").
#El segundo parametro es la coordenada de la esquina superior-izquierda donde se va a ubicar la imagen.

#Tambien podemos redimensionar imagenes con el comando pygame.transform.scale(). Esto es util cuando queramos cambiar el tamano de alguna imagen.

#Vamos a definir una nueva variable llamada "mi_imagen_cambiada", esta va a contener la misma imagen anterior ("mi_imagen") pero redimensionada.
mi_imagen_cambiada = pygame.transform.scale(mi_imagen,(50,100))
#De la funcion scale(), el primer parametro es la superficie que se va a redimensionar, el segundo parametro equivalen a las nuevas dimensiones en pixeles a la que se va a redimensionar (en este caso, 50 x 100 pixeles).

#Una vez que ya cambiamos el tamano de la imagen, vamos a imprimirla en pantalla.
mi_ventana.blit(mi_imagen_cambiada,(300,100))

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()