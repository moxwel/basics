def indices(lista,x):
    ind = []

    for i in range(len(lista)):
        if lista[i] == x:
            ind.append(i)

    return ind

mi_lista = [3,2,3,1,3,4,4,2,3,3,2,1,4,5,4,3,4,3,2,3,4,1,2,4]

print(indices(mi_lista,5))