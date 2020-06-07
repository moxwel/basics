<?php

include "../../include/db.php";

$check = $_POST['editing'];
$id = $_GET['id'];

// Si check es true, se aplican los cambios
// al database.
if ($check) {
    $nom  = $_POST['nom'];
    $nom2 = $_POST['nom2'];
    $nota = $_POST['nota'];

    $query = "UPDATE datos SET nom='$nom', nom2='$nom2', nota='$nota' WHERE id = $id";
    $res = mysqli_query($conn, $query);
    $err = mysqli_error($conn);

    // Si hay error, enviar mensaje a actions.php
    if (empty($res)) {
        $_SESSION['msg'] = "<h3><i class='mdi mdi-close-circle'></i> Error.</h3><br>SQL: $err.";
        header("Location: ../actions.php");
    }else{
        $_SESSION['msg'] = "<h3><i class='mdi mdi-check'></i> Exito.</h3>";
        header("Location: ../actions.php");
    }
}else{
    // Se revisa si existen datos en la Id dada
    $query = "SELECT * FROM datos WHERE id = $id";
    $res = mysqli_query($conn, $query);
    $fila = mysqli_fetch_array($res);

    // Si no hay datos, se marca como error; si
    // hay datos, se habilita un flag y se podra editar
    // en la pagina actions.php
    if (empty($fila)) {
        $_SESSION['msg'] = "<h3><i class='mdi mdi-close-circle'></i> Error.</h3><br>SQL: Ningun dato en la Id $id.";
        header("Location: ../actions.php");
    }else{
        $_SESSION['check'] = TRUE;
        $_SESSION['id'] = $id;
        header("Location: ../actions.php");
    }
}

?>