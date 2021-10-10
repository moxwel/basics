-- Para este ejemplo vamos a utilizar la siguiente tabla:
CREATE TABLE biblioteca (
    titulo    varchar2(30) NOT NULL,
    autor     varchar2(30) NOT NULL,
    editorial varchar2(30) NULL,
    precio    number(5)
);
-- Con los siguientes datos
INSERT INTO biblioteca VALUES ('El senor de los anillos', 'No se', 'Algo', 8999);
INSERT INTO biblioteca VALUES ('Jarri Poter', 'Jk No se cuanto', 'Meme', 42069);
INSERT INTO biblioteca VALUES ('El Quijote', 'Un viejo', null, 5);
INSERT INTO biblioteca VALUES ('Tutorial de C', 'USM', 'USM', 563);
INSERT INTO biblioteca VALUES ('Luna de Pluton', 'Dross', 'Viejo Sabroso', 432);





-- Podemos usar SELECT para poder mostrar por pantalla datos
SELECT titulo,autor,precio FROM biblioteca;

-- Esto genera una especie de "tabla de vista", podemos añadir mas
-- columnas con una operacion, por ejemplo:
SELECT titulo||' $'||precio FROM biblioteca;
-- Donde || es una operacion de concatenacion de strings.

SELECT titulo, precio, precio*0.9 FROM biblioteca;
-- Podemos ver una tercera columna, donde podriamos ver los libros con
-- un 90% de descuento.

UPDATE biblioteca SET
    precio = precio - (precio*0.1);
-- Finalmente, podemos aplicar el descuento en todos los libros de la biblioteca.





-- Como podemos ver, vemos que el titulo de las columnas de select son algo
-- raros. Podemos cambiarselo de tal forma que el select se pueda ver mejor.
SELECT
    titulo,
    autor,
    precio,
    precio*0.1 AS "Precio con 90% descuento"
FROM biblioteca;
-- La palabra clave AS sirve para poner un "alias" a una columna. Esto mejora la
-- visibilidad de las consultas.




-- Referencia de funciones:
-- https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=0&cod=179&punto=21
-- https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=0&cod=180&punto=22
-- https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=0&cod=181&punto=23
