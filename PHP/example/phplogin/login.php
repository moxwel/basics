<?php

require "./include/db.php";
require "./include/header.php";

if (isset($_POST['env'])) {
    $email = $_POST['email'];
    $pass = $_POST['pass'];

    $query = "SELECT * FROM users WHERE email='$email'";
    $res = mysqli_query($conn, $query);
    $row = mysqli_fetch_array($res);

    if (password_verify($pass, $row['pass'])) {
        $_SESSION['user_id'] = $row['id'];
        header("Location: /phplogin/index.php");
    } else {
        $msg = "Credenciales incorrectas";
    }
}

?>

<h1>INGRESATE</h1>

<?php if (isset($msg)) { ?>
    <hr>
    <h3>Mensaje:</h3>
    <p><?php echo $msg; ?></p>
    <hr>
<?php unset($_SESSION['msg']); } ?>

<?php if (!isset($_SESSION['user_id'])) { ?>
    <form action="/phplogin/login.php" method="post">
        <input type="text"     name="email" placeholder="Ingrese email"      required><br>
        <input type="password" name="pass"  placeholder="Ingrese contraseña" required><br>
        <input type="submit"   name="env"   value="Ingresar">
    </form>
<?php } else { ?>
    <h3>Sesion iniciada.</h3>
<?php } ?>

</body>
</html>
