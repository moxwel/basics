-- En Lua, el unico tipo de dato que permite crear estructuras son las denominadas Tablas.

-- En otros lenguajes como Python existen las listas, diccionarios, conjuntos, etc.
-- Pero en Lua, solo existen las Tablas.

-- Las Tablas en realidad son objetos, mas precisamente son "arreglos asociativos",
-- y se crean de manera dinamica. No tienen tamaño maximo y pueden contener multiples
-- tipos de datos (excepto 'nil').

-- La simpleza de las Tablas permiten que este tipo de datos sea extremadamente flexible,
-- hasta el punto de implementar orientacion a objetos usando unicamente tablas.




-- Para crear una tabla vacia, debemos hacer esto:
mi_tabla = {}

print(type(mi_tabla)) -- table
print(mi_tabla)       -- table: 0x56229d9b8670 (referencia)


-- Podemos agregar mas elementos a una tabla existente:
mi_tabla[0] = "Elem1"
mi_tabla[1] = "Elem2"
mi_tabla[2] = "Elem3"
print(mi_tabla[0]..mi_tabla[1]..mi_tabla[2]) -- Elem1Elem2Elem3


-- Podemos usar strings como indices:
mi_tabla["nombre"] = "Max"
mi_tabla["edad"]   = 22
print(mi_tabla["nombre"], mi_tabla["edad"]) -- Max     22


-- Tambien podemos modificar valores ya definidas en un indice:
mi_tabla["nombre"] = "Bob"
print(mi_tabla["nombre"]) -- Bob


-- NOTA: Tambien podemos usar la siguiente notacion (unicamente sirve para los indices como strings)
print(mi_tabla.nombre, mi_tabla.edad) -- Bob     22





-- Podemos crear una tabla con elementos:
nueva_tabla = {"Cosa1", "Cosa2", "Cosa3"}
print(nueva_tabla[1]..nueva_tabla[2]..nueva_tabla[3]) -- Cosa1Cosa2Cosa3
print(nueva_tabla[0]) -- nil

-- ATENCION:
-- Notese los indices... Al contrario de lo que uno podria pensar, ¡los indices de las tablas no comienzan en 0!
-- Cuando creamos tablas con elementos dentro, Lua automaticamente asigna el indice 1 para el primer elemento.
-- El indice 0 no esta asignado a nada, por lo tanto es 'nil'.

-- Comparando el ejemplo con 'mi_tabla', EXPLICITAMENTE definimos un valor en el indice 0, por eso funciona.





-- Podemos tener tablas dentro de tablas:
otra_tabla = {{"Max", "Bob"},
              {"Cosa1", "Cosa2"},
              {"Elem1", "Elem2", "Elem3"}}

print(otra_tabla[1][1]) -- Max
print(otra_tabla[1][2]) -- Bob
print(otra_tabla[2][2]) -- Cosa1
print(otra_tabla[3][1]) -- Elem1





-- Podemos nombrar los indices directamente al definir tablas:
auto = {
    marca  = "Nissan",
    modelo = "Versa",
    anno   = 2018,
    color  = "Azul"
}
print(auto.marca, auto.modelo, auto.color, auto.anno) -- Nissan  Versa   Azul    2018





-- Podemos usar el operador de conteo (#) para obtener la cantidad de elementos:
print(#otra_tabla) -- 3
