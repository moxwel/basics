import turtle

l = turtle.Pen()

for i in range(2):

    l.color("red")

    for x in range(50):
        l.width(x)
        l.fd(5)

    l.left(90)
    l.color("blue")

    for x in range(50):
        l.width(50 - x)
        l.fd(5)

    l.left(90)

while True:
    l.forward(0)