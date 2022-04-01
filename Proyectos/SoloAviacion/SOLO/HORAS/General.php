<?php

// Datos de Coneccion
$servername = "localhost";
$username = "intrang4_soloav";
$password = "SA2012pc_WEB";
$dbname = "intrang4_Control_Usuarios";


// Crea Coneccion
$connexion = new mysqli($servername, $username, $password, $dbname);

$i=0;
for ($i=1; $i<=12; $i++)
{
	$dato=$connexion->query("SELECT Ingresos+Abonos-Gastos as 'total' FROM Balance WHERE ID = '$i'");
	if($r= mysqli_fetch_array ($dato))
	{
		echo $r['total'];
		$balance=$r['total'];
	}
	$new = $connexion->query("UPDATE Balance SET Balance = $balance WHERE ID = '$i'");
	
}

echo "Balance Actualizado";
echo "<script>document.location.href='Menu.html';</script>";
?>
	