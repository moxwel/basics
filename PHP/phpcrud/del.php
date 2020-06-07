<?php

include "db_connect.php";

if (isset($_GET["id"])){

    $id = $_GET["id"];

    $query = "DELETE FROM tablatest WHERE id = $id";

    $res = mysqli_query($conn, $query);

    if ($res) {
        $_SESSION["msg"] = "<i class=\"mdi mdi-check\"></i> Eliminado con exito";
        $_SESSION["msg_type"] = "success";
        header("Location: index.php");
    }else{
        $err = mysqli_error($conn);
        $_SESSION["msg"] = "<i class=\"mdi mdi-alert-octagon\"></i> Fallo al borrar... $err";
        $_SESSION["msg_type"] = "danger";
        header("Location: index.php");
    }
}else{
    $_SESSION["msg"] = "<i class=\"mdi mdi-alert\"></i> Ningun dato recibido.<br>Utiliza el boton borrar para borrar datos.";
    $_SESSION["msg_type"] = "warning";
    header("Location: index.php");
}

?>