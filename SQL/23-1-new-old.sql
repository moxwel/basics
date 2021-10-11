-- Al usar triggers, se generan dos pseudo tablas temporales, "new" y "old",
-- donde se almacenaran los nuevos valores que seran insertados (en un insert),
-- o los datos antigos que hubieron (en un delete) respectivamente.

-- Para poder usar "new" y "old", debe ser un trigger a nivel de filas.

CREATE TABLE compras (
    num_compra number(5),
    producto varchar2(30),
    PRIMARY KEY (num_compra)
);

CREATE TABLE productos (
    nombre varchar2(30)
);

CREATE OR REPLACE TRIGGER registrar_producto
    BEFORE INSERT ON compras
    FOR EACH ROW
BEGIN
    INSERT INTO productos VALUES (:new.producto);
END;
/



INSERT INTO compras VALUES (1, 'Pan');
-- Se agrega "pan" a la tabla de compras, y tambien a la tabla "productos".