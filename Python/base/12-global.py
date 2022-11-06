variable1 = 555

# De una forma simple, los valores fuera de una funcion no se pueden cambiar.
def cambiar_valor():
    variable1 = 10

print(variable1) # 555
cambiar_valor()
print(variable1) # 555
print("")

# Para cambiar el valor de una variable fuera de una funcion DESDE una funcion, hay que decirle a la funcion que la variable que intentamos modificar esta fuera de la funcion. Podemos hacer eso con el comando "global".
def cambiar_valor_global():
    # Le decimos a la funcion que la variable "variable1" esta fuera de la funcion.
    global variable1
    # La funcion va a buscar fuera de la funcion a la variable "variable1", y va a tomar su valor.

    # Cambiamos el valor de la variable "variable1" de 555 a 4
    variable1 = 4

print(variable1) # 555
cambiar_valor_global()
print(variable1) # 4