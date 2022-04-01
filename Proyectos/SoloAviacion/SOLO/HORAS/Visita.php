<?php
// Datos de Coneccion
$servername = "localhost";
$username = "intrang4_soloav";
$password = "SA2012pc_WEB";
$dbname = "intrang4_Control_Usuarios";



// Crea Coneccion
$link = new mysqli($servername, $username, $password, $dbname);
$sql = "SELECT * FROM Balance";
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
                echo "<th>MES 
                </th>";
                echo "<th>INGRESOS </th>";
				echo "<th>ABONOS </th>";
				echo "<th>GASTOS </th>";
				echo "<th>BALANCE </th>";
            echo "</tr>";
        while($row = mysqli_fetch_array($result))
		{
            echo "<tr>";
                echo "<td>" . $row['Mes'] . "</td>";
                echo "<td>" . $row['Ingresos'] . "</td>";
                echo "<td>" . $row['Abonos'] . "</td>";
				echo "<td>" . $row['Gastos'] . "</td>";
				echo "<td>" . $row['Balance'] . "</td>";
            echo "</tr>";
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
    <head>
        <link rel=\"stylesheet\" href=\"/css/box.css\" />
        <link rel=\"stylesheet\" href=\"/css/style.css\" />
    </head>
    <body align=\"center\">
	    <form action=\"Menu.html\" method=\"get\">
            <div class=\"form-actions\">
                <span class=\"pull-right\"><input type=\"submit\" class=\"btn btn-inverse\" value=\"Regresar\"  name=\"return\" /></span> 
            </div>
	    </form>
    </body>
</html>";
?>