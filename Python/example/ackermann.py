def ackermann(m, n):
    if m == 0:
        return n + 1
    elif n == 0:
        return ackermann(m - 1, 1)
    else:
        return ackermann(m - 1, ackermann(m, n-1))

for i in range(13):
    for j in range(13):
        print("ackerman en "+str(i) + " " + str(j))
        print(ackermann(i, j))
        print("\n")
    print("======")
