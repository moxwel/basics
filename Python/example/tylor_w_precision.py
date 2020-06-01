from math import factorial

num = float(input("Valor de X: "))
e = float(input("Precision: "))

suma = 0
anterior = 0

continuar = True
cont = 0
while continuar:
    term = num**cont / factorial(cont)
    print(term)

    if abs(suma+term-anterior) < e:
        continuar = False
    else:
        suma += term
        anterior = suma
        cont += 1

print(suma)