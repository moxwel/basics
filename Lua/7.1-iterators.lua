-- Los 'iteradores' son un tipo de funcion especial que puede recorrer una coleccion (como las tablas)
-- o un conjunto de datos en general que posea una naturaleza de "lista".

-- Se pueden crear iteradores de manera manual, pero no vamos a verlo. Pero si veremos la funcion
-- 'pairs()', que es capaz de transformar una tabla en un iterador.





-- Un bucle for admite una sintaxis especial para 'iteradores', veamos...

-- Creamos una tabla.
una_tabla = {"Elem1", "Elem2", "Elem3", 9999, -192, {"Cosa1", "Cosa2", "Cosa3"}}
una_tabla["nomb"] = "Bob"
una_tabla["color"] = "Azul"





-- La sintaxis de un 'for' para iteradores es:

for key, value in pairs(una_tabla) do
    print("Indice: [" .. key .. "]\tValor: " .. tostring(value))
end
-- Indice: [1]     Valor: Elem1
-- Indice: [2]     Valor: Elem2
-- Indice: [3]     Valor: Elem3
-- Indice: [4]     Valor: 9999
-- Indice: [5]     Valor: -192
-- Indice: [6]     Valor: table: 0x55a1159af6b0
-- Indice: [nomb]  Valor: Bob
-- Indice: [color] Valor: Azul

-- La funcion 'pairs()' retorna un 'iterador', y el 'for' puede recorrerlo.

-- CUIDADO: Los indices nombrados (no numericos) no necesariamente van a estar en orden.





-- La funcion 'ipairs()' es similar, pero unicamente recorre los indices numericos.

print("=====")
for key, value in ipairs(una_tabla) do
    print("Indice: [" .. key .. "]\tValor: " .. tostring(value))
end
-- Indice: [1]     Valor: Elem1
-- Indice: [2]     Valor: Elem2
-- Indice: [3]     Valor: Elem3
-- Indice: [4]     Valor: 9999
-- Indice: [5]     Valor: -192
-- Indice: [6]     Valor: table: 0x555607cad6d0
