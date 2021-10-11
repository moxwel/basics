-- Un procedimiento es un objeto que almacena instrucciones. Permite poder
-- almacenar tareas repetitivas en un unico lugar.

-- Tambien permite a los usuarios poder realizar cambios en la base de datos, sin
-- necesariamente tener acceso a esta.

-- Los procedimientos pueden hacer referencia a tablas, vistas, funciones, y
-- otros procedimientos

-- Para crear un procedimiento, se tiene la siguiente sintaxis:
-- CREATE OR REPLACE PROCEDURE <nombre_procedimiento> AS
-- BEGIN
--    <instrucciones>;
-- END;
-- /

-- Por ejemplo, tengamos la tabla de la tienda anterior.
-- Podemos ir aumentando los precios por un cierto porcentaje:
SELECT
    nombre_producto,
    precio_producto,
    precio_producto+(precio_producto * 0.10)
FROM tienda;

-- Para modificarlos, debemos usar el comando UPDATE, podemos guardarlo dentro
-- de un procedimiento
CREATE OR REPLACE PROCEDURE aumentar_10_porciento AS
BEGIN
    UPDATE tienda SET precio_producto = precio_producto+(precio_producto * 0.10);
END;
/

-- Para ejecutarlo, hay que llamar al procedimiento, para eso, se utiliza la
-- clausula EXECUTE (o EXEC).
EXECUTE aumentar_10_porciento;
-- Podemos ejecutarlo tantas veces como queramos

-- Para eliminarlo, hacemos
-- DROP PROCEDURE <nombre_procedimiento>;
DROP PROCEDURE aumentar_10_porciento;


