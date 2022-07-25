<?php

session_start();

if (isset($_SESSION['user_id'])) {
    session_unset();
    session_destroy();

    $msg = "Sesion cerrada";
    header("Location: /phplogin/index.php");
} else {
    $_SESSION['msg'] = "Ninguna sesion para cerrar";
    header("Location: /phplogin/index.php");
}
