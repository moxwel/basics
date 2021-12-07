-- Una vista es un objeto que almacena consultas.

-- Se puede crear una vista con una consulta especifica, que luego se puede
-- usar posteriormente.

-- Es util para poder proteger la base de datos y solo dejar "ciertas ventanas"
-- para que un usuario cualquiera pueda ver los datos, pero no modificarlos.

-- Para crear vistas, se sigue la siguiente sintaxis:
-- CREATE VIEW <nombre_vista> AS (<subconsulta>);

-- Para acceder a los datos de una vista, se utliza SELECT:
-- SELECT * FROM <nombre_vista>

-- Hagamos un ejemplo:
CREATE TABLE empleados (
    id_empleado number(4),
    rut number(4) UNIQUE NOT NULL,
    nombre varchar(30),
    apellido varchar(30),
    sueldo number(7),
    
    PRIMARY KEY (id_empleado)
);

INSERT INTO empleados VALUES (100, 1111, 'Max', 'Sepu', 100000);
INSERT INTO empleados VALUES (200, 2222, 'Fernan', 'Flo', 500000);
INSERT INTO empleados VALUES (300, 3333, 'Cristo', 'Rey', 1000000);
INSERT INTO empleados VALUES (400, 4444, 'Don', 'Fede', 450000);
INSERT INTO empleados VALUES (500, 5555, 'Goku', 'Drip', 6969420);
INSERT INTO empleados VALUES (600, 6666, 'Mark', 'Zucc', 1);
INSERT INTO empleados VALUES (700, 7777, 'El', 'Admin', 9999999);



-- Imaginemos que quisieramos que los empleados puedan ver quienes trabajan en
-- la empresa, pero obviamente queremos ocultar sus datos personales como el rut
-- y el sueldo. Como administradores de la base de datos, podemos crear
-- una vista para ellos.
CREATE OR REPLACE VIEW vista_empleados AS (
    SELECT id_empleado, nombre, apellido FROM empleados
);

-- Ahora los empleados podran consultar la vista
SELECT * FROM vista_empleados;


-- E incluso, tratar la vista como una tabla comun y corriente.
SELECT nombre, apellido FROM vista_empleados
    WHERE id_empleado = 300;
    
SELECT nombre, apellido FROM vista_empleados
    WHERE sueldo >= 100000;
-- Notese que esta consulta dara un error, pues "vista_empleados" no posee informacion
-- acerca del sueldo, esta oculto. Esta es la gracia de usar vistas.




-- Se pueden crear vistas de otras vistas.

-- Las vistas son consultas almacenadas en una unica unidad, si se actualiza la tabla
-- la vista tambien.

-- Si se elimina la tabla a la cual una vista hace referencia, la vista quedará inutil.




-- Para eliminar una vista, se utiliza la siguiente sintaxis:
-- DROP VIEW <nombre_vista>;
DROP VIEW vista_empleados;



