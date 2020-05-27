# Los bucles pueden ejecutar mas de una vez una misma pieza de codigo. Hay varias formas de hacerlo, la mas basica es el bucle "while" ("mientras..."). En el bucle while, mientras su condicion sea VERDADERA, el codigo que este dentro del while se ejecutara.

# Establecemos la variable "var1".
var1 = 1
# Mientras "var1" sea menor o igual a 5...
while var1 <= 5:
    # ...ejecuta el codigo...

    # Imprime el valor de la variable "var1".
    print("Valor: " + str(var1) + " ... Luego le agregamos 1, queda en " + str(var1+1) + ", y se repite denuevo.")
    # Agregale 1 a su valor (si primero era 1, despues sera 2, y asi).
    var1 += 1

    # ...y luego vuelve a revisar la condicion.

# El codigo anterior debe de ejecutarse 5 veces, ya que cada vez que se repite el bucle, el valor de "var1" aumenta en 1; y la condicion de cada bucle es que "var1" sea menor o igual a 5; cuando queda en 6, la condicion se vuelve falsa, y el bucle termina.

x = 45
y = 80
while x < 50 and y < 100 :
    x = x + 1
    y = y + 1
    print(x,y)

# NOTA: Para escapar de un bucle infinito, o de cualquier bucle, se puede usar el comando "break". Esto detendra la repeticion, y se saldra del bucle, continuando normalmente con el codigo.