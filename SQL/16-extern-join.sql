-- De la misma manera en como una combinacion interna excluye las combinaciones
-- que no tienen correspondencia, tambien podemos incluirlas.

-- Esto se le llama extern join, y podemos elegir "de que tabla" se incluyen los
-- datos que no calzan.

-- Por ejemplo, usando la tabla anterior...
SELECT * FROM biblioteca;

SELECT b.codigo, b.libro, e.nombre FROM biblioteca b
    JOIN editoriales e ON
        b.codigo_editorial = e.codigo;
        
-- El libro que no tiene editorial, ni el que posee editorial 555 aparecen
-- en la combinacion.

-- En este caso, nuestra tabla de la "izquierda" seria la tabla "biblioteca",
-- y la tabla de la "derecha" seria "editoriales.





-- Un LEFT JOIN muestra lo mismo que un JOIN, pero tambien se incluyen aquellas filas
-- de la tabla de la izquierda que no tienen correspondencia con los datos
-- de la de la derecha.

SELECT b.codigo, b.libro, e.nombre FROM biblioteca b
    LEFT JOIN editoriales e ON
        b.codigo_editorial = e.codigo;

SELECT nombre, b.libro from editoriales e
    LEFT JOIN biblioteca b ON
        e.codigo=b.codigo_editorial;
        
-- Podemos combinar filtros para poder ver cuales registros efectivamente
-- no tienen relacion con la otra tabla.

SELECT b.codigo, b.libro, e.nombre FROM biblioteca b
    LEFT JOIN editoriales e ON
        b.codigo_editorial = e.codigo
    WHERE e.nombre is null;






-- De la misma manera, existe el RIGHT JOIN, que hace lo mismo, pero esta
-- vez se incluyen aquellas filas de la tabla de la derecha que no tienen
-- correspondencia con los datos de la izquierda.

SELECT b.codigo, b.libro, e.nombre FROM biblioteca b
    RIGHT JOIN editoriales e ON
        b.codigo_editorial = e.codigo;
        
        
        
        
-- Viendo la diferencia entre LEFT JOIN y RIGHT JOIN, existe tambien FULL JOIN,
-- que une ambos comportamientos.

SELECT b.codigo, b.libro, e.nombre FROM biblioteca b
    FULL JOIN editoriales e ON
        b.codigo_editorial = e.codigo;