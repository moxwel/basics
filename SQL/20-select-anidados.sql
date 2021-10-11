-- Las subconsultas son consultas SELECT dentro de otra consulta SELECT, INSERT,
-- UPDATE, DELETE, u otra subconsulta.

-- Se utilizan generalmente cuando una consulta es muy compleja, o cuando una
-- consulta necesita usar los datos de otra consulta.

-- Sin embargo, utilizar JOIN tiende a ser mas eficiente.

-- Generalmente se utiliza con la clausula WHERE.

-- Una subconsulta puede retornar: un valor, una lista de valores (una columna),
-- o un conjunto de registros de varios campos (una tabla).

-- Dependiendo del tipo de retorno que la subconsulta realiza, se pueden realizar
-- diferentes acciones.

-- Alguna sintaxis generales:
-- SELECT <campos> FROM <tabla> WHERE <campo> <operador> (<subconsulta>);
-- SELECT <campo> <operador> (<subconsulta>) FROM <tabla>;

-- Por ejemplo, utilizando esta tabla:
CREATE TABLE tienda (
    id_producto number(4),
    nombre_producto varchar2(30),
    precio_producto number(30),
    
    PRIMARY KEY (id_producto)
);

INSERT INTO tienda VALUES (1000, 'Pan', 100);
INSERT INTO tienda VALUES (1001, 'Te', 50);
INSERT INTO tienda VALUES (1002, 'Galletas', 500);
INSERT INTO tienda VALUES (1004, 'Frutas', 300);
INSERT INTO tienda VALUES (1006, 'Hamburguesa', 1000);



-- Podemos ver la tabla
SELECT * FROM tienda;

-- Podemos obtyener cual es el mayor precio
SELECT max(precio_producto) FROM tienda;





-- Tambien podemos ver la diferencia de precio de cada producto con respecto
-- al que tiene mas precio. Utilizando la consulta anterior...
SELECT
    id_producto,
    nombre_producto,
    precio_producto - (SELECT max(precio_producto) FROM tienda) as "Diferencia"
FROM tienda;

-- O conocer cual es el producto mas caro, utilizando la consulta anterior.

SELECT id_producto, nombre_producto FROM tienda
    WHERE precio_producto = (SELECT max(precio_producto) FROM tienda);






