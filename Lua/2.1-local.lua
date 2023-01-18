-- Una variable global es una variable que puede ser accesada desde todos los ambitos
-- como pueden ser un bloque if, while, una funcion, etc.

-- Si a la variable no se le antepone nada, quedará como global.

mi_variable = 32 -- Creamos variable global

-- Algun bloque (puede ser un if, while, funcion, etc)
do
    print(mi_variable) -- 32

    mi_variable = 50   -- Modificamos el valor de variable global

    print(mi_variable) -- 50
end

print(mi_variable)     -- 50 (El valor sigue modificado)





-- Una variable local es una variable que solo puede ser accesada dentro del mismo
-- ambito en donde fue declarada.

do
    local mi_variable = "Soy una variable local" -- Creamos variable local

    otra_variable = "Soy global" -- Creamos variable global

    print(mi_variable) -- Soy una variable local
    -- Notese como de esta manera "ocultamos" la variable global con la variable local.

    mi_variable = "Estoy modificado localmente" -- Modificamos variable local (global sigue intacta)

    print(mi_variable) -- Estoy modificado localmente
end

print(mi_variable)  -- 50 (volvimos a la variable global)

print(otra_variable) -- Soy global
