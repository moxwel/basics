import pygame
import time

pygame.init()

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 2")

#A continuacion hay un bucle infinito, esto mantendra la ventana abierta, y permitira al programa checkear eventos en todo momento, ya lo veremos a continuacion.
while True:

    #Pygame funciona con eventos. Los eventos, como su nombre lo dice, son acciones que van ocurriendo en el prorgama, por ejemplo: tocar una tecla, hacer click en algun lugar, etc.

    #Pygame posee una lista interna con todos los eventos posibles, podemos acceder a ella con pygame.event.get() , pero si nosotros queremos hacer que ocurra algo si sucede tal "evento", tenemos que decirle al programa que hacer.

    #Para conseguir esto, podemos usar un bucle for. Este bucle for va a recorrer la lista completa...
    for evento in pygame.event.get():
        #...y mientras este recorriendo la lista, podemos hacer que compare el "tipo de evento" que esta ocurriendo en ese instante.

        #Con este condicional if, lo que estamos haciendo es decirle al programa "si el tipo de evento que esta ocurriendo ES pygame.QUIT ..."
        if evento.type == pygame.QUIT:
            #"...entonces, sal del programa."

            #Vamos a hacer que la consola nos avise que tocamos la "X" de la ventana antes de cerrar todo.
            print("Se toco la \"X\" de la ventana.")

            pygame.quit() #Detiene todos los modulos de Pygame.
            quit() #Detiene Python.

            #Como aclaracion, pygame.QUIT es un evento que ocurre cuando se presiona la "X" de la ventana para cerrarlo. Este es uno de los muchos tipos de eventos que hay en Pygame.

    #Si ninguno de los eventos anteriores ocurre, entonces el programa va a seguir adelante en el codigo.

    #Cuando ocurren cambios en la superficie (por ejemplo: se crea un sprite, o se mueve un objeto) es necesario actualizar la ventana. Esto lo podemos hacer con el siguiente comando:
    pygame.display.update()
    #Actualizar la ventana, quiere decir que el programa va a aplicar todos los cambios hechos, y los va a mostrar a continuacion. Un ejemplo de esto puede ser lo siguiente: si yo creo un cuadrado negro en la ventana, este va a estar ahi, pero nosotros no lo vamos a ver hasta que le digamos al programa que "actualice" la ventana.