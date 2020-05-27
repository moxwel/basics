# Si un bucle tiene su argumento siempre en verdadero, y nunca cambia, el bucle se ejecutara indefinidamente, no se detendra.

repeticion = 0
while True:
    print("Bucle infinito! Vuelta: " + str(repeticion))
    repeticion += 1