<?php
session_name('PHPSESSID');
session_start();
$sessID = session_id();
$url = $_GET['url'];
//echo $url."/*************************/";
$mensaje="";
if( (isset($_POST['l_un_em']) and $_POST['l_un_em']!="" ) and (isset($_POST['l_pword']) and $_POST['l_pword']!="" ) ){

	$l_un_em = $_POST['l_un_em'];
	$l_pword = $_POST['l_pword'];
	$l_pword = md5($l_pword);
	$url = $_POST['url'];
		

	$conexion = new mysqli("localhost", "intrang4_soloav", "SA2012pc_WEB", "intrang4_intranet2");

	$consulta = "SELECT * from CAL_CR_users where email = '$l_un_em' and password = '$l_pword'";
	$resultado = $conexion -> query($consulta);

	if ($resultado) { 
		//echo $message = 'Todo Bien '; 
		$fila = $resultado -> fetch_array();
		if($fila ['email']!=""){
		
			$_SESSION['uid'] = 1;
			//echo "<script>document.location.href='".$url."';</script>";
			echo "<script>document.location.href='./090856.html';</script>";
		}else{
		
			$consulta_2 = "SELECT * from CAL_CR_users where email = '$l_un_em' and tPassword = '$l_pword'";
			$resultado_2 = $conexion -> query($consulta_2);

			if ($resultado_2) { 
				// $message = 'Todo Bien 2'; 
				$fila_2 = $resultado -> fetch_array();

				if($fila_2 ['email']!=""){

					$_SESSION['uid'] = 1;
					//echo "<script>document.location.href='".$url."';</script>";
					echo "<script>document.location.href='./090856.html';</script>";
				}else{
					$consulta_3 = "SELECT * from CAL_CR_users where email = '$l_un_em' and password = '$l_pword'";
					$resultado_3 = $conexion -> query($consulta_3);

					if ($resultado_3) { 
						//echo $message = 'Todo Bien 2'; 
						$fila_3 = $resultado -> fetch_array();

						if($fila_3 ['email']!=""){

							$_SESSION['uid'] = 1;
							//echo "<script>document.location.href='".$url."';</script>";
							echo "<script>document.location.href='./090856.html';</script>";
						}else{
							$consulta_4 = "SELECT * from CAL_CR_users where email = '$l_un_em' and tPassword = '$l_pword'";
							$resultado_4 = $conexion -> query($consulta_4);

							if ($resultado_4) { 
								//echo $message = 'Todo Bien 2'; 
								$fila_4 = $resultado -> fetch_array();

								if($fila_4 ['email']!=""){

									$_SESSION['uid'] = 1;
									//echo "<script>document.location.href='".$url."';</script>";
									echo "<script>document.location.href='./090856.html';</script>";
								}else{
									?>
									<style>
									.error-datos {
										display: block !important;
									}
									#loginbox {
										height: 290px !important;
									}	
									</style>
									<?php
									$mensaje ="Usuario o Contraseña inválidos.<br> Verifica y vuelve a intentar";
								}


							}
						}


					}



				}


			}
		} 	
	}

	

}
?>


<style>
.error-datos {
    background: #80b0dd;
    margin-right: 5%;
    margin-left: 5%;
    padding: 10px !important;
    color: #fff;
    border: 1px solid #073e71;
	display: none;
}

</style>


<?php
echo"<!DOCTYPE html>
<html lang=\"en\">
    <head>
        <title>Intranet V2 | SOLO Aviaci&oacute;n</title>
		<meta charset=\"UTF-8\" />
        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />
		<link rel=\"stylesheet\" href=\"css/bootstrap.min.css\" />
		<link rel=\"stylesheet\" href=\"css/bootstrap-responsive.min.css\" />
        <link rel=\"stylesheet\" href=\"css/unicorn.login.css\" />
        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />
        <link rel=\"shortcut icon\" type=\"image/x-icon\" href=\"favicon.ico\" />
    </head>
    <body>
        <div id=\"logo\">
            <img src=\"img/logo.png\" alt=\"\" />
        </div>
        <div id=\"loginbox\">            
            <form id=\"loginform\" class=\"form-vertical\" action=\"login.php\" method=\"post\">
				<p class=\"error-datos\">$mensaje</p>
				<p>Proporciona tus datos de acceso para continuar.</p>
                <div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                            <span class=\"add-on\"><i class=\"icon-user\"></i></span><input type=\"text\" placeholder=\"Usuario\"  name=\"l_un_em\" id=\"uname\"/>
                        </div>
                    </div>
                </div>
                <div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                            <span class=\"add-on\"><i class=\"icon-lock\"></i></span><input type=\"password\" placeholder=\"Contrase&ntilde;a\"  name=\"l_pword\"/>
							<input type=\"hidden\" name=\"url\"  value=\"$url\" />
                        </div>
                    </div>
                </div>
                <div class=\"form-actions\">
                    <!--<span class=\"pull-left\"><a href=\"#\" class=\"flip-link\" id=\"to-recover\">Contrase&ntilde;a olvidada?</a></span>-->
                    <span class=\"pull-right\"><input type=\"submit\" class=\"btn btn-inverse\" value=\"Entrar\"  name=\"log_in\" /></span>
                </div>
            </form>
            <form id=\"recoverform\" action=\"#\" class=\"form-vertical\">
				<p>Proporciona tu correo electr&oacute;nico para enviarte las instrucciones para recuperar t&uacute; contrase&ntilde;a.</p>
				<div class=\"control-group\">
                    <div class=\"controls\">
                        <div class=\"input-prepend\">
                            <span class=\"add-on\"><i class=\"icon-envelope\"></i></span><input type=\"text\" placeholder=\"Correo Electr&oacute;nico\" />
							
                        </div>
                    </div>
                </div>
                <div class=\"form-actions\">
                    <span class=\"pull-left\"><a href=\"#\" class=\"flip-link\" id=\"to-login\">&lt; Regresar al login</a></span>
                    <span class=\"pull-right\"><input type=\"submit\" class=\"btn btn-inverse\" value=\"Recuperar\" /></span>
                </div>
            </form>
        </div>
        
        <script src=\"js/jquery.min.js\"></script>  
        <script src=\"js/unicorn.login.js\"></script> 
    </body>
</html>";
?>
