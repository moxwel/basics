<!DOCTYPE html>
<head>
    <title>TXTDB - Database</title>
</head>
<body>
    <?php include "../include/pages.html" ?>

    <form method="post">
        <input type="submit" name="del" value="Reiniciar DB">
    </form>

    <?php
        include "../include/tools.php";

        if(isset($_POST["del"]) && $_POST["del"] == "Reiniciar DB"){
            delDB($db);
            echo "<br>Reiniciado...";
        }

        printDB($db);
    ?>
</body>
</html>