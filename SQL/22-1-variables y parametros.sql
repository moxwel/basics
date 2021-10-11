-- Los procedimientos tambien puden recibir parametros y guardar variables.
-- La sintaxis es:

-- CREATE OR REPLACE PROCEDURE
--     <nombre_procedimiento> (<nombre_param> IN <tipo_de_dato>)
-- AS
--     <nombre_variable1> <tipo_de_dato>;
--     <nombre_variable2> <tipo_de_dato>;
--     ...
-- BEGIN
--    <instrucciones>;
-- END;
-- /

CREATE OR REPLACE PROCEDURE aumentar_precio (porcentaje IN number) AS
BEGIN
    UPDATE tienda SET precio_producto = precio_producto + (precio_producto * (porcentaje/100));
END;
/
-- Este procedimiento hace lo mismo que el anterior, pero es para un caso
-- aun mas general. Recibe el porcentaje con el cual queremos aumentar
-- el precio.

-- Para ejecutarlo, debemos llamarlo con sus parametros:
EXEC aumentar_precio(10); -- Aumentar en 10%
EXEC aumentar_precio(50); -- Aumentar en 50%
EXEC aumentar_precio(0);  -- No aumentar

-- Un parametro se le puede definir un valor por defecto, de esta manera,
-- si al llamar al procedimiento no se entrega tales parametros, se toma el valor
-- por defecto.




-- Un ejemplo con variables.
CREATE TABLE libros (
    titulo    varchar2(40),
    autor     varchar2(30),
    editorial varchar2(20),
    precio    number(5, 2)
);
 
CREATE TABLE tabla1 ( 
    titulo varchar2(40),
    precio number(6,2)
);

INSERT INTO libros VALUES ('Uno','Richard Bach','Planeta',15);
INSERT INTO libros VALUES ('Ilusiones','Richard Bach','Planeta',12);
INSERT INTO libros VALUES ('El aleph','Borges','Emece',25);
INSERT INTO libros VALUES ('Aprenda PHP','Mario Molina','Nuevo siglo',50);
INSERT INTO libros VALUES ('Matematica estas ahi','Paenza','Nuevo siglo',18);
INSERT INTO libros VALUES ('Puente al infinito','Bach Richard','Sudamericana',14);
INSERT INTO libros VALUES ('Antología','J. L. Borges','Paidos',24);
INSERT INTO libros VALUES ('Java en 10 minutos','Mario Molina','Siglo XXI',45);
INSERT INTO libros VALUES ('Cervantes y el quijote','Borges- Casares','Planeta',34);

CREATE OR REPLACE PROCEDURE
    obtener_autor_libro (param_titulo_libro IN varchar2)
AS
    variable_autor varchar2(20);
BEGIN
    SELECT autor INTO variable_autor FROM libros
        WHERE titulo=param_titulo_libro;
        
    DELETE tabla1;
  
    INSERT INTO tabla1
        SELECT titulo, precio FROM libros
            WHERE autor=variable_autor;
END;
/
-- Lo que hace este procedimiento es recibir el titulo de un libro, y guardar en
-- "tabla1" todos los libros del autor del libro dado.
 
EXEC obtener_autor_libro ('Uno');

-- Notese la palabra clave INTO, esto guarda el valor de la columna "autor" que
-- se obtiene con ese SELECT, y la guarda en "variable_autor". Vea el resultado.
SELECT autor FROM libros WHERE titulo='Uno';



