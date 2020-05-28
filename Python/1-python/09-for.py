# Para repetir codigo, teniamos el bucle while, pero eso servia solo si una condicion es verdadera. Si quisieramos hacer un bucle while de tal forma que se repita una determinada cantidad de veces, tendriamos que estar definiendo contadores y esas cosas. Para simplificar las cosas, podemos usar el bucle "for".

# Ya sabemos como funciona la funcion range(), asi que de esta forma podemos hacer que el bucle se repita solamente 5 veces.
for x in range(5):
    print("Hola mundo")

print()

# Si tuvieramos una lista, podemos usarla para hacer que el for recorra la lista.
mi_lista = ["A","B","C","D"]
# En esta lista, solo hay 4 valores, por lo tanto, el bucle solo se repetira 4 veces.
for x in mi_lista:
    print("Un bucle con una lista")

print()

# Lo que pasa en el bucle for es que la variable que nosotros ingresamos al bucle va TOMANDO LOS VAORES DE LA LISTA. Es decir, que podemos llamar a esa variable dentro del bucle.
for variable in range(5):
# La lista que se crea con range(5) es [0,1,2,3,4]
    print("El valor de la variable es: " + str(variable))

print()

for variable in mi_lista:
    print("El valor de la variable es: " + str(variable))