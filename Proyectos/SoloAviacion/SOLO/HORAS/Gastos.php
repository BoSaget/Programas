<?php
session_name('PHPSESSID');
session_start();
$sessID = session_id();
$url = $_GET['url'];
//echo $url."/*************************/";
$mensaje="";

if(isset($_POST['mes']) != "")
{

    $mes = $_POST['mes'];
    $descripcion = $_POST['desc'];
    $cantidad = $_POST['cantidad'];
    $precio = $_POST['precio'];
    $moneda = $_POST['moneda'];
    $cambio = $_POST['cambio'];
    if ($moneda=="USD")
    {
        $precio=$precio*$cambio;
        $moneda="MXN";
    }
    $total = $cantidad*$precio;



    // Datos de Coneccion
    $servername = "localhost";
    $username = "intrang4_soloav";
    $password = "SA2012pc_WEB";
    $dbname = "intrang4_Control_Usuarios";



    // Crea Coneccion
    $connexion = new mysqli($servername, $username, $password, $dbname);
    // Checa Coneccion
        if ($connexion->connect_error)
        {
            die("Connection failed: " . $connexion->connect_error);
        }

        if (!($stmt = $connexion->prepare("INSERT INTO Gastos (Mes, Cantidad, Precio, Moneda, Descripcion, Total) VALUES(?,?,?,?,?,?)")))
        {
            echo "Prepare failed\n";
        }
        
        if (!$stmt->bind_param("ssssss", $mes, $cantidad, $precio, $moneda, $descripcion, $total))
        {
            echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
        }

        if (!$stmt->execute())
        {
            echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
        }

        else
        {     
            echo "Registro Exitoso!!!!";
        }

        $dato=$connexion->query("SELECT SUM(Total) as 'suma' FROM Gastos WHERE Mes = '$mes'");
        if($r= mysqli_fetch_array ($dato))
        {
            echo $r['suma'];
            $gastos=$r['suma'];
        }
        
        // Edita Tabla
        $new = $connexion->query("UPDATE Balance SET Gastos = $gastos WHERE Mes = '$mes'");
        if(!$new)
        {
            echo"Error <br>";
        }
        else
        {
            echo("Tabla General Actualizada");
            echo "<script>document.location.href='General.php';</script>";
        }
}
?>

<?php
echo"<!DOCTYPE html>
<html lang=\"en\">
    <head>
        <title>Gastos</title>
		<meta charset=\"UTF-8\" />
        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />
		<link rel=\"stylesheet\" href=\"/css/bootstrap.min.css\" />
		<link rel=\"stylesheet\" href=\"/css/bootstrap-responsive.min.css\" />
        <link rel=\"stylesheet\" href=\"/css/box.css\" />
        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />
        <link rel=\"shortcut icon\" type=\"image/x-icon\" href=\"/favicon.ico\" />
    </head>
    <body>
        <h1 align = \"center\" >Gastos</h1>
        <div id=\"largebox\">            
            <form id=\"loginform\" class=\"form-vertical\" action=\"Gastos.php\" method=\"post\">
				<p class=\"error-datos\">$mensaje</p>
				<p>Ingresa los Siguientes Datos.</p>
                <div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                        <span class=\"add-on\"></span>
                            <select name=\"mes\">
                                <option value=\"Enero\">Enero</option>
                                <option value=\"Febrero\">Febrero</option>
                                <option value=\"Marzo\">Marzo</option>
                                <option value=\"Abril\">Abril</option>
                                <option value=\"Mayo\">Mayo</option>
                                <option value=\"Junio\">Junio</option>
                                <option value=\"Julio\">Julio</option>
                                <option value=\"Agosto\">Agosto</option>
                                <option value=\"Septiembre\">Septiembre</option>
                                <option value=\"Octubre\">Octubre</option>
                                <option value=\"Noviembre\">Noviembre</option>
                                <option value=\"Diciembre\">Diciembre</option>
                            </select>
                        </div>
                    </div>
                </div>
                <div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                            <span class=\"add-on\"></span><input type=\"text\" placeholder=\"Descripcion\"  name=\"desc\" id=\"desc\"/>
                        </div>
                    </div>
                </div>

                <div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                            <span class=\"add-on\"></span><input type=\"text\" placeholder=\"Cantidad\"  name=\"cantidad\" id=\"cantidad\"/>
                        </div>
                    </div>
                </div>

                <div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                            <span class=\"add-on\"></span><input type=\"text\" placeholder=\"Precio\"  name=\"precio\" id=\"precio\"/>
                        </div>
                    </div>
                </div>

                <div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                        <span class=\"add-on\"></span>
                            <select name=\"moneda\">
                                <option value=\"USD\">USD</option>
                                <option value=\"MXN\">MXN</option>
                            </select>
                        </div>
                    </div>
                </div>

                <div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                            <span class=\"add-on\"></span><input type=\"text\" placeholder=\"Cambio\"  name=\"cambio\" id=\"cambio\"/>
                        </div>
                    </div>
                </div>
                
                <div class=\"form-actions\">
                    <span class=\"pull-left\"><input type=\"reset\" class=\"btn btn-inverse\" value=\"Limpiar\"  name=\"clear\" /></span> 
                    <span class=\"pull-right\"><input type=\"submit\" class=\"btn btn-inverse\" value=\"Entrar\"  name=\"send\" /></span>
                </div>
            </form>
        </div>
        
        <script src=\"/js/jquery.min.js\"></script>  
        <script src=\"/js/unicorn.login.js\"></script> 
    </body>
</html>";
?>