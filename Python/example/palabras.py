def palabras(texto):
    cont = 1
    for x in texto:
        if x == " ":
            cont += 1
    return cont

print(palabras(input()))