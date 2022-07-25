<?php

require "./include/db.php";
require "./include/header.php";

?>

<h1>INICIO</h1>

<?php if (isset($msg)) { ?>
    <hr>
    <h3>Mensaje:</h3>
    <p><?php echo $msg; ?></p>
    <hr>
<?php unset($_SESSION['msg']); } ?>

</body>
</html>
