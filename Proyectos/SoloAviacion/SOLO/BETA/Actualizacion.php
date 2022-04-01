<?php
    echo "Hace la actualizacion de TODOS los datos <br>";

    // Datos de Coneccion
    $servername = "localhost";
    $username = "intrang4_soloav";
    $password = "SA2012pc_WEB";
    $dbname = "intrang4_intranet2";
    // Crea Coneccion
    $DB = new mysqli($servername, $username, $password, $dbname);
    
    $sql = "SELECT uid FROM saldo_vuelos";
    if($result = mysqli_query($DB, $sql))
    {
        if(mysqli_num_rows($result) > 0)
        {
            $i=0;
            while($user = mysqli_fetch_array($result))
            {
                $uid=$user['uid'];
    
                /* Recibos VFR */
                $getRecibosVFR = $DB->query("SELECT SUM(cantidad) FROM cpbt_recibos_conceptos WHERE clave IN ('VFR150', 'VFR172') AND folio IN (SELECT folio FROM cpbt_recibos WHERE nombre='$uid')");
                $row = mysqli_fetch_array($getRecibosVFR);
                $saldoVFR=$row['SUM(cantidad)'];
                
                /* Vuelos VFR */
                $getVuelosVFR = $DB->query("SELECT SUM(vuelo) FROM vlo_logbook WHERE tipo IN ('VFR', 'CCS', 'SOLO', 'RUTA', 'XTRA') AND matricula IN (SELECT tailno FROM aer_data WHERE id > '0') AND alumno='$uid'");
                $row = mysqli_fetch_array($getVuelosVFR);
                $vueloVFR = $row['SUM(vuelo)'];


                /* Recibos IFR */
                $getRecibosIFR = $DB->query("SELECT SUM(cantidad) FROM cpbt_recibos_conceptos WHERE clave IN ('IFRPA28', 'IFR172') AND folio IN (SELECT folio FROM cpbt_recibos WHERE nombre='$uid')");
                $row = mysqli_fetch_array($getRecibosIFR);
                $saldoIFR=$row['SUM(cantidad)'];
                
                /* Vuelos IFR */
                $getVuelosIFR = $DB->query("SELECT SUM(vuelo) FROM vlo_logbook WHERE tipo IN ('IFR', 'NOCT') AND alumno='$uid'");
                $row = mysqli_fetch_array($getVuelosIFR);
                $vueloIFR=$row['SUM(vuelo)'];


                /* Recibos SIM */
                $getRecibosSIM = $DB->query("SELECT SUM(cantidad) FROM cpbt_recibos_conceptos WHERE clave='SIM' AND folio IN (SELECT folio FROM cpbt_recibos WHERE nombre='$uid')");
                $row = mysqli_fetch_array($getRecibosSIM);
                $saldoSIM=$row['SUM(cantidad)'];
                
                /* Vuelos SIM */
                $getVuelosSIM = $DB->query("SELECT SUM(vuelo) FROM vlo_logbook WHERE tipo='SIM' AND alumno='$uid'");
                $row = mysqli_fetch_array($getVuelosSIM);
                $vueloSIM=$row['SUM(vuelo)'];

                /* Recibos BIM */
                $getRecibosBIM = $DB->query("SELECT SUM(cantidad) FROM cpbt_recibos_conceptos WHERE clave='BIM' AND folio IN (SELECT folio FROM cpbt_recibos WHERE nombre='$uid')");
                $row = mysqli_fetch_array($getRecibosBIM);
                $saldoBIM=$row['SUM(cantidad)'];
                
                /* Vuelos BIM */
                $getVuelosBIM = $DB->query("SELECT SUM(vuelo) FROM vlo_logbook WHERE tipo='BIM' AND alumno='$uid'");
                $row = mysqli_fetch_array($getVuelosBIM);
                $vueloBIM=$row['SUM(vuelo)'];


                /* Recibos PDV */
                $getRecibosPDV = $DB->query("SELECT SUM(importe) FROM cpbt_recibos_conceptos WHERE clave='PDV' AND folio IN (SELECT folio FROM cpbt_recibos WHERE nombre='$uid')");
                $row = mysqli_fetch_array($getRecibosPDV);
                $saldoPDV=$row['SUM(importe)'];

                /* Tarifas GAP */
                $getTarifaGapL1 = $DB->query("SELECT tarifa FROM tarifasgap WHERE tipo= 'L1'");
                $row = mysqli_fetch_array($getTarifaGapL1);
                $tarifaGapL1 = $row['tarifa'];

                $getTarifaGapL2 = $DB->query("SELECT tarifa FROM tarifasgap WHERE tipo= 'L2'");
                $row = mysqli_fetch_array($getTarifaGapL2);
                $tarifaGapL2 = $row['tarifa'];

                $getTarifaGapL3 = $DB->query("SELECT tarifa FROM tarifasgap WHERE tipo= 'L3'");
                $row = mysqli_fetch_array($getTarifaGapL3);
                $tarifaGapL3 = $row['tarifa'];

                /* Obtener planes de vuelo por categoria GAP */
                $getVuelosL1 = $DB->query("SELECT count(id) FROM vlo_logbook WHERE matricula IN (SELECT tailno FROM aer_data WHERE gap='L1') AND alumno='$uid' AND fecha>= '2017-05-22 00:00:00'");
                $row = mysqli_fetch_array($getVuelosL1);
                $PDVgapL1=$row['count(id)'];
                $gapL1 = $tarifaGapL1 * $PDVgapL1;

                $getVuelosL2 = $DB->query("SELECT count(id) FROM vlo_logbook WHERE matricula IN (SELECT tailno FROM aer_data WHERE gap='L2') AND alumno='$uid' AND fecha>= '2017-05-22 00:00:00'");
                $row = mysqli_fetch_array($getVuelosL2);
                $PDVgapL2=$row['count(id)'];
                $gapL2 = $tarifaGapL2 * $PDVgapL2;

                $getVuelosL3 = $DB->query("SELECT count(id) FROM vlo_logbook WHERE matricula IN (SELECT tailno FROM aer_data WHERE gap='L3') AND alumno='$uid' AND fecha>= '2017-05-22 00:00:00'");
                $row = mysqli_fetch_array($getVuelosL3);
                $PDVgapL3=$row['count(id)'];
                $gapL3 = $tarifaGapL3 * $PDVgapL3;

                /*Impresion
                echo "UID: $uid <br>";
                echo "Saldo VFR: $saldoVFR <br>";
                echo "Saldo IFR: $saldoIFR <br>";
                echo "Saldo BIM: $saldoBIM <br>";
                echo "Saldo SIM: $saldoSIM <br>";
                echo "Cargo VFR: $vueloVFR <br>";
                echo "Cargo IFR: $vueloIFR <br>";
                echo "Cargo BIM: $vueloBIM <br>";
                echo "Cargo SIM: $vueloSIM <br>";	
                echo "Saldo PDV : $saldoPDV <br>";
                echo "GAP1: $gapL1 <br>";
                echo "GAP2: $gapL2<br>";
                echo "GAP3: $gapL3<br>";
                echo "<br>";*/
    
                //Actualizacion
                $update = $DB->query("UPDATE saldo_vuelos SET saldo_vfr = '$saldoVFR', saldo_ifr = '$saldoIFR', saldo_bim ='$saldoBIM', saldo_sim = '$saldoSIM', cargo_vfr ='$vueloVFR', cargo_ifr ='$vueloIFR', cargo_bim ='$vueloBIM', cargo_sim ='$vueloSIM', saldo_pdv ='$saldoPDV', cargo_pdv_L1 ='$gapL1', cargo_pdv_L2 ='$gapL2', cargo_pdv_L3 ='$gapL3' WHERE uid='$uid'");
                
                $i++;
            }
            echo "Actualizacion de $i datos realizada!!!";

            //Liberar Espacio
            mysqli_free_result($result);
        }
        else
        {
            echo "No Hay Registros ";
        }
    }

    

?>
<?php
    echo"<!DOCTYPE html>
    <html>
        <form action=\"Menu.html\" method=\"post\">
                <table border=\"1\" width=\"auto\" align=\"center\">
                    <tr>
                        <td>
                            <input type=\"submit\" value=\"Regresar\">
                        </td>
                    </tr>
                    
                </table>
            </form>
    </html>";
?>