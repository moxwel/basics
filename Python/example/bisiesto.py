while True:
    y = int(input("año: "))

    if y % 100 == 0:
        if y % 400 == 0:
            print(y, "Si")
        else:
            print(y, "No")
    else:
        if y % 4 == 0:
            print(y, "Si")
        else:
            print(y, "No")
