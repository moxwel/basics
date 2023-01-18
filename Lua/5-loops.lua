-- Se puede definir un bucle con 'while'

contador = 0
while (contador < 5) do
    print("Contador: "..contador)
    contador = contador + 1
end
-- Contador: 0
-- Contador: 1
-- Contador: 2
-- Contador: 3
-- Contador: 4





-- Lua tambien permite crear bloques 'repeat until'.
contador = 0
repeat
    print("Contador 2: "..contador)
    contador = contador + 1
until (contador > 5)
-- Contador 2: 0
-- Contador 2: 1
-- Contador 2: 2
-- Contador 2: 3
-- Contador 2: 4
-- Contador 2: 5

-- NOTA:
-- 'while do' va a repetir el bloque MIENTRAS la condicion sea VERDADERA

-- 'repeat until' va a repetir el bloque HASTA que la condicion sea VERDADERA
-- (en otras palabras: el bloque se va a repetir MIENTRAS la condicion sea falsa)




-- Tambien tenemos el bucle 'for'

-- for <inicializacion>, <valor maximo/minimo>, <incremento> do:
for i=1, 10, 1 do
    print("Valor de 'i': "..i)
end
-- Valor de 'i': 1
-- Valor de 'i': 2
-- Valor de 'i': 3
-- Valor de 'i': 4
-- Valor de 'i': 5
-- Valor de 'i': 6
-- Valor de 'i': 7
-- Valor de 'i': 8
-- Valor de 'i': 9
-- Valor de 'i': 10

-- A diferencia de C, en el 'for' no es necesario definir operaciones ni comparaciones en los lugares
-- del valor maximo y el incremento; esto es porque la logica se procesa internamente en el lenguaje.

-- El valor comienza desde el inicio, y termina cuando alzanca el valor maximo o minimo.





-- Podemos usar 'break' para interrumpir la ejecucion y salir del bloque.

numero = 0
while (true) do
    numero = numero + 1
    print(numero)

    if (numero == 5) then
        print("ESCAPANDO...")
        break
    end
end
