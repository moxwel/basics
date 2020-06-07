<?php
    // Ubicacion de DB.
    $db = "../db.txt";

    function ultVal($db){
        /**
         * Retorna el ultimo valor del DB,
         * si el DB esta vacio, retorna 0.
         */

        $leer = file($db);

        if(count($leer) == 0){
            // Archivo vacio
            $ult = 0;
        }else{
            $ult = explode(" ", $leer[count($leer)-1])[0];
        }

        return $ult;
    }

    function addVal($db, $args){
        /**
         * Agrega valores al DB.
         */

        $arc = fopen($db,"a");

        // Si el DB esta vacio, ultVal() retornara 0,
        // es decir, el DB comenzara con 1.
        fwrite($arc, (ultVal($db)+1)." $args\n");

        fclose($arc);
    }

    function printDB($db){
        /**
         * Imprime el DB como una lista
         * solamente si existe.
         */

        if(file_exists($db)){
            $arc = file($db);

            if(empty($arc)){
                echo "<br>DB vacio";
            }else{
                foreach($arc as $l){
                    echo "- ".$l."<br>";
                }
            }
        }else{
            echo "<br>No existe DB!<br>Crea uno. Toca \"Reiniciar DB\"";
        }
    }

    // Borrar DB
    function delDB($db){
        $arc = fopen($db,"w");
        fclose($arc);
    }
?>