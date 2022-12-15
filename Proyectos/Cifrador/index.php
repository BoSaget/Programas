<?php
error_reporting(-1);
include('creaCadenaConexion.php');

$ls_cadena = "Leon Tejeda";
$ls_cadenaSalida = "";
$li_maxIntentos = 50;
$ls_mensaje = "";

if(cadenaConexion($ls_cadena, $li_maxIntentos, $ls_cadenaSalida, $ls_mensaje) < 0){
	echo $ls_mensaje;
	return; 
}
//$ls_cadenaSalida = ')-*Ag*+4[ 0+40+qLm;{LÑC{LN{Lh.7PdPQP*0q nñ?u)D1$^$';
if(cadenaConexionRetorna($ls_cadenaSalida, $ls_cadenaSalidaDes, $ls_mensaje) < 0){
	echo $ls_mensaje;
	return; 
}

echo 'Cifrar: '.$ls_cadena.'<br><br>';

echo 'Cifrado: '.$ls_cadenaSalida.'<br><br>';

echo 'Descifrado: '.$ls_cadenaSalidaDes.'<br><br>';
?>