<?php

require "./include/db.php";
require "./include/header.php";

if (isset($_POST['env'])) {
    if ($_POST['pass'] == $_POST['pass_conf']) {
        $pwd = password_hash($_POST['pass'], PASSWORD_BCRYPT);
        $email = $_POST['email'];

        $query = "INSERT INTO users (email, pass) VALUES ('$email', '$pwd')";
        $res = mysqli_query($conn, $query);
        $err = mysqli_error($conn);

        if ($res) {
            $msg = "Exito";
        } else {
            $msg = "Error<br>SQL: $err";
        }
    } else {
        $msg = "Contraseñas no concuerdan";
    }
}

?>

<h1>REGISTRATE</h1>

<?php if (isset($msg)) { ?>
    <hr>
    <h3>Mensaje:</h3>
    <p><?php echo $msg; ?></p>
    <hr>
<?php unset($_SESSION['msg']); } ?>

<form action="/phplogin/signup.php" method="post">
    <input type="text"     name="email"     placeholder="Ingrese email"       required><br>
    <input type="password" name="pass"      placeholder="Ingrese contraseña"  required><br>
    <input type="password" name="pass_conf" placeholder="Confirme contraseña" required><br>
    <input type="submit"   name="env"       value="Registrarse">
</form>

</body>
</html>
