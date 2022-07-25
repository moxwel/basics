<?php

// Vease carpeta "include"
include "../include/db.php";
include "../include/header.php";

?>

    <!-- Ingresar Id a modificar -->
    <form action="actions.php" method="GET">
        Id: <input name="id" type="number" required><br>
        <button type="submit" name="act" value="edit"><i class='mdi mdi-eye'></i> Revisar</button>
        <button type="submit" name="act" value="del"><i class='mdi mdi-delete'></i> Eliminar</button>
    </form>

    <?php

    // Segun la seleccion del boton, se redigira a otra pagina
    if (isset($_GET['act'])) {
        $act = $_GET['act'];
        $id = $_GET['id'];
        header("Location: tools/$act.php?id=$id");
    }

    // Si hay un mensaje, mostrarlo
    if (isset($_SESSION['msg'])) { echo "<hr>".$_SESSION['msg']; }

    // Si el flag es TRUE, significa que si se esta editando
    // y se muestran los datos a editar
    if (isset($_SESSION['check'])) {
        $id = $_SESSION['id'];

        $query = "SELECT * FROM datos WHERE id = $id";
        $res   = mysqli_query($conn, $query);
        $fila  = mysqli_fetch_array($res);
        $nom   = $fila["nom"];
        $nom2  = $fila["nom2"];
        $nota  = $fila["nota"];?>

        <hr>
        <form action="tools/edit.php?id=<?php echo $id; ?>" method="POST">
            Nombre: <input   name="nom"  type="text"   value="<?php echo $nom; ?>" required autofocus><br>
            Apellido: <input name="nom2" type="text"   value="<?php echo $nom2; ?>" required><br>
            Nota: <input     name="nota" type="number" value="<?php echo $nota; ?>" required><br>
            <button type="submit" name="editing" value="TRUE"><i class='mdi mdi-pencil'></i> Editar</button>
        </form>

    <?php } ?>

</body>
</html>
<?php session_unset(); ?>