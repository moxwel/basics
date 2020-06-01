def factorial(n):
    f = 1
    i = 2
    while i <= n:
        f *= i
        i += 1
    return f

num = int(input("Valor de X: "))
term = int(input("Numero de terminos: "))

suma = 0
cont = 0

while cont <= term:
    val = num**cont / factorial(cont)
    suma += val
    cont += 1

print(suma)