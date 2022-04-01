<!DOCTYPE html>
<html lang="en" >
<head>
  <meta charset="UTF-8">
  <title>Menu Intranet</title>
  
  
  
      <link rel="stylesheet" href="css/menu.css">

  
</head>

<body>
  <!DOCTYPE html>
<html lang="en" class="no-js">
	<head>
		<meta charset="UTF-8" />
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"> 
		<meta name="viewport" content="width=device-width, initial-scale=1.0"> 
		<title>Bienvenido a Intranet</title>
	</head>
	<body>
		<div class="container">	
			<!-- Codrops top bar -->
			<header>
				<h1>Bienvenido a Intranet</h1>	
				<h1>de SOLO Aviacion</h1>
				<?
					SESSION_start();
					$name=$_SESSION['name'];
					echo "Hola de nuevo $name";
				?>		
			</header>
			<div class="main clearfix">
				<nav id="menu" class="nav">					
					<ul>
						<li>
							<a href="/inscripcion.php">
								<span class="icon">
									<i aria-hidden="true" class="icon-home"></i>
								</span>
								<span>Inscripcion</span>
							</a>
						</li>
						</li>
						<li>
							<a href="/ca">
								<span class="icon">
									<i aria-hidden="true" class="icon-blog"></i>
								</span>
								<span>Direccion Administrativa</span>
							</a>
						</li>
						
					<li>
							<a href="/cco">
								<span class="icon">
									<i aria-hidden="true" class="icon-contact"></i>
								</span>
								<span>Coordinacion de Pilotos</span>
							</a>
					</li>			
					</ul>
				</nav>
			</div>
		</div><!-- /container -->
	</body>
</html>
  
    <script  src="js/menu.js"></script>

</body>
</html>