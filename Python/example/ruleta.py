import random
r2 = ["a", "b", "c", "d", "e", "f", "g",
      "h", "i", "j", "k", "l", "m", "n",
      "o", "p", "q", "r", "s", "t", "u",
      "v", "w", "x", "y", "z"]

sel = 5
v = 500000
v2 = 5

for veces2 in range(v2):
    cont = 0
    seq = []
    for x in range (97, 123-sel+1):
        ltr = []
        for y in range(sel):
            ltr.append(chr(x+y))
        seq.append(ltr)

    for veces in range(v):
        letras = []
        for x in range(sel):
            letras.append(random.choice(r2))
        letras.sort()


        if letras in seq:
            cont += 1

    print(cont)
    print((cont*100)/v)
