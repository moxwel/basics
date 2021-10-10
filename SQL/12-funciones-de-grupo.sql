--Considerando la siguiente tabla
CREATE TABLE productos (
    id_producto number(4),
    nombre varchar(30),
    cantidad number(5),
    precio number(5),
    PRIMARY KEY (id_producto)
);
-- Con los siguientes datos
INSERT INTO productos VALUES (1432, 'Manzana', 50, 100);
INSERT INTO productos VALUES (6752, 'Peras', 20, 100);
INSERT INTO productos VALUES (3754, 'Galletas', 100, 300);
INSERT INTO productos VALUES (8635, 'Fideos', 100, 500);
INSERT INTO productos VALUES (7956, 'Lentejas', 50, 100);
INSERT INTO productos VALUES (9756, 'Brocoli', 1, 300);
INSERT INTO productos VALUES (5675, 'Hamburguesa', 400, 1000);
INSERT INTO productos VALUES (3251, 'Bebida', 300, 600);
INSERT INTO productos VALUES (8468, 'Helados', 300, 400);
INSERT INTO productos VALUES (5342, 'Papel', null, 500);
INSERT INTO productos VALUES (8673, 'Queso', null, 200);





-- Existen funciones que nos permiten contar elementos.
-- Para contar LA CANTIDAD TOTAL DE REGISTROS DE UNA TABLA (Incluyendo los
-- valores nulos), se realiza de la siguiente manera:
SELECT COUNT(*) FROM productos;

-- Podemos combinarlo con otros filtros:
SELECT COUNT(*) FROM productos
    WHERE precio <= 300;
-- Cantidad de productos que tienen un precio menor o igual a 300.

-- Poner el nombre de una columna dentro, contara los elementos que no posean
-- null en la columna.
SELECT COUNT(cantidad) FROM productos;
-- Cantidad de productos que si poseen una cantidad registrada.



-- Tambien podemos sumar los elementos de una columna
SELECT
    SUM(precio) as "Precio total de productos",
    SUM(cantidad) as "Stock total",
    SUM(precio*cantidad) as "Precio por cantidad total de productos"
FROM productos;


-- Referencia: https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=25&cod=188&punto=30

