<?php

include "../include/db.php";
include "../include/header.php";

?>

<table>
    <!-- Table header -->
    <tr>
        <th>Id</th>
        <th>Nombre</th>
        <th>Apellido</th>
        <th>Nota</th>
    </tr>

    <?php
    $query = "SELECT * FROM datos";
    $res = mysqli_query($conn, $query);

    // Para cada fila, se va a repetir
    while ($fila = mysqli_fetch_array($res)) { ?>
        <tr>
            <td><?php echo $fila['id']; ?></td>
            <td><?php echo $fila['nom']; ?></td>
            <td><?php echo $fila['nom2']; ?></td>
            <td><?php echo $fila['nota']; ?></td>
        </tr>
    <?php } ?>
</table>

</body>
</html>
<?php session_unset(); ?>