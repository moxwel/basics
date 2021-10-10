-- Utilizaremos esta tabla
CREATE TABLE empleados (
    nombre varchar2(30) NOT NULL,
    genero varchar2(1) DEFAULT 'N',
    anno_nacimiento number(4),
    anno_entrada number(4) NOT NULL,
    sueldo number(7) NOT NULL
);
-- Utilizando estos datos
INSERT INTO empleados VALUES ('Max', 'M', 2000, 2018, 1000);
INSERT INTO empleados VALUES ('Josh', 'M', 1998, 2015, 1000000);
INSERT INTO empleados VALUES ('Juan', 'M', 1999, 2015, 500000);
INSERT INTO empleados VALUES ('Fer', 'F', 2002, 2019, 100000);
INSERT INTO empleados VALUES ('Cata', 'F', 2000, 2018, 100000);
INSERT INTO empleados VALUES ('Eladmin', 'M', 1995, 2010, 4000000);
INSERT INTO empleados VALUES ('Pedrito', 'M', 1999, 2020, 50000);

-- Podemos filtrar datos utilizando SELECT
SELECT nombre FROM empleados
    WHERE sueldo >= 500000;
    
-- Tambien podemos añadir condiciones adicionales
SELECT nombre FROM empleados
    WHERE sueldo >= 500000 AND anno_entrada >= 2015;
    
-- Podemos mezclar orden y filtros
SELECT nombre,anno_entrada,sueldo FROM empleados
    WHERE anno_entrada >= 2015
    ORDER BY sueldo DESC;

-- Se puede usar AND, OR y NOT.





-- Tambien podemos usar BETWEEN
SELECT nombre, anno_nacimiento FROM empleados
    WHERE (anno_nacimiento >= 2000 AND anno_nacimiento <= 2005);
-- Para simplicar consultas de este estilo
SELECT nombre, anno_nacimiento FROM empleados
    WHERE anno_nacimiento BETWEEN 2000 AND 2005;
    
    
    
    
-- Podemos usar el operador IN
SELECT nombre, anno_entrada FROM empleados
    WHERE anno_entrada IN (2015, 2018);
-- Se seleccionan empleados unicamente que entraron en 2015 y 2018




-- Podemos usar el operador LIKE
-- Aqui es necesario el uso de 'wildcards', para buscar patrones.
-- Referencia: https://www.tutorialesprogramacionya.com/oracleya/temarios/descripcion.php?inicio=25&cod=186&punto=28
