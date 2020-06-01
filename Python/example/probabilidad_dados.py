apuesta = int(input())

dado1 = 1
cont = 0

while dado1 <= 6:
    dado2 = 1
    while dado2 <= 6:
        print(dado1, dado2, (dado1 + dado2) == apuesta)
        if dado1 + dado2 == apuesta:
            cont += 1
        dado2 += 1
    dado1 += 1

print("numero de veces:",cont,"... porcentaje:",(cont/36)*100)