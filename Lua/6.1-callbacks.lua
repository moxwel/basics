-- En Lua, las funciones son de primera clase, es decir, se pueden pasar funciones como argumento a otras funciones.
-- En Javascript, este metodo se llama 'callback' (no se llama asi en Lua, pero la idea es la misma).




-- Definimos funciones que realizan operaciones matematicas sencillas.
function suma(num1, num2)
    return num1 + num2
end

function resta(num1, num2)
    return num1 - num2
end

function multi(num1, num2)
    return num1 * num2
end




-- Vamos a crear una funcion llamada 'calculadora', que puede recibir otra funcion como argumento
function calculadora(una_funcion, num1, num2)

    -- Mas aún, esta funcion sera llamada aqui dentro.
    local resultado = una_funcion(num1, num2)

    print("El resultado es: "..resultado)
end




-- Acabamos de crear una calculadora generica y de uso general. Funcionará exactamente igual, y solo
-- cambiará dependiendo de la funcion que le entreguemos (quien se hará cargo de la operación como tal)

calculadora(suma,5,2)   -- El resultado es: 7
calculadora(resta,10,7) -- El resultado es: 3
calculadora(multi,5,10) -- El resultado es: 50

-- Notese que la funcion que ingresamos como argumento no va con parentesis. ¿Por que?

-- 'funcion()' causará una "llamada", la funcion se ejecuta.
-- 'funcion' es la referencia misma de la funcion en memoria.

-- Podemos comprobar esto:

print(type(calculadora)) -- function
print(calculadora)       -- function: 0x55a0205d60c0
