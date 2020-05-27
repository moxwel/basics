# Ya que sabemos como funciona la logica en Python, con ello podemos crear condicionales. Los condicionales nos sirven para poder poner condiciones al programa, por ejemplo, ejecutar un codigo solo si alguna variable tiene tal valor, o si una comparacion es verdadera, etc.

# El condicional mas basico es el "if" ("si..."). Si el argumento que lleva dentro es verdadero, entonces todo lo que este dentro del "if" se ejecutara.
if True:
    print("Hola mundo")

# Si 3 es MENOR a 5, entonces todo lo que este dentro del "if" se ejecutara.
if 3 < 5:
    print("3 es menor que 5")

if 3 == 2:
    print("3 es igual a 2")
    # Este texto no se va a imprimir en consola ya que el argumento del "if" dice "3 ES IGUAL A 2", lo cual es falso, por ende, no se ejecutara.

if 1 == 1 or 3 != 3:
    print("Al menos uno de los argumentos es verdadero")

# Si (1 ES IGUAL A 1) Y (no[4+5 ES MAYOR A 10]) son verdaderos, entonces...
if 1 == 1 and not 4 + 5 > 10:
    print("El argumento de \"if\" es verdadero")

# Justo fuera del "if", se puede poner un "else" ("si no..."). Entonces, si el argumento del "if" es falso, se ejecutara lo que esta dentro del "else" en cambio.

# Si 1 es igual a 3, entonces...
if 1 == 3:
    # ...ejecuta este codigo.
    print("1 es igual a 3")

# Si no...
else:
    # ...ejecuta este codigo.
    print("1 no es igual a 3") # Este codigo se va a ejecutar.

# Tambien le podemos poner una condicion al "else". Esto se puede hacer con "elif", que es como una forma de decir "else if" ("si no, entonces si...").

# Si 1 es igual a 3, entonces...
if 1 == 3:
    # ...ejecuta este codigo.
    print("1 es igual a 3")

# Si no, entonces si 2 es igual a 3...
elif 2 == 3:
    # ...ejecuta este codigo.
    print("2 es igual a 3")

# Si todo lo anterior es falso...
else:
    # ...ejecuta este codigo.
    print("Todo lo demas es falso")