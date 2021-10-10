-- Para este ejemplo vamos a utilizar la siguiente tabla:
CREATE TABLE biblioteca (
    titulo    varchar2(30) NOT NULL,
    autor     varchar2(30) DEFAULT 'Desconocido' NOT NULL,
    editorial varchar2(30) DEFAULT 'Sin Editorial',
    precio    number(5) NOT NULL,
    cantidad  number(3) DEFAULT 0
);

DESCRIBE biblioteca;
-- Notese la sentencia DEFAULT, esto entrega un valor por defecto a la columna.
-- Si al ingresar datos, no se entrega informacion de la tabla, entonces se rellena
-- con el valor por defecto.
-- SIEMPRE debe ir antes de un NOT NULL.





-- Insertaremos los siguientes datos en la tabla:
INSERT INTO biblioteca VALUES ('El senor de los anillos', default, default, 8999, 432);
-- Al utilizar la palabra clave "default" en una insercion, se utilizaran los
-- valores por defecto.

INSERT INTO biblioteca (titulo, precio) VALUES ('Jarri Poter', 42069);
-- Al omitir columnas, se utilizan valores por defecto.