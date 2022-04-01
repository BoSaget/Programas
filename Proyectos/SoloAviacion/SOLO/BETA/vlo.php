<?php
session_name('PHPSESSID');
session_start();
$sessID = session_id();
$url = $_GET['url'];
//echo $url."/*************************/";
$mensaje="";


// Datos de Coneccion
$servername = "localhost";
$username = "intrang4_soloav";
$password = "SA2012pc_WEB";
$dbname = "intrang4_intranet2";


if(isset($_POST['date']) != "" && isset($_POST['matricula']) != "" && isset($_POST['vuelo']) != "" && isset($_POST['maniobra']) != "" && isset($_POST['tipo']) != "")
{
    $id=$_SESSION['id'];
    $date = $_POST['date'];
    $matricula = $_POST['matricula'];
    $vuelo = $_POST['vuelo'];
    $maniobra = $_POST['maniobra'];
    $tipo = $_POST['tipo'];

    // Crea Coneccion
    $connexion = new mysqli($servername, $username, $password, $dbname);
    // Edita Tabla
    
    $new = $connexion->query("UPDATE vlo_logbook SET fecha = '$date', matricula = '$matricula', vuelo ='$vuelo', maniobras = '$maniobra', tipo ='$tipo' WHERE id='$id'");


    if(!$new)
    {
        echo"Error <br>";
    }
    
    else
    {
        echo("Registro Actualizado");
        echo "<script>document.location.href='filavlo.php';</script>";
    }
}

$id=$_POST['id'];
$_SESSION['id']=$id;

// Crea Coneccion
$link = new mysqli($servername, $username, $password, $dbname);
$sql = "SELECT * FROM vlo_logbook WHERE id='$id'";
if($result = mysqli_query($link, $sql))
{
    echo "<center>";
    if(mysqli_num_rows($result) > 0)
	{
        for ($x=0; $x<8; $x++)
        {
            echo "<br>";
        }
        echo "<table>";
            echo "<tr>";
                echo "<th>FILA </th>";
                echo "<th>FECHA </th>";
                echo "<th>MATRICULA </th>";
                echo "<th>VUELO </th>";
                echo "<th>MANIOBRAS </th>";
                echo "<th>TIPO </th>";
            echo "</tr>";
        while($row = mysqli_fetch_array($result))
		{
            echo "<tr>";
                echo "<td>" . $row['id'] . "</td>";
                echo "<td>" . $row['fecha'] . "</td>";
                echo "<td>" . $row['matricula'] . "</td>";
                echo "<td>" . $row['vuelo'] . "</td>";
                echo "<td>" . $row['maniobras'] . "</td>";
                echo "<td>" . $row['tipo'] . "</td>";
            echo "</tr>";

            $date = $row['fecha'];
            $matricula = $row['matricula'];
            $vuelo = $row['vuelo'];
            $maniobra = $row['maniobras'];
            $tipo = $row['tipo'];
        }
        echo "</table>";
        // Free result set
        mysqli_free_result($result);
    }
	else
	{
        echo "No Hay Registros ";
    }
    echo "</center>";
}
else
{
    echo "ERROR" . mysqli_error($link);
}
 
// Close connection
mysqli_close($link);
?>


<?php
echo"<!DOCTYPE html>
<html>
	<title>VLO</title>
	<body>
		<h2 align=\"Center\">Ingrese los datos</h2>
		
		<form action=\"vlo.php\" method=\"post\">
			<table border=\"1\" width=\"auto\" align=\"center\">
				<tr>
						<td>
                            Fecha: <input type=\"text\" name=\"date\" value=\"$date\">
						</td>
                </tr>

                <tr>
						<td>
							Matricula: <input type=\"text\" name=\"matricula\" size=\"10\" value= \"$matricula \">		
						</td>
                </tr>

                <tr>
						<td>
							Vuelo: <input type=\"text\" name=\"vuelo\" size=\"10\" value= \"$vuelo \">		
						</td>
                </tr>
                
                 <tr>
						<td>
							Maniobras: <input type=\"text\" name=\"maniobra\" size=\"10\" value=\"$maniobra \">		
						</td>
                </tr>

                <tr>
						<td>
							Tipo: <select name=\"tipo\">
                                <option value=\"$tipo\">$tipo</option>
                                <option value=\"VFR\">VFR</option>
                                <option value=\"SOLO\">SOLO</option>
                                <option value=\"IFR\">IFR</option>
                                <option value=\"NOCT\">NOCT</option>
                                <option value=\"BIM\">BIM</option>
                                <option value=\"BIMNOCT\">BIMNOCT</option>
                                <option value=\"RUTA\">RUTA</option>
                                <option value=\"CCS\">CCS</option>
                                <option value=\"SIM\">SIM</option>
                                <option value=\"XTRA\">XTRA</option>
                                <option value=\"MULTA\">MULTA</option>
                            </select>
						</td>
				</tr>

				<tr>
					<td>
						<input type=\"submit\" value=\"Enviar\">
						<input type=\"reset\" value=\"Borrar\">
					</td>
				</tr>
				
			</table>
		</form>
	</body>
    </html>";
?>