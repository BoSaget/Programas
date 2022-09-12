        <h1><del>Zona de pruebas</del></h1>
        <h2>Probando Base de datos</h2>

        <div>
                <form action="<?=base_URL("insertar_controller/add");?>" method="get">
                        <div class="form-floating mb-3">
                                <input type="text" class="form-control" id="nombre" name="nombre" placeholder="Nombre">
                                <label for="nombre">Nombre</label>
                        </div>
                        <div class="form-floating mb-3">
                                <input type="text" class="form-control" id="apellido" name="apellido" placeholder="Apellido">
                                <label for="apellido">Apellido</label>
                        </div>
                        <div class="form-floating mb-3">
                                <input type="number" class="form-control" id="numero" name="numero" placeholder="Numero">
                                <label for="celular">Numero</label>
                        </div>
                        <div class="form-floating mb-3">
                                <input type="number" class="form-control" id="boleta" name="boleta" placeholder="Boleta">
                                <label for="boleta">Boleta</label>
                        </div>
                        <div class="col-12">
                                <button class="btn btn-warning" type="submit" name="submit" value="insertar">Enviar</button>
                        </div>
                </form>
        </div>


        
        <div class="container">
                <div class="row justify-content-center">
                        <div class="col-auto">
                                <a class="btn btn-outline-primary" href="home">Home</a>
                        </div>
                </div>
        </div>

        