num = int(input("Numero: "))

d = 1

while d < num:
    if num % d == 0:
        print(num,"/",d,"--- Si")
    else:
        print(num,"/",d,"--- No")
    d += 1