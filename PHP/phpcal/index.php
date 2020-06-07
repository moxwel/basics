<!DOCTYPE html>
<html lang="en">
<head>

<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="X-UA-Compatible" content="ie=edge">

<title>Fecha</title>
<style>
    table {
        width: 100%;
    }
    table, th, td {
        border: 1px solid black;
        height: 50px;
    }
</style>

</head>
<body>

<form method="get">
    <input type="date"     name="fecha" required>
    <input type="submit"   name="env"   value="Ingresar">
</form>

<table>
    <tr>
        <th>Lunes</th>
        <th>Martes</th>
        <th>Miercoles</th>
        <th>Jueves</th>
        <th>Viernes</th>
        <th>Sabado</th>
        <th>Domingo</th>
    </tr>
    <tr>
<?php
if (isset($_GET['fecha'])) {
    $fecha = explode("-", $_GET['fecha']); // 0=año, 1=mes, 2=dia

    $funix = strtotime($_GET['fecha']); // numeros random
    $dsem = date("N", $funix) - 1; // 0=lunes ... 6=domingo
    $dtot = date("t", $funix); // numero entre 28 y 31

    print($fecha[2] . "/" . $fecha[1] . "/" . $fecha[0] . "<br>");
    // print("Dia de la semana:" . $dsem . "<br>");
    // print("Dias totales este mes: " . $dtot . "<br>");

    $d = 1; // dia
    $w = 1; // semana
    $dw = date("N", strtotime($fecha[0] . "-" . $fecha[1] . "-1")) - 1; // el dia de la semana del primer dia del mes

    // Rellar espacios vacios antes de comenzar el mes
    $z = 0;
    while ($z < $dw) {
        print("<th></th>");
        $z++;
    }

    // Rellenar tabla con los dias comenzando desde el 1
    while ($d <= $dtot) {
        if ($d == date("j") && $fecha[1] == date("m") && $fecha[0] == date("Y")) {
            ?><th><a href="select.php?<?php print("d=$d&m=$fecha[1]&y=$fecha[0]") ?>"> <?php print("Hoy: $d") ?> </a></th><?php
        } elseif ($d == $fecha[2]) {
            ?><th><a href="select.php?<?php print("d=$d&m=$fecha[1]&y=$fecha[0]") ?>"> <?php print("Seleccion: $d") ?> </a></th><?php
        } else {
            ?><th><a href="select.php?<?php print("d=$d&m=$fecha[1]&y=$fecha[0]") ?>"> <?php print("$d") ?> </a></th><?php
        }

        // Cuando sea nueva semana se crea nueva fila
        if (($dw % 7) == 6) {
            print("</tr><tr>");
        }
        $d++;
        $dw++;
    }
}
?>
    </tr>
</table>

</body>
</html>
