<?php

include "../../include/db.php";

// Obtencion de datos desde POST
$nom  = $_POST['nom'];
$nom2 = $_POST['nom2'];
$nota = $_POST['nota'];

// Ingresar datos, o devolver error si falla
$query = "INSERT INTO datos(nom, nom2, nota) VALUES('$nom', '$nom2', '$nota')";
$res = mysqli_query($conn, $query);
$err = mysqli_error($conn);

// Si hay error, enviar mensaje a home.php
if (empty($res)) {
    $_SESSION['msg'] = "<h3><i class='mdi mdi-close-circle'></i> Error.</h3><br>SQL: $err";
    header("Location: ../home.php");
}else{
    $_SESSION['msg'] = "<h3><i class='mdi mdi-check'></i> Exito.</h3>";
    header("Location: ../home.php");
}

?>