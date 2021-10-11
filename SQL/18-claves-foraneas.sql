-- Vimos que una clave primaria se refiere a una columna de la tabla que sirve
-- para poder crear identificadores. Es unico para cada elemento de la tabla.

-- Tambien vimos que se podia usar JOIN para poder unir los datos de dos tablas
-- segun alguna regla de combinacion.

-- Las claves foraneas son columnas en la tabla, donde sus datos hacen referencia
-- a la clave primaria de la misma u otra tabla. Creando asi una relacion entre los
-- datos (como lo hacia JOIN).

-- Al crear la tabla, se puede definir una clave foranea de la siguiente manera:
-- FOREIGN KEY (<columna1T1>, <columna2T1>, ...)
--     REFERENCES <tabla2> (<columna1T2>, <columna2T2>, ...)

-- Con esto, decimos que las columnas de la tabla 1 (T1) son claves foraneas, que hacen
-- referencia a las claves primarias dadas de la tabla 2 (T2).

-- Las claves foraneas deben referenciar claves primarias o campos con la restruccion
-- UNIQUE, ademas, deben coincidir en cantidad y tipo de datos.

-- Si no se indica lo contrario, las claves foraneas pueden contener a "null".





-- Hagamos el ejemplo con la tabla de biblioteca y editoriales:
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
);

-- Notese el orden con como se crean las tablas. Esto significa, que la tabla
-- "biblioteca" no puede existir si es que la tabla "editoriales" no existia antes.

-- Tambien hay que tener en cuenta la dependencia que existe ahora con las tablas:
-- libros no pueden poseer un codigo de editorial que no esté pesente antes en la
-- tabla de editoriales.

INSERT INTO biblioteca VALUES (100, 'Libro1', 'Autor1', 111, 9999);
-- Hacer esto primero dará un error, pues, se intenta isnertar un libro con codigo
-- de editorial '111', pero en la tabla editoriales, no existe.

INSERT INTO editoriales VALUES (111, 'Editorial1', 'Direccion1');
-- Ahora existe la editorial con clave 111, ahora podemos insertar el libro.

INSERT INTO biblioteca VALUES (100, 'Libro1', 'Autor1', 111, 9999);




-- Por integridad de datos, no se puede eliminar una tabla que es referenciada
-- por otra tabla con alguna clave foranea.

DROP TABLE editoriales;
-- No podemos borrar la tabla "editoriales" porque es referenciada por la tabla
-- "biblioteca". Primero hay que borrar la tabla biblioteca.
DROP TABLE biblioteca;





-- De manera alternativa, las claves foraneas tambien pueden hacer referencia
-- a campos de la misma tabla. Por ejemplo:
CREATE TABLE afiliados (
    rut number(4),
    nombre varchar2(30),
    agregado_por number(4),
    
    PRIMARY KEY (rut),
    FOREIGN KEY (agregado_por) REFERENCES afiliados (rut)
);

-- Notemos como el campo "agregado_por" hace referencia a un "rut" que esta dentro
-- de la misma tabla. Si quisieramos agregar a alguien que no ha sido agregado por
-- nadie, podemos utilizar 'null'.

INSERT INTO afiliados VALUES (1111, 'Persona1', null);
INSERT INTO afiliados VALUES (2222, 'Persona2', 1111);
INSERT INTO afiliados VALUES (3333, 'Persona3', 1111);
INSERT INTO afiliados VALUES (4444, 'Persona4', null);
INSERT INTO afiliados VALUES (5555, 'Persona5', 3333);
INSERT INTO afiliados VALUES (6666, 'Persona6', 4444);

INSERT INTO afiliados VALUES (7777, 'Persona6', 8888);
-- Esta consulta dara error, porque no existe ninguna persona con rut 8888 registrado
-- aun en la base de datos.





-- Utilizando JOIN, podemos mostrar quien fue agregado por quien

SELECT a.rut, a.nombre, b.nombre as "AGREGADO_POR" FROM afiliados a
    LEFT JOIN afiliados b ON
        a.agregado_por = b.rut;


