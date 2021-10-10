-- Las secuencias son tablas con una columna almacenando un valor,
-- en el que cada vez que se consulta, los valores van incrementando.
-- Resultan ser muy utiles en claves primarias, para establecer identificadores
-- unicos.

-- Para crear una secuencia, se escribe:
-- CREATE SEQUENCE <nombre>
--     START WITH <valor_inicial>
--     INCREMENT BY <incremento>
--     MAXVALUE <valor_maximo>
--     MINVALUE <valor_minimo>
--     [CYCLE|NOCYCLE]




-- Para crear una secuencia basica:
CREATE SEQUENCE sec_basica;
-- Comenzara desde 1, hasta 999999999, avanzando 1, y no cicla.




-- La columna que se incrementa esta contenida en una tabla llamada "dual".
-- Podemos acceder a la secuencia utilizando un "SELECT".

-- Primero hay que inicializarla, haciendo que avance (nextval) por primera vez.
SELECT sec_basica.nextval FROM dual;
-- Si la ejecutamos mas veces, el valor aumenta.

-- Tambien podemos obtener el valor actual (currval)
SELECT sec_basica.currval FROM dual;



-- Para borrar una secuencia, se utiliza "DROP SEQUENCE"
DROP SEQUENCE sec_basica;





-- Como resulta util usarse con tablas, es recomendable mantener el nombre de las
-- secuencias con relacion a la tabla.
CREATE TABLE empleados (
    id_empleado number(5),
    nombre varchar2(30),
    PRIMARY KEY (id_empleado)
);

-- Crear secuencia
CREATE SEQUENCE sec_id_empleados
    START WITH 1000
    MAXVALUE 99999
    INCREMENT BY 7;
    
-- Inicializar secuencia
SELECT sec_id_empleados.nextval FROM dual;

-- Podemos ingresar datos utilizando "sec_id_empleados.nextval"
INSERT INTO empleados VALUES (sec_id_empleados.nextval, 'A');
INSERT INTO empleados VALUES (sec_id_empleados.nextval, 'C');
INSERT INTO empleados VALUES (sec_id_empleados.nextval, 'B');
INSERT INTO empleados VALUES (sec_id_empleados.nextval, 'A');
INSERT INTO empleados VALUES (sec_id_empleados.nextval, 'D');
INSERT INTO empleados VALUES (sec_id_empleados.nextval, 'E');
