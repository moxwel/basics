/*
Para iniciar sesion en Oracle Database, debes entrar a SQLPlus con usuario
'system' y la contrasena que se utilizo al momento de instarlo.

ATENCION: La contrasena debe contener al menos una letra, un numero y un caracter
especial ('_' por ejemplo). Debe contener entre 8 y 30 caracteres. No puede comenzar
con un numero.

La conexion se puede hacer con un administrador de bases de datos como Oracle SQL
Developer. Para la conexion, se utilizan las siguientes configuraciones:

Tipo de autenticacion: Por defecto
Nombre: <cualquiera>
Usuario: system
Contrasena: <contrasena del sistema>
Rol: Por defecto
Tipo de conexion: Basico
Nombre host: localhost
Puerto: 1521
SID: xe
*/





-- SELECCIONAR DATOS:
-- SELECT <columna1, columna2, ...> FROM <tabla>;
-- Selecciona todos los registros (filas) de los campos (columnas) dados (o todos los
-- campos si es '*') de la tabla mencionada y las muestra por pantalla.

SELECT * FROM all_tables;
-- 'all_tables' es una tabla especial que tiene Oracle Database que contiene
-- los nombres de todas las tablas de la base de datos. Con este comando,
-- observaremos todos los campos de esa tabla, con sus registros correspondientes.

-- Advertencia, es una tabla demasiado grande, no la ejecutes en sqlplus, se va a
-- demorar mucho
