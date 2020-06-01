while True:
    print("Di \"suma\" para sumar, \"resta\" para restar, \"mult\" para multiplicar, o \"div\" para dividir. Di \"salir\" para terminar.")

    operation = input("Entrada: > ")

    if operation == "suma":
        print("Operacion seleccionada: Suma")
        numero1 = float(input("Ingresa numero 1: > "))
        numero2 = float(input("Ingresa numero 2: > "))
        resultado = numero1 + numero2
        print("EL resultado es: " + str(resultado) + "\n")

    elif operation == "resta":
        print("Operacion seleccionada: Resta")
        numero1 = float(input("Ingresa numero 1: > "))
        numero2 = float(input("Ingresa numero 2: > "))
        resultado = numero1 - numero2
        print("EL resultado es: " + str(resultado) + "\n")

    elif operation == "mult":
        print("Operacion seleccionada: Multiplicacion")
        numero1 = float(input("Ingresa numero 1: > "))
        numero2 = float(input("Ingresa numero 2: > "))
        resultado = numero1 * numero2
        print("EL resultado es: " + str(resultado) + "\n")

    elif operation == "div":
        print("Operacion seleccionada: Division")
        numero1 = float(input("Ingresa numero 1: > "))
        numero2 = float(input("Ingresa numero 2: > "))
        resultado = numero1 / numero2
        print("EL resultado es: " + str(resultado) + "\n")

    elif operation == "salir":
        print("Programa terminado")
        break

    else:
        print("Invalido\n")
