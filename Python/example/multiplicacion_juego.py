from random import randint

def validar(n1,n2,res):
    if n1*n2 == res:
        return True
    else:
        return False

term = False
buenas = 0
dif = 0
while not term:
    num1 = randint(1+dif,10+dif)
    num2 = randint(1,10)

    print("Cuanto es",num1,"x",num2,"?")
    entr = int(input("Respuesta: "))

    if validar(num1,num2,entr):
        print("Correcto!")
        buenas += 1
        dif += 2
    else:
        print("Incorrecto!")
        print(buenas,"correctas")
        term = True