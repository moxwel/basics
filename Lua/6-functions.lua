-- Podemos definir funciones:

function saludar(nombre)
    print("Buenos dias "..nombre.." :D")
end

saludar("Bob") -- Buenos dias Bob :D




-- Las funciones tambien pueden retornar valores:

function maximo(num1, num2)
    -- Declaremos 'res' como una variable local, asi no podrá ser usado fuera de la funcion
    -- y tampoco causará efectos efectos secundarios fuera de este.
    local res

    if (num1 >= num2) then
        res = num1
    else
        res = num2
    end

    return res
end

print(maximo(50,32)) -- 50
print(maximo(20,40)) -- 40

-- Cuando se retorna un valor, el programa sale de la funcion y deja de ejecutarse.

-- Tambien podemos usar un 'return' sin valor para interrumpir y salir de la funcion.


function mi_funcion(num)
    if (num == 1) then
        return "Uno"
    else
        return
    end
end

print(mi_funcion(1)) -- Uno
print(mi_funcion(0)) -- <nada>





-- Tambien podemos definir funciones de manera local. Esto tendra el mismo comportamiento que las
-- variables locales: solo podran ser accedidas dentro de un ambito.
do
    local function funcion_local()
        print("Esto es una funcion local")
    end

    funcion_local() -- Esto es una funcion local
end
-- 'funcion_local' no existe aqui
