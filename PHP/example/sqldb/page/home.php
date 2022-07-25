<?php

// Vease carpeta "include"
include "../include/db.php";
include "../include/header.php";

?>

    <form action="tools/add.php" method="POST">
        Nombre: <input   name="nom"  type="text"   required autofocus><br>
        Apellido: <input name="nom2"   type="text"   required><br>
        Nota: <input     name="nota" type="number" required><br>
        <button type="submit"><i class='mdi mdi-plus'></i> Añadir</button>
    </form>

    <?php // Si hay un mensaje, mostrarlo
    if (isset($_SESSION['msg'])) { echo "<hr>".$_SESSION['msg']; }
    ?>

</body>
</html>
<?php session_unset(); ?>