<?php

include "db_connect.php";

if(isset($_POST["save"])){
    $nomb = $_POST["nomb"];
    $apell = $_POST["apell"];
    $nota = $_POST["nota"];

    $query = "INSERT INTO tablatest(nom, apell, nota) VALUES ('$nomb', '$apell', '$nota')";
    $result = mysqli_query($conn, $query);

    if ($result) {
        $_SESSION["msg"] = "<i class=\"mdi mdi-check\"></i> Creado con exito";
        $_SESSION["msg_type"] = "success";
        header("Location: index.php");
    }else{
        $err = mysqli_error($conn);
        $_SESSION["msg"] = "<i class=\"mdi mdi-alert-octagon\"></i> Fallo al crear... $err";
        $_SESSION["msg_type"] = "danger";
        header("Location: index.php");
    }

}else{
    $_SESSION["msg"] = "<i class=\"mdi mdi-alert\"></i> Ningun dato recibido.<br>Utiliza el boton guardar para guardar datos.";
    $_SESSION["msg_type"] = "warning";
    header("Location: index.php");
}

?>