gameOver = False
cont = 1
temp = 0

while not gameOver:
    num = int(input("Numero:"))

    if num == 1:
        print("PERDEDOR!")
        gameOver = True
    elif num == temp:
        cont += 1
        if cont == num:
            print("GANADOR!")
            gameOver = True
    else:
        cont = 1
        temp = num