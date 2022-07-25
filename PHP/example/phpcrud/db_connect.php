<?php

session_start();

// Establecer conexion con db en MySQL.
$conn = mysqli_connect('localhost',
                       'root',
                       '',
                       'test');

if($conn){
    echo "conectado a base<br>";
    $query = "SELECT id, nom, apell, nota FROM tablatest LIMIT 1";

    if (mysqli_query($conn, $query)){
        echo "conectado a tabla<br>";
    }else {
        echo "error al conectar tabla<br>";
    }
}else{
    echo "error al conectar db<br>";
}

?>