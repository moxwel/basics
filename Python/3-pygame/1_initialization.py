#Para comenzar con Pygame, hay que importar la libreria de Pygame.
import pygame

#Esta libreria lo usaremos para detener el codigo por un momento, con el comando time.sleep()
import time

#Antes de utilizar cualquier modulo de Pygame, hay que inicializar Pygame, con el siguiente comando:
pygame.init()
#Ahora podemos utilizar los modulos de Pygame.

#Para crear una ventana, se hace lo siguiente:
mi_ventana = pygame.display.set_mode((400,300))
#En donde el primer valor (400) se refiere al ancho de la ventana (o longitud X), y el segundo valor (300) se refiere al alto de la ventana (o longitud Y). Con esto, la variable "mi_ventana" se transforma en un objeto de tipo "surface" (superficie), en el podremos poner todo lo que queramos.

#Para cambiar el nombre de nuestra ventana, se utiliza el siguiente comando:
pygame.display.set_caption("Ventana de Pygame 1")
#Dentro de los parentesis debe haber una cadena de texto con el nombre que queramos.

#Para pausar la ejecucion de codigo, podemos usar el siguiente comando:
time.sleep(1)
#El codigo dejara de ejecutarse durante 1 segundo, luego se reanudara. En este caso, lo usaremos para mantener la ventana que creamos abierta durante un rato.