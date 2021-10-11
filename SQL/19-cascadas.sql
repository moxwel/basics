-- Sabemos que una clave foranea relaciona datos entre tablas (o entre una misma
-- tabla). Pero esto crea una fuerza de dependencia.

-- Un registro no puede eliminarse si es que esta siendo referenciado por otro registro
-- mediante una clave foranea.

-- Una tabla tampoco puede eliminarse si es que hay otra tabla que esta referenciando
-- a esta.

-- Esto ocurre porque cuando creamos una clave foranea, la accion en la eliminacion
-- no esta declarada.

-- Podemos decir "que ocurre con los registros dependientes si es que eliminamos el
-- registro al que hacen referencia". Esto se logra con la sintaxis:
-- FOREIGN KEY (<columna1T1>, <columna2T1>, ...)
--     REFERENCES <tabla2> (<columna1T2>, <columna2T2>, ...)
--     ON DELETE <opcion>;

-- Tenemos 3 opciones:
-- "no action": por defecto, no hace nada. Si se elimina el registro, se lanza error.
-- "cascade": si se elimina el registro, todos los registros que dependian de este se eliminaran tambien.
-- "set null": si se elimina el regsitro, todos los registros que dependian de este se cambiaran a null.


-- Probemos con estos datos
CREATE TABLE editoriales (
    codigo number(5),
    nombre varchar2(30),
    direccion varchar2(30),
    PRIMARY KEY (codigo)
);

CREATE TABLE biblioteca (
    codigo number(5),
    libro varchar2(30),
    autor varchar2(30),
    codigo_editorial number(5),
    precio number(5),
    PRIMARY KEY (codigo),
    FOREIGN KEY (codigo_editorial)
        REFERENCES editoriales (codigo)
        ON DELETE CASCADE
);

-- Con ON DELETE CASCADE, si eliminamos una editorial... todos los libros en la
-- biblioteca que pertenezcan a esa editorial, van a eliminarse tambien.

INSERT INTO editoriales VALUES (111, 'Editorial 1', 'Direccion ED1');
INSERT INTO editoriales VALUES (222, 'Editorial 2', 'Direccion ED2');
INSERT INTO editoriales VALUES (333, 'Editorial 3', 'Direccion ED3');
INSERT INTO editoriales VALUES (666, 'Editorial 6', 'Direccion ED6');

INSERT INTO biblioteca VALUES (100, 'Libro A', 'Autor 1', 111, 1000);
INSERT INTO biblioteca VALUES (200, 'Libro B', 'Autor 2', 222, 1000);
INSERT INTO biblioteca VALUES (300, 'Libro D', 'Autor 3', 333, 1000);
INSERT INTO biblioteca VALUES (400, 'Libro C', 'Autor 4', 111, 1000);
INSERT INTO biblioteca VALUES (500, 'Libro B', 'Autor 2', 333, 1000);
INSERT INTO biblioteca VALUES (600, 'Libro E', 'Autor 5', null, 1000);
INSERT INTO biblioteca VALUES (700, 'Libro F', 'Autor 1', 666, 1000);



-- Podemos ver los libros en la biblioteca
SELECT * FROM biblioteca;

-- Eliminamos la editorial con codigo '333'
DELETE FROM editoriales
    WHERE codigo = 333;

-- Todos los libros con editorial '333', fueron eliminados.
SELECT * FROM biblioteca;




