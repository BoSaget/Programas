<?php
    $conexion = mysqli_connect("localhost","root","","pruebas");
    mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

    $sql = "SELECT * FROM puntos WHERE estatusAnterior <> estatusActual";
    $resultado = mysqli_query($conexion,$sql);
    $info = mysqli_num_rows($resultado);
    $columna = mysqli_fetch_row($resultado);

    $data = array();
    $puntero = array();

    //Se inicializa el valor de i para para acomodar el areglo
    $i=0;
    while ($datos = mysqli_fetch_array($resultado))
    {
        $sqlUpdate = "UPDATE puntos SET estatusAnterior = ". $datos[3] . "  WHERE id = " . $datos[0];
        $update = mysqli_query($conexion,$sqlUpdate);

        //Se acumulan las coordenadas en una sola cadena para despues separarlas
        $puntero[$i] = $datos[1] . '_' . $datos[2] . '_' . $datos[3] . $datos[4];
        $i++;
        
    }

    $data["punto"] = $puntero;
    $data["codigo"] = 0;
    if($info > 1)
    {
        $data["codigo"] = 1;
        
    }

    echo json_encode($data);
?>