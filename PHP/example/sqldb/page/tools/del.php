<?php

include "../../include/db.php";

// Obtencion de datos desde GET
$id  = $_GET['id'];

// Ingresar datos, o devolver error si falla
$query = "DELETE FROM datos WHERE id = $id";
$res = mysqli_query($conn, $query);

// Si hay error, enviar mensaje a actions.php
if (!mysqli_affected_rows($conn)) {
    $_SESSION['msg'] = "<h3><i class='mdi mdi-close-circle'></i> Error.</h3><br>SQL: Ninguna fila afectada.";
    header("Location: ../actions.php");
}else{
    $_SESSION['msg'] = "<h3><i class='mdi mdi-check'></i> Exito.</h3>";
    header("Location: ../actions.php");
}

?>