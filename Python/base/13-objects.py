# Para definir una clase en Python, se debe usar "class" y luego el nombre de la clase que queremos crear.

# Crearemos la clase "miClase"
class miClase:

    # Ahora que estamos dentro de la clase, podemos crear atributos y metodos.
    miAtributo = 150

    # Para definir un metodo, es como cualquier funcion normal.
    def miMetodo():
        print("Se activo el metodo.")

# Para instanciar un objeto de una clase, se debe crear como una variable.
miObjeto = miClase

# Ahora podemos acceder a sus datos.
print(miObjeto.miAtributo) # 150

#Y modificar sus datos.
miObjeto.miAtributo = 500
print(miObjeto.miAtributo) # 500

# Ejecutar sus metodos.
miObjeto.miMetodo() # Se activo el metodo.



class clasePersona:

    # De esta manera se define un constructor, de esta manera, se le puede asignar datos a un objeto desde su creacion (se comienza con el argumento "self" para referirse a la misma clase).
    def __init__(self, arg1, arg2, arg3):
        # De esta manera podemos definir variables "globales" de la clase. Estas variables solo estaran disponibles dentro de la clase.
        self.nombre = arg1
        self.edad = arg2
        self.colorFavorito = arg3

    # Si quisieramos modificar estas variables en algun metodo, tenemos que usar el argumento "self" primero.
    def aumentarEdad(self,valor):
        self.edad += valor

# Ahora al crear un objeto de la clase anterior, tenemos que definir sus datos.
persona1 = clasePersona("Max",18,"Azul")

# Ahora tambien podemos acceder a sus datos.
print(persona1.nombre) # Max
print(persona1.edad) # 18
print(persona1.colorFavorito) # Azul

persona1.aumentarEdad(2)
print(persona1.edad) # 20



# Una clase puede ser sub-clase de otra, y heredar todos sus atributos y metodos. Para crear una subclase, se debe poner el nombre de la clase actual, y entre parentesis, la clase padre (o super clase).

# Tenemos la clase de alguna entidad de un juego, posee tamaño, posicion, nombre, y se puede mover.
class EntidadJuego:

    def __init__ (self, nombre, ancho, alto, x_pos, y_pos):
        self.nombre = nombre
        self.ancho = ancho
        self.alto = alto
        self.x_pos = x_pos
        self.y_pos = y_pos

    def moverse(self,cant_x,cant_y):
        self.x_pos += cant_x
        self.y_pos += cant_y

# Creamos un objeto de "EntidadJuego".
entidad1 = EntidadJuego("Genery",50,50,100,100)
print(entidad1.nombre) # Genery

# Ahora podemos crear una sub-clase de "EntidadJuego". De esta forma, esta clase tiene acceso a todas las variables y metodos que existan en "EntidadJuego".
class NPCJuego(EntidadJuego):

    # Aqui hacemos un constructor normal como siempre, pero que esta vez no definira el tamaño, ya veremos por que.
    def __init__(self, nombre, x_pos, y_pos):

        # La funcion de "super()." es llamar metodos o atributos de la super clase (la clase en la que se basa la sub-clase actual, en este caso, la super clase seria "EntidadJuego").

        # Lo que hara "super()." ahora es llamar al metodo "__init__", que es el constructor de la clase "EntidadJuego", y es el encargado de dar valores a los atributos del objeto.
        super().__init__(nombre, 100, 200, x_pos, y_pos)
        # Como se ve, en los lugares donde supuestamente van los valores de "ancho" y "alto" ya estan predefinidos. Esto quiere decir que un objeto de la clase "NPCJuego" siempre tendra los valores de su tamaño en 100 y 200.

        # En pocas palabras: El tamaño de "NPCJuego" ya esta definida, lo unico que se puede hacer es cambiar su nombre y posicion (notese el constructor).

    # De la misma forma, podemos crear metodos.
    def moverse(self, cant_x):
        # Haremos que la diferencia sea que los NPC solo puedan moverse a traves de la coordenada X, y no en la Y.

        # Entonces para hacer que se mueva, llamaremos al metodo de la super clase que ya habiamos hecho, y solo cambiara el valor de X que nosotros le hayamos colocado, mientras el valor de Y no cambia.
        super().moverse(cant_x,0)

npc1 = NPCJuego("Vendedor", 200, 200)
print(npc1.nombre) # Vendedor
print(str(npc1.ancho) + " " + str(npc1.alto)) # 100 200