-- Tambien es posible definir funciones en tablas. Esto lo podemos lograr usando funciones anonimas.

una_tabla = {
    function()
        print("Soy una funcion en el indice 1.")
    end,

    function()
        print("Soy una funcion en el indice 2.")
    end,

    function()
        print("Soy una funcion en el indice 3.")
    end,
    }

-- Veamos que tenemos

print(una_tabla)    -- table: 0x563dd04d5690

print(una_tabla[1]) -- function: 0x5571e7bcae20

una_tabla[1]()      -- Soy una funcion en el indice 1.

-- Notese como en el indice 1 esta la funcion, y con eso, debemos "llamar" a la funcion.





-- Recordemos que podemos definir nombres de string como indices.

conversaciones = {
    saludar = function(nomb)
        print("Saludos "..nomb.."!")
    end,

    despedir = function(nomb)
        print("Adios "..nomb..".")
    end
    }

-- Podemos llamar a las funciones de la misma forma que antes.

conversaciones["saludar"]("Bob") -- Saludos Bob!

-- Tambien podemos usar la notacion de punto.

conversaciones.despedir("Pip") -- Adios Pip.
