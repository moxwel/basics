<?php

session_start();

if (isset($_SESSION['user_id'])) {
    $id = $_SESSION['user_id'];

    $query = "SELECT * FROM users WHERE id='$id'";
    $res = mysqli_query($conn, $query);
    $row = mysqli_fetch_array($res);

    $email = $row['email'];
    $h = "Sesion iniciada como: $email";
}

if (isset($_SESSION['msg'])) {
    $msg = $_SESSION['msg'];
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>PHPLOGIN</title>
</head>
<body>

<nav>
    <a href="/phplogin/index.php">Inicio</a>
    <?php if (isset($_SESSION['user_id'])) { ?>
        | <a href="/phplogin/logout.php">Salir de Sesion</a> |

    <?php echo $h; } else {?>
        | <a href="/phplogin/login.php">Ingresar</a> |
        <a href="/phplogin/signup.php">Registarse</a>
    <?php } ?>
</nav>
<hr>
