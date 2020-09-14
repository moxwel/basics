# Importar libreria de expresiones regulares incluido en Python
import re

# Se puede crear un PatternObject, que sirve para guardar algun patron en alguna
# variable, luego de esta forma se puede usar en alguna busqueda.
patron = re.compile(r"(a|b)*c")

# PatternObject acepta varios tipos de busqueda:
# Search busca y devuelve el primer calce que encuentre
result = patron.search("dabbcbaac")
# Despues de eso, se crea un MatchObject, que va a almacenar informacion del calce
# que se encuentre. Se pueden usar varias funciones para consultar la informacion
# de este MatchObject

print(result) # <re.Match object; span=(1, 5), match='abbc'>

# Con .group() se puede obtener el calce completo de un patron.
print(result.group()) # abbc

# Con .span() se puede ver el intervalo [inicio, final[ del string donde el patron calza
print(result.span()) # (1, 5)

# Fullmatch solo retorna cuando hay calce completo.
result2 = patron.fullmatch("abbacab")
result3 = patron.fullmatch("abababac")

print(result2) # None
print(result3) # <re.Match object; span=(0, 8), match='abababac'>

# Se puede poner en parentesis varios patrones para dividirlos en grupos
grupos = re.compile(r"(1)(22)(333)")
result4 = grupos.search("122333")

print(result4.group())  # 122333
print(result4.group(1)) # 1
print(result4.group(2)) # 22
print(result4.group(3)) # 333
print(result4.groups()) # ('1', '22', '333')

# Compilar una expresion regular sirve en casos en donde el mismo patron
# debe aplicarse varias veces. Esta es una forma alternativa de buscar en un
# string.
result5 = re.search(r"a*bc+", "aaaaabcccde")
print(result5.group()) #aaaaabccc

# Cuando se intenta buscar un grupo que se repite varias veces, solo se va
# a guardar el ultimo calce que haya habido.
result6 = re.search(r"(hola|mundo|soy|python| )*", "hola soy python mundo")

# Segun este patron, todo el texto calza con el patron en general
print(result6.group()) # hola soy python mundo

# Pero el grupo que existe "(hola|mundo|soy|python| )" puede repetirse 0 o mas veces,
# en ese caso, ese grupo por si solo, va a guardar el ultimo calce que encuentre.
print(result6.groups()) # mundo

# Se pueden nombrar los grupos para organizar mejor la expresion regular.
# Se debe escribir ?P<nombre> al inicio de cada grupo
grupos2 = re.compile(r"(?P<completo>(?P<repeticion>a|b|c|d)*(?P<final>fin))")
result7 = grupos2.search("abcddabbfin")

# Se puede usar .groupdict() para mostrar los grupos como diccionarios, mostrandolos
# con sus respectivos nombres
print(result7.groupdict())
print(result7.group("completo"))   # abcddabbfin
print(result7.group("repeticion")) # b
print(result7.group("final"))      # fin

# Para mas informacion y pruebas, ir a esta pagina: https://regex101.com/
