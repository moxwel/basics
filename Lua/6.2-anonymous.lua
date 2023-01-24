-- Se pueden crear funciones anonimas (es decir, funciones sin nombre).

-- Primero vamos a crear una funcion que lo unico que hará sera: repetir 3 veces la función
-- que le entregaremos como argumento.

function repetir3veces(una_funcion)
    for i=1, 3 do
        una_funcion()
    end
end

-- Ahora, en vez de definir una funcion antes, podemos declararla inmediatamente en la misma linea

repetir3veces(function() print("Hola") end)
-- Hola
-- Hola
-- Hola

-- Notese que la funcion que ingresamos a 'repetir3veces' no posee nombre. ESTA es una funcion anonima.




-- Podemos usar funciones anonimas para definir comportamiento en el mismo momento cuando llamamos a
-- una funcion, o podemos usarlas como variables.

una_variable = function() print("Una variable que almacena una funcion.") end

-- Acabamos de crear una variable que almacena una funcion. Podemos llamarla

una_variable() -- Una variable que almacena una funcion.
