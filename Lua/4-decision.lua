-- La sintaxis de los bloques 'if' es:

condicion = true
if (condicion == true) then
    print("Se ejecuta el bloque.") -- Se ejecuta
end



-- Para establecer un bloque 'else'

if (false) then
    print("No se ejecuta el bloque.")
else
    print("Se imprime el 'else'.") -- Se ejecuta
end



-- Para establecer un bloque 'else if'

numero = 3
if (numero == 1) then
    print("No se ejecuta, continua con la siguiente comprobacion...")
elseif (numero == 2) then
    print("No se ejecuta, continua con la siguiente comprobacion...")
elseif (numero == 3) then
    print("Se imprime este bloque.") -- Se ejecuta
end
