-- Los disparadores (o triggers) son bloques de codigo que se ejecutan automaticamente
-- cuando un cierto evento ocurre, como alguna insecion, actualizacion, borrado, etc.

-- Son utiles para conservar integridad entre los datos, y no para realizar consultas.

-- Los triggers no pueden ser llamados directamente, no reciben ni retornan parametros,
-- y se ejecutan automaticamente.

-- Los triggers se asocian a tablas.

-- La sintaxis es la siguiente:
-- CREATE OR REPLACE TRIGGER <nombre_trigger>
--     <momento> <evento>
-- [OF <campo1> <campo2> ...]    (solo si el evento es update)
-- ON <tabla>
-- <nivel_de_accion>
-- [WHEN (<condicion>)]            (opcional)
-- BEGIN
--     <instrucciones>
-- END;
-- /

-- Momento: puede ser "before" (antes) o "after" (despues) del evento ocurrido.
--          Define el momento cuando se va a ejecutar el disparador.

-- Evento: puede ser "insert", "update" o "delete".
--         Define que accion es el que va a causar que el disparador se ejecute.

-- Nivel de accion: puede ser "statement" (a nivel de sentencia) o "for each row" (a nivel de fila).
--                  Define cuantas veces se ejecuta. Si es a nivel de fila, el trigger
--                  se ejecuta cada vez que un registro es modificado.
--                  Si es a nivel de sentencia, solo se ejecuta una sola vez.
--                  Por defecto es "statement".





-- Por ejemplo:
CREATE TABLE tabla1 (
    elemento varchar2(30)
);

CREATE TABLE control (
    usuario varchar2(30),
    fecha_modificacion date
);

CREATE OR REPLACE TRIGGER registrar_cambio
    BEFORE INSERT ON tabla1
BEGIN
    INSERT INTO control VALUES (user,sysdate);
END;
/

-- Si añadimos un elemento a la tabla 1, el trigger se va a ejecutar, y va a añadir
-- un elemento nuevo en la tabla control.
SELECT * FROM tabla1;
SELECT * FROM control;

INSERT INTO tabla1 VALUES ('Elemento 1');
INSERT INTO tabla1 VALUES ('Elemento 2');
INSERT INTO tabla1 VALUES ('Elemento 3');

SELECT * FROM tabla1;
SELECT * FROM control;
-- Notemos que por cada insercion, se añadio un nuevo elemento en la tabla "control"
-- Si hacemos un cambio que afecte a mas de una fila, aun asi se registrara solo 1
-- elemento en la tabla "control"

-- Usemos la tabla empleados de la seccion 21
INSERT INTO tabla1 (SELECT nombre FROM empleados WHERE sueldo <=500000);
-- Se añadiran 4 filas, pero solo se agrega una fila en la tabla "control.
SELECT * FROM control;




-- Sin embargo, si añadimos "FOR EACH ROW", el trigger se va a ejecutar por cada
-- fila
CREATE OR REPLACE TRIGGER registrar_cambio
    BEFORE INSERT ON tabla1
    FOR EACH ROW
BEGIN
    INSERT INTO control VALUES (user,sysdate);
END;
/

INSERT INTO tabla1 (SELECT nombre FROM empleados WHERE sueldo <=500000);
SELECT * FROM control;





-- Para eliminar un trigger, se debe usar DROP TRIGGER
DROP TRIGGER registrar_cambio;
DROP TRIGGER registrar_cambio_filas;
