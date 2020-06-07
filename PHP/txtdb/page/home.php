<!DOCTYPE html>
<head>
    <title>TXTDB - Home</title>
</head>
<body>
    <!-- Enlaces de las paginas web -->
    <?php include "../include/pages.html" ?>

    <form method="post" action="home.php">
        Nombre: <input name="nom" type="text" required autofocus><br>
        Apellido: <input name="ap" type="text" required><br>
        Nota: <input name="nota" type="number" required><br>
        <input type="submit">
    </form><br>

    <?php
        // Conjunto de funciones.
        include "../include/tools.php";

        // Agrega los datos solamente
        // si las variables estan definidas
        if(isset($_POST["nom"], $_POST["ap"], $_POST["nota"])){

            // Definicion de variables desde POST.
            $nom  = $_POST["nom"];
            $ap   = $_POST["ap"];
            $nota = $_POST["nota"];

            echo addVal($db, "$nom $ap $nota");
        }
    ?>
</body>
</html>