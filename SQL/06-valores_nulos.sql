-- Para este ejemplo vamos a utilizar la siguiente tabla:
CREATE TABLE biblioteca (
    titulo    varchar2(30) NOT NULL,
    autor     varchar2(30) NOT NULL,
    editorial varchar2(30) NULL,
    precio    number(5)
);

DESCRIBE biblioteca;
-- Notese que se especifica NOT NULL en ciertos campos. En esta tabla, significa
-- que los campos 'titulo' y 'autor' NO pueden ser NULOS, es decir, necesariamente
-- deben tener un valor. En cambio el campo 'editorial' SI podria ser NULO.
-- De todas formas, si no se especifica nada, se tomara por defecto que si se puede
-- tomar valores nulos.

-- Nota: NULL no es lo mismo que 0, o un espacio en blanco ' '. Para un string,
-- null puede ser un string nulo ''.




-- Insertaremos los siguientes datos en la tabla:
INSERT INTO biblioteca VALUES ('El senor de los anillos', 'No se', 'Algo', 8999);
INSERT INTO biblioteca VALUES ('Jarri Poter', 'Jk No se cuanto', 'Meme', 42069);
INSERT INTO biblioteca VALUES ('El Quijote', 'Un viejo', null, 5);
INSERT INTO biblioteca VALUES ('Tutorial de C', 'USM', 'USM', null);
INSERT INTO biblioteca VALUES ('Luna de Pluton', 'Dross', 'Viejo Sabroso', null);

-- INSERT INTO biblioteca VALUES ('', 'No se', 'Algo', 9999);
-- Esta solicitud dara error porque el campo 'titulo' esta vacio, cosa que no puede
-- ser por como esta definido la tabla.





-- COMAPRAR CELDAS NULAS:
-- Para comparar si una celda no contiene nada (es NULL), se debe usar el comparador
-- 'IS NULL', o en caso contrario, 'IS NOT NULL'.

SELECT * FROM biblioteca
    WHERE precio IS NULL;
-- Seleccionar todos los registros de la tabla 'biblioteca' donde su precio sea nulo.

SELECT * FROM biblioteca
    WHERE precio IS NOT NULL;
-- Seleccionar todos los registros de la tabla 'biblioteca' donde su precio NO sea nulo.