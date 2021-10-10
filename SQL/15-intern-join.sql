-- Las combinaciones son una de las operaciones fundamentales en SQL, combinar
-- dos tablas nos ayuda a poder organizar mejor la informacion, y con menos
-- redundancias.

-- Imaginemos tenemos estas dos tablas:
CREATE TABLE biblioteca (
    codigo number(5),
    libro varchar2(30),
    autor varchar2(30),
    codigo_editorial number(5),
    precio number(5),
    PRIMARY KEY (codigo)
);

CREATE TABLE editoriales (
    codigo number(5),
    nombre varchar2(30),
    direccion varchar2(30),
    PRIMARY KEY (codigo)
);


-- Con esta informacion
INSERT INTO biblioteca VALUES (100, 'Libro A', 'Autor 1', 111, 1000);
INSERT INTO biblioteca VALUES (200, 'Libro B', 'Autor 2', 222, 1000);
INSERT INTO biblioteca VALUES (300, 'Libro D', 'Autor 3', 333, 1000);
INSERT INTO biblioteca VALUES (400, 'Libro C', 'Autor 4', 111, 1000);
INSERT INTO biblioteca VALUES (500, 'Libro B', 'Autor 2', 333, 1000);
INSERT INTO biblioteca VALUES (600, 'Libro E', 'Autor 5', null, 1000);
INSERT INTO biblioteca VALUES (700, 'Libro F', 'Autor 1', 444, 1000);

INSERT INTO editoriales VALUES (111, 'Editorial 1', 'Direccion ED1');
INSERT INTO editoriales VALUES (222, 'Editorial 2', 'Direccion ED2');
INSERT INTO editoriales VALUES (333, 'Editorial 3', 'Direccion ED3');
INSERT INTO editoriales VALUES (666, 'Editorial 6', 'Direccion ED6');




-- Notemos que si hacemos un select a la biblioteca

SELECT * FROM biblioteca;

-- Tenemos el codigo de la editorial, pero no tenemos idea de quienes son
-- ni cual es su direccion. Pero en la tabla de editoriales tenemos informacion
-- asociada a esos codigos.

SELECT * FROM editoriales;

-- Podemos unir la informacion de ambas tablas para poder ver la relacion entre
-- ellas 2.



-- Sintaxis de combinacion interna (inner join / join):
-- SELECT <col1_T1> <col2_T1> ... FROM <Tabla1>
--     JOIN <Tabla2> ON
--         <Condiciones_de_combinado>
SELECT * FROM biblioteca
    JOIN editoriales ON
        biblioteca.codigo_editorial = editoriales.codigo;
        
-- Las condiciones de combinado especifican que informacion es el que se usa
-- para combinar ambas tablas. En este caso, ambas tablas se relacionan utilizando
-- la columna de "codigo_editorial" (de la tabla "biblioteca") con la columna
-- "codigo" (de la tabla "editoriales").



SELECT biblioteca.codigo, biblioteca.libro, editoriales.nombre FROM biblioteca
    JOIN editoriales ON
        biblioteca.codigo_editorial = editoriales.codigo;
        
-- Notese la forma en como se pueden referenciar columnas de otras tablas, utilizando
-- el operador '.'. Es necesario utilizarlo si es que las columnas de ambas
-- tablas tienen el mismo nombre (vease la columna "codigo" de las tablas
-- "biblioteca" y "editoriales").

-- Si el nombre de las tablas resulta ser muy largo, podemos utilizar un alias
-- para ellos.

SELECT b.codigo, b.libro, e.nombre FROM biblioteca b
    JOIN editoriales e ON
        b.codigo_editorial = e.codigo;
-- Aqui, la tabla "biblioteca" tiene como alias "b" y la tabla "editoriales" tiene
-- como tabla "e".




-- Mas aun, se pueden mezclar todos los conceptos como filtros y condiciones.
SELECT b.codigo, b.libro, e.nombre FROM biblioteca b
    JOIN editoriales e ON
        b.codigo_editorial = e.codigo
    ORDER BY e.nombre;
    
    
-- En este tipo de uniones, si un elemento no coincide con elementos de la otra tabla,
-- o posee 'null', entonces no se incluye.



