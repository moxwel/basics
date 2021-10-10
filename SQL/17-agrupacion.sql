-- Si quisieramos contar la cantidad de libros que cada autor ha publicado, podemos
-- usar un COUNT(*) por cada autor.

SELECT count(*) FROM biblioteca
    WHERE autor='Autor 1';
SELECT count(*) FROM biblioteca
    WHERE autor='Autor 2';
SELECT count(*) FROM biblioteca
    WHERE autor='Autor 3';
    
-- Pero esto se realiza mas facil si usamos una agrupacion con GROUP BY

SELECT autor, count(*) FROM biblioteca
    GROUP BY autor;
-- Se forma una tabla con cada autor, y su cantidad de libros correspondientes.


-- La sintaxis general es la siguiente.
-- SELECT <campo1>, <campo2> ..., <funcion_de_grupo> FROM <tabla>
--    ORDER BY <campo1>, <campo2>;