-- ELIMINAR TODOS LOS REGISTROS DE UNA TABLA:
-- DELETE FROM <nombre_tabla>;
-- Elimina todos los registros de la tabla dada.

DELETE FROM mis_clientes;





-- ELIMINADO CONDICIONAL:
-- DELETE FROM <nombre_tabla> WHERE <condicion>;
-- Para evitar eliminar todos los registros, podemos combinar el uso de WHERE.

DELETE FROM mis_clientes
    WHERE edad > 100;
-- Eliminar todos los clientes que tengan una edad mayor a 100.

DELETE FROM mis_clientes
    WHERE nombre = 'Juan';
-- Eliminar todos los clientes que tengan de nombre 'Juan'.





-- MODIFICAR REGISTROS:
-- UPDATE <nombre_tabla> SET <columna1>=<nuevo_valor>, <columna2>=<nuevo_valor>, ...;
-- Modifica los datos de un campo en todos los registros de una tabla dada.

UPDATE mis_clientes SET edad = '1';
-- Se cambia los datos de la columna 'edad' a 1 en todos los registros de la tabla.

UPDATE mis_clientes SET
    nombre   = 'SQL',
    apellido = 'Developer',
    edad     = 18;
-- Se cambia los datos de la columna 'nombre, 'apellido' y 'edad' en todos los registros de la tabla.





-- MODIFICACION CONDICIONAL:
-- UPDATE <nombre_tabla> SET <columna>=<nuevo_valor> WHERE <condicion>;
-- Para evitar cambiar los datos de todos los registros, podemos combinar el uso
-- de WHERE.

UPDATE mis_clientes SET edad = '50'
    WHERE nombre = 'Pedro';
-- Se cambia los datos de la columna 'edad' a 50 en todos los registros que tengan
-- como nombre 'Pedro'.





-- LIMPIAR TABLA:
-- TRUNCATE TABLE <nombre_tabla>
-- El comportamiento es parecido a DELETE FROM, elimina todos los registros de una
-- tabla, pero TRUNCATE libera la memoria del disco y es mas rapido.
-- En cambio DELETE solo marca los registros como 'borrado', pero son recuperables.

TRUNCATE TABLE mis_clientes;
-- TRUNCATE no posee condiciones.