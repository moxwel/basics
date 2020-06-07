<?php

$conn = mysqli_connect('localhost', 'root', '', 'phplogin');

if ($conn) {
    $query = "SELECT id, email, pass FROM users";
    $res = mysqli_query($conn, $query);
    $err = mysqli_error($conn);

    if (!$res) {
        $msg = "Error<br>SQL: $err";
    }
}
