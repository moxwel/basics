-- CREAR TABLAS:
-- CREATE TABLE <nombre_tabla> (<nombre_col1> <tipo>, <nombre_col2> <tipo>, ...);
-- Crea una tabla con los campos (columnas) descritos. Cada campo se debe expresar con
-- su tipo correspondiente.

CREATE TABLE mis_clientes (
    nombre   varchar2(30),
    apellido varchar2(30),
    edad     number(3)
);

-- Los nombres de las tablas son unicos. Los nombres de los campos no pueden tener
-- espacios en blanco ni comenzar con un numero.

-- Referencia tipo de datos:
-- https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=0&cod=162&punto=4
-- https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=0&cod=173&punto=15
-- https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=0&cod=174&punto=16




-- VER ESTRUCTURA DE UNA TABLA:
-- DESCRIBE <nombre_tabla>;
-- Muestra por pantalla la estructura de una tabla. Muestra sus campos y sus
-- correspondientes tipos de datos admitidos, ademas de informacion adicional.

DESCRIBE mis_clientes;





-- BORRAR TABLAS:
-- DROP TABLE <nombre_tabla>;
-- Borra la tabla dada.

DROP TABLE mis_clientes;