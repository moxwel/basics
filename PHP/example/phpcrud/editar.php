<?php

include "db_connect.php";

if (isset($_GET["id"])){
    $id = $_GET["id"];
    $query = "SELECT * FROM tablatest WHERE id = $id";
    $res = mysqli_query($conn, $query);

    while($fila = mysqli_fetch_array($res)){
        $id = $fila['id'];
        $nomb = $fila['nom'];
        $apell = $fila['apell'];
        $nota = $fila['nota'];
    }
}else{
    $_SESSION["msg"] = "<i class=\"mdi mdi-alert\"></i> Ningun dato recibido.<br>Utiliza el boton editar para editar datos.";
    $_SESSION["msg_type"] = "warning";
    header("Location: index.php");
}

if(isset($_POST["edit"])){
    $nomb = $_POST['nomb'];
    $apell = $_POST['apell'];
    $nota = $_POST['nota'];
    $query = "UPDATE tablatest SET nom='$nomb', apell='$apell', nota='$nota' WHERE id=$id";
    $result = mysqli_query($conn, $query);

    if ($result) {
        $_SESSION["msg"] = "<i class=\"mdi mdi-check\"></i> Editado con exito";
        $_SESSION["msg_type"] = "success";
        header("Location: index.php");
    }else{
        $err = mysqli_error($conn);
        $_SESSION["msg"] = "<i class=\"mdi mdi-alert-octagon\"></i> Fallo al editar... $err";
        $_SESSION["msg_type"] = "danger";
        header("Location: index.php");
    }
}

include "include/header.php";
?>

<div class="container p-4">
    <div class="row">
        <div class="col-md-4 mx-auto">
            <div class="card card-body">
                <form action="editar.php?id=<?php echo $_GET["id"] ?>" method="post">
                    <div class="form-group">
                        <input type="text" name="nomb" value="<?php echo $nomb; ?>" placeholder="nombre" class="form-control" autofocus required>
                        <input type="text" name="apell" value="<?php echo $apell; ?>" placeholder="apellido" class="form-control" required>
                        <input type="number" name="nota" value="<?php echo $nota; ?>" placeholder="nota" class="form-control" required>
                    </div>
                    <button class="btn btn-info btn-block" type="submit" name="edit" value="Editar"><i class="mdi mdi-pencil"></i> fewa</button>
                </form>
            </div>
        </div>
    </div>
</div>

<?php include "include/footer.php"; ?>