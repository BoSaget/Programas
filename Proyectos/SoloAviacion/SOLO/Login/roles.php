<?
SESSION_start();
$name=$_SESSION['name'];
$connexion = new mysqli("localhost", "intrang4_soloav", "SA2012pc_WEB", "intrang4_Control_Usuarios");
$dato=$connexion->query("SELECT ID FROM Usuarios WHERE Nombre = '$name'");

if($r = mysqli_fetch_array ($dato))
{
	$rol=$r['ID'];

	if($rol==1)
	{
		//Estrella
		header ('Location: es');
	}
	
	else if($rol==2)
	{
		//Zuazua
		header ('Location: zu');
	}
	
	else if($rol==3)
	{
		//Fanny
		header ('Location: fa');
	}
	
	else if($rol==4)
	{
		//Jordy
		header ('Location: jo');
	}
	
	else if($rol==5)
	{
		//Alejandra
		header ('Location: al');
	}
	
	else if($rol==6)
	{
		//Ernesto
		header ('Location: er');
	}
	
	else if($rol==7)
	{
		//Cyrus
		header ('Location: cy');
	}
	
	else if($rol==8)
	{
		//Cesar
		header ('Location: ce');
	}
	
	else if($rol==9)
	{
		//Pedro
		header ('Location: pe');
	}
	
	else if($rol==10)
	{
		//Joel
		header ('Location: j');
	}
	
	else if($rol==11)
	{
		//Marcela
		header ('Location: ma');
	}
}

else
{
	header("Location: login.php");
}

?>