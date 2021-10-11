-- Para este ejemplo vamos a utilizar la siguiente tabla:
CREATE TABLE empleados (
    rut number(8),
    nombre varchar2(30) NOT NULL,
    apellido varchar2(30),
    genero varchar2(1),
    PRIMARY KEY (rut)
);

DESCRIBE empleados;
-- Notese la sentencia 'PRIMARY KEY (<campo>)', esto define el campo que se
-- convertira en clave primaria (PK) de la tabla.
-- Ese campo sera el identificador unico de cada registro, solo puede haber
-- una unica clave primaria por tabla, no puede ser nulo y tampoco podra repetirse
-- entre registros.
-- Al poner un campo como PK, automaticamente se restringe con NOT NULL.





-- Insertamos los siguientes registros:
INSERT INTO empleados VALUES (20748362, 'Pepito', 'Pagadoble', 'm');
INSERT INTO empleados VALUES (11783021, 'Juan', 'Perez', 'm');
INSERT INTO empleados VALUES (897, 'Lolo', 'Lala', null);
INSERT INTO empleados VALUES (2978401, 'Lara', 'Croft', 'f');
INSERT INTO empleados VALUES (1, 'EL ADMIN', null, null);

-- INSERT INTO empleados VALUES (1, 'Max', 'Sepu', 'm');
-- Esta sentencia causaria un error porque ya existe un registro con
-- RUT '1', y eso no es posible, porque es clave primaria, no puede
-- repetirse.





-- Las claves primarias tienen ciertas propiedades, pero de manera alternativa
-- podemos establecer otros campos como "unicos" tambien. Esto se logra con la
-- restriccion UNIQUE.
CREATE TABLE empleados (
    id_empleado number(8),
    rut number(8),
    nombre varchar2(30) NOT NULL,
    apellido varchar2(30),
    genero varchar2(1),
    PRIMARY KEY (id_empleado),
    UNIQUE (rut)
);
