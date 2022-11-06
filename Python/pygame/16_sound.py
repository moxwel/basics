import pygame
import time

pygame.init()

negro = pygame.Color(0,0,0)

mi_ventana = pygame.display.set_mode((400,300))
pygame.display.set_caption("Ventana de Pygame 16")

mi_ventana.fill(negro)

#Con Pygame, tambien podemos reproducir sonidos. Para ello, tenemos que hacer de la misma forma como cargar imagenes, tenemos que cargar el sonido dentro de una variable.

#Con el comando pygame.mixer.sound() podemos cargar un archivo de sonido. Dentro de los parentesis, debe ir la direccion relativa del archivo.
mi_sonido = pygame.mixer.Sound("resources/coin.wav")
#Y ahora, el sonido "mi_sonido" hay que reproducirlo con la funcion play(). Para ello hay que llamar a la variable que contiene el archivo de sonido.
mi_sonido.play()

print("Reproduciendo: sonido 1") #Notese la consola

time.sleep(3)

mi_sonido_2 = pygame.mixer.Sound("resources/1up.wav")
mi_sonido_3 = pygame.mixer.Sound("resources/bump.wav")

#Tambien podemos cargar archivos de musica, se prefiere que esten en formato .ogg .
mi_musica = pygame.mixer.Sound("resources/music.ogg")

mi_sonido_2.play(-1)
#Dentro de los parentesis de la funcion play() puede ir un entero, que se refiere a la cantidad de veces que se repite el sonido. 0 para que se repita 1 vez, 1 para que se repita 2, etc...

#NOTA: Poner -1 dentro de los parentesis de play() hara que el sonido se repita para siempre

print("Reproduciendo: sonido 2")

time.sleep(3.5)

#Para cambiar el volumen del sonido, se debe usar la funcion set_volume(). Su parametro es un numero entre 0.0 y 1.0
mi_sonido_2.set_volume(0.1)
print("Cambiando volumen a: sonido 2")

time.sleep(3.5)

#Para detener todos los sonidos que se estan reproduciendo, podemos usar la funcion stop().
mi_sonido_2.stop()
#NOTA: para poder detener un sonido especifico, podemos llamar a la variable que contiene el sonido, y usar la funcion stop, por ejemplo: mi_sonido.stop()

mi_sonido_3.play()
print("Reproduciendo: sonido 3")

time.sleep(3)

mi_musica.play()
print("Sonando musica...")
time.sleep(5)

#Con la funcion fadeout() podemos detener el sonido con un agradabe desvanecimiento.
mi_musica.fadeout(4000)
#Los numeros dentro del parentesis representan el tiempo en milisegundos en que el sonido tardara en desvanecerse.
print("Deteniendo...")

while True:

    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            quit()

    pygame.display.update()