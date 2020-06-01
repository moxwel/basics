def factorial(n):
    f = 1
    i = 2
    while i <= n:
        f *= i
        i += 1
    return f

print(factorial(int(input("Ingresa num: "))))