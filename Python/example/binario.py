binario = int(input())
decimal = 0
potencia = 1

while binario > 0:
    digito = binario % 10

    if digito != 0:
        decimal += digito * potencia

    binario = binario // 10
    potencia = potencia * 2

print(decimal)