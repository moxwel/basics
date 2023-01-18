-- Lua tiene operadores aritmeticos.

print( 5 + 3 )   -- 8
print( 2 - 11 )  -- -9
print( 5 * 10 )  -- 50
print( 50 / 2 )  -- 25.0
print( 10 / 3 )  -- 3.33333333

-- Tambien tiene operadores de modulo (%) y exponente (^)

print( 2 ^ 4 )  -- 16.0
print( 10 % 3 ) -- 1


print("")


-- Los operadores relacionales son:

-- Igual
print( 3 == 3 ) -- true
print( "3"==3 ) -- false
-- Notese que el operador 'igual' tambien considera el tipo de dato.

-- Diferente
print( 3 ~= 3 ) -- false
print( 3 ~= 4 ) -- true

-- Y los clasicos > < >= <=


print("")


-- Los operadores logicos son:

-- And
print(true and true) -- true
print(true and false) -- false
print(false and false) -- false

-- OR
print(true or false) -- true
print(false or false) -- false

-- NOT
print(not true) -- false
print(not false) -- true





-- Y el operador de conteo.

print(#"Hola mundo") -- 10
-- Este operador cuenta cuantos elementos tiene un string (o una tabla, que ya veremos despues).
