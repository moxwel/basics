-- INGRESAR REGISTROS:
-- INSERT INTO <nombre_tabla> (<nombre_col1>, <nombre_col2> ...) VALUES (<val1>, <val2>, ...);
-- Inserta un registro nuevo (fila) en la tabla dada, con los respectivos datos
-- correspondientes a cada columna de la tabla.

-- Considerando que tenemos la tabla 'mis_clientes' con la consulta anterior...
INSERT INTO mis_clientes (nombre, apellido, edad)
    VALUES ('Juan', 'Pepito', 22);
-- Notemos que los strings se denotan con comillas simples.

-- El orden de los valores depende del orden en como estan puestas las columnas.
INSERT INTO mis_clientes (apellido, nombre, edad)
    VALUES ('Perez', 'Pedro', 52);

-- Si no se especifica el nombre de las columnas, se toma el orden por defecto
-- (es decir, el orden en como fueron creados).
INSERT INTO mis_clientes
    VALUES ('Max', 'Sepu', 21);





-- Ahora podemos ver cada registro de la tabla, utilizando SELECT, y con *, decimos
-- que queremos ver todos los campos.
SELECT * FROM mis_clientes;

-- Podemos elegir un unico campo para mostrar.
SELECT apellido FROM mis_clientes;

-- O mas de un campo.
SELECT apellido, edad FROM mis_clientes;




-- Agreguemos mas campos.
INSERT INTO mis_clientes
    VALUES ('Don', 'Fede', 999);

INSERT INTO mis_clientes
    VALUES ('Bromo', 'Mentos', 69);

INSERT INTO mis_clientes
    VALUES ('Bassed', 'Chad', 40);

INSERT INTO mis_clientes
    VALUES ('Charles', 'Marino', 40);



-- Podemos limitar la cantidad de filas que se quieren recuperar

-- Aqui solo se van a mostrar 5 filas
SELECT * FROM mis_clientes LIMIT 5;
