-- APLICAR CONDICIONES A UNA CONSULTA SELECT:
-- SELECT <columna1, columna2, ...> FROM <tabla> WHERE <condicion>;
-- La sentencia WHERE es donde aplicamos una condicion (como una especie de filtro)
-- para los registros que queremos recuperar de la sentencia SELECT.

SELECT nombre FROM mis_clientes
    WHERE edad < 40;
-- Selecciona la columna nombre, de todos los clientes que tienen menos de 40 annos.
    
SELECT nombre FROM mis_clientes
    WHERE edad > 40;
-- Selecciona la columna nombre, de todos los clientes que tienen mas de 40 annos.

SELECT * FROM mis_clientes
    WHERE nombre = 'Juan';
-- Selecciona todas las columnas, de todos los clientes que tienen 'Juan' como nombre.

-- Referencia operadores relacionales:
-- https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=0&cod=165&punto=7