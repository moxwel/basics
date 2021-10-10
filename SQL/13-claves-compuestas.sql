-- Suponiendo que se trabaja con la siguiente tabla

-- Un registro de estacionamientos, se quiere registrar la entrada de vehiculos.
-- Se tiene el numero de patente, el tipo (auto o moto), la hora que entra y sale.

-- No podemos considerar la patente del vehiculo como clave primaria, pues
-- es posible que ese mismo vehiculo vuelva a ingresar al estacionamiento algun dia.
-- Tampoco el tipo, hay muchos autos y motos que entran.
-- Tampoco la fecha de llegada, porque hay muchos autos que entran a la misma hora.

-- Aqui resulta util usar una clave compuesta.
CREATE TABLE registro_estacionamiento (
    patente number(4),
    tipo char(1),
    hora_llegada date,
    hora_salida date,
    PRIMARY KEY (patente, hora_llegada)
);
-- Notemos que al definir las claves primarias, utilizamos dos columnas.

INSERT INTO registro_estacionamiento VALUES (4820, 'a', '18-5-2020', '18-5-2020');
INSERT INTO registro_estacionamiento VALUES (4215, 'a', '19-5-2020', '20-5-2020');
INSERT INTO registro_estacionamiento VALUES (3433, 'm', '28-5-2020', '28-5-2020');
INSERT INTO registro_estacionamiento VALUES (2222, 'm', '18-5-2020', '19-5-2020');

INSERT INTO registro_estacionamiento VALUES (4820, 'a', '19-5-2020', '19-5-2020');
INSERT INTO registro_estacionamiento VALUES (2222, 'm', '19-5-2020', '10-5-2020');
-- Estos no tienen problema, porque a pesar de tener la misma patente, entraron
-- en fechas diferentes al de la primera vez. Eso causa que la clave compuesta
-- ya los diferencie.




