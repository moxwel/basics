<?php include "db_connect.php" ?>
<?php include "include/header.php" ?>

<div class="container p-4">

    <div class="row">

        <div class="col-md-4">

            <?php if (isset($_SESSION["msg"])) {?>
                <div class="alert alert-<?php echo $_SESSION["msg_type"]; ?> alert-dismissible fade show" role="alert">

                    <?php echo $_SESSION["msg"] ?>

                    <button type="button" class="close" data-dismiss="alert" aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                </div>
            <?php session_unset();} ?>

            <div class="card card-body">
                <form action="save.php" method="post">
                    <div class="form-group">
                        <input type="text" name="nomb" class="form-control" placeholder="nombre" autofocus required>
                        <input type="text" name="apell" placeholder="apellido" class="form-control" required>
                        <input type="number" name="nota" placeholder="nota" class="form-control" required>
                    </div>
                    <button class="btn btn-success btn-block" type="submit" name="save" value="Guardar"><i class="mdi mdi-content-save"></i> Guardar</button>
                </form>
            </div>

        </div>

        <div class="col-md-8">
            <table class="table table-bordered">
                <thead>
                    <tr>
                        <th>id</th>
                        <th>Nombre</th>
                        <th>Apellido</th>
                        <th>Nota</th>
                        <th>Acciones</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                        $query = "SELECT * FROM tablatest";
                        $result = mysqli_query($conn, $query);

                        while($fila = mysqli_fetch_array($result)){ ?>

                            <tr>
                                <td> <?php echo $fila["id"] ?> </td>
                                <td> <?php echo $fila["nom"] ?> </td>
                                <td> <?php echo $fila["apell"] ?> </td>
                                <td> <?php echo $fila["nota"] ?> </td>
                                <td>
                                    <a href="editar.php?id=<?php echo $fila["id"] ?>" role="button" class="btn btn-info"><i class="mdi mdi-pencil"></i></a>
                                    <a href="del.php?id=<?php echo $fila["id"] ?>" role="button" class="btn btn-danger"><i class="mdi mdi-delete"></i></a>
                                </td>
                            </tr>

                    <?php } ?>
                </tbody>
            </table>
        </div>

    </div>

</div>

<?php include "include/footer.php" ?>