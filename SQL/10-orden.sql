-- Utilizando la tabla anterior

SELECT * FROM biblioteca;

-- Tambien podemos ordenar las consultas, utilizando ORDER BY

-- ORDER BY <columna1> [asc|desc], <columna2> [asc|desc], ...;
SELECT * FROM biblioteca
    ORDER BY titulo;
    
-- Esto hara que la tabla resultante de la consulta este ordenada por titulo
-- del libro, por defecto, de manera ascendente. Aunque podemos especificar que
-- sea descendente.

SELECT * FROM biblioteca
    ORDER BY titulo DESC;
    
-- O utilizar el numero de columna en orden.
SELECT * FROM biblioteca
    ORDER BY 4;
-- Esto ordenara por precio de manera ascendente (de menor a mayor).

-- Tambien se puede especificar mas de una columna en orden.
SELECT * FROM biblioteca
    ORDER BY titulo ASC, precio DESC;