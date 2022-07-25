<?php

// Para permitir variables de sesion
session_start();

// Crear conexion
$conn = mysqli_connect('localhost', 'root', '');

// Si no hay conexion al servidor, mostrar mensaje de error
if (empty($conn)){
    echo "<h1><i class='mdi mdi-database mdi-dark mdi-inactive'></i><i class='mdi mdi-table mdi-dark mdi-inactive'></i> ERROR: Error de conexion al servidor.</h1><hr>";
}else{
    // Probar conexion a database "txtdb"
    $res = mysqli_select_db($conn, 'txtdb');
    $err = mysqli_error($conn);

    // Probar existencia de tabla "datos"
    $query = "SELECT id, nom, nom2, nota FROM datos LIMIT 1";
    $res2 = mysqli_query($conn, $query);
    $err2 = mysqli_error($conn);

    // Mostrar errores si no existe database, o si no existe tabla
    if (empty($res)) {
        echo "<h1><i class='mdi mdi-database-remove'></i><i class='mdi mdi-table mdi-dark mdi-inactive'></i> ERROR: Error de conexion a database.</h1><br>SQL: $err<hr>";
    }else{
        if (empty($res2)) {
            echo "<h1><i class='mdi mdi-database'></i><i class='mdi mdi-table-remove'></i> ERROR: No hay tabla.</h1><br>SQL: $err2<hr>";
        }else{
            echo "<h1><i class='mdi mdi-check'></i> Conectado.</h1><hr>";
        }
    }
}

?>