-- Lua es un lenguaje debilmente tipificado, significa que no es necesario
-- mencionar que tipo de dato es una variable, el lenguaje lo reconoce de manera
-- implicita.

-- Podemos revisar el tipo de cualquier elemento usando la funcion 'type()'

print(type(343))     -- number
print(type(true))    -- boolean
print(type(nil))     -- nil
print(type("texto")) -- string
print(type(print))   -- function





-- Para crear variables, simplemente es 'identificador = valor'.

una_variable = "Un valor"

print(una_variable) -- Un valor





-- Podemos crear mas variables en una misma linea

var1, var2, var3 = "Max", "Bob", "Pip"

print(var3) -- Pip





-- Cualquier variable no definida tendra como valor 'nil' (que es null basicamente)

print(variable_noexistente) -- nil
